#pragma once
#include <vector>
#include <bitset>
#include <string>

using namespace std;

class LinearAproximation
{
private:
	bitset<16> inputP;
	bitset<16> outputP;
	vector<bitset<4>> SBlocks;

public:
	LinearAproximation();
	void SetInputP(bitset<16> input);
};

