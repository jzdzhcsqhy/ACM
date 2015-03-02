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
这当然可行，但我们也可以利用模板元编程技术来解开循环：
// sumarray2.h
// 原始模板
template <int Dim, typename T>
class Sumarray
{
public:
static T result(T* a)
{
return a[0] + Sumarray<Dim-1, T>::result(a+1);
}
};
// 作为终结准则的局部特化版
template <typename T>
class Sumarray<1, T>
{
public:
static T result(T* a)
{
return a[0];
}
};
用法如下：
// sumarraytest2.cpp
#include <iostream>
#include "sumarray2.h"
int main()
{
int a[6] = {1, 2, 3, 4, 5, 6};
std::cout << " Sumarray<6>(a) = " << Sumarray<6, int>::result(a);
}