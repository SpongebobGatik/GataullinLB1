#ifndef MASSIVE_H
#define MASSIVE_H

typedef struct {
    char** array;
    size_t size;
} StringArray;

StringArray* initStringArray();

void addString(StringArray* sa, int index, const char* value);

void appendString(StringArray* sa, const char* value);

int containsString(StringArray* sa, const char* value);

void replaceString(StringArray* sa, int index, const char* value);

void removeString(StringArray* sa, int index);

void printString(StringArray* sa, int index);

void compareStrings(StringArray* sa, int index1, int index2);

void printStringArray(StringArray* sa);

void freeStringArray(StringArray* sa);

#endif
