#include <stdio.h>
#include <json-c/json.h>

#define CONFIGSIZE 1024

int main(){
    FILE *fp;
    char json[CONFIGSIZE];

    struct json_object *parsed_json;
    struct json_object *name;
    struct json_object *age;
    struct json_object *friends;

    struct json_object *idInfo;
    struct json_object *profile;
    struct json_object *wrapper;
    struct json_object *isProtect;


    struct json_object *friend;       

    size_t n_friends;
    size_t i;

    fp = fopen("test.json","r");
    fread(json, CONFIGSIZE, 1, fp);
    fclose(fp);

    parsed_json = json_tokener_parse(json);
    json_object_object_get_ex(parsed_json,"name",&name);
    json_object_object_get_ex(parsed_json,"age",&age);    
    json_object_object_get_ex(parsed_json,"friends",&friends);    
    json_object_object_get_ex(parsed_json,"1",&idInfo);    
    
    printf("Name: %s\n",json_object_get_string(name));
    printf("Age: %d\n",json_object_get_int(age));

    n_friends = json_object_array_length(friends);
    printf("Found %lu friends \n",n_friends);

    for(i = 0 ; i < n_friends; i++){
        friend = json_object_array_get_idx(friends,i);
        printf("%lu. %s\n",i+1,json_object_get_string(friend));
    }
    json_object_object_get_ex(idInfo, "isProtect", &isProtect);
    printf("isProtect: %d\n",json_object_get_int(isProtect));


}