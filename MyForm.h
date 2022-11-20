#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "LinearSBlock.h"
#include "LinearAproximation.h"
#include "Decryption.h"
#include "Function.h"
#include "PBlock.h"
#include <msclr\marshal_cppstd.h>

namespace linearcryptanalysis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	LinearSBlock* SBlock = new LinearSBlock();
	PBlock* P_Block = new PBlock();

	string filename;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->label2->Text = "";
			this->label3->Text = "";
			this->label5->Text = "";
			this->label13->Text = "";
			this->label14->Text = "";
			this->label15->Text = "";
			this->dataGridView1->ColumnCount = 16;
			this->dataGridView1->RowCount = 16;

			for (int i = 0; i < 16; i++) {
				this->dataGridView1->Columns[i]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
			}

			dataGridView1->Font = gcnew System::Drawing::Font("Arial", 12);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;


	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown3;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"S-block:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(89, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"БЛОК";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(17, 84);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(120, 37);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Ввод";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::Red;
			this->label3->Location = System::Drawing::Point(13, 124);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(75, 20);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Ошибки";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(16, 286);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(120, 32);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Анализ";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(205, 73);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 15;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(826, 509);
			this->dataGridView1->TabIndex = 8;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(13, 33);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(70, 20);
			this->label4->TabIndex = 9;
			this->label4->Text = L"P-block:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(89, 33);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(57, 20);
			this->label5->TabIndex = 10;
			this->label5->Text = L"БЛОК";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(12, 211);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(162, 20);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Начальный SBlock";
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown3->Location = System::Drawing::Point(16, 234);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			this->numericUpDown3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(120, 27);
			this->numericUpDown3->TabIndex = 15;
			this->numericUpDown3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(13, 159);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(165, 20);
			this->label6->TabIndex = 18;
			this->label6->Text = L"Начальная строка";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown1->Location = System::Drawing::Point(17, 182);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 27);
			this->numericUpDown1->TabIndex = 17;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(1049, 73);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(114, 20);
			this->label9->TabIndex = 19;
			this->label9->Text = L"Результаты:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(1049, 124);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(88, 20);
			this->label10->TabIndex = 20;
			this->label10->Text = L"Входные:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(1049, 174);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(100, 20);
			this->label11->TabIndex = 21;
			this->label11->Text = L"Выходные:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(1049, 224);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(125, 20);
			this->label12->TabIndex = 22;
			this->label12->Text = L"Вероятность:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->Location = System::Drawing::Point(1049, 144);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(22, 20);
			this->label13->TabIndex = 23;
			this->label13->Text = L"In";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->Location = System::Drawing::Point(1049, 194);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(36, 20);
			this->label14->TabIndex = 24;
			this->label14->Text = L"Out";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label15->Location = System::Drawing::Point(1049, 244);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(66, 20);
			this->label15->TabIndex = 25;
			this->label15->Text = L"Chance";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(16, 324);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 34);
			this->button1->TabIndex = 26;
			this->button1->Text = L"Взлом";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1326, 682);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Линейный криптоанализ";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 

	System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { // Выбор файла
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) { return; }
		filename = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);

		SBlock->Clear();
		P_Block->Clear();

		string input;

		ifstream fileInput(filename);
		getline(fileInput, input);
		vector<string> line = split(input, ' ');

		SBlock->Set(line);

		getline(fileInput, input);
		line = split(input, ' ');
		P_Block->Set(line);

		fileInput.close();

		UpdateDisplayBlocks();
		SBlock->СalculateSBlock();
		vector<vector<int>> linearApr = SBlock->GetlinearApr();
		DrowGrid(linearApr);
	}

	void UpdateDisplayBlocks() {
		this->label2->Text = "";

		vector <int> numbers = SBlock->GetSBlock();

		for (int i = 0; i < numbers.size(); i++) {
			this->label2->Text += numbers[i];
			if (i != numbers.size() - 1) {
				this->label2->Text += ", ";
			}
		}

		this->label5->Text = "";

		numbers = P_Block->GetPermutation();

		for (int i = 0; i < numbers.size(); i++) {
			this->label5->Text += numbers[i];
			if (i != numbers.size() - 1) {
				this->label5->Text += ", ";
			}
		}
	}

	System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { // Анализ
		int tableLine = Convert::ToInt16(this->numericUpDown1->Value);
		int startSblock = Convert::ToInt16(this->numericUpDown3->Value);

		LinearAproximation* LinApr = new LinearAproximation();

		LinApr->SetInputP(bitset<16> (tableLine << (12 - 4 * (startSblock - 1))));
		LinApr->SetSblock(SBlock);
		LinApr->SetPBlock(P_Block);
		LinApr->SetStartRow(tableLine);

		LinApr->Сalculate();

		this->label13->Text = gcnew System::String(LinApr->GetInput().to_string().c_str());

		this->label14->Text = gcnew System::String(LinApr->GetOutput().to_string().c_str());

		this->label15->Text = gcnew System::String(LinApr->GetChance().ToString());
	}

	void DrowGrid(vector<vector<int>> linearApr) {
		for (int i = 0; i < linearApr.size(); i++) {
			this->dataGridView1->Columns[i]->HeaderText = gcnew System::String(i.ToString());
			this->dataGridView1->Rows[i]->HeaderCell->Value = gcnew System::String(i.ToString());
		}

		for (int i = 0; i < linearApr.size(); i++) {
			for (int j = 0; j < linearApr.size(); j++) {
				this->dataGridView1->Rows[i]->Cells[j]->Value = linearApr[i][j];
			}
		}
	}
	System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { // Взлом
		Decryption* Decryptor = new Decryption();
		Decryptor->SetSblock(SBlock);
		
		ifstream fileInput(filename);
		string input;
		getline(fileInput, input);
		getline(fileInput, input);

		while (getline(fileInput, input)) {
			vector<string> line = split(input, ' ');
			Decryptor->PushData(atoi(line[0].c_str()), atoi(line[1].c_str()));
		}

		fileInput.close();

		string in = msclr::interop::marshal_as<std::string>(this->label13->Text);
		string out = msclr::interop::marshal_as<std::string>(this->label14->Text);

		Decryptor->SetInputApr(bitset<16>(in));
		Decryptor->SetOutputApr(bitset<16>(out));

		Decryptor->Calculate();
	}
};
}
