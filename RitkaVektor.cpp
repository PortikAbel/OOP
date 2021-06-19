#include "RitkaVektor.h"
#include <algorithm>

template<class T>
RitkaVektor<T>::operator Vektor<T>()
{
	T* t = new T[dim];
	std::fill(t, t + dim, 0);
	for (int i = 0; i < nZeroDim; i++)
		t[vektor[i].index] = vektor[i].elem;
	return Vektor<T>(t, dim);
}

template<class T>
RitkaVektor<T>::RitkaVektor()
{
	dim = 0;
	nZeroDim = 0;
	vektor = 0;
}

template<class T>
RitkaVektor<T>::RitkaVektor(int dim)
{
	dim = dim;
	nZeroDim = 1;
	vektor = new nonZero<T>[1];
	vektor[0] = 1;
}

template<class T>
RitkaVektor<T>::RitkaVektor(T* t, int dim)
{
	this->dim = dim;
	nZeroDim = 0;
	for (int i = 0; i < dim; i++)
		if (t[i]) nZeroDim++;
	vektor = new nonZero<T>[nZeroDim];
	nonZero<T> x;
	int j = 0;
	for (int i = 0; i < dim; i++)
		if (t[i])
		{
			x.elem = t[i];
			x.index = i;
			vektor[j] = x;
			j++;
		}
}

template<class T>
RitkaVektor<T>::RitkaVektor(const RitkaVektor& v)
{
	dim = v.dim;
	nZeroDim = v.nZeroDim;
	vektor = new nonZero<T>[nZeroDim];
	for (int i = 0; i < nZeroDim; i++)
		vektor[i] = v.vektor[i];
}

template<class T>
RitkaVektor<T>::~RitkaVektor()
{
	delete[] vektor;
}

template<class T>
RitkaVektor<T> RitkaVektor<T>::operator+(const RitkaVektor& v)
{
	if (dim != v.dim)
		throw "Kulonbozo dimenziok";

	T* t = new T[dim];
	for (int i = 0; i < dim; i++)
		t[i] = 0;
	for (int i = 0; i < nZeroDim; i++)
		t[vektor[i].index] += vektor[i].elem;
	for (int i = 0; i < v.nZeroDim; i++)
		t[v.vektor[i].index] += v.vektor[i].elem;

	int uj_dim = 0;
	for (int i = 0; i < dim; i++)
		if (t[i])
			uj_dim++;
	return RitkaVektor(t, uj_dim);
}

template<class T>
RitkaVektor<T> RitkaVektor<T>::operator-(const RitkaVektor& v)
{
	if (dim != v.dim)
		throw "Kulonbozo dimenziok";

	T* t = new T[dim];
	for (int i = 0; i < dim; i++)
		t[i] = 0;
	for (int i = 0; i < nZeroDim; i++)
		t[vektor[i].index] += vektor[i].elem;
	for (int i = 0; i < v.nZeroDim; i++)
		t[v.vektor[i].index] -= v.vektor[i].elem;

	int uj_dim = 0;
	for (int i = 0; i < dim; i++)
		if (t[i])
			uj_dim++;

	return RitkaVektor(t, uj_dim);
}

template<class T>
double RitkaVektor<T>::operator*(const RitkaVektor& v)
{
	if (dim != v.dim)
		throw "Kulonbozo dimenziok";

	double eredmeny = 0;
	int i = 0, j = 0;
	while (i < nZeroDim && j < v.nZeroDim)
	{
		if (vektor[i].index == v.vektor[j].index)
		{
			eredmeny += vektor[i].elem * v.vektor[j].elem;
			i++;
			j++;
		}
		else if (vektor[i].index < v.vektor[j].index)
			i++;
		else
			j++;
	}
	return eredmeny;
}

template<class T>
double RitkaVektor<T>::operator~()
{
	double eredmeny = 0;
	for (int i = 0; i < nZeroDim; i++)
		eredmeny += static_cast<double>(vektor[i].elem) * vektor[i].elem;
	return sqrt(eredmeny);
}

template<class T>
double RitkaVektor<T>::operator%(const RitkaVektor& v)
{
	if (dim != v.dim)
		throw "Kulonbozo dimenziok";

	double eredmeny = 0;
	int i = 0, j = 0;
	while (i < nZeroDim && j < v.nZeroDim)
	{
		if (vektor[i].index == v.vektor[j].index)
		{
			eredmeny += (vektor[i].elem - v.vektor[j].elem) * (vektor[i].elem - v.vektor[j].elem);
			i++;
			j++;
		}
		else if (vektor[i].index < v.vektor[j].index)
		{
			eredmeny += vektor[i].elem * vektor[i].elem;
			i++;
		}
		else
		{
			eredmeny += v.vektor[j].elem * v.vektor[j].elem;
			j++;
		}
	}
	return eredmeny;
}

template<class T>
T RitkaVektor<T>::operator[](int i) const
{
	int j = 0;
	while (vektor[j].index < i)
		j++;
	return vektor[j].index == i ? vektor[j].elem : 0;
}

template<class T>
std::ostream& RitkaVektor<T>::kiir(std::ostream& s) const
{
	int j = 0;
	for (int i = 0; i < dim; i++)
	{
		if (vektor[j].index == i)
			s << vektor[j++].elem << '\t';
		else
			s << 0 << '\t';
	}
	return s;
}