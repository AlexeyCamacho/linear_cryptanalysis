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
