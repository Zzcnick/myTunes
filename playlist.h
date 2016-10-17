// Headers for playlist.c

#include "linked.h"

// Playlist Struct

struct playlist {
  node *library[26]; // Alphabetical
};
typedef struct playlist playlist;

// Headers
playlist* init_playlist(playlist *pl);
void print_playlist(playlist *pl);
void clear_playlist(playlist *pl);
