// Playlist in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h" 

// Functions
// =====================================================
// init_playlist
// initializes the playlist
playlist* init_playlist() {
  return (playlist *)calloc(1,sizeof(playlist));
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

// print_all_letter
// takes a letter input and prints out all songs in the letter
void print_all_letter(playlist *pl, char c) {
  int index = (c - 65) % 26;
  printf("%c: ", index + 65);
  print_list(pl->library[index]);
}

// print_all_artist
void print_all_artist(playlist *pl, char Artist[]) {
  node *tmp;
  tmp = pl->all;
  while (tmp) {
    if (strstr(tmp->artist, Artist))
      print_node(tmp);
    tmp = tmp->child;
  }
}

// playlist_add_song
// adds a song into the playlist alphabetically
void playlist_add_song(playlist *pl, char Title[], char Artist[]) {
  int index = (*Artist - 65) % 26;
  pl->library[index] = insert_alpha(pl->library[index], Title, Artist);
  pl->all = insert_alpha(pl->all, Title, Artist);
}

// playlist_remove_song
// removes a song from playlist that matches a given title and artist, if it exists
node* playlist_remove_song(playlist *pl, char Title[], char Artist[]) {
  int l_initial = listlen(pl->all);
  node* ret = remove_song(pl->all, Title, Artist);
  int l_final = listlen(pl->all);
  // Removing from library if removed from all songs
  if (l_initial - l_final) {
    pl->all = ret;
    int i = 0;
    for (i; i < 26; i++) {
      l_initial = listlen(pl->library[i]);
      ret = remove_song(pl->library[i], Title, Artist);
      l_final = listlen(pl->library[i]);
      if (!l_final) {
	free(pl->library[i]);
	pl->library[i] = (node *)calloc(1,sizeof(node));
	break;
      } else if (l_initial - l_final) {
	pl->library[i] = ret;
	break;
      }
    }
  }
  return ret;
}

// search_song
// returns first song alphabetically with a certain title in the playlist
node* search_song(playlist *pl, char Title[]) {
  return find_song(pl->all, Title);
}

// search_artist
// returns first song by the artist in the playlist
node* search_artist(playlist *pl, char Artist[]) {
  return find_artist(pl->all, Artist);
}

// shuffle
// returns a random playlist from a given playlist
node* shuffle(playlist *pl) {
  node* raw = pl->all;
  int l = listlen(raw);
  unsigned int order[l];
  int i; 
  for (i = 0; i < l; i++)
    order[i] = i;
  for (i = 0; i < l; i++) {
    int seed = rand()%l;
    int store = order[i];
    order[i] = order[seed];
    order[seed] = store;
    // printf("order[i] = %d\t order[seed] = %d\n", order[i], order[seed]);
  }
  //  for (i = 0; i < l; i++) {
  //    printf("order[%d] = %d\n", i, order[i]);
  //  }
  node* ret = insert_front(NULL, 
			   get_song(raw,order[0])->title,
			   get_song(raw,order[0])->artist);
  for (i = 1; i < l; i++) 
    ret = insert_front(ret, 
		       get_song(raw,order[i])->title,
		       get_song(raw,order[i])->artist);
  return ret;
}
void swap(int *i1, int *i2) {
  *i1 = *i1 ^ *i2;
  *i2 = *i1 ^ *i2;
  *i1 = *i1 ^ *i2;
}

// delete_playlist
// destroys the playlist nice and good
void delete_playlist(playlist *pl) {
  int i = 0;
  for (i; i<26; i++) {
    if (pl->library[i])
      free_list(pl->library[i]);
    else
      free(pl->library[i]);
  }
  free(pl->all);
  free(pl);
}

