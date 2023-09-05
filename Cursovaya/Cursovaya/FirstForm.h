#pragma once

#include "VinForm.h"
#include "dll/dll.h"
#pragma comment(lib, "bin\\dll.lib")
#include <msclr\marshal_cppstd.h>

namespace Cursovaya {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FirstForm
	/// </summary>
	public ref class FirstForm : public System::Windows::Forms::Form
	{
	public:
		FirstForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// 
		~FirstForm()
		{
			db.~DB();
			KEY.~basic_string();
			enc_choose.~basic_string();
			text.~basic_string();
			delete components;
		}

	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::TextBox^ Encryption;
	private: System::Windows::Forms::TextBox^ CleanText;
	private: System::Windows::Forms::ComboBox^ EncChoose;
	private: System::Windows::Forms::Button^ EncBut;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::ComponentModel::IContainer^ components;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Encryption = (gcnew System::Windows::Forms::TextBox());
			this->CleanText = (gcnew System::Windows::Forms::TextBox());
			this->EncChoose = (gcnew System::Windows::Forms::ComboBox());
			this->EncBut = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// Encryption
			// 
			this->Encryption->BackColor = System::Drawing::SystemColors::Window;
			this->Encryption->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Encryption->Location = System::Drawing::Point(499, 12);
			this->Encryption->Multiline = true;
			this->Encryption->Name = L"Encryption";
			this->Encryption->ReadOnly = true;
			this->Encryption->Size = System::Drawing::Size(394, 249);
			this->Encryption->TabIndex = 10;
			// 
			// CleanText
			// 
			this->CleanText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CleanText->Location = System::Drawing::Point(28, 12);
			this->CleanText->Multiline = true;
			this->CleanText->Name = L"CleanText";
			this->CleanText->Size = System::Drawing::Size(394, 249);
			this->CleanText->TabIndex = 11;
			this->CleanText->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &FirstForm::CleanText_MouseClick);
			// 
			// EncChoose
			// 
			this->EncChoose->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EncChoose->FormattingEnabled = true;
			this->EncChoose->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Шифр Цезаря", L"Шифр Гронсфельда", L"Шифр Виженера" });
			this->EncChoose->Location = System::Drawing::Point(28, 277);
			this->EncChoose->Name = L"EncChoose";
			this->EncChoose->Size = System::Drawing::Size(202, 24);
			this->EncChoose->TabIndex = 14;
			this->EncChoose->Text = L"Выберите тип шифрования";
			// 
			// EncBut
			// 
			this->EncBut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EncBut->Location = System::Drawing::Point(312, 278);
			this->EncBut->Name = L"EncBut";
			this->EncBut->Size = System::Drawing::Size(110, 23);
			this->EncBut->TabIndex = 15;
			this->EncBut->Text = L"Зашировать";
			this->EncBut->UseVisualStyleBackColor = true;
			this->EncBut->Click += gcnew System::EventHandler(this, &FirstForm::EncBut_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Window;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(499, 267);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(394, 34);
			this->textBox1->TabIndex = 16;
			// 
			// FirstForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(924, 336);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->EncBut);
			this->Controls->Add(this->EncChoose);
			this->Controls->Add(this->CleanText);
			this->Controls->Add(this->Encryption);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Location = System::Drawing::Point(10, 10);
			this->Margin = System::Windows::Forms::Padding(6);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FirstForm";
			this->Text = L"  ";
			this->Activated += gcnew System::EventHandler(this, &FirstForm::FirstForm_Activated);
			this->Load += gcnew System::EventHandler(this, &FirstForm::FirstForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		VinForm^ f;
		System::Void FirstForm_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void CleanText_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		System::Void EncBut_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void FirstForm_Activated(System::Object^ sender, System::EventArgs^ e);
};

}
