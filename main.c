#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "huffman.h"

int weight[256] = { 0 };

CommandLineArgs parseCommandLineArgs(int argc, char* argv[]);

int main(int argc, char* argv[]) {

    const CommandLineArgs commandLineArgs = parseCommandLineArgs(argc, argv);


    return 0;
}

CommandLineArgs parseCommandLineArgs(int argc, char* argv[]) {
    CommandLineArgs args;
    args.input = stdin;
    args.output = stdout;
    return args;
}
