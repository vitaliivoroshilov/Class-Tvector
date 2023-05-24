/*#include <iostream>
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

*/


#include<iostream>
using namespace std;

template <typename T> class TArray
{
private:
	T* arr;
	int N;

public:
	TArray() //конструктор по умолчанию
	{
		N = 1;
		arr = new T[N];
		for (int i = 0; i < N; i++)
			arr[i] = 0;
	}
	TArray(int n) //конструктор с одним параметром
	{
		N = n;
		arr = new T[N];
		cout << "Введите " << N << " элементов массива: ";
		setElements();
	}

	TArray(const TArray& source) //конструктор копирования
	{
		N = source.N;
		arr = new T[N];
		for (int i = 0; i < N; i++)
			arr[i] = source.arr[i];
	}

	~TArray() //деструктор
	{
		delete[] arr; //освобождение памяти
	}

	int getSize() //возвращение размера массива
	{
		return N;
	}

	void printTArray() //показать массив
	{
		for (int i = 0; i < N; i++)
			cout << arr[i] << "  ";
		cout << endl;
	}

	void setElements() //ввод элементов массива
	{
		for (int i = 0; i < N; i++)
			cin >> arr[i];
	}

	void sortTArray() //сортировка массива по возрастанию
	{
		T temp; // переменные для хранения мин-ного значения и индекса массива
		for (int i = 0; i < N; i++)
		{
			temp = arr[i]; //инициализируем врем. переменную
			for (int j = i; j < N; j++)
				if (temp > arr[j])//находим минимальный элемент
				{
					temp = arr[j]; //делаем перестановку
					arr[j] = arr[i];
					arr[i] = temp;
				}
		}
	}

	T maxElement()
	{
		sortTArray();
		return arr[N - 1];
	}

	T minElement()
	{
		sortTArray();
		return arr[0];
	}
};

int main()
{
	setlocale(LC_CTYPE, "rus");
	int n;
	cout << "Введите размер массива: ";
	cin >> n;
	TArray <char> TArray(n);
	cout << "Массив: ";
	TArray.printTArray();
	TArray.sortTArray();
	cout << "Остортированный массив: ";
	TArray.printTArray();
	cout << "Max = " << TArray.maxElement() << " Min = " << TArray.minElement() << endl;

	return 0;
}