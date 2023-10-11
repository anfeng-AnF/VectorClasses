#include "vec.h"
#include "vec.cpp"
#include"test.h"

using namespace std;

int main()
{
    std::vector<int> data1 = { 1, 2, 3 };
    std::vector<int> data2 = { 4, 5, 6 };
    std::vector<int> data3 = { 4, 5, 6, 7 };


    Vec<int> vec1(data1, 3);
    Vec<int> vec2(data2, 3);

    //// ²âÊÔ¿½±´¸³ÖµÔËËã·û
    //vec1 = vec2;
    //std::cout << "vec1 == vec2: " << (vec1 == vec2) << std::endl;

    //// ²âÊÔ+=ÔËËã·û
    //vec1 += vec2;
    //std::cout << "vec1 += vec2: " << vec1 << std::endl;

    //// ²âÊÔÏÂ±êÈ¡Êı
    //std::cout << "vec1[0]: " << vec1[0] << std::endl;

    //// ²âÊÔshowsizeº¯Êı
    //vec1.showsize();

    testVec();
}