#include <iostream>

using namespace std;

// Function untuk mengurutkan array menggunakan Bubble Sort
void bubble_sort(int a[], int length)
{
    // Flag untuk mengecek apakah ada pertukaran elemen
    bool swapped;
    // Variabel i untuk mengurangi jumlah perbandingan pada setiap iterasi
    int i = 0;
    // Looping do-while untuk terus mengulang 
    // proses hingga tidak ada pertukaran elemen
    do
    {
        // Set swapped ke false di awal setiap iterasi
        swapped = false;
        // Looping untuk membandingkan elemen-elemen dalam array
        for (int j = 0; j < length - 1 - i; j++)
        {
            // semisal j lebih gede dari element sebelah kanannya
            // bisa ascending > bisa descending <
            if (a[j] > a[j + 1])
            // if (a[j] < a[j + 1])
            {
                // maka di swap angka tersebut
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = true;
            } 
        }
        i++;
    } while (swapped);
}

int main(){
    int a[] = {4, 1, 5, 8, 9, 0, 2, 7, 3, 6};

    int length = 10;

    // Memanggil function void
    bubble_sort(a, length);

    for (int i = 0; i < length; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl << endl;

    return 0;
}

