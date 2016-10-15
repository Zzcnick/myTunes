// Main File for myTunes

#include <stdio.h>
#include <stdlib.h>

#include "linked.h"

// Testing
// =========================================================

int main() {
  // Starting The List
  node *alt = insert_front(NULL, "Cough Syrup", "Young The Giant");
  alt = insert_alpha(alt, "Take A Walk", "Passion Pit");
  alt = insert_alpha(alt, "No Room In Frame", "Death Cab For Cutie");
  alt = insert_alpha(alt, "Cleanse Song", "Bright Eyes");

  // Song List
  printf("Some Alternative Music:\n");
  print_list(alt);

  // Song Search
  printf("\nQuery: Room\n");
  print_node(find_song(alt, "Room"));
  printf("\nQuery: Song\n");
  print_node(find_song(alt, "Song"));
  printf("\nQuery: Huzzah\n");
  print_node(find_song(alt, "Huzzah"));
		
  // Create Library


  /*
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
  */
  return 0;
}
