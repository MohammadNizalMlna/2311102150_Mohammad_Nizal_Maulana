/*
Mohammad Nizal Maulana - 2311102150
*/
#include <iostream>
using namespace std;

int main(){
    int panjangArray_150;

    // masukkan panjang array
    cout << "Masukkan panjang array: ";
    cin >> panjangArray_150;

    // Masukkan elemen-elemen array
    int Elemen_150[panjangArray_150];
    for(int i=0; i<panjangArray_150; i++){
        cout << "Masukkan nilai array indeks ke- "<< i << " = ";
        cin >> Elemen_150[i];
    }
    cout << endl;
    // Output Data Array
    cout << "Data Array = ";
    for(int i=0; i<panjangArray_150;i++){   
        cout << Elemen_150[i] << " "<<ends;
    }
    cout << endl;

    //Output Array bilangan genap
    cout << "Nomor Genap = ";
    for(int i =0; i < panjangArray_150; i++){
        if(Elemen_150[i] % 2 == 0){ //misal nilai array Elemen_150 dibagi 2 akan memiliki sisa nilai 0, maka output akan menampilkan
            cout << Elemen_150[i] << " , "<<ends;
        }
    }
    cout << endl;

    //Output Array bilangan ganjil
    cout << "Nomor Ganjil = ";
    for(int i = 0; i < panjangArray_150; i++){ // Misal nilai array Elemen_150 dibagi 2 akan memiliki sisa nilai 1, maka output akan menampilkan
        if(Elemen_150[i] % 2 == 1){
            cout << Elemen_150[i] << " , "<<ends;
        }
    }
    cout << endl;

    return 0;
}