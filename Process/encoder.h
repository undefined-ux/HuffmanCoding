#pragma once
#include "Types.h"

void Select(HuffmanTree* HT, int end, int* index1, int* index2);
int WeightCmp(const CharWeight* f1, const CharWeight* f2);
HuffmanTree* CreateHuffmanTree(int* weight, int n);
void CreateHuffmanCodes(HuffmanTree* tree, CharWeight* ChWeight, int freq);
void SaveHuffmanCodes(CharWeight* ChWeight, size_t size, Paragraph* paragraph);
