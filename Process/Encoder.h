#ifndef ENCODER_H
#define ENCODER_H
#include <stdio.h>
#include <stdlib.h>
#include "Types.h"
/*

typedef char Datatype;
typedef struct HTNode {
    int weight;
    int parent;
    int left_child, right_child;
} *HuffmanTreeNode;
typedef struct HTree {
    HuffmanTreeNode* data;
    int size;
} HuffmanTree;

*/
void Select(HuffmanTree* HT, int end, int* index1, int* index2) {
 	//选出两个权值最小的点
	int min1 = INT_MAX, min2 = INT_MAX;
    for(int i = 0;i <= end;i ++) {
    	if(HT->data[i].parent == -1 && HT -> data[i].weight < min1) {
        	min1 = HT -> data[i].weight;
            *index1 = i;
    	}
    }
    for(int i = 0;i <= end;i ++) {
    	if(i !=  *index1 && HT.data[i].parent == -1 && HT -> data[i].weight < min2) {
        	min2 = HT -> data[i].weight;
            *index2 = i;
    	}
    }
}
HuffmanTree* CreateHuffmanTree(int* weight, int n) {
  	//初始化
	HuffmanTree* HT = (HuffmanTree*)malloc(sizeof(HuffmanTree));
    HT -> data = (HuffmanTreeNode*)malloc(n * sizeof(HuffmanTreeNode*));
    HT -> size = 2 * n - 1;
    for(int i = 0;i < 2 * n - 1;i ++) {
      	if(i < n) {
        	HT -> data[i].weight = weight[i];
        }
        HT -> data[i].parent = -1;
        HT -> data[i].left_child = -1;
        HT -> data[i].right_child = -1;
    }
	//创建树
    for(int i = n;i < 2 * n - 1;i ++) {
		int index1, index2;
        Select(HT, i - 1, &index1, &index2);
        //删除
        HT -> data[index1].parent = i;
        HT -> data[index2].parent = i;
        //合并
        HT -> data[i].left_child = index1;
        HT -> data[i].right_child = index2;
        HT -> data[i].weight = HT -> data[index1].weight + HT -> data[index2].weight;
    }
	return HT;
}

#endif
