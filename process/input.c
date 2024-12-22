#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encoder.h"
#include "input.h"
#include "types.h"
/*
typedef struct P {
    int textLength;
    char* text;
} Paragraph;
typedef struct CharFreq {
    DataType character;
    int weight;
    char* code;
} CharWeight;
*/
int CharCmp(const void* a, const void* b) {
    return ((CharWeight*)a) -> weight - ((CharWeight*)b) -> weight;
}


void OutputHuffmanCodes(CharWeight* ChWeight, int freq, const char* outputFilename) {
    // 修改文件后缀
    char outputFile[256];
    strcpy(outputFile, outputFilename);
    strcat(outputFile, ".z");

    FILE* outputFilePtr = fopen(outputFile, "w");
    if (outputFilePtr == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    // 输出霍夫曼编码到文件
    for (int i = 0; i < freq; i++) {
        fprintf(outputFilePtr, "Character: %c, Weight: %d, Code: %s\n", ChWeight[i].character, ChWeight[i].weight, ChWeight[i].code);
        free(ChWeight[i].code); // 释放编码字符串的内存
    }

    fclose(outputFilePtr);
}

void setInputStream(FILE* file, char* filename) {
    int weight[257] = {0};
    file = fopen(filename, "r");
    Paragraph paragraph;
    if (file == NULL) {
        perror("File not found");
        exit(EXIT_FAILURE);
    } else {
        char* txt = (char*)malloc(BUFFER_SIZE * sizeof(char));
        while (fgets(txt, BUFFER_SIZE, file)) {
            memset(weight, 0, 257 * sizeof(int));
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
                HuffmanTree* tree = CreateHuffmanTree(ChWeight, freq);
				GenerateHuffmanCodes(tree, ChWeight, freq);
                OutputHuffmanCodes(ChWeight, freq, filename);
                free(ChWeight);
            }
        }
        free(txt);
        fclose(file);
    }
}
