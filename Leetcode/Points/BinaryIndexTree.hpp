#pragma once

#include <vector>

using namespace std;

template <typename T>
class CBinaryIndexTree
{
public:

	//���캯�������ҳ�ʼ������
	CBinaryIndexTree(std::vector<T>& vctInit)
	{
		m_vctSrcData = vctInit;
		Init();
	}

	//�����������飬ά����״����
	void Init()
	{
		//�����״����
		m_vctTree.clear();
		//Ϊ�����������ռ�
		m_vctTree = vector<T>(m_vctSrcData.size() , T());

		//��ʼѭ��
		for( int i=0; i< (int) m_vctSrcData.size(); i++ )
		{
			//����lowbit�����޷�����0�� ���ǵ��±��1��ʼ��
			int k = i+1;

			while( k < (int)m_vctTree.size() +1 )//ѭ������������Ҫ�ǵü�1
			{//ѭ��Ϊ���еĸ��ڵ��ۼӵ�ǰ ���ݽڵ��ֵ��

				//�ǵ�bit���±�Ҫ��1
				m_vctTree[k-1] += m_vctSrcData[i];
				//Ѱ�Ҹ��ڵ�
				k += lowbit(k);
			}
		}
	}

	// ��ȡ����͵ĺ���
	// ����ÿһ�����䣬����ֻҪ�ú�κͼ�ȥǰ�κ;ͺ���
	T GetSum(int l, int r )
	{
		//ע�������l-1������l�� �����l�Ļ���������һ�����ݵĺ�
		return Sum(r) - Sum(l-1);
	}

	// ������i֮ǰ�������ݺ�
	// ���˾��޵��ǣ�ÿһ��ǰn��ͣ������ڸ������֮ǰ���и��ڵ��ֵ���ܺ�
	T Sum( int i )
	{
		//�Ȱ���������һ�£���Ȼlowbit����������0
		i++;

		int sum = 0;

		//i������1������������ҲҪ�ǵü�1
		while( i>0 && i< (int)m_vctTree.size() +1 )
		{
			// �ȼ���������
			sum += m_vctTree[i-1];
			// Ѱ����һ�����ڵ�
			i -= lowbit(i);
		}
		return sum;
	}

	//��ȡһ�����ڶ����Ʊ�ʾ�£��������һ��������λ1������ȫ����0��
	//���������ҵ�һ�������������һ��1λ��
	int lowbit( int x )
	{
		return x & (-x);
	}

	//Ϊĳ����������һ��ֵ
	void add( int i, const T& value )
	{
		int k = i + 1;

		while (k < (int)m_vctTree.size() + 1)//ѭ������������Ҫ�ǵü�1
		{//ѭ��Ϊ���еĸ��ڵ��ۼӵ�ǰ ���ݽڵ��ֵ��

			//�ǵ�bit���±�Ҫ��1
			m_vctTree[k - 1] += value;
			//Ѱ�Ҹ��ڵ�
			k += lowbit(k);
		}
	}

public:
	// Դ��������
	vector<T> m_vctSrcData;
	// ����������
	vector<T> m_vctTree;
};