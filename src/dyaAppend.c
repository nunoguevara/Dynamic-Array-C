#include <stdlib.h>
#include <stdint.h>
#include "dynamic_array.h"

enum DyaStatus dyaAppend(struct DyaArray *arr, int value) {
  
  if (arr == NULL) {
    return DYA_ARRAY_INVALID_ARGUMENT;
  }

  if (arr->length > arr->capacity) {
    return DYA_ARRAY_INVALID_STATE;
  }

  if (arr->data == NULL && arr->capacity > 0) {
    return DYA_ARRAY_INVALID_STATE;
  }

  if (arr->data != NULL && arr->capacity == 0) {
    return DYA_ARRAY_INVALID_STATE;
  }
  
  if (arr->capacity > arr->length) {
    arr->data[arr->length] = value;
    arr->length++;
    return DYA_ARRAY_OK;
  }

  size_t new_capacity;
  
  if (arr->capacity == 0) {
    new_capacity = 1;
  }

  if (arr->capacity > SIZE_MAX / 2) {
    return DYA_ARRAY_OVERFLOW;
  }

  if (arr->capacity != 0) {
    new_capacity = arr->capacity * 2;
  }

  if (new_capacity > SIZE_MAX / sizeof(int)) {
    return DYA_ARRAY_OVERFLOW;
  }
  
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
