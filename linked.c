// Linked List in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked.h"

struct node {
  char title[128];
  char artist[128];
  struct node *child;
};

// Functions
// =========================================================
// print_node
// prints out details of a node
void print_node(node *n) {
  if (n)
    printf("Title: %s\nArtist: %s\n", n->title, n->artist);
  else
    printf("<No Such Song>\n");
}

// print_list
// prints all values of the linked list
void print_list(node *n) {
  printf("\"%s\" by %s", n->title, n->artist);
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
    strcpy(n->title, "");
    strcpy(n->artist, "");
    clear_list(n->child);
  }
}

// insert_front
// takes a song node and inserts it to the front of the list and returns it
node* insert_front(node *n, char Title[], char Artist[]) {
  node *parent = (node *)malloc(sizeof(node));
  strcpy(parent->title, Title);
  strcpy(parent->artist, Artist);
  parent->child = n;
  return parent;
}

// insert_alpha
// inserts a song node at the correct location in alphabetical order and returns the front node
node* insert_alpha(node *n, char Title[], char Artist[]) {
  if (strcmp(Title, n->title) < 0)
    return insert_front(n, Title, Artist);
  node *ret = n;
  while (n->child)
    if (strcmp(Title, n->child->title) > 0)
      n = n->child;
    else
      break;
  node *ordered = insert_front(n->child, Title, Artist);
  n->child = ordered;
  return ret;
}

// find_song
// Takes a song name and returns first song with the name, null otherwise
node* find_song(node *n, char Title[]) {
  while (n) {
    if (strstr(n->title, Title))
      break;
    n = n->child;
  }
  return n;
}

// find_song
// Takes an artist name and returns first song by the artist, null otherwise
node* find_artist(node *n, char Artist[]) {
  while (n) {
    if (strstr(n->artist, Artist))
      break;
    n = n->child;
  }
  return n;
}

// free_list
// frees all the memory from a linked list and returns a pointer to the beginning
node* free_list(node *n) {
  if (n->child)
    free_list(n->child);
  free(n);
  return n;
}
