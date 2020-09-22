#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> 
#include "socket.h"
// JSON Lib to send and receive data
// https://github.com/kgabis/parson
#include "parson.h"

/* Variables */

struct sockaddr_in serv_addr, localaddr;
struct hostent *server;
int sockfd, portno, n;

/* Helpers (private) */
void error(const char *msg)
{
    perror(msg);
    exit(0);
}


/* Public Functions */

/* Connect to server
 */
void socket_open(char *addr_interface, char *addr, long unsigned int port){

    // Open socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    // Clean serv_addr variable
    bzero((char *) &localaddr, sizeof(serv_addr));
    bzero((char *) &serv_addr, sizeof(serv_addr));
    // connect to network interface
    localaddr.sin_family = AF_INET;
    localaddr.sin_port = 0;
    localaddr.sin_addr.s_addr = inet_addr(addr_interface);
    bind(sockfd, (struct sockaddr *) &localaddr, sizeof(localaddr));

    // Connect to ip
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(addr);
    serv_addr.sin_port = htons(port);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");      
}

/* Write message to server
 * input char* pointer
 */
void socket_write(char *value){ 
    assert(strlen(value)>0); 
    n = write(sockfd,value,strlen(value));
    if (n < 0) 
         error("ERROR writing to socket");
}

/* Read message from server
 * input char* buffer
 * int buffer_size
 */
char * socket_read(){
    char buffer[2048] = { '\0' };   
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) 
        error("ERROR reading from socket");
    char *res = (char *) malloc(strlen(buffer));
    strcpy(res, buffer);
    return res;
}

/* Helper function to read json value from socket 
 *
 * input JSON_VALUE * schema    Json schema for sanity check of 
 *                              received message.
 * output JSON_VALUE * res       Pointer to return received msg.
 */
JSON_Value * socket_read_json(JSON_Value *schema){
    char *buffer; 
    buffer = socket_read(&buffer); 
    JSON_Value *res = NULL;
    res = json_parse_string(buffer);
    // Release buffer
    free(buffer);
    // Sanity check
    if(res == NULL || json_validate(schema, res) != JSONSuccess){
        error("INVALID json");
    }
    return res;
}

/* Helper function to serialize json (parson lib)
 * 
 *  input JSON_VALUE * json
 * 
 */
void socket_write_json(JSON_Value *json){
    assert(json);
    char *st = json_serialize_to_string(json); 
    socket_write(st);
    // Release memory
    free(st);
}



