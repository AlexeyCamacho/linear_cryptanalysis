#include "Decryption.h"

Decryption::Decryption() {

}

void Decryption::PushData(int x, int y) {
	this->data.push_back(pair<int, int> (x,y));
}

void Decryption::ClearData() {
	this->data.clear();
}

void Decryption::SetInputApr(bitset<16> input) {
	this->inputApr = input;
}

void Decryption::SetOutputApr(bitset<16> input) {
	this->outputApr = input;
}

void Decryption::SetSblock(LinearSBlock* SBlock) {
	this->SBlock = SBlock;
}

double Decryption::GetChance() {
	return this->chance;
}

void Decryption::SetRealyChance(double chance) {
	this->realyChance = chance;
}

string Decryption::GetKey() {
	string tmp;
	int x = 0;
	for (int i = 0; i < 4; i++) {
		vector<int>::iterator itr = find(this->activeSblocks.begin(), this->activeSblocks.end(), i);
		if (itr == this->activeSblocks.end()) {
			tmp += "0000";
		}
		else {
			bitset<16> y (this->key);
			tmp += y.to_string().substr(4 * (4 - this->activeSblocks.size() + x), 4);
			x++;
		}
	}

	string res;

	for (int i = 0; i < 16; i++) {
		if (this->outputApr.test(15 - i)) {
			res += tmp[15 - i];
		}
		else {
			res += "_";
		}
	}

	return res;

}

void Decryption::Calculate(System::Windows::Forms::ProgressBar^ bar) {
	string tmp;
	for (int i = 4; i > 0; i--) {
		if (this->activeSblocks.size() < i) {
			tmp += "0000";
		}
		else {
			tmp += this->outputApr.to_string().substr(4 * this->activeSblocks[this->activeSblocks.size() - i], 4);
		}
	}

	bitset<16> activeData(tmp);

	double chance = 0;
	int key = 0;

	bar->Maximum = 16 * this->activeSblocks.size();
	bar->Value = 0;

	for (int i = 0; i < 16 * this->activeSblocks.size(); i++) {
		double tmpChance = this->ÑheckKey(i, activeData);

		if (this->realyChance > 0.5) {
			if (tmpChance > chance) { chance = tmpChance; key = i; }
		}
		else {
			if (tmpChance < chance) { chance = tmpChance; key = i; }
		}

		bar->Increment(1);
	}

	this->chance = chance;
	this->key = key;
}

void Decryption::GetActiveSblocks() {
	for (int i = 0; i < 4; i++) {
		bitset<4> tmp (this->outputApr.to_string().substr(4 * i, 4));
		if (tmp.count() > 0) {
			this->activeSblocks.push_back(i);
		}
	}
}

int Decryption::GetCountActiveSblocks() {
	return this->activeSblocks.size();
}

double Decryption::ÑheckKey(int key, bitset<16> activeSblocks) {
	double succes = 0;

	for (int i = 0; i < this->data.size(); i++) {

		string tmp;

		for (int j = 4; j > 0; j--) {
			if (this->activeSblocks.size() < j) {
				tmp += "0000";
			}
			else {
				bitset<16> cryptoText(this->data[i].second);
				tmp += cryptoText.to_string().substr(4 * this->activeSblocks[this->activeSblocks.size() - j], 4);
			}
		}

		bitset<16> activeCryptoText(tmp);

		activeCryptoText ^= bitset<16>(key);

		string res;

		int x = 0;
		for (int j = 0; j < 4; j++) {
			vector<int>::iterator itr = find(this->activeSblocks.begin(), this->activeSblocks.end(), j);
			if (itr == this->activeSblocks.end()) { res += "0000"; continue; }

			string s_block = activeCryptoText.to_string().substr(4 * (4 - this->activeSblocks.size() + x), 4);

			x++;

			unsigned long tmp = this->SBlock->ReverceSubstitution(bitset<4>(s_block));

			res += bitset<4>(tmp).to_string();
		}

		activeCryptoText = bitset<16>(res);


		bool hypothesis, flag = false;

		for (int j = 0; j < 16; j++) {
			if (this->outputApr.test(j)) {
				if (!flag) {
					hypothesis = activeCryptoText[j];
					flag = true;
				}
				else {
					hypothesis ^= activeCryptoText[j];
				}
			}
		}

		bitset<16> input(this->data[i].first);

		for (int j = 0; j < 16; j++) {
			if (this->inputApr.test(j)) {
				hypothesis ^= input[j];
			}
		}

		if (this->realyChance > 0.5) {
			if (hypothesis) {
				succes++;
			}
		}
		else {
			if (!hypothesis) {
				succes++;
			}
		}
		
	}

	double res = (succes - (double(this->data.size()) / 2)) / this->data.size();

	return res;
}