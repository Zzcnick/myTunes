// Headers for linked.c

// Node Struct

typedef struct node node;

// Headers 
void print_node(node *n);
void print_list(node *n);
void clear_list(node *n);
node* insert_front(node *n, char Title[], char Artist[]);
node* insert_alpha(node *n, char Title[], char Artist[]);
node* find_song(node *n, char Title[]);
node* find_artist(node *n, char Artist[]);
node* free_list(node *n);
