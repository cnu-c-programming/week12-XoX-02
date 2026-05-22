#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }


    int sum = 0;
    char num[100];
    int n;
    while(fgets(num,sizeof(num),fp) != NULL){
        n = atoi(num);
        sum += n;
    }

    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
