#pragma once
#include <vector>
#include <bitset>

using namespace std;


class LinearSBlock
{
private:
	vector<int> sblock;
	vector<vector<int>> linearApr;

public:
	LinearSBlock();

	vector<int> GetSBlock();
	int Push(int input);
	void Clear();
	void ÑalculateSBlock();
	bool XORBits(bitset<4> mask, bitset<4> input);
	vector<vector<int>> GetlinearApr();
};

