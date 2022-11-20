#pragma once
#include <vector>
#include <string>
#include <bitset>
#include "LinearSBlock.h"

using namespace std;

class Decryption
{
private:
	bitset<16> inputApr;
	bitset<16> outputApr;
	vector<pair<int, int>> data;
	vector<int> activeSblocks;
	LinearSBlock* SBlock;
	double chance;
	int key;

public:
	Decryption();

	void SetInputApr(bitset<16> input);
	void SetOutputApr(bitset<16> input);
	void SetSblock(LinearSBlock* SBlock);

	int GetCountActiveSblocks();
	bitset<16> GetKey();

	void PushData(int x, int y);
	void ClearData();

	void Calculate();
	void GetActiveSblocks();
	double ÑheckKey(int key, bitset<16> activeSblocks);
};

