#pragma once
#ifndef VEC_H
#define VEC_H


#include <vector>
#include <iostream>

using namespace std;


template<typename T>
class Vec
{
private:
	std::vector<T> data;  //��������
	int size;  // ά��

public:
	Vec() : size(0) {};             //Ĭ�Ϲ��캯��
	Vec(const std::vector<T>& _data, int _size) : data(_data), size(_size) {};         //���캯��
	~Vec() {};         //����


	Vec<T>& operator=(const Vec<T>& othervec);						 //�������캯��
	Vec<T>& operator+=(const Vec<T>& othervec);						 //+=����
	void showsize();												 //�������ά��
	bool operator==(const Vec<T>& othervec) const;					 //�ж������Ƿ����
	friend std::ostream& operator<<(std::ostream& os, const Vec<T>& myvec)  //�������
	{
		os << "(";
		for (int i = 0; i < myvec.size; ++i)
		{
			os << myvec.data[i];
			if (i != myvec.size - 1)
				os << ", ";
		}
		os << ")";
		return os;
	}																	 
	friend istream& operator>>(istream& is, Vec<T>& myvec)
	{
		T value;
		// ��ȡ���������ݣ���Ϊ��ʱ��������
		while (is >> value)
		{
			myvec.data.push_back(value);
			myvec.size++;
		}
		return is;
	}    //��������      	   
	T& operator[](int index);                                        //�±�ȡ��

};

#endif
