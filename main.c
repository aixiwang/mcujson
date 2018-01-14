#include <stdio.h>
#include <stdlib.h>

#include "mcujson.h"
#include "main.h"

//----------------------------
// test_mcujson
//----------------------------
int test_mcujson() {
    int buffer_size = 2048;
    char json_data[2048];
    char json_data_with_header[2048];
    
    char token_name[32];    
    char token_value[256];
    
    int ret_code;
    int i,j;
    i = j = 0;
    char c;
    
    if (read_file_to_ram("example.json", json_data, 2048, &buffer_size) < 0) {
        return -1;
    }
    
    mcujson_debug(json_data);
    
    mcujson_add_json_header(json_data,json_data_with_header);
    json_data[0] = 0;
    
    j = 0;
    while (json_data_with_header[j]){
        c = json_data_with_header[j];
        j++;
        printf("c: %c (0x%x)\n",c,c);
        // emulate network or serial port streaming
        
        i = mcujson_stream_state_machine(c,json_data);
        if (i == 1){
            // test json value start
            printf("====================================================================test 1\n");
            strcpy(token_name,"last_name");
            strcpy(token_value,"");
            ret_code = mcujson_get_token(json_data,token_name,token_value);
            printf("retcode=%d,token_value=%s\n",ret_code,token_value);
            
            printf("====================================================================test 2\n");
            strcpy(token_name,"age");
            strcpy(token_value,"");
            ret_code = mcujson_get_token(json_data,token_name,token_value);
            printf("retcode=%d,token_value=%s\n",ret_code,token_value);

            printf("====================================================================test 3\n");
            strcpy(token_name,"children");
            strcpy(token_value,"");

            ret_code = mcujson_get_token(json_data,token_name,token_value);
            printf("retcode=%d,token_value=%s\n",ret_code,token_value);

            printf("====================================================================test 4\n");
            strcpy(token_name,"wife");
            strcpy(token_value,"");

            ret_code = mcujson_get_token(json_data,token_name,token_value);
            printf("retcode=%d,token_value=%s\n",ret_code,token_value);

            printf("====================================================================test 5\n");
            strcpy(token_name,"simple");
            strcpy(token_value,"");

            ret_code = mcujson_get_token(json_data,token_name,token_value);
            printf("retcode=%d,token_value=%s\n",ret_code,token_value);

            printf("====================================================================test 6\n");
            strcpy(token_name,"test_nested");
            strcpy(token_value,"");

            ret_code = mcujson_get_token(json_data,token_name,token_value);
            printf("retcode=%d,token_value=%s\n",ret_code,token_value);

            printf("====================================================================test 7\n");
            strcpy(token_name,"data1");
            strcpy(token_value,"");

            ret_code = mcujson_get_token(json_data,token_name,token_value);
            printf("retcode=%d,token_value=%s\n",ret_code,token_value);

            printf("====================================================================test 8\n");
            strcpy(token_name,"data2");
            strcpy(token_value,"");

            ret_code = mcujson_get_token(json_data,token_name,token_value);
            printf("retcode=%d,token_value=%s\n",ret_code,token_value);

            printf("====================================================================test 9\n");
            strcpy(token_name,"data3");
            strcpy(token_value,"");

            ret_code = mcujson_get_token(json_data,token_name,token_value);
            printf("retcode=%d,token_value=%s\n",ret_code,token_value);

            printf("====================================================================test 10\n");
            strcpy(token_name,"data4");
            strcpy(token_value,"");

            ret_code = mcujson_get_token(json_data,token_name,token_value);
            printf("retcode=%d,token_value=%s\n",ret_code,token_value);

            // test json value end

        }
    }
    
    
    
    // free(json_data);
    return 0;
}

/*----------------------------
 main
 ----------------------------*/
int main(int argc, char **argv) {
    // return example_3_entry(argc, argv);
    return test_mcujson();
    
}

