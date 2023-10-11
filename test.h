#include"vec.h"
#include<random>

template<typename T>
vector<T> getVecRand(int num);

void testVec();

template<typename T>
void testData(vector<Vec<T>> v1, vector<Vec<T>> v2);

template<typename T>
void showVecs(vector<Vec<T>>);

template <typename T>
std::vector<T> getVecRand(int num) {
	vector<T> v;
	random_device rd;
	default_random_engine eng(rd());

	if (is_integral<T>::value) {
		uniform_int_distribution<int> distr(-100, 100);
		for (int i = 0; i < num; i++) {
			v.push_back(distr(eng));
		}
	}
	else if (is_floating_point<T>::value) {
		uniform_real_distribution<double> distr(-100.0, 100.0);
		for (int i = 0; i < num; i++) {
			v.push_back((T)distr(eng));
		}
	}
	return v;
}

template<typename T>
inline void showVecs(vector<Vec<T>> v)
{
	for (Vec<T> obj : v) {
		cout << "\n��������Ϊ:";
		obj.showsize();
		cout << "������Ϊ��";
		cout << obj << endl;
	}
}

void testVec() {
	vector<Vec<int>> intVecL5,intVecL6;
	vector<Vec<double>> doubleVecL6,doubleVecL3;
	vector<int> dataInt;
	vector<double> dataDouble;


	for (int i = 0; i < 10; i++) {
		dataInt = getVecRand<int>(5);
		intVecL5.push_back({ dataInt,5 });
		dataInt = getVecRand<int>(6);
		intVecL6.push_back({ dataInt,6 });
		dataDouble = getVecRand<double>(6);
		doubleVecL6.push_back({ dataDouble,6 });
		dataDouble = getVecRand<double>(3);
		doubleVecL3.push_back({ dataDouble,3 });
	}
	cout << "int data vector testing..." << endl;
	testData(intVecL5,intVecL6);
	cout << "float data vector testing..." << endl;
	testData(doubleVecL3, doubleVecL6);

	//��Ե����
//1,size=0ʱ�Ĳ���
	cout << "=====================================\n";
	cout << "size = 0ʱ�Ĳ���" << endl;
	Vec<int> vZero1, vZero2;
	cout << vZero1 << "+" << vZero2 << "=";
	vZero1 += vZero2;
	cout << vZero1 << endl;
	cout << vZero1 << "==" << vZero2 << "?      ans" << (vZero1 == vZero2) << endl;

	//2,�������ʱ�Ĵ�������
	Vec<int> willOver1({ INT32_MAX - 1 }, 1), willOver2({ INT32_MAX / 2 }, 1);
	cout << willOver1 << "+" << willOver2 << "=";
	willOver1 += willOver2;
	cout << willOver1 << endl;
}

template<typename T>
void testData(vector<Vec<T>> v1, vector<Vec<T>> v2)
{

	cout << "=====================================\n";

	cout << "�����ص�+=���в��ԣ�v1[i]+=v1[i]��\n";
	for (int i = 0; i < v1.size(); i++) {
		try {
			cout << "\n";
			cout << v1.at(i) << "   +   " << v1.at(i) << "equals:";
			v1.at(i) += v1.at(i);
			cout << v1.at(i) << endl;
		}
		catch (const std::runtime_error& e) {
			cout << "�쳣��" << e.what() << endl;
		}
	}

	cout << "�����ص�+=���в�ͬ����������Ͳ��ԣ�v1[i]+=v2[i]��\n";
	for (int i = 0; i < v1.size(); i++) {
		try {
			cout << "\n";
			cout << v1.at(i) << "   +   " << v2.at(i) << "equals:";
			v1.at(i) += v2.at(i);
			cout << v1.at(i) << endl;
		}
		catch (const std::runtime_error& e) {
			cout <<"�쳣��"<< e.what() << endl;
		}
	}
	cout << "�����ص�==���в��ԣ�v1[i]==v2[i]?��\n";
	for (int i = 0; i < v1.size(); i++) {
		cout << v1.at(i) << "==" << v2.at(i) << "     ans:";
		cout<<(v1.at(i) == v2.at(i))<<endl;
	}
	cout << "�����ص�==���в��ԣ�v1[i]==v1[i]?��\n";
	for (int i = 0; i < v1.size(); i++) {
		cout << v1.at(i) << "==" << v1.at(i) << "     ans:";
		cout << (v1.at(i) == v1.at(i)) << endl;
	}

	cout << "=====================================\n";
	cout << "=====================================\n";

	cout << "�Ը�ֵ���ԣ�v1[i]=v2[i]��\n";
	cout << "=====================================\n";

	cout << "��ֵǰv1��" << endl;
	showVecs(v1);
	cout << "=====================================\n";
	cout << "��ֵǰv2��" << endl;
	showVecs(v2);
	for (int i = 0; i < v1.size(); i++) {
		v1.at(i) = v2.at(i);
	}
	cout << "=====================================\n";

	cout << "��ֵ��v1��" << endl;
	showVecs(v1);

}
