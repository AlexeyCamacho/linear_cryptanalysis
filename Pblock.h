#pragma once
#include <vector>
#include <bitset>
#include <string>

using namespace std;

class PBlock
{
private:
	vector<int> permutation;

public:
	PBlock();
	unsigned long Permutation(bitset<16> input);
	unsigned long RevercePermutation(bitset<16> input);
	vector<int> GetPermutation();
	void Set(vector<string> input);
	void Push(int input);
	void Clear();
};

