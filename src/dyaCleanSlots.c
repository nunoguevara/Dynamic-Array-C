#include <stdint.h>
#include <stdlib.h>
#include "dynamic_array.h"

// Reallocate the array
// It reduces unused allocated capacity
enum DyaStatus dyaCleanSlots(struct DyaArray *arr) {
  
  if (arr == NULL) {
    return DYA_ARRAY_INVALID_ARGUMENT;
  }

  if (arr->length > arr->capacity) {
    return DYA_ARRAY_INVALID_STATE;
  }
  
  if (arr->capacity <= arr->length) {     
    return DYA_ARRAY_NOTHING_TO_CLEAN;  
  }

  if (arr->length >= SIZE_MAX) {
    return DYA_ARRAY_OVERFLOW;
  }
  //Leave a slot to spare (intentional)
  size_t clean_size = arr->length + 1;

  if (clean_size > SIZE_MAX / sizeof(int)) {
    return DYA_ARRAY_OVERFLOW;
  }
  
  int *ptr = realloc(arr->data, clean_size * sizeof(int));

  if (ptr == NULL) {
    return DYA_ARRAY_ALLOC_FAILURE;
  }

  arr->data = ptr;
  arr->capacity = clean_size;

  return DYA_ARRAY_OK;
}
