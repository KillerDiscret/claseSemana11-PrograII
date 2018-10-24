#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace Project2;
[STAThread]

void main()
{
	Application::EnableVisualStyles;
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm());

}

