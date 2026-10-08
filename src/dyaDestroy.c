#include <stdlib.h>
#include <stdint.h>
#include "dynamic_array.h"

// OBLITERATE existing pointer, not to confuse with dyaShrinkSlots
enum DyaStatus dyaDestroy(struct DyaArray *arr) {

  if (arr == NULL) {
    return DYA_ARRAY_INVALID_ARGUMENT;
  }
  
  free(arr->data);
  arr->data = NULL;
  arr->length = 0;
  arr->capacity = 0;

  return DYA_ARRAY_OK;
  
}
