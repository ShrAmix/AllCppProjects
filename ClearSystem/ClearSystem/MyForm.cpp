#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

// Головна функція — точка входу програми
[STAThreadAttribute]
int main(array<String^>^ args)
{

    // Увімкнення візуальних стилів
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Створення і запуск форми
    ClearSystem::MyForm^ form = gcnew ClearSystem::MyForm();
    Application::Run(form);

    return 0;
}
