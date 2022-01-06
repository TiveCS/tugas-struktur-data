#include <iostream>

using namespace std;

void menu(){

    int select = -1;

    do{
        cout << "===== Menu Human Relationship =====\n";
        cout << "1. Tambahkan parent ke list\n";
        cout << "2. Tambahkan child ke parent\n";
        cout << "3. Hapus parent\n";
        cout << "4. Hapus child\n";
        cout << "5. Tampilkan list parent\n";
        cout << "6. Tampilkan relasi human\n";
        cout << "7. Tampilkan umur relasi human\n";
        cout << "8. Tampilkan umur generasi human\n";
        cout << "0. Exit\n";
        cout << "\n";
        cout << "Pilih menu: "; cin >> select;
    }while(select != 0);

}