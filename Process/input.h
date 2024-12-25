#pragma once
#include <stdio.h>
#include "../huffman.h"

int CharCmp(const void* a, const void* b);
void setInputStream(FILE* stream);
void Encode();
