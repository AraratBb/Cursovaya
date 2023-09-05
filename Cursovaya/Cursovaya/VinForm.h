#pragma once


namespace Cursovaya {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ VinForm
	/// </summary>
	public ref class VinForm : public System::Windows::Forms::Form
	{
	public:
		VinForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~VinForm()
		{
			delete components;
		}
	private: System::Windows::Forms::Button^ VinBut;
	private: System::Windows::Forms::TextBox^ VinKeyWord;

	public:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->VinBut = (gcnew System::Windows::Forms::Button());
			this->VinKeyWord = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// VinBut
			// 
			this->VinBut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->VinBut->Location = System::Drawing::Point(12, 73);
			this->VinBut->Name = L"VinBut";
			this->VinBut->Size = System::Drawing::Size(260, 30);
			this->VinBut->TabIndex = 0;
			this->VinBut->Text = L"«ашифровать";
			this->VinBut->UseVisualStyleBackColor = true;
			this->VinBut->Click += gcnew System::EventHandler(this, &VinForm::VinBut_Click);
			// 
			// VinKeyWord
			// 
			this->VinKeyWord->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->VinKeyWord->Location = System::Drawing::Point(12, 21);
			this->VinKeyWord->Multiline = true;
			this->VinKeyWord->Name = L"VinKeyWord";
			this->VinKeyWord->Size = System::Drawing::Size(260, 30);
			this->VinKeyWord->TabIndex = 2;
			this->VinKeyWord->Text = L"¬ведите ключевое слово";
			this->VinKeyWord->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &VinForm::VinKeyWord_MouseClick);
			// 
			// VinForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(283, 110);
			this->Controls->Add(this->VinKeyWord);
			this->Controls->Add(this->VinBut);
			this->Name = L"VinForm";
			this->Text = L"VinForm";
			this->Load += gcnew System::EventHandler(this, &VinForm::VinForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		String^ GetKey();
		System::Void VinBut_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void VinKeyWord_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		System::Void VinForm_Load(System::Object^ sender, System::EventArgs^ e);
	};
}
