#include "LinearSBlock.h"

LinearSBlock::LinearSBlock()
{
	for (int i = 0; i < 16; i++) {
		this->linearApr.push_back(vector<int> (16));
	}
}

vector<int> LinearSBlock::GetSBlock()
{
	return this->sblock;
}

int LinearSBlock::Push(int input)
{
	vector<int>::iterator itr = find(this->sblock.begin(), this->sblock.end(), input);
	if (itr == this->sblock.end()) {
		this->sblock.push_back(input);
		return 1;
	}
	return 0;
}

void LinearSBlock::Set(vector<string> input)
{
	for (int i = 0; i < input.size(); i++) {
		this->Push(stoi(input[i]));
	}
}

void LinearSBlock::Clear()
{
	this->sblock.clear();
}

void LinearSBlock::СalculateSBlock()
{
	for (int i = 0; i < this->sblock.size(); i++) { // Маска для X
		for (int j = 0; j < this->sblock.size(); j++) { // Маска для Y
			int countMathes = 0;
			for (int k = 0; k < this->sblock.size(); k++) { // Перебираем все варианты и ищем совпадения
				bitset<4> maskX(i);
				bitset<4> maskY(j);

				bitset<4> x(k);
				bitset<4> y(this->sblock[k]);

				bool resX = this->XORBits(maskX, x);
				bool resY = this->XORBits(maskY, y);

				if (resX == resY) { countMathes++; }

			}

			this->linearApr[i][j] = countMathes - 8;
		}
	}
}

bool LinearSBlock::XORBits(bitset<4> mask, bitset<4> input)
{
	bool res = 0, flag = false;
	for (int i = 0; i < 4; i++) {
		if (mask.test(i)) {
			if (flag) {
				res ^= input[i];
			}
			else {
				res = input[i];
				flag = true;
			}
		}
	}

	return res;
}

vector<vector<int>> LinearSBlock::GetlinearApr()
{
	return this->linearApr;
}
