/* 
 * File:   main.c
 * Author: pehladik
 */

#include <stdio.h>
#include <errno.h>
#include "socket.h"
#include "json.h"
#include "hippo.h"
#include "hippo_app_functions.h"
#include <sys/time.h>

struct a0  f_read();
int f_write(struct a1);
/*
* Function linked to the task t
*/
struct a0  f_read() {
	// Check problem with memory leak
	// read data from socket
	/*struct a0 tmp = {0}; // memory allocated locally, we should use malloc

	for (int i=0; i< 8; i++){
		tmp.at[i] = rand()%2;
	}
    return tmp;*/
	//printf("@Receiving....\n");
	//fflush(stdout);
	JSON_Value *input = socket_read_json(get_schema_input());
	//printf("@Parsing....\n");
	//fflush(stdout);
	struct a0 *res= parse_json_obj(input);
	//printf("@Received\n");	
	//json_print(input);
	//fflush(stdout);
	json_value_free(input);
	return *(res);
}

int f_write(struct a1 arg){
	// send data to socket
	//printf("{%d,%d,%d,%d}\n", arg.at[0], arg.at[1], arg.at[2], arg.at[3]);
	JSON_Value *output = get_json_obj(arg);
	//printf("@Sending....\n");
	//fflush(stdout);
	//json_print(output);
	socket_write_json(output);
	//printf("Send.\n");
	//fflush(stdout);
	json_value_free(output); 
	return 0;
}

/*
 * 
 */
int main(int argc, char** argv) {
	// Json memory
	json_init();
	// Connect Socket
	char socket_interface_adr[] = "0.0.0.0";
	char socket_adr[] ="10.0.2.2";
	long unsigned int  socket_port = 5000;
	socket_open(socket_interface_adr, socket_adr, socket_port);
	 time_t t;
	/* Intializes random number generator */
	srand((unsigned) time(&t));
	
    engine_run();
    return (EXIT_SUCCESS);
}
