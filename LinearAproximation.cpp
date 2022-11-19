#include "LinearAproximation.h"

LinearAproximation::LinearAproximation()
{
	for (int i = 0; i < 4; i++) {
		this->SBlocks.push_back(bitset<4>());
	}
}

void LinearAproximation::SetInputP(bitset<16> input)
{
	this->inputP = input;
}

void LinearAproximation::SetSblock(LinearSBlock* SBlock)
{
	this->SBlock = SBlock;
}

void LinearAproximation::SetStartRow(int i)
{
	this->startRow = i;
}

void LinearAproximation::Ñalculate()
{
	this->tmp = this->inputP;
	this->DistributeToSblock();
	this->ProcessingSblocks();
}

int LinearAproximation::BestColInLine(vector<int> input)
{
	vector<int> resTmp;
	int res = -1;
	int maxi = -1;

	for (int i = 0; i < input.size(); i++) {
		if (abs(input[i]) > maxi) {
			maxi = abs(input[i]);
			resTmp.clear();
			resTmp.push_back(i);
		}
		else if (abs(input[i]) == maxi) {
			resTmp.push_back(i);
		}
	}


	int min = 5;
	for (int i = 0; i < resTmp.size(); i++) {
		bitset<4> x = bitset<4>(resTmp[i]);
		if (x.count() > 0 && x.count() < min) {
			res = resTmp[i];
			min = x.count();
		}
	}

	return res;
}

void LinearAproximation::DistributeToSblock()
{
	string input;

	for (int i = 0; i < 4; i++) {
		input = this->tmp.to_string().substr(4 * i, 4);
		this->SBlocks[i] = bitset<4>(input);
	}
}

void LinearAproximation::ProcessingSblocks() {
	for (int i = 0; i < 4; i++) {
		unsigned long indexLineTable = this->SBlocks[i].to_ulong();

		vector<int> line = this->SBlock->GetLine(indexLineTable);
		unsigned long indexColTable = this->BestColInLine(line);

		this->chance.push_back(this->SBlock->GetÑhance(indexLineTable, indexColTable));

		this->SBlocks[i] = bitset<4>(indexColTable);
	}
}
