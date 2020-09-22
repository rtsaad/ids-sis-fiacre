#ifndef _JSON_H
#define _JSON_H


#include "hippo.h"
#include "parson.h" 
#include "mce_oilngas.hippo/hippo_app_functions.h"


void json_init();

JSON_Value *get_schema_output();

JSON_Value *get_schema_input();

void json_print(JSON_Value *value);

JSON_Value* get_json_obj(struct a1 output);

struct a0 *parse_json_obj(JSON_Value *input);


#endif