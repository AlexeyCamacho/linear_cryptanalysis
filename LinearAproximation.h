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
	bitset<16> tmp;
	vector<bitset<4>> SBlocks;
	vector<int> chance;
	LinearSBlock* SBlock;
	int startRow;

public:
	LinearAproximation();
	void SetInputP(bitset<16> input);
	void SetSblock(LinearSBlock* SBlock);
	void Ñalculate();
	void SetStartRow(int i);
	int BestColInLine(vector<int> input);
	void DistributeToSblock();
	void ProcessingSblocks();
};

