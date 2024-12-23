#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encoder.h"
#include "input.h"
#include "types.h"

static FILE *file = NULL;

int CharCmp(const void* a, const void* b) {
    return ((CharWeight*)a) -> weight - ((CharWeight*)b) -> weight;
}

void setInputStream(FILE* stream) {
  	file = stream;
}

void stdInput() {

    if (file == NULL) {
        perror("No file specified\n");
        exit(EXIT_FAILURE);
    }

    int weight[257] = { 0 };
    Paragraph paragraph;
    char* txt = (char*)malloc(BUFFER_SIZE * sizeof(char));
    while (fgets(txt, BUFFER_SIZE, file)) {
        memset(weight, 0, 257 * sizeof(int));
        memset(txt, 0, BUFFER_SIZE * sizeof(char));
        paragraph.text = txt;
        paragraph.textLength = strlen(txt);
        if (paragraph.textLength > 1 && txt[0] != '\n') {
            int freq = 0;
            for (int p = 0; p < paragraph.textLength; p++) {
                if (weight[(unsigned char)paragraph.text[p]] == 0) {
                    freq++;
                }
                weight[(unsigned char)paragraph.text[p]]++;
            }
            CharWeight* ChWeight = (CharWeight*)malloc(freq * sizeof(CharWeight));
            int point = 0;
            for (int ch = 0; ch < 257; ch++) {
                if (weight[ch] != 0) {
                    ChWeight[point].character = ch;
                    ChWeight[point ++].weight = weight[ch];
                }
            }
            qsort(ChWeight, freq, sizeof(CharWeight), CharCmp);
            HuffmanTree* tree = CreateHuffmanTree(weight, freq);
            CreateHuffmanCodes(tree, ChWeight, freq);
            SaveHuffmanCodes(ChWeight, freq, &paragraph);
            free(ChWeight);
        }
    }
    free(txt);
    fclose(file);
}

