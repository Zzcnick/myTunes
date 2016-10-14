// Linked List in C

# include <stdio.h>
# include <stdlib.h>

# include "linked.h"

struct node {
  double v;
  struct node *child;
};

// Functions
// =========================================================
// print_list
// prints all values of the linked list
void print_list(node *n) {
  printf("%f", n->v);
  if (n->child) {
    printf(" >> ");
    print_list(n->child);
  } else {
    printf("\n");
  }
}

// clear_list
// resets all values in the list to 0
void clear_list(node *n) {
  if (n->child) {
    n->v = 0;
    clear_list(n->child);
  }
}

// insert_front
// takes a double d and a node *n, and adds another node with value d to *n
node* insert_front(double d, node *n) {
  node *parent = (node *)malloc(sizeof(node));
  parent->v = d;
  parent->child = n;
  return parent;
}

// free_list
// frees all the memory from a linked list and returns a pointer to the beginning
node* free_list(node *n) {
  if (n->child)
    free_list(n->child);
  free(n);
  return n;
}

// Testing
// =========================================================

int main() {

  // Starting A Linked List
  node *Foo = (node *)malloc(sizeof(node));
  Foo->child = 0; Foo->v = 0;
  printf("Foo: ");
  print_list(Foo);

  // Adding Values
  printf("Adding values 1, 2, 4, 8, 16, 32, 64 to front of list...\n");

  int i;
  for (i = 1; i < 128; i = i * 2)
    Foo = insert_front(i, Foo);

  printf("Foo: ");
  print_list(Foo);

  // Clearing Values
  printf("Clearing the list...\n");
  clear_list(Foo);

  printf("Foo: ");
  print_list(Foo);

  // Freeing Memory
  printf("Freeing memory...\n");
  free_list(Foo);

  // Is there actually any way to test this?

  return 0;
}
