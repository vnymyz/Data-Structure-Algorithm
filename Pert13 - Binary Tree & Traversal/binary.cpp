#include <iostream>
using namespace std;

// membuat struktur node
struct Node {
    // data dan pointer ke anak kiri dan kanan
    char data;
    // pointer ke anak kiri
    Node* left;
    // pointer ke anak kanan
    Node* right;

    // konstruktor nyimpen nilai
    Node(char val) {
        // nyimpen nilai ke data atau node atau ke pohon
        data = val;
        // inisialisasi anak kiri dan kanan ke nullptr
        // atau pohon nya masih kosong
        left = right = nullptr;
    }
};

// membuat function traversal
void preorder(Node* root) {
    // kalau misal pohon nya kosong
    // maka return atau keluar dari function
    if (root == nullptr) return;
    // proses node root dulu
    cout << root->data << " ";
    // lalu rekursif ke anak kiri
    preorder(root->left);
    // lalu rekursif ke anak kanan
    preorder(root->right);
}
// PREORDER ITU ROOT - LEFT - RIGHT

// INORDER ITU LEFT - ROOT - RIGHT
void inorder(Node* root) {
    // kalau misal pohon nya kosong
    // maka return atau keluar dari function
    if (root == nullptr) return;
    // rekursif ke anak kiri dulu
    inorder(root->left);
    // proses node root
    cout << root->data << " ";
    // lalu rekursif ke anak kanan
    inorder(root->right);
}

// POSTORDER ITU LEFT - RIGHT - ROOT
void postorder(Node* root) {
    // kalau misal pohon nya kosong
    // maka return atau keluar dari function
    if (root == nullptr) return;
    // rekursif ke anak kiri dulu
    postorder(root->left);
    // lalu rekursif ke anak kanan
    postorder(root->right);
    // proses node root
    cout << root->data << " ";
}

// Program utama
int main() {
    // membuat pohon biner contoh
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->right = new Node('F');

    // melakukan traversal
    // preorder, inorder, postorder function
    cout << "Preorder Traversal: ";
    preorder(root); cout << endl;

    cout << "Inorder Traversal: ";
    inorder(root); cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root); cout << endl;

    // selesai
    return 0;
}
