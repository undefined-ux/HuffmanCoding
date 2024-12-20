#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Encoder.h"
#include "Input.h"
#include "Types.h"
void setInputAndOutputStream(FILE* file){
    char filename[BUFFER_SIZE];

}
void addCharWeight(CharWeight *Weight, int *size, char ch) {
    for (int i = 0; i < *size; i++) {
        if (Weight[i].character == ch) {
            Weight[i].weight++;
            return;
        }
    }
    Weight[*size].character = ch;
    Weight[*size].weight = 1;
    (*size)++;
}
void setInputStream(FILE* file,char* filename) {
  	int weight[256];
    file = fopen(filename, "r");
 	Paragraph paragraph;
    if (file == NULL) {
         perror("File not found");
         exit(EXIT_FAILURE);
    } else {
        char* txt = (char*)malloc(BUFFER_SIZE * sizeof(char));
        paragraph.text = txt;
        while(fgets(txt,BUFFER_SIZE,file)) {
			memset(weight, 0, 256 * sizeof(int));
            memset(txt, 0, BUFFER_SIZE * sizeof(char));
          	paragraph.textLength = strlen(txt);
			  	if(paragraph.textLength == 1 && txt[0] == '\n') {
              	    if(paragraph.textLength > 1) {
                    	paragraph.text[paragraph.textLength - 1] = '\0';
						int n = 0;
                        for(int i = 0; i < paragraph.textLength - 1; i++) {

						}
                        HuffmanTree* tree = CreateHuffmanTree(weight, paragraph.textLength);
          	 	 	}
		  	    }
				continue;
        }
    }
}
Paragraph FileWriter(FILE* file,char* filename, int* weight) {
    //输出霍夫曼编码
    file = fopen(filename, "w");

}
void (*file_modifier)(FILE*, char*);
