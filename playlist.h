// Headers for playlist.c

#include "linked.h"

// Playlist Struct

struct playlist {
  node *library[26]; // Alphabetical
  node *all; // List of all songs
};
typedef struct playlist playlist;

// Headers
playlist* init_playlist();
void print_playlist(playlist *pl);
void print_all_letter(playlist *pl, char c);
void print_all_artist(playlist *pl, char Artist[]);
void playlist_add_song(playlist *pl, char Title[], char Artist[]);
node* playlist_remove_song(playlist *pl, char Title[], char Artist[]);
node* search_song(playlist *pl, char Title[]);
node* search_artist(playlist *pl, char Artist[]);
void delete_playlist(playlist *pl);

