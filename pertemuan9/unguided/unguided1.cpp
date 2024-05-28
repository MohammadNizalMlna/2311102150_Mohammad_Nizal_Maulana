#include <iostream>
#include <string>

using namespace std;

int main(){
    int jumlahSimpul_150; // Deklarasi variaber int untuk menyimpan jumlah simpul
    cout << "Masukan Jumlah simpul: ";
    cin >> jumlahSimpul_150;

    string namaSimpul_150[jumlahSimpul_150]; // Deklarasi array string untuk menyimpan nama-nama simpul
    cout << "masukan nama simpul " <<endl;
    for(int i=0;i<jumlahSimpul_150;i++){
        cout << "Simpul " << i+1 << " : ";
        cin >> namaSimpul_150[i];
    } 

    int graph[jumlahSimpul_150][jumlahSimpul_150];// Deklarasi array 2D untuk menyimpan matriks ketetanggaan
    for(int i=0;i<jumlahSimpul_150;i++){
        for(int j=0;j<jumlahSimpul_150;j++){
            if(i==j){
                graph[i][j] = 0;
            }else{
                cout << namaSimpul_150[i] << " --> " <<namaSimpul_150[j] << " = ";
                cin >> graph[i][j];
            }
        }
    }

    cout << endl;
    cout << "Matriks keteanggaan: " <<endl;
    cout << "     ";
    for(int i=0;i<jumlahSimpul_150;i++){
        cout << namaSimpul_150[i] << " ";
    }
    cout << endl;

    for(int i=0;i<jumlahSimpul_150;i++){
        cout << namaSimpul_150[i] << " ";// cetak nama setiap simpul sebagai header baris
        for(int j=0; j<jumlahSimpul_150;j++){
            cout << graph[i][j] << " ";// Cetak nilai setiap elemen dalam matriks
        }
        cout <<endl;
    }
    return 0;
}