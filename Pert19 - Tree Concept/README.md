# Pertemuan 19 - Tree Concept

## Materi yang akan dibahas :

1. Binary Tree

2. Traversal

---

### 1. Teori Singkat

- Tree adalah struktur data hirarkis yang terdiri dari node yang saling terhubung.

- Binary tree: setiap node mempunyai maksimal 2 anak, biasa dinamai left dan right.

istilah penting :

- Root: node paling atas.

- Leaf (daun): node tanpa anak.

- Internal node: node yang punya setidaknya 1 anak.

- Depth/Height: tingkat/tinggi tree (dapat ada definisi kecil berbeda).

Jenis traversal (mengunjungi semua node):

- Preorder (N L R): kunjungi node, lalu rekursif ke kiri, lalu ke kanan.

- Inorder (L N R): rekursif kiri, kunjungi node, rekursif kanan. (untuk BST, menghasilkan urutan terurut)

- Postorder (L R N): kiri, kanan, lalu node.

- Level-order (BFS): kunjungi per level dari atas ke bawah, kiri ke kanan (menggunakan queue).

Kompleksitas traversal (semua): O(n) waktu, O(h) ruang rekursi (h = tinggi tree). Level-order menggunakan O(n) ruang queue pada worst-case.

### 2. Secara Visualisasi (Tree)

Contoh tree :

```markdown
        1
       / \
      2   3
     / \   \
    4   5   6
```

Representasi diatas :

- Root = 1

- 1.left = 2, 1.right = 3

- 2.left = 4, 2.right = 5

- 3.right = 6

### 3. Traversal pada Tree diatas

- Preorder (N L R): 1, 2, 4, 5, 3, 6
  Langkah: visit 1 → masuk kiri → visit 2 → kiri → visit 4 → kembali → kanan → visit 5 → kembali ke 1 → kanan → visit 3 → kanan → visit 6.

- Inorder (L N R): 4, 2, 5, 1, 3, 6
  (lihat urutan kunjungan kiri sebelum node)

- Postorder (L R N): 4, 5, 2, 6, 3, 1

- Level-order (per level): 1, 2, 3, 4, 5, 6

Berikut step by step singkat untuk preorder :

1. Start at 1 → output 1

2. Go to 2 → output 2

3. Go to 4 → output 4 (4 punya no children → back)

4. Back to 2 → go right → 5 → output 5

5. Back to 1 → go right → 3 → output 3

6. 3.right → 6 → output 6

### 4. Kode C sederhana — membuat tree manual & traversal

Kode dibawah seperti tree diatas dan menampilkan semua traversal.

```c
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
    /* Membangun contoh tree:
             1
            / \
           2   3
          / \   \
         4   5   6
    */
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

    /* Note: untuk program pembelajaran sederhana ini kita tidak membebaskan memori. */
    return 0;
}
```

Penjelasan :

- `newNode` membuat node baru.

- `preorder`, `inorder`, `postorder` sifatnya rekursif.

- `levelOrder` mengimplementasikan BFS sederhana memakai array sebagai queue.

### 5. Perbandingan traversal dan penggunaan nyata

- Inorder → mendapatkan urutan menaik jika tree adalah BST. Berguna untuk sortir.

- Preorder → berguna untuk menyalin tree atau mengekspor struktur (mis. menyimpan struktur untuk pembentukan ulang).

- Postorder → berguna untuk operasi yang membutuhkan hasil anak-anak dahulu (mis. menghapus tree / menghitung ukuran dari bawah).

- Level-order → berguna untuk menemukan shortest path di tree tak berbobot antar levels, atau menampilkan per-level.

### 6. Latihan

Diberi tree :

```bash
      8
     / \
    3   10
   / \    \
  1   6    14
     / \   /
    4   7 13
```

Tuliskan hasil traversal: preorder, inorder, postorder, level-order :

Jawaban :

- Preorder: 8 3 1 6 4 7 10 14 13

- Inorder : 1 3 4 6 7 8 10 13 14

- Postorder: 1 4 7 6 3 13 14 10 8

- Level-order: 8 3 10 1 6 14 4 7 13
