/*
Mohammad Nizal Maulana - 2311102150
*/
#include <iostream>
#include <map> //Menggunakan library map agar bisa menggunakan fungsi map pada program ini
using namespace std;

int main(){
    map<string, float> tinggi_badan; //membuat map dengan key bertipe string dan value bertipe float

    //menambahkan data kedalam map
    tinggi_badan["Nizal"] = 185.2;
    tinggi_badan["Alif"] = 198.6;
    tinggi_badan["Ilham"] = 177;
    tinggi_badan["Bowo"] = 181.7;

    //mengakses dan mencetak nilai dari map
    cout << "tinggi badan Nizal : "<< tinggi_badan["Nizal"] << " Cm "<< endl;
    cout << "tinggi badan Alif  : "<< tinggi_badan["Alif"] << " Cm "<< endl;
    cout << "tinggi badan Ilham : "<< tinggi_badan["Ilham"] << " Cm "<< endl;
    cout << "tinggi badan Bowo  : "<< tinggi_badan["Bowo"] << " Cm "<< endl;

    return 0;
}