#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

enum DyaStatus dyaAppend(struct DyaArray *arr, int value) {
  
  if (arr == NULL) {
    return DYA_ARRAY_INVALID_STATE;
  }
  
  if (arr->capacity > arr->length) {
    arr->data[arr->length] = value;
    arr->length++;
    return DYA_ARRAY_OK;
  }

  if (arr->capacity == 0) {
    arr->capacity = 1;
  }

  size_t new_capacity = arr->capacity * 2;
  
  int *ptr = realloc(arr->data, new_capacity * sizeof(int));
  
  if (ptr == NULL) {
    return DYA_ARRAY_ALLOC_FAILURE;
  }
  
  arr->capacity = new_capacity;
  arr->data = ptr;
  arr->data[arr->length] = value;
  arr->length++;

  return DYA_ARRAY_OK;
}
