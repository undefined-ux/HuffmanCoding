#ifndef TYPES_H
#define TYPES_H
#define BUFFER_SIZE 2048

typedef char Datatype;

typedef struct HTNode { //霍夫曼树节点
    Datatype character;
    int weight; //权
    int parent; //父节点
    int left_child, right_child; //左孩子，右孩子
} HuffmanTreeNode;


typedef struct HTree {
    HuffmanTreeNode* data;
    int size;
} HuffmanTree;




typedef struct P {
    int textLength;
    char* text;
} Paragraph;


typedef struct CharFreq {
    char character;
    int weight;
    char* code;
} CharWeight;

#endif
