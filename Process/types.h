#pragma once

#define TEXT_SIZE 4096
#define BUFFER_SIZE 2048
#define CODE_SIZE 2048

extern char code[CODE_SIZE];
extern int pointer;

typedef char Datatype;
typedef struct HTNode { //霍夫曼树节点
    Datatype character; //字符
    int weight; //权
    int parent; //父节点
    int left_child, right_child; //左孩子，右孩子
} HuffmanTreeNode;
typedef struct HTree {
    HuffmanTreeNode* data;
    size_t size;
} HuffmanTree;
typedef struct P {
    size_t textLength;
    char* text;
} Paragraph;
typedef struct CharFreq {
    char character;
    int weight;
    char* code;
} CharWeight;

