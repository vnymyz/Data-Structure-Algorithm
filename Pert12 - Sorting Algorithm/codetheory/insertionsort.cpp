#include <iostream>

using namespace std;

// membuat function insertion sort
void insertion_sort(int a[], int length)
{
    // looping dari index ke 1 sampai length-1
    for (int i = 1; i < length; i++)
    {
        // buat key dan j untuk pembanding
        int key = a[i];
        int j = i - 1;
        // selagi j lebih besar sama dengan 0 akan terus berjalan prosesnya
        while(j >= 0 && a[j] > key)
        {
            // geser elemen ke kanan
            a[j + 1] = a[j];
            // mencari elemen selanjutnya
            j = j - 1;
        }
        // tempatkan key pada posisi yang sudah benar
        a[j + 1] = key;
    }
}

// program utama
int main()
{
    // array yang akan di sorting
    int a[] = {8, 2, 7, 4, 5, 1, 9, 3};

    // panjang array
    int length = 8;

    // memanggil function insertion sort
    insertion_sort(a, length);

    // menampilkan hasil sorting
    for (int i = 0; i < length; i++)
    {
        cout << "a[" << i << "] = " << a[i] << endl;
    }

    return 0;
}
