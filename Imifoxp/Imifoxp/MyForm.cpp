#include "MyForm.h"

using namespace System;
using namespace Imifoxp;

[STAThread]
int main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    if (args->Length > 0)
    {
        // If an argument is passed, use it as the file path
        String^ filePath = args[0];
        Imifoxp::MyForm^ form = gcnew Imifoxp::MyForm(filePath);
        Application::Run(form);
    }
    else
    {
        // Otherwise, run the default form
        Imifoxp::MyForm^ form = gcnew Imifoxp::MyForm();
        Application::Run(form);
    }
    return 0;  // Завершення програми після закриття форми
}
