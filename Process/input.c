#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../huffman.h"

static FILE* file = NULL;

int CharCmp(const void* a, const void* b) {
    return ((CharWeight*)a) -> weight - ((CharWeight*)b) -> weight;
}

void setInputStream(FILE* stream) {
  	file = stream;
}

void Encode() {

    if (file == NULL) {
        perror("No file specified\n");
        exit(EXIT_FAILURE);
    }

    int weight[257] = { 0 };
    Paragraph paragraph;
    char* txt = malloc(BUFFER_SIZE * sizeof(char));
    while (fgets(txt, BUFFER_SIZE, file)) { //以一段或BUFFER_SIZE为基准读取字符
        //在每段的开始初始化权重
        memset(weight, 0, 257 * sizeof(int));
        //没有什么必要的段落结构体
        paragraph.text = txt;
        paragraph.textLength = strlen(txt);

        if (paragraph.textLength > 1 && txt[0] != '\n') {

            int freq = 0; //记录字符出现的种类的数量
            for (int p = 0; p < paragraph.textLength; p++) {
                if (weight[(unsigned char)paragraph.text[p]] == 0) {
                    freq++;
                }
                weight[(unsigned char)paragraph.text[p]]++;
            }
            int point = 0;
            CharWeight* ChWeight = malloc((point + 1) * sizeof(CharWeight));

            for (int ch = 0; ch < 257; ch ++) {
                if (weight[ch] != 0) {
                    ChWeight[point].code = NULL;
                    ChWeight[point].character = (char)ch;
                    ChWeight[point ++].weight = weight[ch];
                }
            }
            qsort(ChWeight, freq, sizeof(CharWeight), CharCmp);//为字符按照权重排序
            //构建霍夫曼树并编码
            HuffmanTree* tree = CreateHuffmanTree(ChWeight, freq);
            CreateHuffmanCodes(tree, ChWeight, freq);
            SaveHuffmanCodes(ChWeight, freq, &paragraph);
            free(ChWeight);
            memset(txt, 0, BUFFER_SIZE * sizeof(char));
        }
    }
    free(txt);
    //终于结束了
    fclose(file);
}

