#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char *nama;
    struct Node *left;
    struct Node *right;
} Node;

Node* newNode(char *nama) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->nama = nama;
    node->left = node->right = NULL;
    return node;
}

void preorder(Node *root) {
    if (!root) return;
    printf("%s ", root->nama);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root) {
    if (!root) return;
    inorder(root->left);
    printf("%s ", root->nama);
    inorder(root->right);
}

void postorder(Node *root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%s ", root->nama);
}

int main() {
    // Bangun tree menu
    Node *menu = newNode("Menu");
    menu->left = newNode("Makanan");
    menu->right = newNode("Minuman");

    menu->left->left = newNode("Nasi");
    menu->left->right = newNode("Mie");

    menu->right->left = newNode("Kopi");
    menu->right->right = newNode("Jus");

    printf("=== Traversal Menu Restoran ===\n");

    printf("\nPreorder  (urutan brosur): ");
    preorder(menu);

    printf("\nInorder   (urut kiri-kanan): ");
    inorder(menu);

    printf("\nPostorder (hapus dari bawah): ");
    postorder(menu);

    printf("\n");

    return 0;
}

// === Traversal Menu Restoran ===

// Preorder  (urutan brosur): Menu Makanan Nasi Mie Minuman Kopi Jus
// Inorder   (urut kiri-kanan): Nasi Makanan Mie Menu Kopi Minuman Jus
// Postorder (hapus dari bawah): Nasi Mie Makanan Kopi Jus Minuman Menu

// Menu adalah root.

// Makanan dan Minuman adalah cabang kiri dan kanan.

// Nasi, Mie, Kopi, dan Jus adalah daun (leaf).

// Preorder (Menu dulu) → cocok untuk menampilkan daftar dari atas ke bawah.

// Inorder (urut kiri-kanan) → cocok untuk melihat kategori terurut.

// Postorder (bawah dulu) → cocok saat mau menghapus atau mereset menu.
