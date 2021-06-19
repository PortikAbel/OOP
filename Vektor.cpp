#include "Vektor.h"
#include <algorithm>

template<class T>
Vektor<T>::Vektor()
{
	m_dim = 0;
	m_t = 0;
}

template<class T>
Vektor<T>::Vektor(int dim)
{
	m_dim = dim;
	m_t = new T[dim];
	std::fill(m_t, m_t + dim, 0);
}

template<class T>
Vektor<T>::Vektor(T* t, int dim)
{
	m_dim = dim;
	m_t = new T[dim];
	for (int i = 0; i < dim; i++)
		m_t[i] = t[i];
}

template<class T>
Vektor<T>::Vektor(const Vektor& v)
{
	m_dim = v.m_dim;
	m_t = new T[m_dim];
	for (int i = 0; i < m_dim; i++)
		m_t[i] = v.m_t[i];
}

template<class T>
Vektor<T>::~Vektor()
{
	delete[] m_t;
}

template<class T>
Vektor<T> Vektor<T>::operator+(const Vektor& v)
{
	if (m_dim != v.m_dim)
		throw "Kulonbozo dimenziok";

	T* eredmeny = new T[m_dim];
	for (int i = 0; i < m_dim; i++)
		eredmeny[i] = m_t[i] + v.m_t[i];
	return Vektor<T>(eredmeny, m_dim);
}

template<class T>
Vektor<T> Vektor<T>::operator-(const Vektor& v)
{
	if (m_dim != v.m_dim)
		throw "Kulonbozo dimenziok";

	T* eredmeny = new T[m_dim];
	for (int i = 0; i < m_dim; i++)
		eredmeny[i] = m_t[i] - v.m_t[i];
	return Vektor<T>(eredmeny, m_dim);
}

template<class T>
double Vektor<T>::operator*(const Vektor& v)
{
	if (m_dim != v.m_dim)
		throw "Kulonbozo dimenziok";

	double eredmeny = 0;
	for (int i = 0; i < m_dim; i++)
		eredmeny += m_t[i] * v.m_t[i];
	return eredmeny;
}

template<class T>
double Vektor<T>::operator~()
{
	double eredmeny = 0;
	for (int i = 0; i < m_dim; i++)
		eredmeny += m_t[i] * m_t[i];
	return sqrt(eredmeny);
}

template<class T>
double Vektor<T>::operator%(const Vektor& v)
{
	if (m_dim != v.m_dim)
		throw "Kulonbozo dimenziok";

	double eredmeny = 0;
	for (int i = 0; i < m_dim; i++)
		eredmeny += (static_cast<double>(m_t[i]) - v.m_t[i]) * (m_t[i] - v.m_t[i]);
	return sqrt(eredmeny);
}

template<class T>
T Vektor<T>::operator[](int i) const
{
	if (i < 0 || i >= m_dim)
		throw "Helytelen index";
	return m_t[i];
}

template<class T>
Vektor<T>::operator RitkaVektor<T>()
{
	int dim = 0;
	for (int i = 0; i < m_dim; i++)
		if (m_t[i]) dim++;
	T* t = new T[dim];
	int j = 0;
	for (int i = 0; i < m_dim; i++)
		if (m_t[i])
			t[j++] = m_t[i];
	return RitkaVektor<T>(t, dim);
}

template<class T>
std::ostream& Vektor<T>::kiir(std::ostream& s) const
{
	for (int i = 0; i < m_dim; i++)
		s << m_t[i] << '\t';
	return s;
}