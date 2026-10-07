#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct Array {
  int *data;
  size_t length;
  size_t capacity;
};

void append(struct Array *arr, int value) {

  if (arr->capacity > arr->length) {
    arr->data[arr->length] = value;
    arr->length++;
    return;
  }

  if (arr->capacity == 0) {
    arr->capacity = 1;
  }

  int new_capacity = arr->capacity * 2;
  
  int *ptr = realloc(arr->data, new_capacity * sizeof(int));
  
  if (ptr == NULL) {
    printf("Re-allocation failed!");
    return;
  }
  
  arr->capacity = new_capacity;
  arr->data = ptr;
  arr->data[arr->length] = value;
  arr->length++;
  
}

void clean(struct Array *arr) {

  if (arr->capacity <= arr->length) {
    printf("Capacity can't be smaller than length!");
    return;
  }

  int clean_size = arr->length + 1;
  int *ptr = arr->data;
  ptr = realloc(arr->data, clean_size * sizeof(int));

  if (ptr == NULL) {
    printf("ERROR: re-allocation failed!");
    return;
  }

  arr->data = ptr;
  arr->capacity = clean_size;
  
}

int main() {
  int my_data[] = {1, 6, 8, 9, 10, 15, 12};
  int n = sizeof(my_data) / sizeof(*my_data);

  struct Array my_array = {
    .data = malloc(n * sizeof(int)),
    .length = n,
    .capacity = n
  };

  for (int i = 0; i < n; i++) {
    *(my_array.data + i) = my_data[i];
  }

  append(&my_array, 6);

  printf("%d", my_array.data[my_array.length - 1]);
  free(my_array.data);
  my_array.data = NULL;

  return 0;
}

