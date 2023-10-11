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
	std::vector<T> data;  //向量数组
	int size;  // 维数

public:
	Vec() : size(0) {};             //默认构造函数
	Vec(const std::vector<T>& _data, int _size) : data(_data), size(_size) {};         //构造函数
	~Vec() {};         //析构


	Vec<T>& operator=(const Vec<T>& othervec);						 //拷贝构造函数
	Vec<T>& operator+=(const Vec<T>& othervec);						 //+=运算
	void showsize();												 //输出向量维数
	bool operator==(const Vec<T>& othervec) const;					 //判断向量是否相等
	friend std::ostream& operator<<(std::ostream& os, const Vec<T>& myvec)  //输出重载
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
		// 读取输入流数据，不为空时持续输入
		while (is >> value)
		{
			myvec.data.push_back(value);
			myvec.size++;
		}
		return is;
	}    //输入重载      	   
	T& operator[](int index);                                        //下标取数

};

#endif
