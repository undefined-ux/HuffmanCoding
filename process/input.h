#pragma once
#include <stdio.h>
#include "types.h"

void addCharWeight(CharWeight *Weight, int *size, char ch);
void setInputAndOutputStream(FILE* file);
void setInputStream(FILE* file,char* filename);
void addOrUpdateCharFreq(CharFrequency *freqArray, int *size, char ch);
Paragraph fileWriter(FILE* file,char* filename, int* weight);
