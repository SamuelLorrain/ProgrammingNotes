#include <stdio.h>
#include <stdlib.h>

/*
 * Path,
 * Root,
 * Parent,
 * Child
 * Leaf,
 * Subtree,
 * Visiting,
 * Traversing,
 * Levels,
 * keys
 *
 * Common op:
 *  - Insert,
 *  - Search,
 *  - Preorder Traversal
 *  - Inorder Traversal
 *  - Postorder Traversal
 *
 */

typedef struct Node
    int data;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

void insert(Node *root, int data){
    Node *tempNode = (Node*)malloc(sizeof(Node));
    Node *current;
    Node *parent;

    tempNode->data = data;
    tempNode->leftChild = NULL;
    tempNode->leftChild = NULL;

    if (root == NULL){
        root = tempNode;
    }else{
        current = root;
        parent = NULL;
        while(1){
            parent = current;

            if(data < parent->data){
                current = current->leftChild;
                if(current ==NULL){
                    parent->leftChild = tempNode;
                    return;
                }
            }else{
                current = current->rightChild;
                if(current == NULL){
                    parent->rightChild = tempNode;
                    return;
                }
            }

        }
    }
}

Node* search(Node *root, int data){
    Node* current = root;
    while(current->data != data){
        if(current != NULL){
            if(current->data > data){
                current = current->leftChild;
            }
            else{
                current = current->rightChild;
            }
        }
        if(current == NULL){
            return NULL;
        }
        return current;
    }
}

void preorderTraversal(Node *root);
void inorderTraversal(Node *root);
void postorderTraversal(Node *root);
