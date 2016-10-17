// Playlist in C

#include <stdio.h>
#include <stdlib.h>
#include "playlist.h" 

// Functions
// =====================================================
// init_playlist
// initializes the playlist
playlist* init_playlist(playlist *pl) {
  int i;
  for (i = 0; i < 26; i++) {
    pl->library[i] = (node *)malloc(sizeof(node));
  }
  return pl;
}

// print_playlist 
// prints out all songs in collection alphabetical order
void print_playlist(playlist *pl) {
  int i;
  for (i = 0; i < 26; i++) {
    printf("%c: ", (char)(i+65));
    print_list(pl->library[i]);
  }
}

// clear_playlist
// clear all songs but don't delete the playlist
void clear_playlist(playlist *pl) {
  int i;
  for (i = 0; i < 26; i++) {
    clear_list(pl->library[i]);
  }
}
