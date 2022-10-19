#include "LinearSBlock.h"

vector<int> LinearSBlock::GetSBlock()
{
	return this->sblock;
}

void LinearSBlock::Push(int input)
{
	this->sblock.push_back(input);
}

void LinearSBlock::Clear()
{
	this->sblock.clear();
}

void LinearSBlock::ÑalculateSBlock()
{

}
