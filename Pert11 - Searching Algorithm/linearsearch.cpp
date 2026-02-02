#include <iostream>
using namespace std;
                // start     step    stop
// function buat mencari elemen dalam array
// parameter: arr (array), n (ukuran array), target (elemen yang dicari)
int linearSearch(int arr[], int n, int target) {
    // perulangan untuk mencari elemen
    for (int i = 0; i < n; i++) {
        // kalau misal elemen sama dengan target yang dicari
        if (arr[i] == target) {
            // mengembalikan indeks elemen yang ditemukan
            return i; // ditemukan di indeks ke-i
        }
    }
    return -1; // tidak ditemukan
}

int main() {
    // contoh array
    int data[] = {5, 3, 7, 9, 1, 6};
    // menghitung ukuran array dan jumlah elemen atau indeks nya
    int size = sizeof(data)/sizeof(data[0]);
    // elemen yang dicari
    int target = 6;

    // rumus nya panggil fungsi linearSearch
    // parameter: data (array), size (ukuran array), target (elemen yang dicari)
    int hasil = linearSearch(data, size, target);

    // kalau misal hasilnya ditemukan
    if (hasil != -1)
    // menampilkan indeks elemen yang ditemukan
        cout << "Elemen ditemukan di indeks: " << hasil << endl;
    else
    // kalau tidak ditemukan
        cout << "Elemen tidak ditemukan" << endl;

    return 0;
}
