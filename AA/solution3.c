#include "stdio.h"
#include "stdlib.h"

int N_MAX_NODES = 20;
int N_FIELDS = 4;

struct Node{
    int key;
    int child;
    int sibling;
    int parent;
};

typedef struct Node Node;

struct Tree{
    Node* nodes;
    int max_number_nodes;
    int root_index;
};

typedef struct Tree Tree;

enum USEFUL{EMPTY=-1};

void tree_init(Tree* tree, int max_nodes)
{
    tree->max_number_nodes = max_nodes;
    tree->nodes = (Node*)malloc(tree->max_number_nodes * sizeof(Node));
    tree->root_index = -1;
    for(int i = 0; i < tree->max_number_nodes; ++i)
    {
        tree->nodes[i].key = EMPTY;
        tree->nodes[i].child = EMPTY;
        tree->nodes[i].sibling = EMPTY;
        tree->nodes[i].parent = EMPTY;
    }
}

void print(Tree tree)
{
    printf("\n---PRINTING TREE---\n");
    printf("Tree has %d nodes\n", tree.max_number_nodes);
    printf("Tree root index: %d\n", tree.root_index);
    printf("Tree table:\n");
    for(int i = 0; i < tree.max_number_nodes; ++i)
    {
        printf("%d, %d, %d, %d\n", tree.nodes[i].key, tree.nodes[i].child, tree.nodes[i].sibling, tree.nodes[i].parent);
    }
    printf("---     END     ---\n");
}

// set the line corresponding to 'node_index' in the table to -1
void empty_table_line(Tree tree, int node_index)
{
    tree.nodes[node_index].key = EMPTY;
    tree.nodes[node_index].child = EMPTY;
    tree.nodes[node_index].sibling = EMPTY;
    tree.nodes[node_index].parent = EMPTY;
}

// is the tree empty?
int is_empty(Tree tree)
{
    return tree.root_index == -1;
}

// does a node have a sibling?
int has_sibling(Tree tree, int node_index)
{
    return tree.nodes[node_index].sibling != EMPTY;
}

// does a node have a child?
int has_child(Tree tree, int node_index)
{
    return tree.nodes[node_index].child != EMPTY;
}

// return the table index of the node with the specified key
int find_node(Tree tree, int key)
{
    for(int i = 0; i < tree.max_number_nodes; ++i)
        if(tree.nodes[i].key == key)
            return i;
    return EMPTY;
}

// find the next empty table row
int next_empty_index(Tree tree)
{
    return find_node(tree, EMPTY);
}

// add a node to the table
int add_node(Tree tree, int key, int child, int sibling, int parent)
{
    int current_node_index = next_empty_index(tree);
    if(current_node_index < 0)
        return -1;
    if(is_empty(tree))
    {
        tree.root_index = current_node_index;
    }

    tree.nodes[current_node_index].key = key;
    tree.nodes[current_node_index].child = child;
    tree.nodes[current_node_index].sibling = sibling;
    tree.nodes[current_node_index].parent = parent;
    return current_node_index;
}

// add a child (as the first child) to a specific node
void add_child(Tree tree, int key, int parent_node_index)
{
    int current_node_index = add_node(tree, key, EMPTY, tree.nodes[parent_node_index].child, parent_node_index);
    tree.nodes[parent_node_index].child = current_node_index;
}

void read_tree(Tree* tree)
{
    int n_nodes;
    scanf("%d", &n_nodes);
    tree_init(tree, n_nodes);
    for(int i = 0; i < n_nodes; ++i)
    {
        int chr;
        scanf("%d", &(tree->nodes[i].key));
        scanf("%d", &(tree->nodes[i].child));
        scanf("%d", &(tree->nodes[i].sibling));
        scanf("%d", &(tree->nodes[i].parent));
    }
    tree->root_index = 0;
}

// TODO 1
// traverse a tree in pre-order
// recursive implementation!
void traverse_preorder(Tree tree, int current_node_index)
{
    if (current_node_index == EMPTY)
        return;
    if (has_child(tree, current_node_index))
        traverse_preorder(tree, tree.nodes[current_node_index].child);

    printf("%d -> ", tree.nodes[current_node_index].key);

    if (has_sibling(tree, current_node_index))
        traverse_preorder(tree, tree.nodes[current_node_index].sibling);
}

// TODO 2
// traverse a tree in post-order
// recursive implementation!
void traverse_postorder(Tree tree, int current_node_index)
{
   if (current_node_index == EMPTY)
        return;

    if (has_child(tree, current_node_index))
        traverse_postorder(tree, tree.nodes[current_node_index].child);

    if (has_sibling(tree, current_node_index))
        traverse_postorder(tree, tree.nodes[current_node_index].sibling);

    printf("%d -> ", tree.nodes[current_node_index].key);

}

// TODO 3
// recursive helper function
// this function will remove the current node and ALL its child nodes recursively from the table
void delete_recursive(Tree tree, int node_index)
{
    if (node_index == EMPTY)
        return;
    if (has_child(tree, node_index)) 
        delete_recursive(tree, tree.nodes[node_index].child);
    
    int current_child = tree.nodes[tree.nodes[node_index].parent].child;
    int previous_child = EMPTY;

    while (current_child != node_index && current_child != EMPTY) {
        previous_child = current_child;
        current_child = tree.nodes[current_child].sibling;
    }
    if (previous_child != EMPTY) 
        tree.nodes[previous_child].sibling = tree.nodes[node_index].sibling;
    else 
        tree.nodes[tree.nodes[node_index].parent].child = tree.nodes[node_index].sibling;

    empty_table_line(tree, node_index);
}

// TODO 4
// Find the sibling BEFORE the current node
int find_left_sibling(Tree tree, int node_index)
{
     if(node_index==EMPTY)
    return;
    // get parent and verify not empty
    int parent_index = tree.nodes[node_index].parent;
    if (parent_index == EMPTY) 
        return EMPTY; 

    int current_child = tree.nodes[tree.nodes[node_index].parent].child;
    int previous_sibling = EMPTY;

    // get first child of parent
    while (current_child != node_index && current_child != EMPTY) {
        previous_sibling = current_child;
        current_child = tree.nodes[current_child].sibling;
    }

    // iterate
    return previous_sibling;
}

// TODO 5
// Delete a node together with all its child nodes and readjust the tree structure. 
// Make sure to use already implemented functions for this.
void delete_node(Tree tree, int node_index)
{
    // 1 delete children
    delete_recursive(tree, tree.nodes[node_index].child);
    // 2 if the node to be deleted is first child then ...
    if (tree.nodes[tree.nodes[node_index].parent].child == node_index)
        tree.nodes[tree.nodes[node_index].parent].child = tree.nodes[node_index].sibling;
    else{
        // 3 adapt left sibling
        int left_sibling = find_left_sibling(tree, node_index);
        if (left_sibling != EMPTY) {
            tree.nodes[left_sibling].sibling = tree.nodes[node_index].sibling;
        }
    }
    // 4 remove node
     empty_table_line(tree, node_index);
    // 5 adapt root index
     if (tree.root_index == node_index)
        tree.root_index = EMPTY;
}


int main()
{
    Tree tree;
    read_tree(&tree);
    int function_to_execute;
    printf("\n++++++RESULT++++++\n");

    scanf("%d", &function_to_execute);
    while(function_to_execute != 0)
    {
        switch(function_to_execute){
            int argument;
            int a1, a2, a3, a4;
            case 1:
                scanf("%d", &argument);
                printf("%d\n", has_sibling(tree, argument));
                break;
            case 2:
                scanf("%d", &argument);
                printf("%d\n", has_child(tree, argument));
                break;
            case 3:
                scanf("%d", &argument);
                printf("%d\n", find_node(tree, argument));
                break;
            case 4:
                scanf("%d", &argument);
                empty_table_line(tree, argument);
                break;
            case 5:
                printf("%d\n", next_empty_index(tree));
                break;
            case 6:
                scanf("%d", &a1);
                scanf("%d", &a2);
                scanf("%d", &a3);
                scanf("%d", &a4);
                add_node(tree, a1, a2, a3, a4);
                break;
            case 7:
                print(tree);
                break;
            case 8:
                scanf("%d", &a1);
                scanf("%d", &a2);
                add_child(tree, a1, a2);
                break;
            case 9:
                traverse_preorder(tree, tree.root_index);
                break;
            case 10:
                traverse_postorder(tree, tree.root_index);
                break;
            case 11:
                scanf("%d", &a1);
                delete_recursive(tree, a1);
                break;
            case 12:
                scanf("%d", &a1);
                printf("%d\n", find_left_sibling(tree, a1));
                break;
            case 13:
                scanf("%d", &a1);
                delete_node(tree, a1);
                break;
            default:
                break;
        }
        scanf("%d", &function_to_execute);
    }
}

/*
case= Traverse Preorder
input=6
5 1 -1 -1
6 4 2 0
7 -1 3 0
8 -1 -1 0
9 -1 5 1
10 -1 -1 1
9
0

output=
++++++RESULT++++++
9 -> 10 -> 6 -> 7 -> 8 -> 5 -> 

case= Traverse Postorder
input=6
5 1 -1 -1
6 4 2 0
7 -1 3 0
8 -1 -1 0
9 -1 5 1
10 -1 -1 1
10
0

output=
++++++RESULT++++++
5 -> 6 -> 9 -> 10 -> 7 -> 8 -> 

case= Delete Recursive 1
input=6
5 1 -1 -1
6 4 2 0
7 -1 3 0
8 -1 -1 0
9 -1 5 1
10 -1 -1 1
11 3
7
0

output=
++++++RESULT++++++

---PRINTING TREE---
Tree has 6 nodes
Tree root index: 0
Tree table:
5, 1, -1, -1
6, 4, 2, 0
7, -1, 3, 0
-1, -1, -1, -1
9, -1, 5, 1
10, -1, -1, 1
---     END     ---

case= Delete Recursive 2
input=6
5 1 -1 -1
6 4 2 0
7 -1 3 0
8 -1 -1 0
9 -1 5 1
10 -1 -1 1
11 1
7
0

output=
++++++RESULT++++++

---PRINTING TREE---
Tree has 6 nodes
Tree root index: 0
Tree table:
5, 1, -1, -1
-1, -1, -1, -1
-1, -1, -1, -1
-1, -1, -1, -1
-1, -1, -1, -1
-1, -1, -1, -1
---     END     ---

case= Find Left Sibling
input=6
5 1 -1 -1
6 4 2 0
7 -1 3 0
8 -1 -1 0
9 -1 5 1
10 -1 -1 1
12 3
0

output=
++++++RESULT++++++
2

case= Delete Node 1
input=6
5 1 -1 -1
6 4 2 0
7 -1 3 0
8 -1 -1 0
9 -1 5 1
10 -1 -1 1
13 3
10
0

output=
++++++RESULT++++++
5 -> 6 -> 9 -> 10 -> 7 -> 

case= Delete Node 2
input=6
5 1 -1 -1
6 4 2 0
7 -1 3 0
8 -1 -1 0
9 -1 5 1
10 -1 -1 1
13 1
10
0

output=
++++++RESULT++++++
5 -> 7 -> 8 ->

*/