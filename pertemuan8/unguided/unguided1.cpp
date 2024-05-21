#include <iostream>

using namespace std;

// Prosedur untuk mengurutkan kalimat secara manual (menggunakan bubble sort)
void bubbleSort_150(char arr[], int n){
    for (int i=0; i < n - 1; i++){
        for(int j=0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                //temukan elemen
                char temp_150 = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp_150;
            }
        }
    }
}

// Fungsi binary search untuk mencari karakter pada kalimat yang di inputkan

int binarySearch_150(const char arr[], int kiri_150, int kanan_150, char cariHuruf_150){
    while (kiri_150 <= kanan_150){
        int tengah_150 = kiri_150 + (kanan_150 - kiri_150) / 2;

        if(arr[tengah_150] == cariHuruf_150)
        return tengah_150; // karakter ditemukan dalam indeks tengah_150
        if (arr[tengah_150] < cariHuruf_150)
        kiri_150 = tengah_150 + 1; // pindah ke kanan
        else
        kanan_150 = tengah_150 - 1; // pindah ke kiri
    }

    return -1; // huruf tidak ditemukan
}

int main() {
    char masukan_150[100];
    char cariHuruf_150;

    cout << "Masukkan kalimat: ";
    cin.getline(masukan_150,100);

    cout << "Masukkan Huruf yang dicari dalam kalimat: ";
    cin >> cariHuruf_150;

    //Menghitung panjang kalimat
    int length_150 = 0;
    while(masukan_150[length_150] != '\0'){
        length_150++;
    }

    //Mengurutken kalimat
    bubbleSort_150(masukan_150, length_150);

    //Menampilkan kalimat yang sudah diurutkan
    cout << "Kalimat diurutkan (a-z): " << masukan_150 << endl;

    //Mencari huruf yang dimasukan dengan binnary search
    int result_150 = binarySearch_150(masukan_150,0,length_150-1,cariHuruf_150);
    if(result_150 != -1){
        cout << "Huruf : " << cariHuruf_150 << " ditemukan pada indeks ke- " << result_150 << " Pada kalimat yang telah diurutkan"<<endl;
    }else{
        cout << "Huruf " << cariHuruf_150 << " Tidak ditemukan dalam kalimat "<<endl;
    }
    return 0;
}