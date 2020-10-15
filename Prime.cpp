#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

// Prime Number Generator by Dwi Andhika Aji Pamungkas (15 October 2020)

// Pertama, saya membuat fungsi boolean untuk mengecek apakah "n" prima atau tidak.
// Kalau dia habis dibagi dengan setidaknya 1 bilangan yang 
// kurang dari floor(sqrt(n)), maka dapat dipastikan itu bukan bilangan prima.
// Kemudian kita akan membuat loop untuk mengecek bilangan yang akan dicek.

// Kalau dia punya pembagi/faktor yang lebih dari floor(sqrt(n)) maka dia pasti 
// juga punya faktor yang kurang dari floor(sqrt(n)), karena apabila tidak, maka kedua 
// "faktor" tersebut kalau dikalikan akan menghasilkan bilangan yang 
// lebih dari n, yang tentunya merupakan kontradiksi.

// Kalau untuk mengecek bilangan prima yang sangat besar, menurut saya lebih baik
// kita mengecek keterbagiannya dengan bilangan prima yang kurang dari floor(sqrt(n)), bukan
// dengan bilangan bulat yang kurang dari floor(sqrt(n)), karena dengan demikian, kita dapat mengurangi pengecekan yang tidak perlu.
// namun untuk code ini sendiri saya implementasikan untuk mencari bilangan prima yang tidak terlalu besar.
// Laptop low-end saya bisa mencari 1000 bilangan prima pertama sekitar 2 detik dengan code ini.

// Kalau bilangan tersebut memiliki sebuah faktor, maka fungsi dibawah akan me-return hasil "false" 

bool cekPrima(int bilangan, int akarBulat){
	for(int i = 2; i <= akarBulat; i++){
		if(bilangan % i == 0){
			return false;
			break;
		}
	}
}

main(){
	int jumlah;
	int bil = 2;
	int n = 0;
	
	cout << "Masukan berapa banyak bilangan prima yang ingin dicari : ";cin >> jumlah;
	ofstream list;
 	list.open ("prime.txt");
	
	while(n < jumlah){
		int akarBulat = floor(sqrt(bil));
		if(cekPrima(bil, akarBulat) == true){
			list << bil << endl;
			n++;
		}
		bil++;
	}
	cout << "Selesai!";
}


