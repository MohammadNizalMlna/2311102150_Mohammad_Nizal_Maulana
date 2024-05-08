#include <iostream>

using namespace std;

// Menentukan apakah kata adalah palindrom atau tidak
bool cekPalindrom_150(string kata_150) {
    int length = kata_150.length();
    for(int i = 0; i < length / 2; i++) {
        if(tolower(kata_150[i]) != tolower(kata_150[length - i - 1])) {
            return false;
        }
    }
    return true;
}

int main() {
    string masukanKalimat_150;
    cout << "----CEK KATA PALINDROM----"<<endl;
    cout << "Masukkan Kata: ";
    cin >> masukanKalimat_150;

    if(cekPalindrom_150(masukanKalimat_150)) {
        cout << "Kata tersebut adalah Palindrom" << endl;
    } else {
        cout << "Kata tersebut bukan Palindrom" << endl;
    }
    return 0;
}
