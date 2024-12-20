#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "huffman.h"

CommandLineArgs parseCommandLineArgs(int argc, char* argv[]);



int main(int argc, char* argv[]) {
    CommandLineArgs args = parseCommandArgs(argc, argv);
    if (args.input) {
        setInputStream(args.input, argv[argc - 1]);
    }
    if (args.input) fclose(args.input);
    if (args.output) fclose(args.output);

    return 0;
}
/*
typedef struct CLArguments {
    FILE* input;
    FILE* output;
    int compress;
} CommandLineArgs;
 */
CommandLineArgs parseCommandArgs(int argc, char* argv[]) {
    CommandLineArgs args;
    args.input = NULL;
    args.output = NULL;
    args.compress = 0;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--output") == 0 || strcmp(argv[i], "-of") == 0) {
            if (i + 1 < argc) {
                fputs("Output:", stdout);
                fputs(argv[i + 1], stdout);
                fputs("\n", stdout);
                args.output = fopen(argv[i + 1], "w");
                if (args.output == NULL) {
                    perror("Error opening output file");
                    exit(EXIT_FAILURE);
                }
                i++;
            } else {
                fputs("Error: --output option requires a file path.\n", stderr);
                exit(EXIT_FAILURE);
            }
        } else if (strcmp(argv[i], "--input") == 0 || strcmp(argv[i], "-i") == 0) {
            if (i + 1 < argc) {
                args.input = fopen(argv[i + 1], "r");
                if (args.input == NULL) {
                    perror("Error opening input file");
                    exit(EXIT_FAILURE);
                }
                i++;
            } else {
                fputs("Error: --input option requires a file path.\n", stderr);
                exit(EXIT_FAILURE);
            }
        } else if (strcmp(argv[i], "--compress") == 0 || strcmp(argv[i], "-c") == 0) {
            args.compress = 1;
        } else {
            fprintf(stderr, "Unknown option: %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
    }

    if (args.input == NULL) {
        fputs("Error: input file is required.\n", stderr);
        exit(EXIT_FAILURE);
    }

    if (args.output == NULL) {
        fputs("Error: output file is required.\n", stderr);
        exit(EXIT_FAILURE);
    }

    return args;
}

