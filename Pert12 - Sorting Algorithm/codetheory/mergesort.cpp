#include <iostream>
using namespace std;

// mergeSort() memecah array menjadi 2 bagian

// merge() menyatukan dua bagian yang sudah terurut

// Proses rekursif terus berlangsung sampai ukuran array = 1

// Fungsi untuk menggabungkan dua bagian array
// left = indeks awal, mid = indeks tengah, right = indeks akhir
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // panjang bagian kiri
    int n2 = right - mid;    // panjang bagian kanan

    // ini untuk membuat array sementara untuk di urutin
    int L[n1], R[n2];  // array sementara

    // Copy data ke array sementara
    for (int i = 0; i < n1; ++i)
    // untuk nge bandingin dan masukin ke array sementara
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Merge array sementara kembali ke arr[]
    int i = 0, j = 0, k = left;

    // nge bandingin antara dua array sementara
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Salin sisa elemen jika masih ada
    // jika ada elemen tersisa di L[]
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Fungsi utama Merge Sort (rekursif)
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // ini dibagi bagian tengah
        int mid = left + (right - left) / 2;  // Hindari overflow

        mergeSort(arr, left, mid);         // Sort bagian kiri
        mergeSort(arr, mid + 1, right);    // Sort bagian kanan
        merge(arr, left, mid, right);      // Gabungkan keduanya
    }
}

// Fungsi untuk mencetak array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Main program
int main() {
    int arr[] = {6, 5, 3, 2, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array sebelum disortir: ";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Array setelah merge sort: ";
    printArray(arr, n);

    return 0;
}
