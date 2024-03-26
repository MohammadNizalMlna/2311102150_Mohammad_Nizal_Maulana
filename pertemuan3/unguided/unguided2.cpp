//Mohammad Nizal Maulana - 2311102150
#include<iostream>
#include<iomanip>

using namespace std;

struct node{
    string barang_150;
    int harga_150;
    node *prev;
    node *next;
};
    node *head;
    node *tail;

//prosedur inisiaslisasi 
void Inisialisasi_150(){
    head = nullptr;
    tail = nullptr;
}

//prosedur tambah node
void TambahNode_150(string produk_150, int harga_150, int posisi){
    if(posisi < 1 ){
        cout << "node berada diluar jangkauan" << endl;
    } else if(posisi == 1){
        node *baru = new node;
        baru->barang_150 = produk_150;
        baru->harga_150 = harga_150;
        baru->next = head;
        baru->prev = nullptr;
        if(head != nullptr){
            head->prev = baru;
        } else {
            tail = baru;
        }
        head = baru;
    } else {
        node *current = head;
        node *baru = new node;
        baru->barang_150 = produk_150;
        baru->harga_150 = harga_150;
        baru->next = nullptr;
        baru->prev = nullptr;
        int hitung = 1;
        while(hitung < posisi - 1){
            hitung++;
            current = current->next;
        }
        baru->next = current->next;
        baru->prev = current;
        if(current->next != nullptr){
            current->next->prev = baru;
        } else {
            tail = baru;
        }
        current->next = baru;
    }
}

//prosedur hapus node
void HapusNode_150(int posisi){
    if(posisi < 1){
        cout << "Posisis node berada diluar jangkauan" << endl;
    } else if(posisi == 1){
        node *current = head;  
        head = head->next;     
        if(head != nullptr) {
            head->prev = nullptr;  
        }
        delete current;  
    } else {
        node *current = head;
        int hitung = 1;
        while(hitung < posisi){
            hitung++;
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }
}

// update data
bool UpdateData(string ProdukLama, string ProdukBaru, int HargaBaru){
    node *current = head;
    while (current != nullptr){
        if(current->barang_150 == ProdukLama){
            current->barang_150 = ProdukBaru;
            current->harga_150 = HargaBaru;
            return true;
        }
        current = current->next;
    }
    return false;
}

//hapus semua data
void HapusSemua_150(){
    node *current = head;
    while(current != nullptr){
        node *temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

// tampilkan data
void TampilData_150(){
    node *current = head;
    if(head != nullptr){
        cout << left << setw(20) << "- Nama Produk -" << right << setw(5) << "- Harga -" << endl; 
        while(current != nullptr){
            cout << left << setw(20) << current->barang_150 << right << setw(7) << current->harga_150 << endl; 
            current = current->next;
        }
    }
    cout << endl;
}

int main(){
    int pilih, HargaBaru_150, Posisi;
    string ProdukBaru_150, ProdukLama_150;
    Inisialisasi_150();
    cout << "--- DAFTAR PRODUK SKINCARE ---" << endl;
    TambahNode_150("Hanasui", 30000, 1 );
    TambahNode_150("Wardah", 50000, 1);
    TambahNode_150("Skintific", 100000, 1);
    TambahNode_150("Somethinc", 150000, 1);
    TambahNode_150("Originote", 60000, 1);
    TampilData_150();

    mainMenu:
    cout << "--- TOKO SKINCARE PURWOKERTO ---" << endl;
    cout << "1. Tambah data" << endl;
    cout << "2. Hapus data" << endl;
    cout << "3. Update data" << endl;
    cout << "4. Tambah data urutan tertentu" << endl;
    cout << "5. Hapus data urutan tertentu" << endl;
    cout << "6. Hapus seluruh data" << endl;
    cout << "7. Tampilkan data" << endl;
    cout << "8. exit" << endl;
    cout << "Pilihan anda = "; cin >> pilih;
    cout << endl;

    switch(pilih){
        case 1 :
            cout << "- Tambah Data Produk -" << endl;
            cout << "Masukkan nama produk yang ingin ditambahkan = "; cin >> ProdukBaru_150;
            cout << "Masukkan harga produk = "; cin >> HargaBaru_150;
            TambahNode_150(ProdukBaru_150, HargaBaru_150, 1);
            cout << "Produk telah ditambahkan" << endl;
            cout << endl;
            goto mainMenu;
            break;
        case 2 :
            cout << "- Hapus Data Produk Pertama - " << endl;
            HapusNode_150(1);
            cout << "Data produk ke-1 telah dihapus" << endl;
            cout << endl;
            goto mainMenu;
            break;
        case 3 :
            cout << "- Update Data Produk -" << endl;
            cout << "Masukkan produk lama yang ingin diganti = ";cin >> ProdukLama_150;
            cout << "Masukkan nama produk baru = "; cin >> ProdukBaru_150;
            cout << "Masukkan harga produk baru = "; cin >> HargaBaru_150;
            UpdateData(ProdukLama_150, ProdukBaru_150, HargaBaru_150);
            cout << "Produk telah diupdate" << endl;
            cout << endl;
            goto mainMenu;
            break;
        case 4 :
            cout << "- Tambah Data Urutan Tertentu -" << endl;
            cout << "nama baru produk = "; cin >> ProdukBaru_150;
            cout << "Harga baru produk = "; cin >> HargaBaru_150;
            cout << "posisi produk = "; cin >> Posisi;
            TambahNode_150(ProdukBaru_150, HargaBaru_150, Posisi);
            cout << "Produk baru telah ditambahkan" << endl;
            cout << endl;
            goto mainMenu;
            break;
        case 5 :
            cout << "- Hapus Data Urutan Tertentu -" << endl;
            cout << "masukkan urutan produk yang ingin dihapus = "; cin >> Posisi;
            HapusNode_150(Posisi);
            cout << "produk urutan ke-" << Posisi << " telah dihapus" << endl;
            cout << endl;
            goto mainMenu;
            break;
        case 6 :
            cout << "- Hapus Seluruh Data -" << endl;
            HapusSemua_150();
            cout << "seluruh data telah dihapus" << endl;
            cout << endl;
            goto mainMenu;
            break;
        case 7 :
            cout << "- Tampilkan Data -" << endl;
            TampilData_150();
            cout << endl;
            goto mainMenu;
            break;
        case 8 :
            cout << "Anda keluar" << endl;
            return 0;
        default :
            cout << "pilihan tak tersedia di menu" << endl;
            cout << endl;
            goto mainMenu;
            break;
    }    
}