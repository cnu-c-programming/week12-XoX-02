#include <stdio.h>

int main(int argc, const char* argv[]) {
    if (argc < 3)
        return 0;

    FILE* fp_src = fopen(argv[1], "r");
    FILE* fp_dst = fopen(argv[2], "a");
    if(fp_src == NULL) perror("error: cannot open\n");
    if(fp_dst == NULL) perror("error: cannot open\n");
    
    char c;
    while((c = fgetc(fp_src,)) != NULL){
        fputc(c,fp_dst);
        if(ferror(fp_dst)) perror("error: cannot write\n");
    }

    if(ferror(fp_src)) perror("error: cannot read\n");

    fclose(fp_src);
    fclose(fp_dst);

    return 0;
}

