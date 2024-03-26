#include <iostream>
#include <iomanip>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    string nama_150;
    int usia_150;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init_150()
{
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah linked list kosong
bool kosong()
{
    return head == NULL;
}

// Menghitung jumlah Node dalam linked list
int listNode_150()
{
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Menambahkan node di depan
void inputdepan_150(string nama, int usia)
{
    // membuat Node baru
    Node *baru = new Node;
    baru->nama_150 = nama;
    baru->usia_150 = usia;
    baru->next = NULL;
    if (kosong())
    {
        head = tail = baru;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
// Menambahkan node di tengah
void inputtengah_150(string nama, int usia, int posisi)
{
    if (posisi < 1 || posisi > listNode_150() + 1)
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        inputdepan_150(nama, usia);
    }
    else
    {
        Node *baru = new Node();
        baru->nama_150 = nama;
        baru->usia_150 = usia;
        Node *bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Menambahkan node di belakang
void inputbelakang_150(string nama, int usia)
{
    // membuat Node baru
    Node *baru = new Node;
    baru->nama_150 = nama;
    baru->usia_150 = usia;
    baru->next = NULL;

    if (kosong())
    {
        head = tail = baru;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

// Hapus Node di depan
void hapusDepan_150()
{
    if (!kosong())
    {
        Node *hapus = head;
        if (head == tail)
        {
            head = tail = NULL;
        }
        else
        {
            head = head->next;
        }
        delete hapus;
    }
    else
    {
        cout << "Tidak ada list yang tersedia" << endl;
    }
}

// Hapus Node di tengah
void hapusTengah_150(int posisi)
{
    if (posisi < 1 || posisi > listNode_150())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        hapusDepan_150();
    }
    else
    {
        Node *bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        Node *hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

// Hapus Node di belakang
void hapusBelakang_150()
{
    if (!kosong())
    {
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node *bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            delete tail;
            tail = bantu;
            tail->next = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

// Update Node di tengah
void ubahTengah_150(string nama, int usia, int posisi)
{
    if (posisi < 1 || posisi > listNode_150())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else
    {
        Node *bantu = head;
        int nomor = 1;
        while (nomor < posisi)
        {
            bantu = bantu->next;
            nomor++;
        }
        bantu->nama_150 = nama;
        bantu->usia_150 = usia;
    }
}

// Update Node di belakang
void ubahBelakang_150(string nama, int usia)
{
    if (!kosong())
    {
        tail->nama_150 = nama;
        tail->usia_150 = usia;
    }
    else
    {
        cout << "Tidak ada list yang tersedia" << endl;
    }
}

// Hapus semua Node dalam linked list
void hapusList_150()
{
    Node *bantu = head;
    while (bantu != NULL)
    {
        Node *hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan semua Node dalam linked list
void Tampilan_150()
{
    Node *bantu = head;
    cout << left << setw(10) << "Nama" << right << setw(2) << "Usia" << endl;
    if (!kosong())
    {
        while (bantu != NULL)
        {
            cout << left << setw(10) << bantu->nama_150 << right << setw(2) << bantu->usia_150 << endl;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "Tidak ada data yang tersedia!" << endl;
    }
}

int main()
{
    init_150();
    cout << "single linked list" << endl;

    // Menambahkan data awal

    inputdepan_150("Karin", 18);
    inputdepan_150("Hoshino", 18);
    inputdepan_150("Akechi", 20);
    inputdepan_150("Yusuke", 19);
    inputdepan_150("Michael", 18);
    inputdepan_150("Jane", 20);
    inputdepan_150("John", 19);

    int pilih;
    do
    {
        // Menu utama program
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Masukkan pilihanmu: ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
        {
            string nama_150;
            int usia_150;
            cout << "Masukkan nama: ";
            cin >> nama_150;
            cout << "Masukkan usia: ";
            cin >> usia_150;
            inputdepan_150(nama_150, usia_150);
            break;
        }
        case 2:
        {
            string namaHapus;
            cout << "Masukkan nama data yang ingin dihapus: ";
            cin >> namaHapus;
            Node *temp = head;
            int posisi = 1;
            while (temp != NULL && temp->nama_150 != namaHapus)
            {
                temp = temp->next;
                posisi++;
            }
            if (temp != NULL)
            {
                hapusTengah_150(posisi);
                cout << "Data dengan nama " << namaHapus << " berhasil dihapus." << endl;
            }
            else
            {
                cout << "Data dengan nama " << namaHapus << " tidak ditemukan." << endl;
            }
            break;
        }
        case 3:
        {
            string namaLama, namaBaru;
            int usiaBaru;
            cout << "Masukkan nama yang ingin diupdate: ";
            cin >> namaLama;
            cout << "Masukkan nama baru: ";
            cin >> namaBaru;
            cout << "Masukkan usia baru: ";
            cin >> usiaBaru;
            Node *temp = head;
            int posisi = 1;
            while (temp != NULL && temp->nama_150 != namaLama)
            {
                temp = temp->next;
                posisi++;
            }
            if (temp != NULL)
            {
                ubahTengah_150(namaBaru, usiaBaru, posisi);
            }
            else
            {
                cout << "Data tidak ditemukan" << endl;
            }
            break;
        }
        case 4:
        {
            string nama, namabaru;
            int usia;
            cout << "Masukkan nama: ";
            cin >> nama;
            cout << "Masukkan usia: ";
            cin >> usia;
            cout << "Masukkan nama setelah data baru: ";
            cin >> namabaru;
            Node *temp = head;
            int posisi = 1;
            while (temp != NULL && temp->nama_150 != namabaru)
            {
                temp = temp->next;
                posisi++;
            }
            if (temp != NULL)
            {
                inputtengah_150(nama, usia, posisi + 1);
            }
            else
            {
                cout << "Data tidak ditemukan" << endl;
            }
            break;
        }
        case 5:
        {
            int posisi;
            cout << "Masukkan posisi data yang ingin dihapus: ";
            cin >> posisi;
            hapusTengah_150(posisi);
            break;
        }
        case 6:
        {
            hapusList_150();
            break;
        }
        case 7:
        {
            Tampilan_150();
            break;
        }
        case 8:
        {
            cout << "Terima kasih telah menggunakan program ini!" << endl;
            break;
        }
        default:
        {
            cout << "Pilihan tidak valid" << endl;
            break;
        }
        }
    } while (pilih != 8);

    return 0;
}