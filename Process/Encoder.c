#include <stdlib.h>
#include "Types.h"
#include "Encoder.h"

void Select(HuffmanTree* HT, int end, int* index1, int* index2) {
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
int WeightCmp(const CharWeight* a, const CharWeight* b) {
    const CharWeight* f1 = (const CharWeight*) a;
    const CharWeight* f2 = (const CharWeight*) b;
    if (f1 -> weight < f2 -> weight) {
        return -1; // f1 小于 f2
    } else if (f1 -> weight > f2 -> weight) {
        return 1;  // f1 大于 f2
    } else {
        return 0;  // 两者相等
}
/*

typedef char Datatype;
typedef struct HTNode {
	Datatype Data;
    int weight;
    int parent;
    int left_child, right_child;
} HuffmanTreeNode;
typedef struct HTree {
    HuffmanTreeNode* data;
    int size;
} HuffmanTree;

*/

HuffmanTree* CreateHuffmanTree(CharWeight* charweight, int n) {
    //初始化
    HuffmanTree* HT = (HuffmanTree*)malloc(sizeof(HuffmanTree));
    qsort(charweight -> weight, n, sizeof(CharWeight), WeightCmp);
    HT -> data = (HuffmanTreeNode*)malloc((2 * n - 1) * sizeof(HuffmanTreeNode*));
    HT -> size = 2 * n - 1;
    for(int i = 0;i < 2 * n - 1;i ++) {
        if(i < n) {
            HT -> data[i].weight = Freq -> frequency[i];
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

char CreateHuffmanCode(HuffmanTree* HT, int* weight) {

    for (int i = 0; i < HT -> size; i++) {
        weight[HT -> data[i].character] = i;
    }
}
