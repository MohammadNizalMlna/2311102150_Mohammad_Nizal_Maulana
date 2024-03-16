/*
Mohammad NNizal Maulana - 2311102150
*/
#include <iostream>
using namespace std;

int main(){
    int x_150,y_150,z_150;
    cout << "masukkan jumlah elemen untuk dimensi x : "; //Meminta user memasukkan ukuran array x
    cin >> x_150;
    cout << "Masukkan jumlah elemen untuk dimensi y : "; //Meminta user memasukkan ukuran array y
    cin >> y_150;
    cout << "Masukkan jumlah elemen untuk dimensi z : "; //Meminta user memasukkan ukuran array z
    cin >> z_150;

    // Mendeklarasikan array 3 dimensi
    int array3D_150 [x_150][y_150][z_150];

    //Memasukkan nilai ke dalam array
    cout << "Masukkan nilai untuk setiap elemen array: "<<endl;
    for (int i=0; i < x_150; i++){
        for(int j=0; j < y_150; j++){
            for(int k=0; k < z_150; k++){
                cout << "Elemen ["<< i << "][" << j <<"][" << k << "]: ";
                cin >> array3D_150[i][j][k];
            }
        }
    }
    //Menampilkan nilai dari array3D_150
     cout << "Nilai yang dimasukkan ke dalam array:  "<<endl;
    for (int i=0; i < x_150; i++){
        for(int j=0; j < y_150; j++){
            for(int k=0; k < z_150; k++){
                cout << "Elemen ["<< i << "][" << j <<"][" << k << "]: ";
                cin >> array3D_150[i][j][k];
            }
        }
    }
     cout << endl;
    // Tampilan array3D_150
    for (int x = 0; x < x_150; x++)
    {
        for (int y = 0; y < y_150; y++)
        {
            for (int z = 0; z < z_150; z++)
            {
                cout << array3D_150[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}