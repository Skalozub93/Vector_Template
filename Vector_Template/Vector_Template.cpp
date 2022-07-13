#include <iostream>
#include <algorithm>
using namespace std;
template <typename T>
class Vector
{
	T* arr = nullptr;
	int size = 0;
	int capacity = 10;
public:
	Vector(unsigned int capacity);
    ~Vector();

	Vector& operator = (const Vector& other);
	bool operator!= (const Vector& other);
	T operator[](int index);
	bool operator ==(const Vector& other);


public:


	void RemoveByIndex(T& k);
	void RemoveByValue(T& N);
	void PopFront();
	void PopBack();
	void TrimToSize();
	int IndexOf(T& value);
	int LastIndexOf(T& value);
	void Reverse();
	void SortAsc();
	void SortDesc();
	void Shuffle();
	void RandomFill(T& N);
	void Equals();
	int GetSize() const;
	int GetCapacity() const;
	void Print();
};


template <typename T>
Vector<T>::Vector(unsigned int capacity)
{
	if (capacity < 10)
	{
		capacity = 10;
	}
	this->capacity = capacity;
	arr = new int[capacity];
}

template <typename T>
Vector<T>::~Vector()
{
	if (arr != nullptr)
	{
		delete[] arr;
		arr = nullptr;
	}
}

template <typename T>
Vector<T>& Vector<T>::operator = (const Vector& other)
{
	if (this == &other)
	{
		return *this;
	}
	arr = other.arr;
	size = other.size;

	return *this;
}

template<typename T>
bool Vector<T>::operator!=(const Vector& other)
{
	if (*this == other) return false;
	return true;
}

template <typename T>
T Vector<T>::operator[](int index)
{
	if (index < 0 || index >= size)
	{
		return arr[0];
	}
	return arr[index];
}
template <typename T>
bool Vector<T>::operator ==(const Vector& other)
{
	return this->arr == other.arr;
}

template <typename T>
void Vector<T>::RemoveByIndex(T& k)
{
	for (int i = k; i < size; i++)
	{
		arr[i] = arr[i + 1];
	}
	size--;
}

template <typename T>
void Vector<T>::RemoveByValue(T& N)
{
	for (int i = 0; i < size; i++)
	{
		if (N == arr[i])
		{
			RemoveByIndex(i);
		}
	}
}

template <typename T>
void Vector<T>::PopFront()
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = arr[i + 1];
	}
	size--;
}

template <typename T>
void Vector<T>::PopBack()
{

	size--;
}

template <typename T>
void Vector<T>::TrimToSize()
{
	int* temp = new int[size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;

	arr = temp;
	capacity = size;
	delete[] temp;
}

template <typename T>
int Vector<T>::IndexOf(T& value)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value) return i;
		else - 1;
	}
}

template <typename T>
int Vector<T>::LastIndexOf(T& value)
{
	for (int i = size; i >= 0; i--)
	{
		if (arr[i] == value)
		{
			if (arr[i] == value) return i;
			else - 1;
		}
	}
}

template <typename T>
void Vector<T>::Reverse()
{
	int temp;
	for (int i = 0; i < size / 2; i++)
	{
		temp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = temp;
	}
}

template <typename T>
void Vector<T>::SortAsc()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

template <typename T>
void Vector<T>::SortDesc()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
template <typename T>
void Vector<T>::Shuffle()
{
	for (int i = 0; i < size; i++)
	{
		swap(arr[i], arr[rand() % size]);
	}
}
template <typename T>
void Vector<T>::RandomFill(T& N)
{
	if (N <= capacity)
	{
		for (int i = 0; i < N; i++)
		{
			arr[i] = rand() % 10;
			size++;
		}
	}
	else
	{
		throw "elements more than size";
	}
}

template <typename T>
void Vector<T>::Equals()
{

}

template <typename T>
int Vector<T>::GetSize() const
{
	return size;
}

template <typename T>
int Vector<T>::GetCapacity() const
{
	return capacity;
}

template <typename T>
void Vector<T>::Print()
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{

}


