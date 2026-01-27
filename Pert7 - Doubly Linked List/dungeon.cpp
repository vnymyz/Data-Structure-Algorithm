#include <iostream>
using namespace std;

// Struktur Node sebagai ruangan
struct Ruangan {
    // nama dan deskripsi ruangan
    string nama;
    string deskripsi;
    // ini buat navigasi kiri kanan ruangan
    Ruangan* prev;
    Ruangan* next;
};

// Pointer ke ruangan pertama dan posisi player
// dan pointer nya ini masih kosong
// nanti bakal diisi pas tambahRuangan
// ruangan head itu ruangan pertama
// player itu posisi kita sekarang
Ruangan* head = nullptr;
Ruangan* player = nullptr;

// fungsi buat nambahin ruangan baru
void tambahRuangan(string nama, string deskripsi) {
    // buat ruangan baru kalau ditambahin
    Ruangan* baru = new Ruangan{nama, deskripsi, nullptr, nullptr};
    // kalau ruangannya kosong berarti buat ruangan baru
    // jadi ruangan pertama
    if (head == nullptr) {
        head = baru;
        player = baru;
        // kalau lain atau else ruangannya udah ada, berarti lanjut ke ruangan
        // berikutnya
    } else {
        // cari ruangan terakhir
        Ruangan* temp = head;
        // selagi masih ada ruangan berikutnya, maju terus
        while (temp->next != nullptr)
        // maju ke ruangan berikutnya kalau ada ruangan
            temp = temp->next;

        // pas udah ketemu ruangan terakhir, tambahin ruangan baru
        temp->next = baru;
        baru->prev = temp;
    }
}

// Tampilkan ruangan sekarang
// fungsi buat nampilin deskripsi ruangan sekarang atau diinjek sekarang
void tampilkanRuangan() {
    cout << "\nKamu berada di: " << player->nama << endl;
    cout << player->deskripsi << endl;
}

// Navigasi ke kanan
// fungsi buat jalan ke kanan dengan mencet tombol d
void jalanKanan() {
    if (player->next != nullptr) {
        player = player->next;
        tampilkanRuangan();
    } else {
        cout << "\n Tidak ada jalan ke kanan lagi!\n";
    }
}

// Navigasi ke kiri
void jalanKiri() {
    // kalau masih ada ruangan sebelumnya
    if (player->prev != nullptr) {
        // maju ke ruangan sebelumnya
        player = player->prev;
        // nampilin deskripsi ruangan sekarang atau yang dia pijak
        tampilkanRuangan();
        // kalau ga ada ruangan sebelumnya
    } else {
        cout << "\n Tidak ada jalan ke kiri lagi!\n";
    }
}

int main() {
    // Setup dungeon
    // nambahin ruangan-ruangan di dungeon
    tambahRuangan("Gerbang", "Gerbang tua yang sudah berkarat.");
    tambahRuangan("Koridor", "Lorong panjang yang gelap dan lembap.");
    tambahRuangan("Ruang Senjata", "Terdapat banyak pedang dan tameng di dinding.");
    tambahRuangan("Ruang Rahasia", "Ruangan misterius dengan simbol sihir di lantai.");

    // Game loop
    // char perintah ini buat kita bisa pencet tombol a kiri, d kanan, q keluar
    char perintah;
    // nampilin deskripsi ruangan yang kita injek 
    // sesuai dengan tombol atau ruangan yg kita pijak
    tampilkanRuangan();

    // looping selama perintahnya bukan q
    do {
        cout << "\nPerintah (a: kiri, d: kanan, q: keluar): ";
        // minta input perintah
        cin >> perintah;

        // eksekusi perintah
        switch (perintah) {
            // kalau pencet a, jalan kiri
            case 'a': jalanKiri(); break;
            // kalau pencet d, jalan kanan
            case 'd': jalanKanan(); break;
            // kalau pencet q, keluar
            case 'q': cout << "Keluar dari dungeon...\n"; break;
            // kalau pencet selain itu, perintah ga dikenali
            default: cout << " Perintah tidak dikenali\n";
        }
    } while (perintah != 'q');

    return 0;
}
