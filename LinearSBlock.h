#pragma once
#include <vector>
#include <bitset>
#include <string>

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
	void Set(vector<string> input);
	void Clear();
	void —alculateSBlock();
	bool XORBits(bitset<4> mask, bitset<4> input);
	vector<vector<int>> GetlinearApr();
	int Get—hance(int i, int j);
	vector<int> GetLine(int i);
	unsigned long ReverceSubstitution(bitset<4> input);
};

