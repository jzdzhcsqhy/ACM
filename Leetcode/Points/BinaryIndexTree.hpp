#pragma once

#include <vector>

using namespace std;

template <typename T>
class CBinaryIndexTree
{
public:

	//构造函数，并且初始化数组
	CBinaryIndexTree(std::vector<T>& vctInit)
	{
		m_vctSrcData = vctInit;
		Init();
	}

	//根据数据数组，维护树状数组
	void Init()
	{
		//清空树状数组
		m_vctTree.clear();
		//为辅助数组分配空间
		m_vctTree = vector<T>(m_vctSrcData.size() , T());

		//开始循环
		for( int i=0; i< (int) m_vctSrcData.size(); i++ )
		{
			//由于lowbit函数无法处理0， 我们的下标从1开始，
			int k = i+1;

			while( k < (int)m_vctTree.size() +1 )//循环条件的上限要记得加1
			{//循环为所有的父节点累加当前 数据节点的值，

				//记得bit的下标要减1
				m_vctTree[k-1] += m_vctSrcData[i];
				//寻找父节点
				k += lowbit(k);
			}
		}
	}

	// 获取区间和的函数
	// 对于每一个区间，我们只要用后段和减去前段和就好了
	T GetSum(int l, int r )
	{
		//注意这里，是l-1，不是l， 如果是l的话，就少了一个数据的和
		return Sum(r) - Sum(l-1);
	}

	// 求索引i之前所有数据和
	// 令人惊艳的是，每一个前n项和，都等于该项，与他之前所有根节点的值的总和
	T Sum( int i )
	{
		//先把索引自增一下，不然lowbit函数处理不了0
		i++;

		int sum = 0;

		//i增加了1，树的总上限也要记得加1
		while( i>0 && i< (int)m_vctTree.size() +1 )
		{
			// 先加上它自身
			sum += m_vctTree[i-1];
			// 寻找上一个根节点
			i -= lowbit(i);
		}
		return sum;
	}

	//获取一个数在二进制表示下，保留最后一个二进制位1，其余全都置0，
	//这样就能找到一个二进制数最后一个1位了
	int lowbit( int x )
	{
		return x & (-x);
	}

	//为某个数据增加一个值
	void add( int i, const T& value )
	{
		int k = i + 1;

		while (k < (int)m_vctTree.size() + 1)//循环条件的上限要记得加1
		{//循环为所有的父节点累加当前 数据节点的值，

			//记得bit的下标要减1
			m_vctTree[k - 1] += value;
			//寻找父节点
			k += lowbit(k);
		}
	}

public:
	// 源数据数组
	vector<T> m_vctSrcData;
	// 二叉索引树
	vector<T> m_vctTree;
};