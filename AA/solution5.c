#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINT(var) printf("%s: %d\n", #var, var)

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

void pretty_print(Node* node)
{
    printf("\n");
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

Node *create_node(int key, Node* left, Node* right, int height)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    new_node->left = left;
    new_node->right = right;
    new_node->height = height;
    return new_node;
}

Node* create_bst1()
{
    return create_node(5, 
        create_node(3, 
            create_node(2, NULL, NULL, 1), create_node(4, NULL, NULL, 1), 
        2), 
        create_node(7, 
            create_node(6, NULL, NULL, 1), 
        NULL, 2),
    3
    );
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

int maxf(int a, int b)
{
    return (a > b) ? a : b;
}

int find(Node *node, int key)
{
    if (node == NULL)
        return 0;

    if (key < node->key)
    {
        return find(node->left, key);
    }
    else if (key > node->key)
    {
        return find(node->right, key);
    } else {
        return 1;
    }
}


int get_height(Node *N)
{
    if (N == NULL)
        return 0;
    else
        return N->height;
}

void recalculate_height(Node *N)
{
    if (N == NULL)
        return;
    int left_height = get_height(N->left);
    int right_height = get_height(N->right);

    N->height = 1 + max(left_height, right_height);
}

Node *insert_bst(Node *node, int key)
{
    if (node == NULL)
        return create_node(key, NULL, NULL, 1);

    if (key < node->key)
    {
        node->left = insert_bst(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert_bst(node->right, key);
    }

    recalculate_height(node);
    return node;
}

// TODO 1
// height difference between left and right node
// treat NULL case!
int height_difference(struct Node *N)
{
    if(N=NULL)
    return ;

    int left_height = get_height(N->left);
    int right_height = get_height(N->right);
    return left_height - right_height;

    //return get_height(N->left)-get_height(N->right);
}

// TODO 2
// follow theory
Node *rotate_right(Node *y)
{
    Node *x=y->left;
    Node* T2=x->right;
    x->right=y;
    y->left=T2;
    recalculate_height(y);
    recalculate_height(x);
}

// TODO 3
// follow theory
Node *rotate_left(Node *x)
{
    Node *y=x->right;
    Node* T2=y->left;
    y->left=x;
    x->right=T2;
    recalculate_height(x);
    recalculate_height(y);
}

// TODO 4
// complete rotations
Node *insert_avl(Node *node, int key)
{
    // INSERT BST //
    if (node == NULL)
        return create_node(key, NULL, NULL, 1);

    if (key < node->key)
    {
        Node* new_subtree = insert_avl(node->left, key);
        node->left = new_subtree;
    }
    else if (key > node->key)
    {
        Node* new_subtree = insert_avl(node->right, key);
        node->right = new_subtree;
    }
    else
    {
        return node;
    }
    recalculate_height(node);
    // INSERT BST //

    // TODO starts here
    int balance=height_difference(node);
    // compute difference
    // Left Left Case
    if(balance >1&&key<node->left->key)
    return rotate_right(node);
    // Right Right Case
    if(balance<-1&&key>node->right->key)
    return rotate_left(node);
    // Left Right Case
    if(balance>1 && key>node->left->key)
    {
        node->left=rotate_left(node->left);
        return rotate_right(node);
    }
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }
    // return node at the end
    return node;
}

// TODO 5
// returns 1 if the node has only one child, 0 otherwise
int has_only_one_child(Node *node)
{
    return ((node->left==NULL && node->right !=NULL) || (node->left !=NULL && node->right==NULL));
}

// TODO 6
// returns 1 if the node has no child (is a leaf), 0 otherwise
int has_no_child(Node *node)
{
    return (node->left==NULL && node->right==NULL);
}

// TODO 7
// go left as much as possible and return node
Node *find_leftmost_node(Node *node)
{
    while(node->left !=NULL)
    {
        node=node->left;
    }
    return node;
}

// TODO 8
// delete node; follow the instructions below for help
struct Node *deleteNode(struct Node *root, int key)
{
    // what if root is NULL? what do we return? if(...)
    if(root==NULL)
    return root;

    // recursive call if query key smaller than key of the root
    // if(...)
    

    // recursive call if query key larger than key of the root
    // else if(...)

    // else we have found the key; now we have 3 cases treated separately

        // First: if the node to be deleted has only one child, we will delete the current node and put the child in its place
        // 1. we save the child that is not NULL to a temp Node
        // 2. we set all the values of the root to the values of the temp
        // 3. we free temp


        // Second: easiest case, if the node has no child we simply remove it
        // 1. we free the root
        // 2. we return NULL


        // Third: complicated case, the node has 2 children
        // 1. we find the leftmost node of the right child of the current node: node -> right_child -> leftmost child
        // 2. we replace the key of the current node with the key of the leftmost child we found in step 1
        // 3. we call deleteNode on the right child querying the key of the leftmost child found in step 1

    // exactly like insert_avl rotations!
    // copy-paste from there everything after recalculate height

}

int main()
{
    Node* root = create_bst1();
    Node* original_root = root;
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
            case 7:
                printf("\n++++++RESULT++++++\n");
                printf("%d\n", height_difference(root));
                break;
            case 8:
                root = rotate_right(root);
                break;
            case 9:
                root = rotate_left(root);
                break;
            case 10:
                scanf("%d", &argument);
                insert_avl(root, argument);
                break;
            case 11:
                printf("\n++++++RESULT++++++\n");
                printf("%d\n",has_only_one_child(root));
                break;
            case 12:
                printf("\n++++++RESULT++++++\n");
                printf("%d\n",has_no_child(root));
                break;
            case 13:
                printf("\n++++++RESULT++++++\n");
                printf("%d\n", (*find_leftmost_node(root)).key);
                break;
            case 14:
                scanf("%d", &argument);
                root = deleteNode(root, argument);
                break;
            case 20:
                root = original_root;
                break;
            case 30:
                pretty_print(root);
                break;
            default:
                break;
        }
        scanf("%d", &function_to_execute);
    }
}


/*
case= Height Difference
input=1 1
1 0
7
5 2 0
7
5 1 0
7
0

output=
++++++RESULT++++++
2

++++++RESULT++++++
1

++++++RESULT++++++
0

case= Rotate Right
input=1 1
1 0
2
5 1 1 0
8
2
20
2
0

output=
++++++RESULT++++++
0: 1 | 1: 2 | 2: 3 | 3: 4 | 4: 1 | 5: 5 | 6: 1 | 7: 2 | 
++++++RESULT++++++
0: 1 | 1: 2 | 2: 1 | 
++++++RESULT++++++
2: 1 | 3: 4 | 4: 1 | 5: 5 | 6: 1 | 7: 2 | 

case= Rotate Left
input=1 8
1 9
1 10
2
5 2 2 0
9
2
20
2
0

output=
++++++RESULT++++++
2: 1 | 3: 2 | 4: 1 | 5: 5 | 6: 1 | 7: 4 | 8: 3 | 9: 2 | 10: 1 | 
++++++RESULT++++++
8: 1 | 9: 2 | 10: 1 | 
++++++RESULT++++++
2: 1 | 3: 2 | 4: 1 | 5: 5 | 6: 1 | 7: 4 | 8: 1 |


case= Insert AVL 1
input=10 1
10 0
2
0

output=
++++++RESULT++++++
0: 1 | 1: 2 | 2: 1 | 3: 3 | 4: 1 | 5: 4 | 6: 1 | 7: 2 |

case= Insert AVL 2
input=10 8
10 9
10 10
2
0

output=
++++++RESULT++++++
2: 1 | 3: 2 | 4: 1 | 5: 4 | 6: 1 | 7: 3 | 8: 1 | 9: 2 | 10: 1 |


case= Child Conditions
input=11
12
5 2 0
11
12
5 1 0
11
12
0

output=
++++++RESULT++++++
0

++++++RESULT++++++
0

++++++RESULT++++++
1

++++++RESULT++++++
0

++++++RESULT++++++
0

++++++RESULT++++++
1


case= Find Leftmost Node
input=13
0

output=
++++++RESULT++++++
2


case= Delete AVL
input=14 2
2
14 3
2
14 5
2
0

output=
++++++RESULT++++++
3: 2 | 4: 1 | 5: 3 | 6: 1 | 7: 2 | 
++++++RESULT++++++
4: 1 | 5: 3 | 6: 1 | 7: 2 | 
++++++RESULT++++++
4: 1 | 6: 2 | 7: 1 | 

*/