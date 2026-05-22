#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }


    int sum = 0;
    char str[100];
    char error[100] = "";
    int n;
    while(fgets(str,sizeof(str),fp) != NULL){
        n = atoi(str);
        if(n == 0){
            strcat(error, "invalid input ");
            strcat(error, str);
        }else{
            sum += n;
        }
    }

    printf("sum: %d\n", sum);
    printf("%s", error);
    fclose(fp);
    return 0;
}
