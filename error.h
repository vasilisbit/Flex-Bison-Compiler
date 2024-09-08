// error.h
#ifndef ERROR_H
#define ERROR_H

#ifdef __cplusplus
extern "C" {
#endif

struct error {
    int line;
    char *message;
    char *token;
};

extern struct error errorTable[5000];
extern int errorCount;

void addError(int line, const char *message, const char *token);

#ifdef __cplusplus
}
#endif

#endif // ERROR_H