// Headers for linked.c

// Node Struct

typedef struct node node;

// Headers 
void print_list(node *n);
void clear_list(node *n); // Not required, but surely this will be useful!
node* insert_front(double d, node *n);
node* free_list(node *n);
