#pragma once

namespace ClearSystem {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Collections::Generic;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::IO;
    using namespace Microsoft::Win32;
    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;
        System::Windows::Forms::Button^ buttonDelete;
        System::Windows::Forms::Button^ buttonScan;
        System::Windows::Forms::ListBox^ listBoxFiles;
        System::Windows::Forms::CheckBox^ checkBoxDownloadFolder;
    private: System::Windows::Forms::CheckBox^ checkBoxTemp;
    private: System::Windows::Forms::CheckBox^ checkBoxRecycleBin;
    private: System::Windows::Forms::CheckBox^ checkBoxBrowserCache;
    private: System::Windows::Forms::CheckBox^ checkBoxPrefetch;

    private: System::Windows::Forms::CheckBox^ checkBoxStoreCache;
    private: System::Windows::Forms::CheckBox^ checkBoxOldLogs;
    private: System::Windows::Forms::CheckBox^ checkBoxRestorePointsOld;
    private: System::Windows::Forms::CheckBox^ checkBoxDumpFiles;

    private: System::Windows::Forms::CheckBox^ checkBoxRestorePointsNew;
    private: System::Windows::Forms::Label^ labelHowMany;
    private: System::Windows::Forms::RadioButton^ radioButtonNoAll;
    private: System::Windows::Forms::RadioButton^ radioButtonAll;
    private: System::Windows::Forms::Label^ labelTap;
    private: System::Windows::Forms::Label^ labelAllSize;
    private: System::Windows::Forms::Label^ labelSizeTab;





           System::Windows::Forms::ProgressBar^ progressBar;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->progressBar = (gcnew System::Windows::Forms::ProgressBar());
            this->buttonDelete = (gcnew System::Windows::Forms::Button());
            this->buttonScan = (gcnew System::Windows::Forms::Button());
            this->listBoxFiles = (gcnew System::Windows::Forms::ListBox());
            this->checkBoxDownloadFolder = (gcnew System::Windows::Forms::CheckBox());
            this->checkBoxTemp = (gcnew System::Windows::Forms::CheckBox());
            this->checkBoxRecycleBin = (gcnew System::Windows::Forms::CheckBox());
            this->checkBoxBrowserCache = (gcnew System::Windows::Forms::CheckBox());
            this->checkBoxPrefetch = (gcnew System::Windows::Forms::CheckBox());
            this->checkBoxStoreCache = (gcnew System::Windows::Forms::CheckBox());
            this->checkBoxOldLogs = (gcnew System::Windows::Forms::CheckBox());
            this->checkBoxRestorePointsOld = (gcnew System::Windows::Forms::CheckBox());
            this->checkBoxDumpFiles = (gcnew System::Windows::Forms::CheckBox());
            this->checkBoxRestorePointsNew = (gcnew System::Windows::Forms::CheckBox());
            this->labelHowMany = (gcnew System::Windows::Forms::Label());
            this->radioButtonNoAll = (gcnew System::Windows::Forms::RadioButton());
            this->radioButtonAll = (gcnew System::Windows::Forms::RadioButton());
            this->labelTap = (gcnew System::Windows::Forms::Label());
            this->labelAllSize = (gcnew System::Windows::Forms::Label());
            this->labelSizeTab = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // progressBar
            // 
            this->progressBar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->progressBar->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->progressBar->Location = System::Drawing::Point(12, 331);
            this->progressBar->Name = L"progressBar";
            this->progressBar->Size = System::Drawing::Size(1000, 23);
            this->progressBar->TabIndex = 5;
            // 
            // buttonDelete
            // 
            this->buttonDelete->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->buttonDelete->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->buttonDelete->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonDelete.BackgroundImage")));
            this->buttonDelete->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->buttonDelete->Cursor = System::Windows::Forms::Cursors::Hand;
            this->buttonDelete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonDelete->Location = System::Drawing::Point(903, 363);
            this->buttonDelete->Name = L"buttonDelete";
            this->buttonDelete->Size = System::Drawing::Size(109, 109);
            this->buttonDelete->TabIndex = 1;
            this->buttonDelete->UseVisualStyleBackColor = false;
            this->buttonDelete->Click += gcnew System::EventHandler(this, &MyForm::buttonDelete_Click);
            // 
            // buttonScan
            // 
            this->buttonScan->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->buttonScan->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->buttonScan->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonScan.BackgroundImage")));
            this->buttonScan->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->buttonScan->Cursor = System::Windows::Forms::Cursors::Hand;
            this->buttonScan->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonScan->Location = System::Drawing::Point(788, 363);
            this->buttonScan->Name = L"buttonScan";
            this->buttonScan->Size = System::Drawing::Size(109, 109);
            this->buttonScan->TabIndex = 2;
            this->buttonScan->UseVisualStyleBackColor = false;
            this->buttonScan->Click += gcnew System::EventHandler(this, &MyForm::buttonScan_Click);
            // 
            // listBoxFiles
            // 
            this->listBoxFiles->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->listBoxFiles->BackColor = System::Drawing::SystemColors::InactiveCaption;
            this->listBoxFiles->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->listBoxFiles->FormattingEnabled = true;
            this->listBoxFiles->ItemHeight = 16;
            this->listBoxFiles->Location = System::Drawing::Point(12, 13);
            this->listBoxFiles->Name = L"listBoxFiles";
            this->listBoxFiles->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
            this->listBoxFiles->Size = System::Drawing::Size(1000, 308);
            this->listBoxFiles->TabIndex = 3;
            this->listBoxFiles->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBoxFiles_SelectedIndexChanged);
            // 
            // checkBoxDownloadFolder
            // 
            this->checkBoxDownloadFolder->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->checkBoxDownloadFolder->AutoSize = true;
            this->checkBoxDownloadFolder->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->checkBoxDownloadFolder->Location = System::Drawing::Point(12, 383);
            this->checkBoxDownloadFolder->Name = L"checkBoxDownloadFolder";
            this->checkBoxDownloadFolder->Size = System::Drawing::Size(166, 20);
            this->checkBoxDownloadFolder->TabIndex = 4;
            this->checkBoxDownloadFolder->Text = L"Папка Завантаження";
            this->checkBoxDownloadFolder->UseVisualStyleBackColor = true;
            // 
            // checkBoxTemp
            // 
            this->checkBoxTemp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->checkBoxTemp->AutoSize = true;
            this->checkBoxTemp->Checked = true;
            this->checkBoxTemp->CheckState = System::Windows::Forms::CheckState::Checked;
            this->checkBoxTemp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->checkBoxTemp->Location = System::Drawing::Point(12, 360);
            this->checkBoxTemp->Name = L"checkBoxTemp";
            this->checkBoxTemp->Size = System::Drawing::Size(140, 20);
            this->checkBoxTemp->TabIndex = 6;
            this->checkBoxTemp->Text = L"Тимчасові файли";
            this->checkBoxTemp->UseVisualStyleBackColor = true;
            // 
            // checkBoxRecycleBin
            // 
            this->checkBoxRecycleBin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->checkBoxRecycleBin->AutoSize = true;
            this->checkBoxRecycleBin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->checkBoxRecycleBin->Location = System::Drawing::Point(12, 452);
            this->checkBoxRecycleBin->Name = L"checkBoxRecycleBin";
            this->checkBoxRecycleBin->Size = System::Drawing::Size(66, 20);
            this->checkBoxRecycleBin->TabIndex = 7;
            this->checkBoxRecycleBin->Text = L"Кошик";
            this->checkBoxRecycleBin->UseVisualStyleBackColor = true;
            // 
            // checkBoxBrowserCache
            // 
            this->checkBoxBrowserCache->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->checkBoxBrowserCache->AutoSize = true;
            this->checkBoxBrowserCache->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->checkBoxBrowserCache->Location = System::Drawing::Point(12, 406);
            this->checkBoxBrowserCache->Name = L"checkBoxBrowserCache";
            this->checkBoxBrowserCache->Size = System::Drawing::Size(118, 20);
            this->checkBoxBrowserCache->TabIndex = 8;
            this->checkBoxBrowserCache->Text = L"Кеш браузера";
            this->checkBoxBrowserCache->UseVisualStyleBackColor = true;
            // 
            // checkBoxPrefetch
            // 
            this->checkBoxPrefetch->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->checkBoxPrefetch->AutoSize = true;
            this->checkBoxPrefetch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->checkBoxPrefetch->Location = System::Drawing::Point(185, 454);
            this->checkBoxPrefetch->Name = L"checkBoxPrefetch";
            this->checkBoxPrefetch->Size = System::Drawing::Size(75, 20);
            this->checkBoxPrefetch->TabIndex = 9;
            this->checkBoxPrefetch->Text = L"Prefetch";
            this->checkBoxPrefetch->UseVisualStyleBackColor = true;
            // 
            // checkBoxStoreCache
            // 
            this->checkBoxStoreCache->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->checkBoxStoreCache->AutoSize = true;
            this->checkBoxStoreCache->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->checkBoxStoreCache->Location = System::Drawing::Point(12, 429);
            this->checkBoxStoreCache->Name = L"checkBoxStoreCache";
            this->checkBoxStoreCache->Size = System::Drawing::Size(143, 20);
            this->checkBoxStoreCache->TabIndex = 9;
            this->checkBoxStoreCache->Text = L"Кеш Microsoft Store";
            this->checkBoxStoreCache->UseVisualStyleBackColor = true;
            // 
            // checkBoxOldLogs
            // 
            this->checkBoxOldLogs->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->checkBoxOldLogs->AutoSize = true;
            this->checkBoxOldLogs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->checkBoxOldLogs->Location = System::Drawing::Point(185, 408);
            this->checkBoxOldLogs->Name = L"checkBoxOldLogs";
            this->checkBoxOldLogs->Size = System::Drawing::Size(187, 20);
            this->checkBoxOldLogs->TabIndex = 10;
            this->checkBoxOldLogs->Text = L"Старі журнали оновлень";
            this->checkBoxOldLogs->UseVisualStyleBackColor = true;
            // 
            // checkBoxRestorePointsOld
            // 
            this->checkBoxRestorePointsOld->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->checkBoxRestorePointsOld->AutoSize = true;
            this->checkBoxRestorePointsOld->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->checkBoxRestorePointsOld->Location = System::Drawing::Point(185, 362);
            this->checkBoxRestorePointsOld->Name = L"checkBoxRestorePointsOld";
            this->checkBoxRestorePointsOld->Size = System::Drawing::Size(187, 20);
            this->checkBoxRestorePointsOld->TabIndex = 11;
            this->checkBoxRestorePointsOld->Text = L"Старі точки відновлення";
            this->checkBoxRestorePointsOld->UseVisualStyleBackColor = true;
            // 
            // checkBoxDumpFiles
            // 
            this->checkBoxDumpFiles->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->checkBoxDumpFiles->AutoSize = true;
            this->checkBoxDumpFiles->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->checkBoxDumpFiles->Location = System::Drawing::Point(185, 431);
            this->checkBoxDumpFiles->Name = L"checkBoxDumpFiles";
            this->checkBoxDumpFiles->Size = System::Drawing::Size(107, 20);
            this->checkBoxDumpFiles->TabIndex = 12;
            this->checkBoxDumpFiles->Text = L"Дамп-файли";
            this->checkBoxDumpFiles->UseVisualStyleBackColor = true;
            // 
            // checkBoxRestorePointsNew
            // 
            this->checkBoxRestorePointsNew->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->checkBoxRestorePointsNew->AutoSize = true;
            this->checkBoxRestorePointsNew->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->checkBoxRestorePointsNew->Location = System::Drawing::Point(185, 385);
            this->checkBoxRestorePointsNew->Name = L"checkBoxRestorePointsNew";
            this->checkBoxRestorePointsNew->Size = System::Drawing::Size(181, 20);
            this->checkBoxRestorePointsNew->TabIndex = 13;
            this->checkBoxRestorePointsNew->Text = L"Нові точки відновлення";
            this->checkBoxRestorePointsNew->UseVisualStyleBackColor = true;
            // 
            // labelHowMany
            // 
            this->labelHowMany->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->labelHowMany->AutoSize = true;
            this->labelHowMany->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->labelHowMany->Location = System::Drawing::Point(600, 459);
            this->labelHowMany->Name = L"labelHowMany";
            this->labelHowMany->Size = System::Drawing::Size(134, 16);
            this->labelHowMany->TabIndex = 14;
            this->labelHowMany->Text = L"Знайдено файлів: 0";
            // 
            // radioButtonNoAll
            // 
            this->radioButtonNoAll->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->radioButtonNoAll->AutoSize = true;
            this->radioButtonNoAll->Checked = true;
            this->radioButtonNoAll->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->radioButtonNoAll->Location = System::Drawing::Point(394, 362);
            this->radioButtonNoAll->Name = L"radioButtonNoAll";
            this->radioButtonNoAll->Size = System::Drawing::Size(164, 20);
            this->radioButtonNoAll->TabIndex = 15;
            this->radioButtonNoAll->TabStop = true;
            this->radioButtonNoAll->Text = L"Видалити виборочно";
            this->radioButtonNoAll->UseVisualStyleBackColor = true;
            this->radioButtonNoAll->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButtonNoAll_CheckedChanged);
            // 
            // radioButtonAll
            // 
            this->radioButtonAll->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->radioButtonAll->AutoSize = true;
            this->radioButtonAll->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->radioButtonAll->Location = System::Drawing::Point(394, 385);
            this->radioButtonAll->Name = L"radioButtonAll";
            this->radioButtonAll->Size = System::Drawing::Size(115, 20);
            this->radioButtonAll->TabIndex = 16;
            this->radioButtonAll->Text = L"Видалити все";
            this->radioButtonAll->UseVisualStyleBackColor = true;
            this->radioButtonAll->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButtonAll_CheckedChanged);
            // 
            // labelTap
            // 
            this->labelTap->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->labelTap->AutoSize = true;
            this->labelTap->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->labelTap->Location = System::Drawing::Point(599, 443);
            this->labelTap->Name = L"labelTap";
            this->labelTap->Size = System::Drawing::Size(135, 16);
            this->labelTap->TabIndex = 17;
            this->labelTap->Text = L"Виділено об\'єктів: 0";
            // 
            // labelAllSize
            // 
            this->labelAllSize->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->labelAllSize->AutoSize = true;
            this->labelAllSize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->labelAllSize->Location = System::Drawing::Point(338, 459);
            this->labelAllSize->Name = L"labelAllSize";
            this->labelAllSize->Size = System::Drawing::Size(171, 16);
            this->labelAllSize->TabIndex = 18;
            this->labelAllSize->Text = L"Загальний розмір: 0 байт";
            // 
            // labelSizeTab
            // 
            this->labelSizeTab->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->labelSizeTab->AutoSize = true;
            this->labelSizeTab->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->labelSizeTab->Location = System::Drawing::Point(338, 443);
            this->labelSizeTab->Name = L"labelSizeTab";
            this->labelSizeTab->Size = System::Drawing::Size(175, 16);
            this->labelSizeTab->TabIndex = 19;
            this->labelSizeTab->Text = L"Розмір виділеного: 0 байт";
            // 
            // MyForm
            // 
            this->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->ClientSize = System::Drawing::Size(1024, 484);
            this->Controls->Add(this->labelSizeTab);
            this->Controls->Add(this->labelAllSize);
            this->Controls->Add(this->labelTap);
            this->Controls->Add(this->radioButtonAll);
            this->Controls->Add(this->radioButtonNoAll);
            this->Controls->Add(this->labelHowMany);
            this->Controls->Add(this->checkBoxRestorePointsNew);
            this->Controls->Add(this->checkBoxDumpFiles);
            this->Controls->Add(this->checkBoxRestorePointsOld);
            this->Controls->Add(this->checkBoxOldLogs);
            this->Controls->Add(this->checkBoxStoreCache);
            this->Controls->Add(this->checkBoxPrefetch);
            this->Controls->Add(this->checkBoxBrowserCache);
            this->Controls->Add(this->checkBoxRecycleBin);
            this->Controls->Add(this->checkBoxTemp);
            this->Controls->Add(this->checkBoxDownloadFolder);
            this->Controls->Add(this->listBoxFiles);
            this->Controls->Add(this->buttonScan);
            this->Controls->Add(this->buttonDelete);
            this->Controls->Add(this->progressBar);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->MinimumSize = System::Drawing::Size(1040, 350);
            this->Name = L"MyForm";
            this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
            this->Text = L"ClearSystem";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
        void SaveDownloadPathToFile(String^ downloadPath)
        {
            // Шлях до текстового файлу
            String^ filePath = "downloadPath.txt";

            // Запис шляху до файлу
            File::WriteAllText(filePath, downloadPath);
        }
        String^ GetDefaultBrowser()
        {
            String^ browserPath = nullptr;
            RegistryKey^ key = Registry::ClassesRoot->OpenSubKey("HTTP\\shell\\open\\command");
            if (key != nullptr)
            {
                browserPath = (String^)key->GetValue("");
                browserPath = browserPath->Trim('"');
            }
            return browserPath;
        }
        String^ GetDownloadPathFromFile()
        {
            // Шлях до текстового файлу
            String^ filePath = "downloadPath.txt";

            // Перевіряємо чи існує файл
            if (File::Exists(filePath))
            {
                // Зчитуємо шлях з файлу
                return File::ReadAllText(filePath);
            }

            return nullptr;  // Якщо файл не існує, повертаємо null
        }

        void buttonScan_Click(System::Object^ sender, System::EventArgs^ e)
        {
            listBoxFiles->Items->Clear();
            progressBar->Value = 0;

            // Оголошуємо список файлів та ініціалізуємо його
            List<String^>^ files = gcnew List<String^>();

            // Оголошуємо масив шляхів для перевірки
            array<String^>^ pathsToCheck = nullptr;

            // Якщо checkbox для тимчасових файлів вибраний, ініціалізуємо список шляхів
            if (checkBoxTemp->Checked) {
                pathsToCheck = gcnew array<String^>
                {
                    "C:\\Windows\\Temp",
                        "C:\\Users\\" + Environment::UserName + "\\AppData\\Local\\Temp",
                        "C:\\Users\\" + Environment::UserName + "\\AppData\\Local\\Microsoft\\Windows\\INetCache",
                };
            }

            // Додатково сканувати папку "Завантаження"
            if (checkBoxDownloadFolder->Checked)
            {
                String^ downloadPath = GetDownloadPathFromFile();

                // Якщо шлях не збережений, дозволяємо вибір
                if (downloadPath == nullptr || !downloadPath->Contains("\\Downloads"))
                {
                    downloadPath = Environment::GetFolderPath(Environment::SpecialFolder::UserProfile) + "\\Downloads";

                    // Створюємо діалогове вікно для вибору папки
                    FolderBrowserDialog^ folderBrowserDialog = gcnew FolderBrowserDialog();
                    folderBrowserDialog->Description = "Оберіть папку 'Downloads'";
                    folderBrowserDialog->SelectedPath = downloadPath;  // Значення за замовчуванням

                    // Повторюємо вибір, поки шлях не містить папку "Downloads"
                    while (true)
                    {
                        if (folderBrowserDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
                        {
                            downloadPath = folderBrowserDialog->SelectedPath;

                            // Перевірка, чи вибрана папка містить "Downloads"
                            if (downloadPath->Contains("\\Downloads"))
                            {
                                // Зберігаємо шлях у файл
                                SaveDownloadPathToFile(downloadPath);
                                break;
                            }
                            else
                            {
                                MessageBox::Show("Вибрана папка повинна містити 'Downloads'. Будь ласка, оберіть правильну папку.",
                                    "Неправильна папка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                            }
                        }
                        else
                        {
                            MessageBox::Show("Ви повинні обрати папку 'Downloads' для продовження.",
                                "Увага", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                        }
                    }
                }

                // Сканування вибраної папки
                if (Directory::Exists(downloadPath))
                {
                    array<String^>^ downloadFiles = Directory::GetFiles(downloadPath, "*.*", SearchOption::AllDirectories);
                    files->AddRange(downloadFiles);
                }
            }

            // Перевірка кожного шляху
            if (pathsToCheck != nullptr) // Перевірка на те, чи були шляхи ініціалізовані
            {
                
                for each (String ^ path in pathsToCheck)
                {
                    try
                    {
                        if (Directory::Exists(path))
                        {
                            // Отримання всіх файлів у папці
                            array<String^>^ tempFiles = Directory::GetFiles(path, "*.*", SearchOption::AllDirectories);
                            files->AddRange(tempFiles);
                        }
                    }
                    catch (UnauthorizedAccessException^ ex)
                    {
                        // Якщо доступ заборонено, пропускаємо цей шлях і виводимо повідомлення
                       
                    }
                }
            }

            if (checkBoxRecycleBin->Checked)
            {
                try
                {
                    // Отримуємо список усіх логічних дисків
                    array<String^>^ drives = Directory::GetLogicalDrives();

                    // Проходимо через кожен диск
                    for (int i = 0; i < drives->Length; i++)
                    {
                        String^ drive = drives[i];

                        // Шлях до корзини для кожного диска
                        String^ recycleBinPath = drive + "$Recycle.Bin";

                        if (Directory::Exists(recycleBinPath))
                        {
                            array<String^>^ tempFiles = Directory::GetFiles(recycleBinPath, "*.*", SearchOption::AllDirectories);
                            files->AddRange(tempFiles);
                        }
                    }
                }
                catch (UnauthorizedAccessException^ ex)
                {
                   
                }
                catch (DirectoryNotFoundException^ ex)
                {
                    
                }
                catch (Exception^ ex)
                {
                    
                }
            }


            if (checkBoxBrowserCache->Checked)
            {
                // Кеш для Google Chrome
                String^ browserCachePath = "C:\\Users\\" + Environment::UserName + "\\AppData\\Local\\Google\\Chrome\\User Data\\Default\\Cache\\Cache_Data";
                if (Directory::Exists(browserCachePath))
                {
                    array<String^>^ tempFiles = Directory::GetFiles(browserCachePath, "*.*", SearchOption::AllDirectories);
                    files->AddRange(tempFiles);
                }
                // Кеш для Firefox
                browserCachePath = "C:\\Users\\" + Environment::UserName + "\\AppData\\Local\\Mozilla\\Firefox\\Profiles\\vruoli5v.default-release\\cache2";
                if (Directory::Exists(browserCachePath))
                {
                    array<String^>^ tempFiles = Directory::GetFiles(browserCachePath, "*.*", SearchOption::AllDirectories);
                    files->AddRange(tempFiles);
                }
                // Кеш для Microsoft Edge
                browserCachePath = "C:\\Users\\" + Environment::UserName + "\\AppData\\Local\\Microsoft\\Edge\\User Data\\Default\\Cache\\Cache_Data";
                if (Directory::Exists(browserCachePath))
                {
                    array<String^>^ tempFiles = Directory::GetFiles(browserCachePath, "*.*", SearchOption::AllDirectories);
                    files->AddRange(tempFiles);
                }
            }

            if (checkBoxStoreCache->Checked)
            {
                String^ storeCachePath = "C:\\Program Files\\WindowsApps"; // Кеш Microsoft Store
                if (Directory::Exists(storeCachePath))
                {
                    array<String^>^ tempFiles = Directory::GetFiles(storeCachePath, "*.*", SearchOption::AllDirectories);
                    files->AddRange(tempFiles);
                }
            }

            if (checkBoxOldLogs->Checked)
            {
                String^ oldLogsPath = "C:\\Windows\\SoftwareDistribution\\Download"; // Старі журнали оновлень
                if (Directory::Exists(oldLogsPath))
                {
                    array<String^>^ tempFiles = Directory::GetFiles(oldLogsPath, "*.*", SearchOption::AllDirectories);
                    files->AddRange(tempFiles);
                }
            }

            if (checkBoxPrefetch->Checked)
            {
                String^ prefetchPath = "C:\\Windows\\Prefetch"; // Prefetch
                if (Directory::Exists(prefetchPath))
                {
                    array<String^>^ tempFiles = Directory::GetFiles(prefetchPath, "*.*", SearchOption::AllDirectories);
                    files->AddRange(tempFiles);
                }
            }

            if (checkBoxRestorePointsOld->Checked)
            {
                String^ restorePointsOldPath = "C:\\System Volume Information"; // Старі точки відновлення
                try
                {
                    if (Directory::Exists(restorePointsOldPath))
                    {
                        array<String^>^ tempFiles = Directory::GetFiles(restorePointsOldPath, "*.*", SearchOption::AllDirectories);
                        files->AddRange(tempFiles);
                    }
                }
                catch (UnauthorizedAccessException^)
                {
                    // Якщо немає доступу до цієї директорії, пропускаємо її
                    
                }
            }

            if (checkBoxRestorePointsNew->Checked)
            {
                String^ restorePointsNewPath = "C:\\System Volume Information"; // Нові точки відновлення
                try
                {
                    if (Directory::Exists(restorePointsNewPath))
                    {
                        array<String^>^ tempFiles = Directory::GetFiles(restorePointsNewPath, "*.*", SearchOption::AllDirectories);
                        files->AddRange(tempFiles);
                    }
                }
                catch (UnauthorizedAccessException^)
                {
                    // Якщо немає доступу до цієї директорії, пропускаємо її
                   
                }
            }


            if (checkBoxDumpFiles->Checked)
            {
                String^ dumpFilesPath = "C:\\Windows\\Memory.dmp"; // Дамп-файли
                if (File::Exists(dumpFilesPath))
                {
                    files->Add(dumpFilesPath);
                }
            }



            // Оголошуємо змінну для загального розміру файлів
            long long totalSize = 0;

            // Виведення кількості знайдених файлів у label
            labelHowMany->Text = "Знайдено файлів: " + files->Count.ToString();

            // Відображення файлів та підрахунок загального розміру
            for (int i = 0; i < files->Count; i++)
            {
                // Додаємо файл до listBox
                listBoxFiles->Items->Add(files[i]);

                // Отримуємо розмір файлу
                try
                {
                    FileInfo^ fileInfo = gcnew FileInfo(files[i]);
                    totalSize += fileInfo->Length;  // Додаємо розмір файлу до загальної суми
                }
                catch (IOException^ ex)
                {
                    // Якщо не вдається отримати розмір файлу, пропускаємо його
                    Console::WriteLine("Error reading file: " + ex->Message);
                }

                // Оновлюємо прогресбар
                progressBar->Value = (int)((i + 1) * 100 / files->Count);
            }

            // Показуємо загальний розмір файлів у labelAllSize
            labelAllSize->Text = "Загальний розмір: " + FormatSize(totalSize);

        }
        // Функція для форматування розміру файлу
        String^ FormatSize(long long size)
        {
            if (size < 1024)
                return size.ToString() + " байт";
            else if (size < 1024 * 1024)
                return (size / 1024.0).ToString("0.##") + " КБ";
            else if (size < 1024 * 1024 * 1024)
                return (size / (1024.0 * 1024)).ToString("0.##") + " МБ";
            else
                return (size / (1024.0 * 1024 * 1024)).ToString("0.##") + " ГБ";
        }




        void radioButtonAll_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
        {
            if (radioButtonAll->Checked && listBoxFiles->Items->Count > 0)
            {

                // Запитуємо користувача, чи впевнений він, що хоче видалити файли
                if (MessageBox::Show("Ви впевнені, що хочете видалити вибрані файли?",
                    "Підтвердження видалення",
                    MessageBoxButtons::YesNo,
                    MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
                {
                    // Створення списку, щоб зберегти елементи, які потрібно видалити з listBoxFiles
                    List<String^>^ filesToDelete = gcnew List<String^>();

                    // Додаємо файли, які вибрані для видалення
                    for each (String ^ file in listBoxFiles->Items)
                    {
                        filesToDelete->Add(file);
                    }

                    // Видаляємо файли з файлової системи
                    for each (String ^ file in filesToDelete)
                    {
                        try
                        {
                            File::Delete(file); // Видаляємо файл з файлової системи
                            // Якщо файл успішно видалений, то видаляємо його і з listBoxFiles
                            listBoxFiles->Items->Remove(file);
                        }
                        catch (Exception^ ex)
                        {
                           
                        }
                    }

                    // Показуємо повідомлення після завершення операції
                    MessageBox::Show("Обрані файли видалено.");
                }
                else
                {
                    // Якщо користувач натиснув "No", то операція скасовується
                    MessageBox::Show("Операція видалення скасована.");
                }
            }
            radioButtonAll->Checked = false;
            radioButtonNoAll->Checked = true;
        }






        // Обробник події для radioButtonNoAll
        void radioButtonNoAll_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
        {
            if (radioButtonNoAll->Checked)
            {
                

                // Знімаємо виділення всіх елементів шляхом зміни SelectionMode
                listBoxFiles->SelectionMode = SelectionMode::None;
                listBoxFiles->SelectionMode = SelectionMode::MultiExtended;

                labelTap->Text = "Виділено об'єктів: 0";
                UpdateSelectedFilesSize();
            }
        }



        // Обробник події для зміни вибору елементів в listBoxFiles
        void listBoxFiles_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
        {
            // Отримуємо кількість виділених елементів
            int selectedCount = this->listBoxFiles->SelectedItems->Count;

            // Оновлюємо текст labelTap
            labelTap->Text = "Виділено об'єктів: " + selectedCount.ToString();
            UpdateSelectedFilesSize();
        }

        // Функція для підрахунку розміру виділених файлів
        void UpdateSelectedFilesSize()
        {
            long long selectedSize = 0;  // Оголошуємо змінну для розміру виділених файлів

            // Проходимо через всі виділені файли в listBox
            for each (String ^ selectedFile in listBoxFiles->SelectedItems)
            {
                try
                {
                    // Отримуємо розмір файлу
                    FileInfo^ fileInfo = gcnew FileInfo(selectedFile);
                    selectedSize += fileInfo->Length;  // Додаємо розмір файлу до загальної суми
                }
                catch (IOException^ ex)
                {
                    
                }
            }

            // Показуємо загальний розмір виділених файлів у labelSizeTab
            labelSizeTab->Text = "Розмір виділених файлів: " + FormatSize(selectedSize);
        }

        void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Запитуємо користувача, чи впевнений він, що хоче видалити файли
            if (MessageBox::Show("Ви впевнені, що хочете видалити вибрані файли?",
                "Підтвердження видалення",
                MessageBoxButtons::YesNo,
                MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
            {
                // Створення списку, щоб зберегти елементи, які потрібно видалити з listBoxFiles
                List<String^>^ filesToDelete = gcnew List<String^>();

                // Додаємо файли, які вибрані для видалення
                for each (String ^ file in listBoxFiles->SelectedItems)
                {
                    filesToDelete->Add(file);
                }

                // Видаляємо файли з файлової системи
                for each (String ^ file in filesToDelete)
                {
                    try
                    {
                        File::Delete(file); // Видаляємо файл з файлової системи
                        // Якщо файл успішно видалений, то видаляємо його і з listBoxFiles
                        listBoxFiles->Items->Remove(file);
                    }
                    catch (Exception^ ex)
                    {
                       
                    }
                }

                // Показуємо повідомлення після завершення операції
                MessageBox::Show("Обрані файли видалено.");
            }
            else
            {
                // Якщо користувач натиснув "No", то операція скасовується
                MessageBox::Show("Операція видалення скасована.");
            }
        }



    System::Void progressBar_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

    }
private: System::Void labelHowMany_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
