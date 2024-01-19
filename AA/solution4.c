#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define COUNT 10

typedef struct Node Node;

struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;
};

typedef struct Trunk Trunk;

struct Trunk
{
    Trunk* prev;
    char* str;
};

Trunk* create_trunk(Trunk* prev, char* str)
{
    Trunk* result = (Trunk*) malloc(sizeof(Trunk));
    result->prev = prev;
    result->str = (char*)malloc( (strlen(str)+1) * sizeof(char));
    strcpy(result->str, str);
    return result;
}
 
// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
    if (p == NULL) {
        return;
    }
 
    showTrunks(p->prev);
    printf("%s", p->str);
}
 
void printTree(Node* root, Trunk *prev, int isLeft)
{
    if (root == NULL) {
        return;
    }
 
    char prev_str[5] = "    ";
    Trunk* trunk = create_trunk(prev, prev_str);

    printTree(root->right, trunk, 1);
 
    if (!prev) {
        strcpy(trunk->str, "———");
    }
    else if (isLeft)
    {
        strcpy(trunk->str, ".———");
        strcpy(prev_str, "   |");
    }
    else {
        strcpy(trunk->str, "`———");
        strcpy(prev->str, prev_str);
    }
 
    showTrunks(trunk);
    printf(" %d\n", root->key);
 
    if (prev) {
        strcpy(prev->str, prev_str);
    }
    strcpy(trunk->str, "   |");
 
    printTree(root->left, trunk, 0);
}
// use this to print the tree structure
void pretty_print(Node* node)
{
    printTree(node, NULL, 0);
}

Node* quick_traverse(Node* root)
{
    Node* current = root;
    int option = 1;

    while(option != 0)
    {
        scanf("%d", &option);
        if(option == 0)
            return current;
        if(option == 1) {
            current = current->left;
        }
        if(option == 2) {
            current = current->right;
        }
    }
    
    return current;
}


// max function
int maxf(int a, int b)
{
    return (a > b) ? a : b;
}

// in-order
void print(Node *root)
{
    if (root != NULL)
    {
        print(root->left);
        printf("%d: %d | ", root->key, root->height);
        print(root->right);
    }
}

// TODO 1
Node *create_node(int key, Node* left, Node* right, int height)
{
    Node* node=(Node*)malloc(sizeof(Node));
    node->key=key;
    node->left=left;
    node->right=right;
    node->height=height;
    return node;
}


Node* create_bst1()
{
    return create_node(5, 
        create_node(3, 
            create_node(2, NULL, NULL, 1), create_node(4, NULL, NULL, 1), 
        2), 
        create_node(7, 
            create_node(6, NULL, NULL, 2), 
        NULL, 2),
    3
    );
}

// TODO 2
// get the height of a node
int get_height(Node *N)
{
    if(N==NULL)
    {
        return 0;
    }
    return N->height;
}



// TODO 3
// height of current node is max of ...
// be aware of NULL cases
void recalculate_height(Node *N)
{
    if(N==NULL)
    return;

    N->height=maxf(get_height(N->left), get_height(N->right))+1;
}

// TODO 4
// recursive implementation
// dont forget to recalculate heights
Node *insert_bst(Node *node, int key)
{
    if(node==NULL)
    return create_node(key,NULL,NULL,1);

    if(key<node->key)
    node->left=insert_bst(node->left, key);
    else if(key>node->key)
    node->right=insert_bst(node->right, key);

    recalculate_height(node);
    return node;
}

// TODO 5
// is a node present in the tree?
// recursive implementation
// returns 1 if found, 0 otherwise
int find(Node *node, int key)
{
    if(node==NULL)
    return 0;
    if(node->key==key)
    return 1;
    if(key<node->key)
    return find(node->left, key);
    else
    return find(node->right, key);
}

int main()
{
    Node* root = create_bst1();
    int function_to_execute;

    scanf("%d", &function_to_execute);
    while(function_to_execute != 0)
    {
        switch(function_to_execute){
            int argument;
            int a1, a2, a3, a4;
            case 1:
                scanf("%d", &argument);
                insert_bst(root, argument);
                break;
            case 2:
                printf("\n++++++RESULT++++++\n");
                print(root);
                break;
            case 3:
                printf("\n++++++RESULT++++++\n");
                printf("%d\n", get_height(root));
                break;
            case 4:
                scanf("%d", &argument);
                printf("\n++++++RESULT++++++\n");
                printf("%d\n", find(root, argument));
                break;
            case 5:
                root = quick_traverse(root);
                break;
            case 6:
                recalculate_height(root);
                break;
            default:
                break;
        }
        scanf("%d", &function_to_execute);
    }
}

/*
case= Get Height 1
input=3
0

output=
++++++RESULT++++++
3

case= Get Height 2
input=5
1
0
3
0

output=
++++++RESULT++++++
2

case= Recalculate Height
input=5
2
1
0
6
3
0

output=
++++++RESULT++++++
1

case= Insert BST 1
input=1 8
2
0

output=
++++++RESULT++++++
2: 1 | 3: 2 | 4: 1 | 5: 4 | 6: 2 | 7: 3 | 8: 1 | 

case= Insert BST 2
input=1 8
1 1
2
0

output=
++++++RESULT++++++
1: 1 | 2: 2 | 3: 3 | 4: 1 | 5: 4 | 6: 2 | 7: 3 | 8: 1 |

case= Find 1
input=4 3
4 8
0

output=
++++++RESULT++++++
1

++++++RESULT++++++
0

case= Find 2
input=4 3
4 8
4 5
4 20
4 -20
0

output=
++++++RESULT++++++
1

++++++RESULT++++++
0

++++++RESULT++++++
1

++++++RESULT++++++
0

++++++RESULT++++++
0
*/