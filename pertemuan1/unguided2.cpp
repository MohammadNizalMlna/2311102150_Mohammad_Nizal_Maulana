/*
Mohammad Nizal Maulana - 2311102150
*/
#include <iostream>
using namespace std;

// Deklarasi class mahasiswa_2150 yang berisi nama string, nim int, dan tb(tunggi badan) float dalam akses public
class Mahasiswa_2150 {
    public:
    // Data member (variabel)
    string nama_2150;
    int nim_2150;
    float tb_2150;

    // Fungsi member (metode)
    void display() {
        cout << "Nama: " << nama_2150 << endl;
        cout << "NIM: " << nim_2150 << endl;
        cout << "tingi badan:  " << tb_2150 << " cm " << endl;
    }
};

// Deklarasi struct
struct jenis_motor {
    // Data member (variabel)
    string nama_motor;
    int tahun_rilis;
    float kapasitas_tangki;

    // Tidak dapat memiliki fungsi member (metode)
};

int main() {
    // deklarasi Menggunakan class dengan fungi
    Mahasiswa_2150 mhs1;
    mhs1.nama_2150 = "Mohammad Nizal Maulana";
    mhs1.nim_2150 = 231110250;
    mhs1.tb_2150 = 185.2;
    cout << "Data Mahasiswa:" << endl;
    mhs1.display();
    cout << endl;

    // deklarasi Menggunakan struct
    jenis_motor motor1;
    motor1.nama_motor = "Supra X 125";
    motor1.tahun_rilis = 2005;
    motor1.kapasitas_tangki = 5.6 ;
    cout << "Data motor:" << endl;
    cout << "Nama motor: " << motor1.nama_motor << endl;
    cout << "tahun rilis: " << motor1.tahun_rilis << endl;
    cout << "Kapasitas tangki: " << motor1.kapasitas_tangki << " Liter "<< endl;

    return 0;
}