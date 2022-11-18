#pragma once
#include <vector>
#include <bitset>
#include <string>
#include "LinearSBlock.h"

using namespace std;

class LinearAproximation
{
private:
	bitset<16> inputP;
	bitset<16> outputP;
	vector<bitset<4>> SBlocks;
	vector<int> chance;
	LinearSBlock* SBlock;
	pair<int, int> tableIndex;

public:
	LinearAproximation();
	void SetInputP(bitset<16> input);
	void SetSblock(LinearSBlock* SBlock);
	void Ñalculate();
	void SetTableIndex(int i, int j);
	int BestColInLine(vector<int> input);
};

