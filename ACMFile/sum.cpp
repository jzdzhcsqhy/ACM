template <typename T>
inline T sum_array(int Dim, T* a)
{
T result = T();
for (int i = 0; i < Dim; ++i)
{
result += a;
}
return result;
}
�⵱Ȼ���У�������Ҳ��������ģ��Ԫ��̼������⿪ѭ����
// sumarray2.h
// ԭʼģ��
template <int Dim, typename T>
class Sumarray
{
public:
static T result(T* a)
{
return a[0] + Sumarray<Dim-1, T>::result(a+1);
}
};
// ��Ϊ�ս�׼��ľֲ��ػ���
template <typename T>
class Sumarray<1, T>
{
public:
static T result(T* a)
{
return a[0];
}
};
�÷����£�
// sumarraytest2.cpp
#include <iostream>
#include "sumarray2.h"
int main()
{
int a[6] = {1, 2, 3, 4, 5, 6};
std::cout << " Sumarray<6>(a) = " << Sumarray<6, int>::result(a);
}