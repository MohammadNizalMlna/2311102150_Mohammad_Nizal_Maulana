#include <iostream>
#include <string>
#include <stack>

using namespace std;

void balikKalimat_150(string kalimat_150)
{
    stack<char> b;

    // Memasukkan karakter kalimat ke dalam stack
    for (char c : kalimat_150)
    {
        b.push(c);
    }

    // Mengambil karakter dari stack dan menyimpannya kembali ke dalam variabel kalimat yang dibalik
    string kalimatDibalik_150;
    while (!b.empty())
    {
        kalimatDibalik_150 += b.top();
        b.pop();
    }

    // Menampilkan kalimat yang dibalik
    cout << kalimatDibalik_150 << endl;
}

int main()
{
    string kalimat_150;

    // Meminta masukan kalimat dari pengguna
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat_150);

    // Memastikan kalimat minimal memiliki 3 kata
    int kata = 1;
    for (char c : kalimat_150){
        if (c == ' '){
            kata++;
        }
    }
    if (kata < 3){
        cout << "Kalimat harus terdiri minimal 3 kata"<<endl;
    }else{
        // membalik kalimat dan menampilkan hasil kalimat yang dibalik
        balikKalimat_150(kalimat_150);
    }
    return 0;
}
