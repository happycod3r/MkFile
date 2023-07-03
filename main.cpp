#using <System.dll>
#using <System.Windows.Forms.dll>

#include "main.h"
#include "gui.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array<String^>^ args) {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MkFile::gui());
	return 0;
}