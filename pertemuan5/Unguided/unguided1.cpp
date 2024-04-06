#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Struck untuk setiap mahasiswa
struct Mahasiswa{
    string nama_150;
    string nim_150;
    int nilai_150;
};

//struck untuk setiap node dalam hash table
struct HashNode{
    Mahasiswa data;
    HashNode* next;
    HashNode(const Mahasiswa& data) : data(data), next(nullptr){}
};

//class hash table
class HashTable{
    private:
    static const int TABLE_SIZE = 10;
    vector<HashNode*>table[TABLE_SIZE];

    // Fungsi hashFunc untuk menghasilkan indeks dari NIM
    int hashFunc_150(const string& nim_150){
        int hashVal = 0;
        for(char c : nim_150){
            hashVal += c;
        }
        return hashVal % TABLE_SIZE;
    }

    public:
    // untuk menambahkan data mahasiswa kedalam hash table
    void insert_150(const Mahasiswa& mahasiswa){
        int index = hashFunc_150(mahasiswa.nim_150);
        HashNode* newNode = new HashNode(mahasiswa);
        newNode->next = table[index].size() > 0 ? table[index][0] : nullptr;
        table[index].insert(table[index].begin(),newNode);
    }
    //fungsi menghapus data mahasiswa  berdasarkan NIM
    void hapus_150(const string& nim){
        int index = hashFunc_150(nim);
        for(size_t i=0; i<table[index].size(); i++){
            if(table[index][i]->data.nim_150 == nim){
                delete table[index][i];
                table[index].erase(table[index].begin()+i);
                return;
            }
        }
        cout << "Data mahasiswa dengan NIM " << nim << " tidak dapat ditemukan " <<endl;
    }

    //fungsi untuk mencari data mahasiswa berdasarkan NIM
    Mahasiswa* searchByNIM(const string& nim){
        int index = hashFunc_150(nim);
        for(size_t i = 0; i <table[index].size(); i++){
            if(table[index][i]->data.nim_150 == nim){
                return &(table[index][i]->data);
            }
        }
        return nullptr;
    }

    // Fungsi mencari data mahasiswa berdasarkan rentang nilai
    vector<Mahasiswa*> searchBYRange(int minNilai, int maxNilai){
        vector<Mahasiswa*> result;
        for(int i = 0; i < TABLE_SIZE; i++){
            for(size_t j = 0; j < table[i].size(); j++){
                if(table[i][j]->data.nilai_150 >= minNilai && table[i][j]->data.nilai_150 <= maxNilai){
                    result.push_back(&(table[i][j]->data));
                }
            }
        }
        return result;
    }

};

int main(){
    HashTable hashTable_150;
    int pilih_150;

    menu:
    cout << "Program Hash Table Sederhana" <<endl;
    cout << "1. Tambah data Mahasiswa"<<endl;
    cout << "2. Hapus data Mahasiswa"<<endl;
    cout << "3. Cari data Mahasiswa berdasarkan NIM"<<endl;
    cout << "4. Cari data Mahasiswa berdsarkan rentang nilai(80 - 90)"<<endl;
    cout << "5. Keluar"<<endl;
    cout << "Pilih menu diatas : "; cin >> pilih_150;
    cout << endl;

    switch(pilih_150){
        case 1 :{
            Mahasiswa mhs;
            cout << "-TAMBAH DATA MAHASISWA-"<<endl;
            cout << "Masukkan Nama Mahasiswa : ";
            cin >> mhs.nama_150;
            cout << "Masukkan NIM Mahasiswa : ";
            cin >> mhs.nim_150;
            cout << "Masukkan Nilai Mahasiswa : ";
            cin >> mhs.nilai_150;
            hashTable_150.insert_150(mhs);
            goto menu;
            break;
        }
        case 2 :{
            string nim;
            cout << "-HAPUS DATA MAHASISWA-"<<endl;
            cout << "Masukkan NIM untuk menghapus data Mahasiswa : ";
            cin >> nim;
            hashTable_150.hapus_150(nim);
            cout << "Data Mahasiswa dengan NIM " << nim << " telah dihapus"<<endl;
            goto menu;
            break;
        }
        case 3 :{
            string nim;
            cout << "-CARI DATA MAHASISWA BERDASARKAN NIM-"<<endl;
            cout << "Masukkan NIM untuk mencari data Mahasiswa: ";
            cin >> nim;
            Mahasiswa* result = hashTable_150.searchByNIM(nim);
            if(result != nullptr){
                cout << "Data ditemukan!!"<<endl;
                cout << "Nama: " << result->nama_150 << "\nNIM: " << result->nim_150 << "\nNilai: " << result->nilai_150 <<endl;
            }else{
                cout << "Data mahasiswa dengan NIM " << nim << "Tidak dapat ditemukan"<<endl;
            }
            goto menu;
            break;
        }
        case 4 :{
            int minNilai = 80, maxNilai = 90;
            cout << "-CARI DATA MAHASISWA BERDASARKAN RENTANG NILAI (80 - 90)" <<endl;
            vector<Mahasiswa*> result = hashTable_150.searchBYRange(minNilai, maxNilai);
            if(result.size() > 0){
                cout << "Data mahasiswa dalam rentang nilai " << minNilai << " hingga " << maxNilai << ":\n";
                for(Mahasiswa* mhs : result){
                    cout << "Nama Mahasiswa: " << mhs->nama_150 << "\tNIM: " << mhs->nim_150 << "\tNilai: "<< mhs->nilai_150 <<endl;
                }
            }else{
                cout << "Tidak ada Mahasiswa dalam rentang nilai tersebut "<<endl;
            }
            goto menu;
            break;
        }
        case 5:
            cout << "Anda keluar dari program"<<endl;
            break;
        default:
            cout << "pilihan tidak ada dalam menu";
            goto menu;
    }
    return 0;
}