#pragma once
#include <vector>

using namespace std;


class LinearSBlock
{
private:
	vector<int> sblock;

public:
	vector<int> GetSBlock();
	void Push(int input);
	void Clear();
	void ÑalculateSBlock();
};

