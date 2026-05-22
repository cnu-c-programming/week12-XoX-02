#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct config {
    char InputFileName[64];
    int Options;
    char SectionName[64];
    unsigned long long Address;
} Config;

void config_parser(Config* config_ptr) {
    FILE* fp = fopen("config.txt","r");
    char str[64];

    while(fgets(str,sizeof(str),fp) != NULL){
        char *token = strtok(str,"=\n");
        
        if(strcmp(token,"InputFileName") == 0){
            token = strtok(NULL,"=\n");
            strcpy(config_ptr->InputFileName,token);
        }
        else if(strcmp(token,"Options") == 0){
            token = strtok(NULL,"=\n");
            config_ptr->Options = atoi(token);
        }
        else if(strcmp(token,"SectionName") == 0){
            token = strtok(NULL,"=\n");
            strcpy(config_ptr->SectionName, token);
        }
        else if(strcmp(token,"Address") == 0){
            token = strtok(NULL,"=\n");
            config_ptr->Address = strtoull(token,NULL,16);
        }
    }

}

int main(int argc, const char* argv[]) {
    Config config;
    config_parser(&config);

    printf("config: %s %d %s %llu\n", 
        config.InputFileName, 
        config.Options,
        config.SectionName,
        config.Address);
    return 0;
}

