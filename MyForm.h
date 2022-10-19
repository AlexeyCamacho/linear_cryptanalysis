#pragma once
#include <vector>
#include <string>
#include "LinearSBlock.h"

namespace linearcryptanalysis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	LinearSBlock* SBlock = new LinearSBlock();

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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::DataGridView^ dataGridView1;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
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
			// button1
			// 
			this->button1->Location = System::Drawing::Point(17, 127);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 34);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Очистить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
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
			// numericUpDown1
			// 
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown1->Location = System::Drawing::Point(17, 51);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 27);
			this->numericUpDown1->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::Red;
			this->label3->Location = System::Drawing::Point(14, 176);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(75, 20);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Ошибки";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(17, 199);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(120, 34);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Расчитать";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(201, 51);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 15;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(717, 509);
			this->dataGridView1->TabIndex = 8;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1326, 682);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Линейный криптоанализ";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
	System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { // Очистить SBlock
		SBlock->Clear();
		UpdateDisplaySblock();
	}

	System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { // Ввод
		this->label3->Text = "";
		int input = Convert::ToInt16(this->numericUpDown1->Value);

		if (!SBlock->Push(input)){
			this->label3->Text = "Данный элемент уже есть!";
		}

		UpdateDisplaySblock();

		this->numericUpDown1->Focus();
	}

	void UpdateDisplaySblock() {
		this->label2->Text = "";

		vector <int> numbers = SBlock->GetSBlock();

		for (int i = 0; i < numbers.size(); i++) {
			this->label2->Text += numbers[i];
			if (i != numbers.size() - 1) {
				this->label2->Text += ", ";
			}
		}
	}

	System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		SBlock->СalculateSBlock();
		vector<vector<int>> linearApr = SBlock->GetlinearApr();
		DrowGrid(linearApr);
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
