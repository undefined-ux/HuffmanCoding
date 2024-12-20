#pragma once
#include <stdio.h>
#include "Types.h"

void addCharWeight(CharWeight *Weight, int *size, char ch);
void setInputAndOutputStream(FILE* file);
void setInputStream(FILE* file,char* filename);
void addOrUpdateCharFreq(CharFrequency *freqArray, int *size, char ch);
Paragraph FileWriter(FILE* file,char* filename, int* weight);
