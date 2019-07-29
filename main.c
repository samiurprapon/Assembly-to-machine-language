#include<stdio.h>
#include <string.h>

int main() {
    char assemble_code[100];
    FILE *file;
    FILE *output;
    char* token;
    int c = 0;
    int i = 0;
    int counter = 1;

    if ((file = fopen("input.txt", "r")) != NULL) {

        while((c = fgetc(file)) != EOF){
            assemble_code[i] = c;
            i++;
        }

        token = strtok(assemble_code, ",");
        output = fopen("output.txt", "a");

        while (token != NULL) {
            if (counter == 5) {
                fprintf(output, "\n");
                counter = 0;
            }

            if(strcmp(token, "add") == 0) {
                fprintf(output, "0011");
            } else if(strcmp(token, "sub") == 0) {
                fprintf(output, "0110");
            } else if(strcmp(token, "$t0") == 0) {
                fprintf(output, "0000");
            } else if(strcmp(token, "$t1") == 0) {
                fprintf(output, "0001");
            } else if(strcmp(token, "$t2") == 0) {
                fprintf(output, "0010");
            }

            counter++;
            token = strtok(NULL, ",");
        }

        fclose(output);
    }

    fclose(file);
    return 0;
}


