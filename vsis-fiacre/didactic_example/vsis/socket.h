#ifndef _SOCKET_H
#define _SOCKET_H

#include "parson.h"

/* Socket Header */
#define SOCKET_ID 1234
#define SERVER_ADDRESS_DEFAULT '127.0.0.1'
#define SERVER_PORT_DEFAULT 2000

void socket_open(char *addr_interface, char *addr, long unsigned int port);
void socket_write(char *value);
void socket_write_json(JSON_Value *json);
char * socket_read();
JSON_Value * socket_read_json(JSON_Value *schema);

#endif