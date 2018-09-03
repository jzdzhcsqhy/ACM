#pragma once
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <functional>
#include <sstream>
#include <tuple>

using namespace std;

class CSolutionBase
{
public:
	virtual bool run() = 0;
};