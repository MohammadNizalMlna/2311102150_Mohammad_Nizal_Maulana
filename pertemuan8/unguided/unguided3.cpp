#include <iostream>

using namespace std;

// Fungsi untuk menghitung jumlah angka 4 dalam array menggunakan sequential search
int HitungAngka4_150(int arr_150[], int ukuran_150){
    int hitung_150 = 0;
    for(int i=0; i<ukuran_150; i++){
        if (arr_150[i] == 4){
            hitung_150++;
        }
    }
    return hitung_150;
}

int main(){
    int angka_150[] = {9,4,1,4,7,10,5,4,12,4};
    int ukuranData_150 = 10; // ukuran array didefinisikan secara manual

    int Angka4_150 = HitungAngka4_150(angka_150,ukuranData_150);

    cout << "9,4,1,4,7,10,5,4,12,4"<<endl;
    cout << "Jumlah angka 4 dalam data tersebut adalah: " << Angka4_150 << endl;

    return 0;
}