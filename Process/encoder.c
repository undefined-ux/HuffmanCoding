#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../huffman.h"

void Select(HuffmanTree* HT, int end, int* index1, int* index2) {
    //检查点
    if (HT == NULL) {
        perror("Error: Failed to allocate memory for Huffman Tree");
        exit(EXIT_FAILURE);
    }
    //选出两个权值最小的点
    int min1 = INT_MAX, min2 = INT_MAX;
    for(int i = 0;i <= end;i ++) {
        if(HT -> data[i].parent == -1 && HT -> data[i].weight < min1) {
            min1 = HT -> data[i].weight;
            *index1 = i;
        }
    }
    for(int i = 0;i <= end;i ++) {
        if(i !=  *index1 && HT -> data[i].parent == -1 && HT -> data[i].weight < min2) {
            min2 = HT -> data[i].weight;
            *index2 = i;
        }
    }
}

HuffmanTree* CreateHuffmanTree(CharWeight* ChWeight, int n) {

    //初始化
    HuffmanTree* HT = malloc(sizeof(HuffmanTree));
    HT -> data = (HuffmanTreeNode*)malloc((2 * n - 1) * sizeof(HuffmanTreeNode*));
    HT -> size = 2 * n - 1;
    for(int i = 0;i < 2 * n - 1;i ++) {
        if(i < n) {
            HT -> data[i].weight = ChWeight[i].weight;
        }
        HT -> data[i].parent = -1;
        HT -> data[i].left_child = -1;
        HT -> data[i].right_child = -1;
    }

    //生长
    for(int i = n;i < 2 * n - 1;i ++) {
        int index1, index2;
        Select(HT, i - 1, &index1, &index2);
        //重置父节点
        HT -> data[index1].parent = i;
        HT -> data[index2].parent = i;
        //合并
        HT -> data[i].left_child = index1;
        HT -> data[i].right_child = index2;
        HT -> data[i].weight = HT -> data[index1].weight + HT -> data[index2].weight;
    }
    return HT;
}

void CreateHuffmanCodes(HuffmanTree* HT, CharWeight* ChWeight, int freq) {

    //生成霍夫曼编码
    char buffer[256];
    for (int i = 0; i < freq; i++) {
        int current = i;
        int index = 0;
        int parent = HT -> data[current].parent;

        while (parent != -1) {
            if (HT -> data[parent].left_child == current) {
                buffer[index++] = '0';
            } else {
                buffer[index++] = '1';
            }
            current = parent;
            parent = HT -> data[current].parent;
        }
        buffer[index] = '\0';

        //反转编码
        for (int j = 0; j < index / 2; j++) {
            char temp = buffer[j];
            buffer[j] = buffer[index - j - 1];
            buffer[index - j - 1] = temp;
        }
        //初始化code，容量为包含二进制数字的个数
        ChWeight[i].code = (char*)malloc((index + 1) * sizeof(char));
        //把已经做好的编码copy进code里
        strcpy(ChWeight[i].code, buffer);
    }
}

char code[CODE_SIZE];
int pointer = 0;

void SaveHuffmanCodes(const CharWeight* ChWeight, size_t size, Paragraph* paragraph) {

    for (size_t i = 0; i < paragraph -> textLength; i ++) {
        for (size_t j = 0; j < size; j ++) {
            if (ChWeight[j].character == paragraph -> text[i]) {
                size_t codeLength = strlen(ChWeight[j].code);
                if (pointer + codeLength >= TEXT_SIZE) { //为防止内存溢出加一道保险
                    fprintf(stderr, "Error: code array overflow\n");
                    exit(EXIT_FAILURE);
                }
                for (size_t k = 0; k < codeLength; k ++) {
                    code[pointer ++] = ChWeight[j].code[k];
                }
                break;
            }
        }
    }
}

