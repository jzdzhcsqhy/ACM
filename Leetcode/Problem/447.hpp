#pragma once
#include "../Base.hpp"

class Solution : public CSolutionBase
{

public:
	bool run()
	{
		vector<pair<int, int> > vct = { {1, 1},{2, 2},{3, 3} };

		cout << numberOfBoomerangs (vct)<<endl;
		return true;
	}
	
public:
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		//int iRs = 0;
		//

		//std::vector< std::tuple<int, int, int > > vctDis;

		//auto funcGetDis = [](pair<int, int> l, pair<int, int> r)-> int
		//{
		//	return abs( (r.second - l.second)*(r.second - l.second) -
		//		(r.first - l.first) * (r.first - l.first) );
		//};

		//for (size_t i = 0; i < points.size(); i++)
		//{
		//	for (size_t j = i + 1; j < points.size(); j++)
		//	{
		//		int iDis = funcGetDis(points[i], points[j]);

		//		vctDis.push_back(make_tuple<int,int,int>
		//		((int)i,(int)j,(int&&)iDis));
		//	}
		//}

		//sort(vctDis.begin(), vctDis.end(), [&](std::tuple<int, int, int > l, std::tuple<int, int, int > r)->bool
		//{
		//	int ll = std::get<2>(l);
		//	int rr = std::get<2>(r);
		//	return ll < rr;
		//});

		//auto funcCheck = [&](std::tuple<int, int, int > l, std::tuple<int, int, int > r)-> bool
		//{
		//	auto p1 = points[std::get<0>(l)];
		//	auto p2 = points[std::get<1>(l)];

		//	auto p3 = points[std::get<0>(r)];
		//	auto p4 = points[std::get<1>(r)];
		//	if (p1 == p3
		//		|| p1 == p4
		//		|| p2 == p3
		//		|| p2 == p4)
		//	{
		//		return true;
		//	}
		//	return false;
		//};

		//int iCheck = std::get<2>(vctDis[0]);
		//int iL = 0;
		//int iR = 0;
		//int sum = 0;
		//for (size_t i = 1; i < vctDis.size(); i++)
		//{
		//	if (iCheck != std::get<2>(vctDis[i]))
		//	{
		//		if (iL == iR )
		//		{
		//			iL = i;
		//			iR = i;
		//			continue;
		//		}
		//		else
		//		{
		//			if (funcCheck(vctDis[iL], vctDis[iR]))
		//			{
		//				sum += 2;
		//			}
		//		}
		//		

		//		iCheck = std::get<2>(vctDis[i]);
		//	}
		//}
		int sum = 0;

		map<int, int> mapDisToCounts;

		auto funcGetDis = [](pair<int, int> l, pair<int, int> r)-> int
		{
			return abs( (r.second - l.second)*(r.second - l.second) +
				(r.first - l.first) * (r.first - l.first) );
		};

		for (auto p1 : points)
		{
			mapDisToCounts.clear();

			for (auto p2 : points)
			{
				if (p1 == p2)
				{
					continue;
				}

				int iDis = funcGetDis(p1, p2);
				mapDisToCounts[iDis] ++;
			}

			for (auto mit : mapDisToCounts)
			{
				if (mit.second > 1)
				{
					sum += mit.second*(mit.second - 1);
				}
			}
		}

		return sum;
	}

};


CSolutionBase* gpBase = new Solution;