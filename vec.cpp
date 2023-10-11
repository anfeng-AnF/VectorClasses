#include "vec.h"
#include <vector>

template<typename T>
Vec<T>& Vec<T>::operator=(const Vec<T>& othervec)
{
    if (this == &othervec)
        return *this;
    size = othervec.size;
    data = othervec.data;
    return *this;
}

template<typename T>
Vec<T>& Vec<T>::operator+=(const Vec<T>& othervec)
{
    if (size != othervec.size)
    {
        throw std::runtime_error("ά����ƥ�䣬�޷����");
    }

    for (int i = 0; i < size; ++i)
    {
        data[i] += othervec.data[i];
    }

    return *this;
}

template<typename T>
void Vec<T>::showsize()
{
    std::cout << size << std::endl;
}

template<typename T>
bool Vec<T>::operator==(const Vec<T>& othervec) const
{
    if (size != othervec.size)
        return false;

    for (int i = 0; i < size; ++i)
    {
        if (data[i] != othervec.data[i])
            return false;
    }

    return true;
}


template<typename T>
T& Vec<T>::operator[](int index)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("��Ч���±�");
    }

    return data[index];
}


