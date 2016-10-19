// Headers for linked.c

// Node Struct

struct node {
  char title[128];
  char artist[128];
  struct node *child;
};

typedef struct node node;

// Headers 
void print_node(node *n);
void print_list(node *n);
void clear_list(node *n);
int listlen(node *n);
node* insert_front(node *n, char Title[], char Artist[]);
node* insert_alpha(node *n, char Title[], char Artist[]);
node* find_song(node *n, char Title[]);
node* find_artist(node *n, char Artist[]);
node* free_list(node *n);
node* get_random_song(node *n);
node* remove_index(node *n, int index);
node* remove_song(node *n, char Title[], char Artist[]);
