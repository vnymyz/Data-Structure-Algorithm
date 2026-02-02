#include <iostream>
using namespace std;

// fungsi buat mencari elemen dalam array
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // != - 1
        }
    }
    return -1; // = -1
}

// program utama
int main() {
    // start
    // mendeklarasikan variabel untuk ukuran array
    int n;
    // minta input jumlah elemen
    // array nya bisa muat berapa ?
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    // buat masukin elemen ke array
    int arr[n];
    // step
    // masukkin elemen ke array dari kita input
    // dan berulang sebanyak n kali atau jumlah array yang bisa kita masukkin.
    cout << "Masukkan " << n << " elemen array:\n";
    for (int i = 0; i < n; i++) {
        cout << "Elemen ke-" << i << ": ";
        cin >> arr[i];
    }
    // stop
    int target;
    // input elemen yang kita pengen cari
    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> target;

    // dari function linearSearch buat cari elemen yang kita targetin
    int hasil = linearSearch(arr, n, target);

    // output hasil pencarian
    if (hasil != -1)
    // menampilkan indeks elemen yang ditemukan
        cout << "Elemen ditemukan di indeks: " << hasil << endl;
    else
    // kalau misal enggak ketemu bakal nampilin gini
        cout << "Elemen tidak ditemukan." << endl;

    return 0;
}
