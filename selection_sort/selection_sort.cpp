#include <cstdlib>
#include <iostream>
#include <conio.h>
using namespace std;
// By : Dian Nugraha -> 1112091000081
int main ( )
{
    int data [] = { 7, 3, 9, 2, 5}; //Kondisi awal:Unsorted list = data

    int tmp; //Sorted list = kosong

    cout<<"\tSELECTION SORT\n\n";
    cout << "Data yang akan di urutkan \t:";
    for( int i = 0; i < 5; i++)
        cout << data[i] << " ";

    cout << endl;

    for (int i = 0; i < 5 -1; i++)

        for (int j = i+1; j < 5; j++)
            //1. Pengecekan dimulai data ke-1 sampai dengan data ke-n
            if (data[i] > data[j])
            {
               //2. Tentukan bilangan dengan Index terkecil dari data bilangan tersebut
                tmp = data[i];
                //3. Tukar bilangan dengan Index terkecil tersebut dengan bilangan  pertama ( I = 1 ) dari data bilangan tersebut

                data[i] = data[j];
                data[j] = tmp;
            }
            //4. Lakukan langkah 2 dan 3 untuk bilangan berikutnya ( I= I+1 ) sampai didapatkan urutan yg optimal.

   cout<<"\nData yang telah di urutkan \t:";
    for( int i = 0; i < 5; i++)
        cout << data[i] << " ";

    cout << endl;
    getch();
    return 0;
}
