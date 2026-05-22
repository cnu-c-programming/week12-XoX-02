#include <stdio.h>
#include <string.h>

int main(int argc, const char* argv[]) {
    if (argc < 3)
        return 0;

    FILE* fp = fopen(argv[1], "r");
    const char* target_str = argv[2];

    char str[200];

    while(fgets(str,sizeof(str),fp) != NULL){
        if(strstr(str,agrv[2])){
            printf("%s\n",str);
        }
    }
    
    fclose(fp);

    return 0;
}

