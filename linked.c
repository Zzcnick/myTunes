// Linked List in C

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "linked.h"

struct node {
  char name[128];
  char artist[128];
  struct node *child;
};

// Functions
// =========================================================
// print_list
// prints all values of the linked list
void print_list(node *n) {
  printf("\"%s\" by %s", n->name, n->artist);
  if (n->child) {
    printf(" >> ");
    print_list(n->child);
  } else {
    printf("\n");
  }
}

// clear_list
// resets all values in the list to ""
void clear_list(node *n) {
  if (n->child) {
    n->name = "";
    n->artist = "";
    clear_list(n->child);
  }
}

// insert_front
// takes a song node and inserts it to the front of the list
node* insert_front(char Name[], char Artist[], node *n) {
  node *parent = (node *)malloc(sizeof(node));
  parent->name = strcpy(parent->name, Name);
  parent->artist = strcpy(parent->artist, Artist);
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
