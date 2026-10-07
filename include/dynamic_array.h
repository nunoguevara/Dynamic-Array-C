#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>

enum DyaStatus {
  DYA_ARRAY_OK = 0;
  DYA_ARRAY_INVALID_ARGUMENT = -1;
  DYA_ARRAY_INVALID_STATE = -2;
  DYA_ARRAY_ALLOC_FAILURE = -3;
  DYA_ARRAY_OVERFLOW = -4;

  DYA_ARRAY_NOTHING_TO_CLEAN = -40;
}

struct DyaArray {
  int *data;
  size_t length;
  size_t capacity;
};

void append(struct Array *arr, int value);
void clean(struct Array *arr);

#endif
