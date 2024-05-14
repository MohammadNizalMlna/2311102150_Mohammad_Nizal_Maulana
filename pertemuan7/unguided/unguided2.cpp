#include<iostream>

using namespace std;

//Deklarasi struct node
struct node{ 
    string Mahasiswa_150;
    string NIM_150;
    node *next;
};
    node *front; //Deklarasi node front
    node *back; //Deklarasi node back

//Prosedur inisialisasi node front dan back sebagai NULL
void Inisialisasi_150(){ 
    front = NULL;
    back = NULL;
}

//Untuk mengecek apakah queue kosong atau tidak
bool isEmpty_150(){
    if (front == 0){
        return true; 
    } else {
        return false;
    }
}

//Prosedur untuk menambah data pada antrian
void TambahAntrian_150(string Nama_150, string NIM_150){
    node *baru = new node;
    baru->Mahasiswa_150 = Nama_150; 
    baru->NIM_150 = NIM_150; 
    baru->next = NULL; 
    if(isEmpty_150() == true){ //jika antrian kosong, maka lanjutkan
        front = back = baru; 
        back->next = NULL;
    } else if(isEmpty_150() == false){ //jika antrian tidak kosong, maka lanjutkan
        back->next = baru; 
        back = baru; 
    }
}

//Prosedur untuk mengurangi antrian 
void KurangiAntrian_150(){
    node *hapus; 
    if(isEmpty_150() == false){ //jika antrian tidak kosong, maka lanjutkan
        if(front->next != NULL){ 
            hapus = front; 
            front = front->next; 
            delete hapus; 
        } else { //jika tidak ada node selanjutnya setelah antrian pertama, maka lanjutkan
            front = back = NULL; 
        }
    }
}

//Fungsi untuk menghitung jumlah antrian
int HitungAntrian_150(){
    node *hitung; 
    hitung = front; 
    int jumlah_150 = 0; 
    while(hitung != NULL){ 
        hitung = hitung->next; 
        jumlah_150++; 
    }
    return jumlah_150; 
}

//Prosedur untuk menghapus seluruh antrian
void HapusSemuaAntrian_150(){
    node *hapus, *bantu;
    bantu = front; 
    while(bantu != NULL){ 
        hapus = bantu; 
        bantu = bantu->next; 
        delete hapus; 
    }
    front = back = NULL; 
}

//Prosedur untuk menampilkan antrian
void TampilkanAntrian_150(){
    node *bantu; 
    bantu = front; 
    if(isEmpty_150() == true){  
        cout << "Antrian Masih Kosong!" << endl; 
    } else if(isEmpty_150() == false){ 
        cout << "List Antrian" << endl; 
        int NomorAntrian_150 = 1; 
        while(bantu != NULL){ 
            cout << NomorAntrian_150 << ". " << bantu->Mahasiswa_150 << " - " << bantu->NIM_150 << endl; 
            bantu = bantu->next; 
            NomorAntrian_150++; 
        }
    }
    cout << endl;
}

int main(){
    string Mahasiswa_150, NIM_150; 
    int Pilih;
    //Menampilkan pilihan menu
    Menu:
    cout << "----- MENU ANTRIAN MAHASISWA -----" << endl; 
    cout << "1. Tambah antrian" << endl;
    cout << "2. Kurangi antrian" << endl;
    cout << "3. Hitung jumlah antrian" << endl;
    cout << "4. Hapus antrian" << endl;
    cout << "5. Lihat antrian" << endl;
    cout << "6. Keluar" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Pilihan Anda [1-6] = ";
    cin >> Pilih;
    cout << endl;
    switch(Pilih){ 
        case 1: 
            cout << "----- Tambah antrian -----" << endl;
            cout << "Masukkan nama mahasiswa = ";
            cin >> Mahasiswa_150;
            cout << "Masukkan NIM mahasiswa = ";
            cin >> NIM_150;
            TambahAntrian_150(Mahasiswa_150, NIM_150); //Memanggil prosedur TambahAntrian_150
            cout << "Data Mahasiswa berhasil dimasukan" << endl;
            cout << endl;
            goto Menu;
            break;
        case 2: 
            cout << "--- Kurangi Antrian ---" << endl;
            if(isEmpty_150() == true){ 
                cout << "Belum ada antrian yang masuk!" << endl;
            } else { 
                KurangiAntrian_150(); //Memanggil prosedur KurangiAntrian_150
                cout << "Antrian telah dikurangi "<<endl;
            }
            cout << endl;
            goto Menu;
            break;
        case 3: 
            cout << "--- Jumlah Antrian ---" << endl;
            cout << "Antrian yang telah disimpan " << HitungAntrian_150() << endl;// Memanggil fungsi HitungAntrian_150 
            cout << endl;
            goto Menu;
            break;
        case 4:
            HapusSemuaAntrian_150();// Memanggil prosedur HapusSemuaAntrian_150
            cout << "Antrian berhasil dihapus" <<endl;
            cout << endl;
            goto Menu;
            break;
        case 5: 
            TampilkanAntrian_150(); //Memanggil prosedur TampilkanAntrian_150
            cout << endl;
            goto Menu;
            break;
        case 6:
            cout << "Anda keluar dari program" << endl;
            cout << endl;
            return 0;
            break;
        default: 
            cout << "Pilihan anda tidak ada dalam menu" << endl;
            cout << endl;
            goto Menu;
            break;
    }
}