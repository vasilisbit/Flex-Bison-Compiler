// error.cpp
#include "error.h"
#include <cstring>
#include <cstdlib>
#include <cstdio>

struct error errorTable[5000];
int errorCount = 0;

void addError(int line, const char *message, const char *token) {
    // Check if the same error already exists
    for (int i = 0; i < errorCount; i++) {
        if (errorTable[i].line == line && strcmp(errorTable[i].message, message) == 0 && strcmp(errorTable[i].token, token) == 0) {
            return; // Error already exists, do not add it again
        }
    }

    if (errorCount < 5000) {
        errorTable[errorCount].line = line;
        errorTable[errorCount].message = strdup(message);
        errorTable[errorCount].token = strdup(token);
        errorCount++;
    } else {
        fprintf(stderr, "Error:\n\nToo many errors\n");
        exit(1);
    }
}