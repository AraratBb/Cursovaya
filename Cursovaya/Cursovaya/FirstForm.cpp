#include "FirstForm.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace Cursovaya;

[STAThreadAttribute]

int main(array<String^>^ args)
{
	ContextMenuStrip;
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	FirstForm form;
	Application::Run(% form);
}

Void FirstForm::FirstForm_Load(Object^ sender, EventArgs^ e)
{
	this->CleanText->Text = L"Начните ввод сообщения, после чего выберите внизу тип шифровния";
	return Void();
}

Void FirstForm::CleanText_MouseClick(Object^ sender, MouseEventArgs^ e)
{

	if(this->CleanText->Text == L"Начните ввод сообщения, после чего выберите внизу тип шифровния")
		this->CleanText->Text = L"";

	return Void();
}

Void FirstForm::EncBut_Click(Object^ sender, EventArgs^ e)
{
	text = msclr::interop::marshal_as<string>(CleanText->Text);
	enc_choose = msclr::interop::marshal_as<string>(EncChoose->Text);

	if (enc_choose == "Выберите тип шифрования")
		return Void();

	if (enc_choose == "Шифр Виженера" && open == 0)
	{
		f = gcnew VinForm();
		f->Show();
		open++;
		return Void();
	}

	KEY = "Ключ: ";
	text = db[enc_choose]->Cipher(text);
	Encryption->Text = gcnew String(text.c_str());
	KEY += db[enc_choose]->print_key;
	textBox1->Text = gcnew String(KEY.c_str());


	return Void();
}

Void FirstForm::FirstForm_Activated(Object^ sender, EventArgs^ e)
{
	if (flag)
	{
		KEY = "Ключ: ";
		text = msclr::interop::marshal_as<string>(CleanText->Text);
		db[enc_choose]->print_key = msclr::interop::marshal_as<string>(f->GetKey());
		text = db[enc_choose]->Cipher(text);
		Encryption->Text = gcnew String(text.c_str());
		KEY += db[enc_choose]->print_key;
		textBox1->Text = gcnew String(KEY.c_str());
	}
	return Void();
}