#pragma once
#include "Types.h"

int WeightCmp(const CharWeight* f1, const CharWeight* f2);
char CreateHuffmanCode(HuffmanTree* HT, CharWeight* Freq);
HuffmanTree* CreateHuffmanTree(CharWeight* charweight, int n);
void Select(HuffmanTree* HT, int end, int* index1, int* index2);

#endif
