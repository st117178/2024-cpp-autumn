#ifndef ARRAY_HEADER_H
#define ARRAY_HEADER_H

template<class T>
Array<T>::Array(T* b)
{
	for (int i = 0;i < 7;i++)
	{
		array[i] = b[i];
	}
}

template<class T>
void Array<T>::show()
{
	for (int i = 0; i < 7; i++)
	{
		std::cout << array[i];
	}
}

template<class T>
T Array<T>::minimum(Array<T>& m)
{
	T min = m.array[0];
	for (int i = 0; i < 7; i++)
	{
		if (min > m.array[i])
		{
			min = m.array[i];
		}
	}
	return min;
}

#endif