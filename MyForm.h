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
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
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
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
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
			this->button3->Location = System::Drawing::Point(17, 362);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(120, 34);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Взлом";
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
			this->dataGridView1->Size = System::Drawing::Size(717, 509);
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
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(17, 174);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 16, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 22);
			this->numericUpDown1->TabIndex = 11;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(13, 151);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(165, 20);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Начальная строка";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(12, 208);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(176, 20);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Начальная столбец";
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(16, 231);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 16, 0, 0, 0 });
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(120, 22);
			this->numericUpDown2->TabIndex = 13;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(12, 273);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(162, 20);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Начальный SBlock";
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(16, 296);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			this->numericUpDown3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(120, 22);
			this->numericUpDown3->TabIndex = 15;
			this->numericUpDown3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1326, 682);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->numericUpDown1);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 

	System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { // Выбор файла
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) { return; }
		filename = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);

		SBlock->Clear();

		string input;

		ifstream fileInput(filename);
		getline(fileInput, input);
		vector<string> line = split(input, ' ');

		SBlock->Set(line);

		getline(fileInput, input);
		line = split(input, ' ');
		P_Block->Set(line);

		UpdateDisplayBlocks();

		fileInput.close();
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

	System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { // Взлом
		SBlock->СalculateSBlock();
		vector<vector<int>> linearApr = SBlock->GetlinearApr();
		DrowGrid(linearApr);

		int tableLine = Convert::ToInt16(this->numericUpDown1->Value);
		int tableCol = Convert::ToInt16(this->numericUpDown2->Value);
		int startSblock = Convert::ToInt16(this->numericUpDown3->Value);

		LinearAproximation* LinApr = new LinearAproximation();

		LinApr->SetInputP(bitset<16> (tableLine << (12 - 4 * (startSblock - 1))));
		LinApr->SetSblock(SBlock);
		LinApr->SetTableIndex(tableLine, tableCol);
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
};
}
