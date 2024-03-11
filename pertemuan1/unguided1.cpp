/*
1.  Buatlah program menggunaka tipe data primitif minimal dua fungsi dan bebas.
    menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi data primitif!.
*/
/*
oleh Mohammad Nizal Maulana - 2311102150
*/
#include <iostream>
using namespace std;

// fungsi menghitung luas Persegi
int menghitung_luas_persegi(int sisi){
    return sisi * sisi;
}

// fungsi menghitung keliling segitiga
int menghitung_keliling_segitiga(int a,int b,int c){
    return a+b+c;
}
int main(){
    //menggunakan fungsi menghitung luas persegi
    int sisi = 150;
    int luas = menghitung_luas_persegi(sisi);
    cout << "Luas persegi dengan sisi "<<sisi<< " adalah : "<< luas <<endl; 

    // menggunakan fungsi menghitung keliling segitiga
    int a = 2;
    int b = 5;
    int c = 11;
    int keliling = menghitung_keliling_segitiga(a,b,c);
    cout << "keliling segitiga dengan sisi a "<< a << " sisi b "<< b <<" dan sisi c "<< c << " adalah : "<< keliling <<endl;
    return 0;
}