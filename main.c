// Main File for myTunes

#include <stdio.h>
#include <stdlib.h>

#include "linked.h"

// Testing
// =========================================================

int main() {
  // Seeding for Randomness
  srand(time(NULL));

  // Starting The List
  node *alt = insert_front(NULL, "Cough Syrup", "Young The Giant");
  alt = insert_alpha(alt, "Take A Walk", "Passion Pit");
  alt = insert_alpha(alt, "No Room In Frame", "Death Cab For Cutie");
  alt = insert_alpha(alt, "Cleanse Song", "Bright Eyes");
  alt = insert_alpha(alt, "I'll Follow You Into The Dark", "Death Cab For Cutie");
  alt = insert_alpha(alt, "Ready Or Not", "Puggy");

  // Song List
  printf("Some Alternative Music:\n");
  print_list(alt);

  // Song Search
  printf("\nSong Query: Room\n");
  print_node(find_song(alt, "Room"));
  printf("\nSong Query: Song\n");
  print_node(find_song(alt, "Song"));
  printf("\nSong Query: Huzzah\n");
  print_node(find_song(alt, "Huzzah"));

  // Artist Search
  printf("\nArtist Query: Giant\n");
  print_node(find_artist(alt, "Giant"));
  printf("\nArtist Query: Cutie\n");
  print_node(find_artist(alt, "Cutie"));
  printf("\nArtist Query: Shins\n");
  print_node(find_artist(alt, "Shins"));	
  
  // Random Song
  int i = 0;
  for (; i < 3; i++) {
    printf("\nHave a random song!\n");
    print_node(get_random_song(alt));
  }

  // Removing Song by Index
  printf("\nRemoving song 0...\n");
  print_list(alt = remove_song(alt, 0));
  printf("\nRemoving song 3...\n");
  print_list(alt = remove_song(alt, 3));
  printf("\nRemoving song 100... not!\n");
  print_list(alt = remove_song(alt, 100));

  // Freeing the List - Verified with valgrind
  free_list(alt);

  // Create Library
  
  return 0;
}
