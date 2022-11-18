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

void LinearAproximation::SetTableIndex(int i, int j)
{
	this->tableIndex.first = i;
	this->tableIndex.second = i;
}

void LinearAproximation::Ñalculate()
{
	this->chance.push_back(this->SBlock->GetÑhance(this->tableIndex.first, this->tableIndex.second));

	vector<int> line = this->SBlock->GetLine(this->tableIndex.second);
	
	int col = this->BestColInLine(line);
	this->tableIndex.first = this->tableIndex.second;
	this->tableIndex.second = col;
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
