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
    int n_nodes;
    int root_index;
};

typedef struct Tree Tree;

enum USEFUL{EMPTY=-1};

void tree_init(Tree* tree, int max_nodes)
{
    tree->n_nodes = max_nodes;
    tree->nodes = (Node*)malloc(tree->n_nodes * sizeof(Node));
    tree->root_index = -1;
    for(int i = 0; i < tree->n_nodes; ++i)
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
    printf("Tree has %d nodes\n", tree.n_nodes);
    printf("Tree root index: %d\n", tree.root_index);
    printf("Tree table:\n");
    for(int i = 0; i < tree.n_nodes; ++i)
    {
        printf("%d, %d, %d, %d\n", tree.nodes[i].key, tree.nodes[i].child, tree.nodes[i].sibling, tree.nodes[i].parent);
    }
    printf("---     END     ---\n");
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
}

// set the line corresponding to 'node_index' in the table to -1
void empty_table_line(Tree tree, int node_index)
{
    tree.nodes[node_index].key = EMPTY;
    tree.nodes[node_index].child = EMPTY;
    tree.nodes[node_index].sibling = EMPTY;
    tree.nodes[node_index].parent = EMPTY;
}

// TODO 1
// is the tree empty?
int is_empty(Tree tree)
{
    if(tree.n_nodes==-1)
    {
        return tree.n_nodes;
    }
}

// TODO 2
// does a node have a sibling?
int has_sibling(Tree tree, int node_index)
{
    return tree.nodes[node_index].sibling !=-1;
}

// TODO 3
// does a node have a child?
int has_child(Tree tree, int node_index)
{
    return tree.nodes[node_index].child !=-1;
}

// TODO 4
// return the table index of the node with the specified key
int find_node(Tree tree, int key)
{
    int i;
    for(i=0;i<tree.n_nodes;i++)
    {
        if(tree.nodes[i].key==key)
        return i;
    }
    return -1;
}

// TODO 5
// find the next empty table row
int next_empty_index(Tree tree)
{
    int i;
    for(i=0;i<tree.n_nodes;i++)
        if(tree.nodes[i].key==EMPTY)
            return i;

    return -1;
    
}

// TODO 6
// add a node to the table
int add_node(Tree tree, int key, int child, int sibling, int parent)
{
    int empty;
    empty=next_empty_index(tree);
    if(empty!=-1)
    {
        tree.nodes[empty].key = key;
        tree.nodes[empty].child = child;
        tree.nodes[empty].sibling = sibling;
        tree.nodes[empty].parent = parent;
        return 1;
    }
    return 0;

}

// TODO 7
// add a child (as the first child) to a specific node
void add_child(Tree tree, int key, int parent_node_index)
{
    int empty;
    empty=next_empty_index(tree);
    if(empty!=-1)
    {
        tree.nodes[empty].key=key;
        tree.nodes[empty].child = -1;
        tree.nodes[empty].sibling =tree.nodes[parent_node_index].child;
        tree.nodes[empty].parent = parent_node_index;
    }
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
            default:
                break;
        }
        scanf("%d", &function_to_execute);
    }
}

/*
case= Has Child
input=
6
5 1 -1 -1
6 4 2 0
7 -1 3 0
8 -1 -1 0
9 -1 5 1
10 -1 -1 1
2 1
2 4
0

output=
++++++RESULT++++++
1
0

case= Has Sibling
input=
6
5 1 -1 -1
6 4 2 0
7 -1 3 0
8 -1 -1 0
9 -1 5 1
10 -1 -1 1
1 0
1 1
0

output=
++++++RESULT++++++
0
1

case= Next Empty Index
input=
6
5 1 -1 -1
6 4 2 0
7 -1 3 0
8 -1 -1 0
9 -1 5 1
10 -1 -1 1
5
4 2
5
0

output=
++++++RESULT++++++
-1
2

case= Add Node
input=
6
5 1 -1 -1
6 4 2 0
7 -1 3 0
8 -1 -1 0
9 -1 5 1
10 -1 -1 1
4 1
6 100 4 2 0
7
0

output=
++++++RESULT++++++

---PRINTING TREE---
Tree has 6 nodes
Tree root index: -1
Tree table:
5, 1, -1, -1
100, 4, 2, 0
7, -1, 3, 0
8, -1, -1, 0
9, -1, 5, 1
10, -1, -1, 1
---     END     ---

case= Add Child
input=
7
5 1 -1 -1
6 4 2 0
7 -1 3 0
8 -1 -1 0
9 -1 5 1
10 -1 -1 1
-1 -1 -1 -1
8 200 1
7
0

output=
++++++RESULT++++++

---PRINTING TREE---
Tree has 7 nodes
Tree root index: -1
Tree table:
5, 1, -1, -1
6, 6, 2, 0
7, -1, 3, 0
8, -1, -1, 0
9, -1, 5, 1
10, -1, -1, 1
200, -1, 4, 1
---     END     ---
*/