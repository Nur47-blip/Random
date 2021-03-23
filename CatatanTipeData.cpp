#include <iostream> 

using namespace std;

int main(){
	
//	bilangan bulat
//	int
//	
//	huruf
//	char
//	
//	kata
//	string
//	
//	bilangan real (bisa pecahan)
//	double
//	
//	boolean (benar salah)
//	bool
	
//	ini namanya comment, tidak ikut tercompile
	
	int bilangan_bulat; //nilainya masih random
	int Bilangan_bulat = 5; //nilainya langsung 5
	
	Bilangan_bulat = 6; //mengganti nilai Bilangan_bulat jadi 6
	cout << Bilangan_bulat;
	
/////////////////////////////////////////////////////////////////////////////
	
	int a = 5;
	int b = 6;
	
	cout << a + b << endl;
	cout << 2*b << endl;
	cout << b << endl;
	
	b = b*2; //ini boleh, tapi kadang kita pengen ngetik cepet.
	b *= 2;
	b += 5*a; //ini maksudnya adalah b = b + (5*a);
	a /= b; // maksudnya a dibagi b
	a -= b;
	
	//operasi modulo (operasi sisa)
	
	7 dibagi 5 hasilnya 1.4 --> ini pembagian di double
	7 dibagi 5 hasilnya 1 --> kalau di integer
	7 dibagi 5 SISANYA 2 --> 7 mod 5 = 2
	8 dibagi 2 sisanya 0 --> 8 mod 2 = 0
	
	a = a % b --> a dimodulo dengan b
	
	//operasi xor 
	
	a = a^b;
}
