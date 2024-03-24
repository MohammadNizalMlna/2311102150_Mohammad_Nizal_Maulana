/*
Mohammad Nizal Maulana - 2311102150
*/
#include <iostream>
using namespace std;

//Deklarasi Struct Node
struct Node {
    string nama_150;
    int umur_150;
    Node* next;
};

Node* head;
Node* tail;

//Inisialisasi Node
void init_150() {
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool kosong_150() {
    if (head == NULL)
        return true;
    else
        return false;
}
//Tambah Depan
void tambahDepan_150(string nama, int umur) {
    //Buat Node baru
    Node* baru = new Node;
    baru->nama_150 = nama;
    baru->umur_150 = umur;
    baru->next = NULL;

    if (kosong_150() == true) {
        head = tail = baru;
        tail->next = NULL;
    }
    else {
        baru->next = head;
        head = baru;
    }
}
//Tambah Belakang
void tambahBelakang_150(string nama, int umur) {
    //Buat Node baru
    Node* baru = new Node;
    baru->nama_150 = nama;
    baru->umur_150 = umur;
    baru->next = NULL;

    if (kosong_150() == true) {
        head = tail = baru;
        tail->next = NULL;
    }
    else {
        tail->next = baru;
        tail = baru;
    }
}
//Hitung Jumlah List
int hitungList_150() {
    Node* hitung;
    hitung = head;
    int jumlah = 0;

    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }

    return jumlah;
}
//Tambah Tengah
void tambahTengah_150(string nama, int umur, int posisi) {
    if (posisi < 1 || posisi > hitungList_150()) {
        cout << "Posisi ada diluar jangkauan" << endl;
    }
    else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah." << endl;
    }
    else {
        Node* baru, * bantu;
        baru = new Node();
        baru->nama_150 = nama;
        baru->umur_150 = umur;

        // tranversing
        bantu = head;
        int nomor = 1;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}
//Hapus Depan
void hapusDepan_150() {
    Node* hapus;

    if (kosong_150() == false) {
        if (head->next != NULL) {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else {
            head = tail = NULL;
        }
    }
    else {
        cout << "KOSONG!" << endl;
    }
}
//Hapus Belakang
void hapusBelakanh_150() {
    Node* hapus;
    Node* bantu;

    if (kosong_150() == false) {
        if (head != tail) {
            hapus = tail;
            bantu = head;

            while (bantu->next != tail) {
                bantu = bantu->next;
            }

            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else {
            head = tail = NULL;
        }
    }
    else {
        cout << "KOSONG!" << endl;
    }
}
//Hapus Tengah
void hapusTengah_150(int posisi) {
    Node* hapus, * bantu, * bantu2;

    if (posisi < 1 || posisi > hitungList_150()) {
        cout << "Posisi ada diuar jangkauan!" << endl;
    }
    else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah." << endl;
    }
    else {
        int nomor = 1;
        bantu = head;

        while (nomor <= posisi) {
            if (nomor == posisi - 1) {
                bantu2 = bantu;
            }

            if (nomor == posisi) {
                hapus = bantu;
            }

            bantu = bantu->next;
            nomor++;
        }

        bantu2->next = bantu;
        delete hapus;
    }
}
//Ubah Depan
void ubahDepan_150(string nama, int umur) {
    if (kosong_150() == false) {
        head->nama_150 = nama;
        head->umur_150 = umur;
    }
    else {
        cout << "LIST MASIH KOSONG!" << endl;
    }
}
//Ubah Tengah
void ubahTengah_150(string nama, int umur, int posisi) {
    Node* bantu;
    if (kosong_150() == false) {
        if (posisi < 1 || posisi > hitungList_150()) {
            cout << "Posisi berada diluar jangkauan!" << endl;
        }
        else if (posisi == 1) {
            cout << "Posisi buukan posisi tengah." << endl;
        }
        else {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi) {
                bantu = bantu->next;
                nomor++;
            }
            bantu->nama_150 = nama;
            bantu->umur_150 = umur;
        }
    }
    else {
        cout << "KOSONG" << endl;
    }
}
//Ubah Belakang
void ubahBelakang(string nama, int umur) {
    if (kosong_150() == false) {
        tail->nama_150 = nama;
        tail->umur_150 = umur;
    }
    else {
        cout << "KOSONG" << endl;
    }
}
//Hapus List
void hapusList_150() {
    Node* bantu, * hapus;
    bantu = head;
    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil dihapus" << endl;
}
//Tampilkan List
void tampilkan_150() {
    Node* bantu;
    bantu = head;

    if (kosong_150() == false) {
        while (bantu != NULL) {
            cout << bantu->nama_150 << " " << bantu->umur_150 << endl;
            bantu = bantu->next;
        }

        cout << endl;
    }
    else {
        cout << "KOSONG!" << endl;
    }
}

int main() {
    init_150(); // Inisialisasi Linked List
     // Menjawab pertanyaan A
    cout << "(a). Masukkan data sesuai urutan berikut. (Gunakan insert depan,belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda."<<endl;
    tambahDepan_150("Karin      ", 18);
    tambahDepan_150("Hoshino    ", 18);
    tambahDepan_150("Akechi     ", 20);
    tambahDepan_150("Yusuke     ", 19);
    tambahDepan_150("Michael    ", 18);
    tambahDepan_150("Jane       ", 20);
    tambahDepan_150("John       ", 19);
    tambahDepan_150("Nizal      ", 18);
    tampilkan_150();

    // Menjawab pertanyaan b
    cout << "(b). Hapus data Akechi" << endl;
    hapusTengah_150(6);
    tampilkan_150();

    // Menjawab pertenyaan c
    cout << "(c). Tambahkan data Futaba 18 diantara John dan Jane" << endl;
    tambahTengah_150("Futaba     ", 18, 3);
    tampilkan_150();

    // Menjawab pertanyaan d
    cout << "(d). Tambahkan data Igor 20 di awal" << endl;
    tambahDepan_150 ("Igor       ",20);
    tampilkan_150();

    // Menjawab pertanyaan e 
    cout << "(e). Ubah data Michael menjadi Reyn 18" << endl;
    ubahTengah_150("Reyn       ", 18, 6);
    tampilkan_150();

    //Menjawab pertanyaan f
    cout << "(f). Tampilkan seluruh data "<<endl;
    tampilkan_150();

    return 0;
}