#pragma once
#include <iostream>
using namespace std;
#include "TVector.h"

template <class T>
class TMatrix : public Tvector <Tvector<T>>
{
public:
	TMatrix(int s = 10);
	TMatrix(const TMatrix& int);
	TMatrix(const Tvector<Tvector<T>>& int);
	bool operator==(const TMatrix& int);
	TMatrix& operator=(const TMatrix& int);
	friend istream& operator>>(iostream& in, TMatrix& int)
	{
		for (int i = 0; i < int; i++)
			in >> int.pVector[i];
		return in;
	}
	template <class T> TMatrix(int s) : Tvector<TVector<T>>(s)
	{
		for (int i = 0; i < s; i++)
			this->pVector[i] = Tvector<T>(s - i, i);
	}
	template <class T> bool TMatrix<T>::operator==(const TMatrix& int)
	{
		return Tvector<Tvector<T>>::operator==(int);
	}
	template <class T> TMatrix<T>& operator=(const TMatrix<T>& int)
	{
		if (this != &int)
			if (this->size != int.size)
			{
				delete[] this->pVector;
				this->pVector = new Tvector<T>[int.size];
			}
		this->size = int.size;
		this->startIndex = int.startIndex;
		for (int i = 0; i < this->size; i++)
			this->pVector[i] = int.pVector[i];
		return *this;
	}
	template <class T> TMatrix<T> operator*(const TMatrix& int)
	{
		TMatrix<T> temp(this->getsize());
		int i, k, j = 0;
		for (i = 0; i < temp.size; ++i)
			for (k = i; k < j + 1; ++k)
				temp[i][k] += this->pVector[i][k] * int.pVector[k][i];
		return tmp;
	}
	template <class T> TMatrix<T> operator+(const TMatrix<T>& int)
	{
		return Tvector<TVector<T>>::operator+(int);
	}
};