#include <stdio.h>
#include <stdlib.h>
#include "json.h"

struct a0 *memory = NULL;
JSON_Value  *scheme_output = NULL;
JSON_Value  *scheme_intput = NULL;

/*
* Init memory 
* Reuse memory to avoid memory leak
*/
void json_init(){
    memory = malloc(sizeof(struct a0));
}

/*
* Get Json Output Scheme for Sanity Check 
* returns JSON_Value*
*/
JSON_Value *get_schema_output(){
    if(!scheme_output){
        scheme_output = json_parse_string("{ \"at\":[]}");
    }
    return scheme_output;
}

/*
* Get Json Input Scheme for Sanity Check 
* returns JSON_Value*
*/
JSON_Value *get_schema_input(){
    if(!scheme_intput){
        scheme_intput = json_parse_string("{ \"at\":[]}");
    }
    return scheme_intput;
}

/*
* Create a json object with data from Fiacre
* input a0 * output  Output array of booleans defined
*                   at hippo_app_functions.h
* returns JSON_Value * pointer with embedded json
*/
JSON_Value* get_json_obj(struct a1 output){
    JSON_Value *root_value = json_value_init_object();
    JSON_Object *root_object = json_value_get_object(root_value);
    // Create Array    
    JSON_Value *root_array = json_value_init_array();
    JSON_Array *array = json_array(root_array);
    json_array_append_boolean(array, output.at[0]);
    json_array_append_boolean(array, output.at[1]);
    json_array_append_boolean(array, output.at[2]);
    json_array_append_boolean(array, output.at[3]);
    //json_array_append_boolean(array, output.at[4]);
    // Add to json
    json_object_set_value(root_object, "at", root_array);
    return root_value;
}

/*
* Parse string to json object
* input chat* serialized json string
* returns a1 structure poiter with send data.
*/
struct a0 *parse_json_obj(JSON_Value *input){ 
    JSON_Object * field = json_value_get_object(input);
    JSON_Array *array = json_object_get_array(field, "at"); 
    // Check memory
    if(!memory)
        json_init();

    for(int i=0; i<json_array_get_count(array); i++){        
        memory->at[i] = json_array_get_number(array, i); 
    }
    return memory;
}

/*
* Print JSON variable
* input JSON_Value * value pointer
*/
void json_print(JSON_Value *value){
    char *str = json_serialize_to_string_pretty(value);
    printf("%s \n", str);
    json_free_serialized_string(str);
}