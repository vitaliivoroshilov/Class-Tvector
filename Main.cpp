#include <iostream>
using namespace std;

template <class T> class Tvector
{
protected:
	T* pVector;
	int size, startIndex;
public:
	Tvector(int s = 10, int si = 0);
	Tvector(const Tvector& v);
	~Tvector();

	friend istream& operator>>(istream& in, Tvector& v)
	{
		for (int i = 0; i < v.size; i++)
			in >> pVector[i];
		return in;
	}

	friend ostream& operator<<(ostream& out, const Tvector& v)
	{
		for (int i = 0; i < v.size; i++)
			out << pVector[i]<<"";
		return out;
	}

	bool operator==(const Tvector& v)
	{
		bool flag = 0;
		if ((size == v.size) && (startIndex == v.startIndex))
		{
			int n = 0;
			for (int i = 0; i < size; i++)
				if (pVector[i] == v.pVector[i])
					n++;
			if (n = size)
				flag = 1;
		}
		return flag;
	}

	Tvector<T> operator=(const Tvector& v)
	{
		if (this != &v)
		{
			if (size != v.size)
			{
				delete pVector;
				pVector = new T[v.size];
			}
			size = v.size;
			startIndex = v.startIndex;
			for (int i = 0; i < size; i++)
				pVector[i] = v.pVector[i];
		}
		return *this;
	}
		
	Tvector(int s, int si)
	{
		size = s;
		startIndex = si;
		pVector = new T[size];
		for (int i = 0; i < size; i++)
			pVector[i] = 0;
	}

	Tvector(const Tvector& v)
	{
		size = v.size;
		startIndex = v.startIndex;
		pVector = new T[size];
		for (int i = 0; i < size; i++)
			pVector[i] = v.pVector[i];
	}

	~Tvector()
	{
		delete[]pVector;
		pVector = nullptr;
	}

	template <class T>
	T& operator[](int pos)
	{
		return pVector[pos - startIndex];
	}

	template <class T>
	Tvector<T> operator+(const Tvector<T>& v)
	{
		Tvector temp(size, startIndex);
		for (int i = 0; i < size; i++)
			temp.pVector[i] = pVector[i] + v.pVector[i];
		return temp;
	}

	template <class T>
	Tvector<T> operator-(const Tvector<T>& v)
	{
		Tvector temp(size, startIndex);
		for (int i = 0; i < size; i++)
			temp.pVector[i] = pVector[i] - v.pVector[i];
		return temp;
	}

	template <class T>
	Tvector<T> operator*(const Tvector<T>& v)
	{
		Tvector temp(size, startIndex);
		for (int i = 0; i < size; i++)
			temp.pVector[i] = pVector[i] * v.pVector[i];
		return temp;
	}
};