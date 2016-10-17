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

// add_song - TO TEST
// adds a song into the playlist alphabetically
void add_song(playlist *pl, char Title[], char Artist[]) {
  int index = (*Title - 65) % 26;
  insert_alpha(pl->library[index], Title, Artist);
}

// search_song - TO TEST
// returns first song alphabetically with a certain title in the playlist
node* search_song(playlist *pl, char Title[]) {
  int i; node *n;
  for (i = 0; i < 26; i++) {
    n = find_song(pl->library[i], Title);
    if (!n)
      break;
  }
  return n;
}

// search_artist - TO TEST
// returns first song by the artist in the playlist
node* search_artist(playlist *pl, char Artist[]) {
  int i; node *n;
  for (i = 0; i < 26; i++) {
    n = find_artist(pl->library[i], Artist);
    if (!n)
      break;
  }
  return n;
}
