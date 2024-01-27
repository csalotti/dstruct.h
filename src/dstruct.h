#ifndef LIST_OPS_H
#define LIST_OPS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macros
#define ds_alloc(type) ((type *)malloc(sizeof(type)))
// Generic pointer for easier use
typedef void *pointer;

// Linked List
typedef struct Node {
  pointer value;
  struct Node *next;

} Node;

typedef struct {
  size_t size;
  size_t element_size;
  Node *head;
} Llist;

Node *Node_init(pointer value, size_t elem_size);
Llist *Llist_init(size_t element_size);
bool Llist_append(Llist *llist, pointer value);
bool Llist_push(Llist *llist, pointer value);
bool Llist_insert(Llist *llist, pointer value, size_t index);
bool LList_remove(Llist *llist, size_t index);
pointer LList_pop(Llist *llist);

#endif
