// Playlist in C

#include <stdio.h>
#include <stdlib.h>
#include "playlist.h" 
#include "linked.h"

struct playlist {
  node library[26]; // Alphabetical
};

// Functions
// =====================================================
// print_playlist 
// prints out all songs in collection alphabetical order
void print_playlist(playlist pl) {
  int i;
  for (i = 0; i < 26; i++) {
    printf("Chacha: ");
    print_list(&(pl.library[i]));
  }
}
