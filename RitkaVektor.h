#pragma once
#include "Vektor.h"

template < class T >
struct nonZero
{
	T elem;
	int index;
};


template<class T>
class RitkaVektor
{
public:
	operator Vektor<T>();
	RitkaVektor();
	RitkaVektor(int dim);
	RitkaVektor(T *t, int dim);
	RitkaVektor(const RitkaVektor&);
    ~RitkaVektor();

	RitkaVektor operator+(const RitkaVektor&);
	RitkaVektor operator-(const RitkaVektor&);
	double operator*(const RitkaVektor&);
	double operator~();
	double operator%(const RitkaVektor&);
	T      operator[](int) const;
	std::ostream& kiir(std::ostream&) const;

private:
	nonZero <T> * vektor;
	int nZeroDim;
	int dim;
};