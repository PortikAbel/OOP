#include <iostream>
#include "Vektor.h"
#include "Vektor.cpp"
#include "RitkaVektor.h"
#include "RitkaVektor.cpp"

using namespace std;

int a[6] = { 0,1,0,0,2,0 };
double a_d[7] = { 0,1.9,0,5.3,0,2.09,0 };
int b[6] = { 3,0,0,1,4,0 };
double b_d[7] = { 3.1,0,0,1.5,0,4.2,0 };

template<class T>
ostream& operator <<(ostream& s, const Vektor<T>& v)
{
	return v.kiir(s);
}

template<class T>
ostream& operator <<(ostream& s, const RitkaVektor<T>& v)
{
	return v.kiir(s);
}

int main()
{
	Vektor<int> A(a, 6);
	Vektor<double> B(b_d, 7);
	RitkaVektor<int> C(b, 6);
	RitkaVektor<double> D(a_d, 7);
	cout << "A =\t" << A << endl
		<< "B =\t" << B << endl
		<< "C =\t" << C << endl
		<< "D =\t" << D << endl
		<< endl;

	try {
		cout << "A + C =\t" << A + C << endl;
	}
	catch (const char* s)
	{
		cout << "Osszeadas hiba! " << s;
	}

	try {
		cout << "B - D =\t" << B - D << endl;
	}
	catch (const char* s)
	{
		cout << "Kivonas hiba! " << s;
	}

	try {
		cout << "B * D =\t" << B * D << endl;
	}
	catch (const char* s)
	{
		cout << "Skalar szorzat hiba! " << s;
	}

	try {
		cout << "~C =\t" << ~C << endl;
	}
	catch (const char* s)
	{
		cout << "Euklideszi norma hiba! " << s;
	}

	try {
		cout << "A[3] =\t" << A[3] << endl;
	}
	catch (const char* s)
	{
		cout << "[] operator hiba! " << s;
	}

	
	try {
		cout << "A % C =\t" << A % C << endl;
	}
	catch (const char* s)
	{
		cout << "Euklideszi tavolsag hiba! " << s;
	}
}