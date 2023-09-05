#include "VinForm.h"
#include "FirstForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Cursovaya;

String^ VinForm::GetKey()
{
	return VinKeyWord->Text;
}

Void VinForm::VinBut_Click(Object^ sender, EventArgs^ e)
{
	if (VinKeyWord->Text->Length == 0 || VinKeyWord->Text == L"Введите ключевое слово")
	{
		VinKeyWord->Text = L"Введите ключевое слово";
		return Void();
	}
	open--;
	flag = true;
	this->Close();

	return Void();
}

Void VinForm::VinKeyWord_MouseClick(Object^ sender, MouseEventArgs^ e)
{
	if (VinKeyWord->Text == L"Введите ключевое слово")
		VinKeyWord->Text = L"";

	return Void();
}

System::Void Cursovaya::VinForm::VinForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
