#include <iostream>

using namespace std;

// Fungsi untuk menghitung jumlah angka vokal dalam sebuah kalimat (menggunakan Sequential Search)
int hitungVokal_SequentialSearch_150(int arr[], int cariHurufVokal[], int &IndexVokal) {
    int temukan_150 = 0;
    IndexVokal = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        int ch_150 = arr[i];
        if (ch_150 == 'a' || ch_150 == 'i' || ch_150 == 'u' || ch_150 == 'e' || ch_150 == 'o' ||
            ch_150 == 'A' || ch_150 == 'I' || ch_150 == 'U' || ch_150 == 'E' || ch_150 == 'O') {
            cariHurufVokal[IndexVokal++] = ch_150;
            temukan_150++;
        }
    }
    cariHurufVokal[IndexVokal] = '\0'; // Mengakhiri string dengan null terminator
    return temukan_150;
}

int main() {
    int masukankalimat[100];
    int cariHurufVokal[100];
    int IndexVokal;

    cout << "Masukkan kalimat: ";
    char input[100];
    cin.getline(input, 100);

    // mengkonvert char array ke int array
    int i = 0;
    while (input[i] != '\0') {
        masukankalimat[i] = input[i];
        i++;
    }
    masukankalimat[i] = '\0'; // null terminator untuk int array

    int hitungHurufVokal_150 = hitungVokal_SequentialSearch_150(masukankalimat, cariHurufVokal, IndexVokal);

    cout << "Jumlah huruf vokal dalam kalimat: " << hitungHurufVokal_150 << endl;
    cout << "Huruf vokal yang ditemukan: ";
    for (int j = 0; j < IndexVokal; j++) {
        cout << static_cast<char>(cariHurufVokal[j]);
    }
    cout << endl;

    return 0;
}
