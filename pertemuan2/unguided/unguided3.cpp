/*
Mohammad Nizal Maulana - 2311102150
*/
#include <iostream>
using namespace std;
int main(){
    int jmlhElemen_150;
    int arr[jmlhElemen_150]; // Mendeklarasikan array dengan ukuran yang dimasukan user
    // User memasukka jumlah elemen array
    int pilih_150; // untuk memilih menu
    cout << "Masukkan jumlah elemen array: ";
    cin >> jmlhElemen_150;

    //Memasukkan nilai untuk setiap elemen array
    cout << "Masukkan nilai untuk setiap elemen array: "<<endl;
    for(int i=0;i<jmlhElemen_150;++i){
        cout<< "Elemen "<< i + 1<< " : ";
        cin >> arr[i];
    }
    //Menampilkan menu
    cout << "----MENU----"<<endl;
    cout << "1.Mencari Nilai Maksimum\n ";
    cout << "2.Mencari Nilai Minimum\n ";
    cout << "3.Mencari Nilai Rata-rata\n ";
    cout << "Pilih menu : "; 
    cin >> pilih_150;
    // Melakukan operasi sesuai dengan pilihan  user
    switch(pilih_150){
        case 1:{
            //Mencari nilai maksimum
            int max_150 = arr[0];
            for(int i=1;i<jmlhElemen_150;i++){
                if (arr[i]>max_150){
                    max_150 = arr[i];
                }
            }
            cout << "Nilai maksimumnya adalah: "<< max_150 <<endl;
            break;
        }
        case 2:{
            //Mencari nilai minimum
            int min_150 = arr[0];
            for(int i=1;i<jmlhElemen_150;i++){
                if(arr[i]<min_150){
                    min_150=arr[i];
                }
            }
            cout << "Nilai Minimumnya adalah: "<< min_150 << endl;
            break;
        }
        case 3:{
            //Mencari nilai Rata-rata
            double rta_150 = 0;
            for(int i=0;i<jmlhElemen_150;i++){
                rta_150 += arr[i];
            }
            double rataRata_150 = rta_150 / jmlhElemen_150;
            cout << "Nilai Rata-ratanya adalah: "<< rataRata_150 << endl;
            break;
        }
        default:
            cout << "Pilihan anda tidak tersedia"<<endl;
    }
    return 0;
}