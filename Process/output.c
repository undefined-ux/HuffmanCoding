#include <stdio.h>
#include <stdlib.h>
#include "output.h"
#include <string.h>
#include "types.h"

static FILE* file = NULL;
void setOutputStream(FILE* stream) {
    file = stream;
}
void compressOutput() {
    if (file == NULL) {
        perror("Error: No file specified\n");
        exit(EXIT_FAILURE);
    }
    if(pointer >= CODE_SIZE) {
        perror("Error: Code array overflow\n");
        exit(EXIT_FAILURE);
    }
    fwrite(code, sizeof(char), pointer, file);
    memset(code, 0, sizeof(char) * CODE_SIZE);
}


