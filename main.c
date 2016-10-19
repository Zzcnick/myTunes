// Main File for myTunes

#include <stdio.h>
#include <stdlib.h>

//#include "linked.h"
#include "playlist.h"

// Testing
// =========================================================

int main() {
  // Seeding for Randomness
  srand(time(NULL));

  // LINKED LIST TESTING
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
  print_list(alt = remove_index(alt, 0));
  printf("\nRemoving song 3...\n");
  print_list(alt = remove_index(alt, 3));
  printf("\nRemoving song 100... not!\n");
  print_list(alt = remove_index(alt, 100));
  
  // Removing Song by Name
  printf("\nRemoving 'Dark' and 'Cutie'...\n");
  print_list(alt = remove_song(alt, "Dark", "Cutie"));
  printf("\nRemoving 'Syrup' and 'Young'...\n");
  print_list(alt = remove_song(alt, "Syrup", "Young"));
  printf("\nRemoving 'Woulda' and 'Thought'...\n");
  print_list(alt = remove_song(alt, "Woulda", "Thought"));

  // Freeing the List - Verified with valgrind
  free_list(alt);
  //  print_playlist(Alt); // Should be fine

  // PLAYLIST TESTING
  // Create Library
  playlist* Alt = init_playlist();
  printf("\nPrinting initial playlist...\n");
  print_playlist(Alt);

  // Populating Playlist
  printf("\nAdding songs...\n");
  playlist_add_song(Alt, "Cough Syrup", "Young The Giant");
  playlist_add_song(Alt, "Mind Over Matter", "Young The Giant");
  playlist_add_song(Alt, "Take A Walk", "Passion Pit");
  playlist_add_song(Alt, "No Room In Frame", "Death Cab For Cutie");
  playlist_add_song(Alt, "I'll Follow You Into The Dark", "Death Cab For Cutie");
  playlist_add_song(Alt, "Ready Or Not", "Puggy");
  playlist_add_song(Alt, "Girl", "Jukebox The Ghost");
  playlist_add_song(Alt, "Hotel California", "Eagles");
  playlist_add_song(Alt, "Such Great Heights", "The Postal Service");
  playlist_add_song(Alt, "Simple Song", "The Shins");
  print_playlist(Alt);

  printf("\nAll songs:\n");
  print_list(Alt->all);

  // Finding Songs by Artist or Title
  printf("\nArtist Query: Giant\n");
  print_node(search_artist(Alt, "Giant"));
  printf("\nArtist Query: Cutie\n");
  print_node(search_artist(Alt, "Cutie"));
  printf("\nSong Query: Room\n");
  print_node(search_song(Alt, "Room"));
  printf("\nSong Query: Song\n");
  print_node(search_song(Alt, "Song"));

  // Looking For Songs - By Letter and Artist
  printf("\nLooking for D and Z...");
  print_all_letter(Alt, 'D');
  print_all_letter(Alt, 'Z');
  printf("\nLooking for Young and Chacha...\n");
  print_all_artist(Alt, "Young");
  print_all_artist(Alt, "Chacha");

  // Removing Songs
  print_playlist(Alt);

  printf("\nRemoving 'Ready' and 'Puggy'...\n");
  playlist_remove_song(Alt, "Ready", "Puggy");
  print_playlist(Alt); 

  printf("\nRemoving 'Hotel' and 'Eagles'...\n");
  playlist_remove_song(Alt, "Hotel", "Eagles");
  print_playlist(Alt);

  printf("\nRemoving 'Woulda' and 'Thought'...\n");
  playlist_remove_song(Alt, "Woulda", "Thought");
  print_playlist(Alt);

  printf("\nDeleting playlist...\nDone\n");

  delete_playlist(Alt); 
/*===============================================================  
  ===============================================================*/
  return 0;  
}
