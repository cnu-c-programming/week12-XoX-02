#include <stdio.h>

int main(int argc, const char* argv[]) {
    if (argc < 2)
        return 0;

    FILE* fp = fopen(argv[1], "r");

    int alpabet[27] = {0};

    while(!feof(fp)){
        char c;
        fscanf(fp,"%c",&c);
        if(c>='a' && c<='z'){
            alpabet[c-'a']++;
        }
    }

    for(int i =0; i < sizeof(alpabet)/sizeof(alpabet[0]); i++){
        printf("%c: %d\n", 'a' + i, alpabet[i]);
    }

    fclose(fp);

    return 0;
}

