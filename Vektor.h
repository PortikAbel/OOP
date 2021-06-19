#pragma once
#include <iostream>

template<class T>
class RitkaVektor;

template<class T>
class Vektor
{
public:
	Vektor();
	Vektor(int dim);
	Vektor(T *t, int dim);
	Vektor(const Vektor&);
    ~Vektor();

	Vektor operator+(const Vektor&);
	Vektor operator-(const Vektor&);
	double operator*(const Vektor&);
	double operator~();
	double operator%(const Vektor&);
	T      operator[](int) const;
	operator RitkaVektor<T>();
	std::ostream& kiir(std::ostream&) const;

private:
	T*  m_t;
	int m_dim;
};
