#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* newNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    if (!n) { perror("malloc"); exit(EXIT_FAILURE); }
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

/* Traversals (rekursif) */
void preorder(Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

/* Level-order (BFS) menggunakan queue sederhana */
#define MAXQ 1000
void levelOrder(Node* root) {
    if (!root) return;
    Node* q[MAXQ];
    int front = 0, rear = 0;
    q[rear++] = root;
    while (front < rear) {
        Node* cur = q[front++];
        printf("%d ", cur->data);
        if (cur->left)  q[rear++] = cur->left;
        if (cur->right) q[rear++] = cur->right;
        if (rear >= MAXQ) { fprintf(stderr, "Queue overflow\n"); break; }
    }
}

int main() {

    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printf("Preorder: "); preorder(root); printf("\n");
    printf("Inorder : "); inorder(root);  printf("\n");
    printf("Postorder: "); postorder(root); printf("\n");
    printf("Level-order: "); levelOrder(root); printf("\n");

    
    return 0;
}