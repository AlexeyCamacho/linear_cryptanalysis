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

void LinearAproximation::SetPBlock(PBlock* P_block) {
	this->P_block = P_block;
}

void LinearAproximation::SetStartRow(int i)
{
	this->startRow = i;
}

bitset<16> LinearAproximation::GetInput() {
	return this->inputP;
}

bitset<16> LinearAproximation::GetOutput() {
	return this->outputP;
}

double LinearAproximation::GetChance() {
	double res = 0.5; 
	double tmp = pow(2, this->chance.size() - 1);

	for (int i = 0; i < this->chance.size(); i++) {
		tmp *= double(this->chance[i]) / 16;
	}

	res += tmp;

	return res;
}


void LinearAproximation::Ñalculate()
{
	this->tmp = this->inputP;

	for (int i = 0; i < 3; i++) {
		this->DistributeToSblock();
		this->ProcessingSblocks();
		this->MergerSblock();
		this->ProcessingPblock();
	}

	this->outputP = this->tmp;

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

		if (indexLineTable == 0) {
			this->SBlocks[i] = bitset<4>();
			continue;
		}

		vector<int> line = this->SBlock->GetLine(indexLineTable);
		unsigned long indexColTable = this->BestColInLine(line);

		this->chance.push_back(this->SBlock->GetÑhance(indexLineTable, indexColTable));

		this->SBlocks[i] = bitset<4>(indexColTable);
	}
}

void LinearAproximation::MergerSblock() {
	string res;

	for (int i = 0; i < 4; i++) {
		res += this->SBlocks[i].to_string();
	}

	this->tmp = bitset<16>(res);
}

void LinearAproximation::ProcessingPblock() {
	this->tmp = this->P_block->Permutation(this->tmp);
}

