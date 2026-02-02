#include <iostream>

using namespace std;

// membuat function selection sort
void selection_sort(int a[], int length)
{   
    for (int i = 0; i < (length - 1); i++) // indeks pertama yang kita lihat
    {
        int min_position = i; // cek nilai terkecil dan disimpen
        for (int j = i + 1; j < length; j++) // cek elemen sisanya
        {
            if (a[j] < a[min_position])
            {
                min_position = j;
            }
        } 

        // lakukan swap jika posisi min berubah
        if (min_position != i)
        {
            int temp = a[i];
            a[i] = a[min_position];
            a[min_position] = temp;
        }
    }
}

// program utama nya
int main(){
    int a[] = {6, 5, 3, 2, 1, 4};
    int length = 6;

    selection_sort(a, length);

    for (int i = 0; i < length; i++ )
    {
        cout << "a[" << i << "] = " << a[i] << endl;
    }

    return 0;
}

