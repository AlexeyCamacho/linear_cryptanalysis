#pragma once
#include <vector>
#include <bitset>
#include <string>
#include <cmath>
#include "LinearSBlock.h"
#include "Pblock.h"

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
	PBlock* P_block;
	int startRow;

public:
	LinearAproximation();

	void SetInputP(bitset<16> input);
	void SetSblock(LinearSBlock* SBlock);
	void SetStartRow(int i);
	void SetPBlock(PBlock* P_block);

	bitset<16> GetInput();
	bitset<16> GetOutput();
	double GetChance();

	void Ñalculate();
	int BestColInLine(vector<int> input);
	void DistributeToSblock();
	void ProcessingSblocks();
	void ProcessingPblock();
	void MergerSblock();
};

