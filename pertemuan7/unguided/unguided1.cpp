#include <iostream>
using namespace std;

// Struktur data untuk setiap elemen di linked list
struct Node{
    string data_150;
    Node* next;
};

// Pointer yang menunjuk ke front dan back linkedlist
Node* front = nullptr;
Node* back = nullptr;

//menambah data kebelakang antrian
void TambahData_150(string nama_150){
    Node* baru = new Node;
    baru->data_150 = nama_150;
    baru->next = nullptr;

    if(back == nullptr){
        front = baru;
        back = baru;
    }else{
        back->next = baru;
        back = baru;
    }
}

//Mengurangi data dari depan antrian
void KurangiAntrian_150(){
    if (front == nullptr){
        cout << "Antrian masih kosong" <<endl;
    }else{
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

//Menghitung banyak antrian
int jumlahAntrian_150(){
    int count_150 = 0;
    Node* current_150 = front;
    while(current_150 != nullptr){
        count_150++;
        current_150 = current_150->next;
    }
    return count_150;
}

//Menghapus seluruh antrian
void ClearAll_150(){
    while(front != nullptr){
        Node* temp = front;
        front = front->next;
        delete temp;
    }
    back = nullptr;
}

//Menampilkan antrian
void TampilkanAntrian_150(){
    cout << "Data antrian = " << endl;
    Node* current = front;
    int i = 1;
    int MaksimalAntrian_150 = 5;
    while (current != nullptr){
        cout << i << ". " << current->data_150 << endl;
        current = current->next;
        i++;
    }
    for (; i <= MaksimalAntrian_150; i++){
        cout << i << ". " << "(Kosong)" <<endl;
    }
}

int main(){
    //Menambah 3 data nama kedalam antria
    TambahData_150("Alya");
    TambahData_150("Kiki");
    TambahData_150("Artika");

    //Menampilkan data yang sudah ditambahkan
    TampilkanAntrian_150();

    //Mengurangi data
    KurangiAntrian_150();

    //Menampilkan data setelah dikurangi
    TampilkanAntrian_150();

    //Menghapus seluruh antrian
    ClearAll_150();

    //Menampilkan data setelah dihapus
    TampilkanAntrian_150();

    return 0;

}