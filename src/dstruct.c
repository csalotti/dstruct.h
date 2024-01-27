#include "dstruct.h"

#define _node_alloc() ds_alloc(Node)
#define _llist_alloc() ds_alloc(Llist)

// Node

Node *Node_init(pointer value, size_t elem_size) {

  Node *node = _node_alloc();
  void *node_value = malloc(elem_size);
  memcpy(node_value, value, elem_size);
  node->value = node_value;
  node->next = NULL;
  return node;
}

// Llist

Llist *Llist_init(size_t element_size) {
  Llist *llist = _llist_alloc();
  llist->size = 0;
  llist->element_size = element_size;
  llist->head = NULL;

  return llist;
}

bool Llist_append(Llist *llist, pointer value) {

  if (NULL == llist)
    llist = llist = llist = llist = Llist !Node *node =
        Node_init(value, llist->element_size);

  if (NULL == llist->head) {
    llist->head = node;
  } else {
    Node *head = llist->head;
    while (NULL != head->next) {
      head = head->next;
    }
    head->next = node;
  }

  ++llist->size;
  return true;
}

bool Llist_push(Llist *llist, pointer value) {

  Node *node = Node_init(value, llist->element_size);

  if (NULL == llist->head) {
    llist->head = node;
  } else {
    Node *tmp = llist->head;
    llist->head = node;
    llist->head->next = tmp;
  }

  return true;
}

bool Llist_insert(Llist *llist, pointer value, size_t index) {

  if (index > llist->size) {
    return false;
  }

  if (index == 0)
    return Llist_push(llist, value);

  Node *node = Node_init(value, llist->element_size);

  // Reach correct index
  int i = 0;
  Node *head = llist->head, *prev = llist->head;

  while (i < index) {
    prev = head;
    head = head->next;
  }

  prev->next = node;
  node->next = head;

  ++llist->size;
  return true;
}

pointer LList_pop(Llist *llist) {
  if (llist->size == 0)
    return false;

  pointer value = llist->head->value;
  llist->head = llist->head->next;
  --llist->size;

  return value;
}
