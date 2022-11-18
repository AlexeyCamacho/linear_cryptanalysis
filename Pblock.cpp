#include "PBlock.h"

PBlock::PBlock()
{

}

unsigned long PBlock::Permutation(bitset<16> input)
{
	bitset<16> res;
	for (int i = 0; i < 16; i++) {
		res[this->permutation[i]] = input[i];
	}

	return res.to_ulong();
}

unsigned long PBlock::RevercePermutation(bitset<16> input)
{
	bitset<16> res;
	for (int i = 0; i < 16; i++) {
		vector<int>::iterator itr = find(this->permutation.begin(), this->permutation.end(), i);
		res[distance(this->permutation.begin(), itr)] = input[i];
	}

	return res.to_ulong();
}

vector<int> PBlock::GetPermutation()
{
	return this->permutation;
}

void PBlock::Set(vector<string> input) {
	for (int i = 0; i < input.size(); i++) {
		this->Push(stoi(input[i]));
	}
}

void PBlock::Push(int input) {
	this->permutation.push_back(input);
}
