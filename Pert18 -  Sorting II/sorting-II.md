# Sorting Algorithm

Sorting Algorithm yang akan kita bahas selanjutnya adalah :

1. Merge Sort

2. Quick Sort

## 1. Merge Sort

Link video merge sort : https://www.youtube.com/watch?v=3j0SWDX4AtU

Merge Sort bekerja dengan cara:

- Divide (pecah): Bagi array menjadi dua bagian sampai tiap bagian berisi satu elemen.

- Conquer (urutkan): Urutkan tiap bagian kecil.

- Combine (gabungkan): Gabungkan dua bagian kecil tersebut dalam urutan yang benar (ascending / descending).

### Cara Kerja Merge Sort

```csharp
[38, 27, 43, 3, 9, 82, 10]
```

1. Pecah terus hingga jadi satuan kecil

```css
[38, 27, 43, 3, 9, 82, 10]
     /                \
[38, 27, 43, 3]      [9, 82, 10]
   /        \           /     \
[38, 27]  [43, 3]    [9, 82]  [10]
 /   \      /  \      /   \     \
[38] [27] [43] [3]  [9] [82]   [10]
```

2. Gabungkan sambil diurutkan

```less
[38] [27] → [27, 38]
[43] [3]  → [3, 43]
[9] [82]  → [9, 82]

Sekarang:

[27, 38] [3, 43] → [3, 27, 38, 43]
[9, 82] [10] → [9, 10, 82]
```

3. Gabungkan hasil akhir

```css
[3, 27, 38, 43] + [9, 10, 82]
→ [3, 9, 10, 27, 38, 43, 82]
```

### Merge Process

```csharp
Split:
[38, 27, 43, 3, 9, 82, 10]
        ↓
[38, 27, 43, 3]      [9, 82, 10]
        ↓                  ↓
[27, 38, 3, 43]      [9, 10, 82]
        ↓                  ↓
[3, 9, 10, 27, 38, 43, 82]  ✅
```

### Pseudocode / C version

```c
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
```

## 2. Quick Sort

Link video : https://www.youtube.com/watch?v=Vtckgz38QHs

Quick Sort juga pakai Divide and Conquer, tapi cara “menggabungkannya” beda.

1. Pilih Pivot: Elemen acuan (bisa yang pertama, tengah, atau terakhir).

2. Partisi: Pisahkan elemen menjadi dua sisi:

   - Kiri → lebih kecil dari pivot

   - Kanan → lebih besar dari pivot

3. Rekursif: Lakukan quick sort lagi di sisi kiri dan kanan.

### Cara kerja Quick Sort

```ini
[38, 27, 43, 3, 9, 82, 10]
 L                     H
Pivot = 10
```

Langkah Partisi :

```less
Kiri (<10): [3, 9]
Pivot: [10]
Kanan (>10): [38, 27, 43, 82]

→ [3, 9, 10, 38, 27, 43, 82]
```

Kemudian Sort lagi :

- `[3, 9]` (sudah urut)

- `[38, 27, 43, 82]` → pilih pivot 43

```less
Kiri (<43): [38, 27]
Pivot: [43]
Kanan (>43): [82]
→ [27, 38, 43, 82]
```

Gabungkan hasil akhir :

```css
[3, 9] + [10] + [27, 38, 43, 82]
→ [3, 9, 10, 27, 38, 43, 82]
```

### Proses Quick Sort

```csharp
[38, 27, 43, 3, 9, 82, 10]
                  |
                pivot = 10
     ↓ partition ↓
[3, 9]  [10]  [38, 27, 43, 82]
            ↓
[3, 9]  [10]  [27, 38, 43, 82]
            ↓
[3, 9, 10, 27, 38, 43, 82] ✅
```

### Pseudocode / C Version

```c
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
    }
    int temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
```

## 3. Perbandingan

| Aspek                  | Merge Sort                     | Quick Sort                |
| ---------------------- | ------------------------------ | ------------------------- |
| Strategi               | Divide, lalu merge             | Divide via partition      |
| Kompleksitas rata-rata | O(n log n)                     | O(n log n)                |
| Kompleksitas terburuk  | O(n log n)                     | O(n²) (kalau pivot buruk) |
| Memory                 | Butuh array tambahan           | In-place (hemat memori)   |
| Stabilitas             | Stabil                         | Tidak selalu stabil       |
| Cocok untuk            | Data besar, stabilitas penting | Data acak / pivot efisien |
