// Headers for linked.c

// Node Struct

typedef struct node node;

// Headers 
void print_list(node *n);
void clear_list(node *n);
node* insert_front(char Name[], char Artist[], node *n);
node* insert_alpha(char Name[], char Artist[], node *n);
node* free_list(node *n);
