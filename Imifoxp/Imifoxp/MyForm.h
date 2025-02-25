#pragma once

namespace Imifoxp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Drawing::Imaging;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void) : MyForm(nullptr) {}
		MyForm(String^ imagePath)
		{
			InitializeComponent();
			InitializeEventHandlers();

			if (imagePath != nullptr)
			{
				DownloadImg(imagePath);
			}

			this->WindowState = FormWindowState::Maximized;
			this->Shown += gcnew EventHandler(this, &MyForm::MyForm_Shown);
		}

		void MyForm::MyForm_Shown(Object^ sender, EventArgs^ e)
		{
			ResizeImageToFitScreen();
		}
	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1; // Діалогове вікно для вибору файлу
	private: System::Drawing::Image^ loadedImage; // Змінна для збереження завантаженого зображення
	private: List<String^>^ imagePaths; // Список шляхів до зображень
	private: int currentImageIndex; // Індекс поточного зображення
		   float currentScale = 1.0f; // Поточний масштаб
	protected:

	private:
		bool isMouseDown = false; // Флаг для визначення, чи натиснута ліва кнопка миші
		int lastX = 0; // Остання координата X миші
		int lastY = 0; // Остання координата Y миші

	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Button^ buttonClose;
	private: System::Windows::Forms::Button^ buttonEsc;
	private: System::Windows::Forms::Label^ labelInfo;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ buttonFolder;
	private: System::Windows::Forms::ListBox^ listBoxImages;
	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::Button^ buttonHelp;
	private: System::Windows::Forms::RadioButton^ radioButtonSizeAuto;
	private: System::Windows::Forms::RadioButton^ radioButtonSizeSingle;
	private: System::ComponentModel::IContainer^ components;

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
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			   this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			   this->buttonClose = (gcnew System::Windows::Forms::Button());
			   this->buttonEsc = (gcnew System::Windows::Forms::Button());
			   this->labelInfo = (gcnew System::Windows::Forms::Label());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->radioButtonSizeAuto = (gcnew System::Windows::Forms::RadioButton());
			   this->radioButtonSizeSingle = (gcnew System::Windows::Forms::RadioButton());
			   this->buttonHelp = (gcnew System::Windows::Forms::Button());
			   this->buttonFolder = (gcnew System::Windows::Forms::Button());
			   this->listBoxImages = (gcnew System::Windows::Forms::ListBox());
			   this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   this->panel1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			   this->pictureBox1->Location = System::Drawing::Point(0, 46);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = this->ClientSize;
			   this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureBox1->TabIndex = 0;
			   this->pictureBox1->TabStop = false;
			   this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			   // 
			   // checkBox1
			   // 
			   this->checkBox1->Appearance = System::Windows::Forms::Appearance::Button;
			   this->checkBox1->BackColor = System::Drawing::Color::Black;
			   this->checkBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkBox1.BackgroundImage")));
			   this->checkBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->checkBox1->CheckAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   this->checkBox1->FlatAppearance->BorderSize = 0;
			   this->checkBox1->FlatAppearance->CheckedBackColor = System::Drawing::Color::Transparent;
			   this->checkBox1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->checkBox1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->checkBox1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->checkBox1->Location = System::Drawing::Point(10, 10);
			   this->checkBox1->Name = L"checkBox1";
			   this->checkBox1->Size = System::Drawing::Size(30, 30);
			   this->checkBox1->TabIndex = 3;
			   this->checkBox1->TabStop = false;
			   this->checkBox1->UseVisualStyleBackColor = false;
			   this->checkBox1->Visible = false;
			   this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_1);
			   // 
			   // buttonClose
			   // 
			   this->buttonClose->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			   this->buttonClose->BackColor = System::Drawing::Color::Transparent;
			   this->buttonClose->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonClose.BackgroundImage")));
			   this->buttonClose->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->buttonClose->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->buttonClose->FlatAppearance->BorderSize = 0;
			   this->buttonClose->FlatAppearance->CheckedBackColor = System::Drawing::Color::Transparent;
			   this->buttonClose->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->buttonClose->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->buttonClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->buttonClose->ForeColor = System::Drawing::Color::Transparent;
			   this->buttonClose->Location = System::Drawing::Point(1217, 10);
			   this->buttonClose->Name = L"buttonClose";
			   this->buttonClose->RightToLeft = System::Windows::Forms::RightToLeft::No;
			   this->buttonClose->Size = System::Drawing::Size(30, 30);
			   this->buttonClose->TabIndex = 4;
			   this->buttonClose->UseVisualStyleBackColor = false;
			   this->buttonClose->Visible = false;
			   this->buttonClose->Click += gcnew System::EventHandler(this, &MyForm::buttonClose_Click_1);
			   // 
			   // buttonEsc
			   // 
			   this->buttonEsc->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			   this->buttonEsc->BackColor = System::Drawing::Color::Transparent;
			   this->buttonEsc->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonEsc.BackgroundImage")));
			   this->buttonEsc->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->buttonEsc->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->buttonEsc->FlatAppearance->BorderSize = 0;
			   this->buttonEsc->FlatAppearance->CheckedBackColor = System::Drawing::Color::Transparent;
			   this->buttonEsc->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->buttonEsc->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->buttonEsc->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->buttonEsc->ForeColor = System::Drawing::Color::Transparent;
			   this->buttonEsc->Location = System::Drawing::Point(1181, 10);
			   this->buttonEsc->Name = L"buttonEsc";
			   this->buttonEsc->RightToLeft = System::Windows::Forms::RightToLeft::No;
			   this->buttonEsc->Size = System::Drawing::Size(30, 30);
			   this->buttonEsc->TabIndex = 5;
			   this->buttonEsc->UseVisualStyleBackColor = false;
			   this->buttonEsc->Visible = false;
			   this->buttonEsc->Click += gcnew System::EventHandler(this, &MyForm::buttonEsc_Click_1);
			   // 
			   // labelInfo
			   // 
			   this->labelInfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			   this->labelInfo->AutoSize = true;
			   this->labelInfo->BackColor = System::Drawing::Color::Black;
			   this->labelInfo->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204), true));
			   this->labelInfo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				   static_cast<System::Int32>(static_cast<System::Byte>(255)));
			   this->labelInfo->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			   this->labelInfo->Location = System::Drawing::Point(0, 540);
			   this->labelInfo->MinimumSize = System::Drawing::Size(130, 0);
			   this->labelInfo->Name = L"labelInfo";
			   this->labelInfo->Size = System::Drawing::Size(130, 20);
			   this->labelInfo->TabIndex = 6;
			   this->labelInfo->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			   this->labelInfo->Click += gcnew System::EventHandler(this, &MyForm::labelInfo_Click);
			   // 
			   // panel1
			   // 
			   this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->panel1->BackColor = System::Drawing::Color::Transparent;
			   this->panel1->Controls->Add(this->radioButtonSizeAuto);
			   this->panel1->Controls->Add(this->radioButtonSizeSingle);
			   this->panel1->Controls->Add(this->buttonHelp);
			   this->panel1->Controls->Add(this->buttonFolder);
			   this->panel1->Controls->Add(this->buttonEsc);
			   this->panel1->Location = System::Drawing::Point(0, 0);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(1250, 50);
			   this->panel1->TabIndex = 7;
			   this->panel1->Visible = false;
			   // 
			   // radioButtonSizeAuto
			   // 
			   this->radioButtonSizeAuto->Appearance = System::Windows::Forms::Appearance::Button;
			   this->radioButtonSizeAuto->BackColor = System::Drawing::Color::Transparent;
			   this->radioButtonSizeAuto->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"radioButtonSizeAuto.BackgroundImage")));
			   this->radioButtonSizeAuto->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->radioButtonSizeAuto->CheckAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   this->radioButtonSizeAuto->FlatAppearance->BorderSize = 0;
			   this->radioButtonSizeAuto->FlatAppearance->CheckedBackColor = System::Drawing::Color::Transparent;
			   this->radioButtonSizeAuto->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->radioButtonSizeAuto->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->radioButtonSizeAuto->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->radioButtonSizeAuto->Location = System::Drawing::Point(118, 10);
			   this->radioButtonSizeAuto->Name = L"radioButtonSizeAuto";
			   this->radioButtonSizeAuto->Size = System::Drawing::Size(30, 30);
			   this->radioButtonSizeAuto->TabIndex = 11;
			   this->radioButtonSizeAuto->UseVisualStyleBackColor = false;
			   this->radioButtonSizeAuto->CheckedChanged += gcnew System::EventHandler(this, &MyForm::UpdateRadioButtons);
			   // 
			   // radioButtonSizeSingle
			   // 
			   this->radioButtonSizeSingle->Appearance = System::Windows::Forms::Appearance::Button;
			   this->radioButtonSizeSingle->BackColor = System::Drawing::Color::Transparent;
			   this->radioButtonSizeSingle->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"radioButtonSizeSingle.BackgroundImage")));
			   this->radioButtonSizeSingle->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->radioButtonSizeSingle->CheckAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   this->radioButtonSizeSingle->Checked = true;
			   this->radioButtonSizeSingle->FlatAppearance->BorderSize = 0;
			   this->radioButtonSizeSingle->FlatAppearance->CheckedBackColor = System::Drawing::Color::Transparent;
			   this->radioButtonSizeSingle->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->radioButtonSizeSingle->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->radioButtonSizeSingle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->radioButtonSizeSingle->Location = System::Drawing::Point(82, 10);
			   this->radioButtonSizeSingle->Name = L"radioButtonSizeSingle";
			   this->radioButtonSizeSingle->Size = System::Drawing::Size(30, 30);
			   this->radioButtonSizeSingle->TabIndex = 10;
			   this->radioButtonSizeSingle->TabStop = true;
			   this->radioButtonSizeSingle->UseVisualStyleBackColor = false;
			   this->radioButtonSizeSingle->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButtonSizeSingle_CheckedChanged);
			   // 
			   // buttonHelp
			   // 
			   this->buttonHelp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			   this->buttonHelp->BackColor = System::Drawing::Color::Transparent;
			   this->buttonHelp->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonHelp.BackgroundImage")));
			   this->buttonHelp->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->buttonHelp->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->buttonHelp->FlatAppearance->BorderSize = 0;
			   this->buttonHelp->FlatAppearance->CheckedBackColor = System::Drawing::Color::Transparent;
			   this->buttonHelp->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->buttonHelp->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->buttonHelp->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->buttonHelp->ForeColor = System::Drawing::Color::Transparent;
			   this->buttonHelp->Location = System::Drawing::Point(1145, 10);
			   this->buttonHelp->Name = L"buttonHelp";
			   this->buttonHelp->RightToLeft = System::Windows::Forms::RightToLeft::No;
			   this->buttonHelp->Size = System::Drawing::Size(30, 30);
			   this->buttonHelp->TabIndex = 9;
			   this->buttonHelp->UseVisualStyleBackColor = false;
			   this->buttonHelp->Visible = false;
			   // 
			   // buttonFolder
			   // 
			   this->buttonFolder->BackColor = System::Drawing::Color::Transparent;
			   this->buttonFolder->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonFolder.BackgroundImage")));
			   this->buttonFolder->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->buttonFolder->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->buttonFolder->FlatAppearance->BorderSize = 0;
			   this->buttonFolder->FlatAppearance->CheckedBackColor = System::Drawing::Color::Transparent;
			   this->buttonFolder->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->buttonFolder->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->buttonFolder->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->buttonFolder->ForeColor = System::Drawing::Color::Transparent;
			   this->buttonFolder->Location = System::Drawing::Point(46, 10);
			   this->buttonFolder->Name = L"buttonFolder";
			   this->buttonFolder->RightToLeft = System::Windows::Forms::RightToLeft::No;
			   this->buttonFolder->Size = System::Drawing::Size(30, 30);
			   this->buttonFolder->TabIndex = 8;
			   this->buttonFolder->UseVisualStyleBackColor = false;
			   this->buttonFolder->Visible = false;
			   // 
			   // listBoxImages
			   // 
			   this->listBoxImages->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->listBoxImages->BackColor = System::Drawing::Color::Black;
			   this->listBoxImages->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->listBoxImages->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->listBoxImages->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->listBoxImages->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				   static_cast<System::Int32>(static_cast<System::Byte>(255)));
			   this->listBoxImages->FormattingEnabled = true;
			   this->listBoxImages->ItemHeight = 19;
			   this->listBoxImages->Location = System::Drawing::Point(983, 99);
			   this->listBoxImages->Name = L"listBoxImages";
			   this->listBoxImages->RightToLeft = System::Windows::Forms::RightToLeft::No;
			   this->listBoxImages->Size = System::Drawing::Size(267, 342);
			   this->listBoxImages->TabIndex = 8;
			   this->listBoxImages->Visible = false;
			   this->listBoxImages->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBoxImages_SelectedIndexChanged_1);
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::Black;
			   this->ClientSize = System::Drawing::Size(1250, 600);
			   this->Controls->Add(this->listBoxImages);
			   this->Controls->Add(this->labelInfo);
			   this->Controls->Add(this->buttonClose);
			   this->Controls->Add(this->checkBox1);
			   this->Controls->Add(this->panel1);
			   this->Controls->Add(this->pictureBox1);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->KeyPreview = true;
			   this->MinimumSize = System::Drawing::Size(500, 400);
			   this->Name = L"MyForm";
			   this->Text = L"Imifoxp";
			   this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			   this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   this->panel1->ResumeLayout(false);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }

#pragma endregion
		   int offsetX = 0; // Поточне зміщення по X
		   int offsetY = 0; // Поточне зміщення по Y

		   // Обробник натискання клавіші
		   void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
		   {
			   if (e->KeyCode == Keys::O) // Клавіша O для відкриття зображення
			   {
				   openFileDialog1->Filter = L"Image Files|*.jpg;*.jpeg;*.png;*.bmp;*.gif;*.tiff;*.ico|All Files|*.*";

				   if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				   {
					   DownloadImg(openFileDialog1->FileName);
				   }
			   }
			   // Обробка натискання клавіші Esc для виходу з повноекранного режиму
			   else if (e->KeyCode == Keys::Escape)
			   {
				   EscapeBut();
				   array<System::Windows::Forms::Control^>^ controls = { checkBox1, buttonClose,buttonEsc,panel1,buttonFolder,labelInfo,listBoxImages }; // додайте свої елементи сюди

				   HideControlsAll(controls);
			   }
			   else if (loadedImage != nullptr)
			   {
				   // Обертання зображення вгору (на 90 градусів)
				   if (e->KeyCode == Keys::Up || e->KeyCode == Keys::W)
				   {
					   pictureBox1->Image->RotateFlip(RotateFlipType::Rotate90FlipNone);
					   pictureBox1->Invalidate(); // Перемалювати PictureBox
				   }
				   // Обертання зображення вниз
				   else if (e->KeyCode == Keys::Down || e->KeyCode == Keys::S)
				   {
					   pictureBox1->Image->RotateFlip(RotateFlipType::Rotate270FlipNone);
					   pictureBox1->Invalidate();
				   }
				   // Переміщення зображення вправо
				   else if (e->KeyCode == Keys::Right || e->KeyCode == Keys::D)
				   {
					   NavigateImage(true);
				   }
				   // Переміщення зображення вліво
				   else if (e->KeyCode == Keys::Left || e->KeyCode == Keys::A)
				   {
					   NavigateImage(false);
				   }
			   }
		   }

		   // Початковий масштаб
		   

		   void MyForm_MouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		   {
			   if (loadedImage != nullptr)
			   {
				   const float maxScale = 200.0f;
				   const float minScale = 0.01f;
				   float scaleFactor = 0.2f;
				  

				   if (e->Delta > 0)
				   {
					   if (currentScale >= 1)
						   scaleFactor = (currentScale / maxScale)*20;
					  // scaleFactor = 0.1f + (maxScale + currentScale) * 0.01f;
					   else
						   scaleFactor = 0.05f;
					   if (pictureBox1->Width* (currentScale + scaleFactor) <= this->ClientSize.Width* maxScale && pictureBox1->Height* (currentScale+ scaleFactor) <= this->ClientSize.Height * maxScale) 
						   currentScale += scaleFactor;
				   }
				   else if (e->Delta < 0)
				   {
					   if (currentScale >= 1)
						   scaleFactor = (currentScale / maxScale) * 20;

					   else
						   scaleFactor = 0.05f;
					   if (pictureBox1->Width * (currentScale + scaleFactor) >= this->ClientSize.Width * minScale && pictureBox1->Height * (currentScale + scaleFactor) >= this->ClientSize.Height * minScale)  
						   currentScale -= scaleFactor;
				   }
				   if (minScale > currentScale)currentScale = minScale;
				   if (maxScale <  currentScale)currentScale = maxScale;

				   pictureBox1->Width = (int)(this->ClientSize.Width * currentScale);
				   pictureBox1->Height = (int)(this->ClientSize.Height *  currentScale);

				   // Центруємо зображення, враховуючи зміщення
				   pictureBox1->Location = System::Drawing::Point(
					   (this->ClientSize.Width - pictureBox1->Width) / 2,
					   (this->ClientSize.Height - pictureBox1->Height) / 2);

				   pictureBox1->Invalidate();
			   }
		   }
		 
		   void ResizeImageToFitScreen()
		   {
			  
			   if (loadedImage != nullptr)
			   {
				 
				   Bitmap^ processedImage = gcnew Bitmap(loadedImage);
				   if (radioButtonSizeAuto->Checked)
				   currentScale = 1.0f;
				   pictureBox1->Location = System::Drawing::Point(0, 0);
				   pictureBox1->Size = this->ClientSize;
				   pictureBox1->Image = processedImage;


				   
				   pictureBox1->Width = (int)(pictureBox1->Width * currentScale);
				   pictureBox1->Height = (int)(pictureBox1->Height * currentScale);
				   // Центруємо зображення, враховуючи зміщення
				   pictureBox1->Location = System::Drawing::Point(
					   (this->ClientSize.Width - pictureBox1->Width) / 2,
					   (this->ClientSize.Height - pictureBox1->Height) / 2);
			   }
		   }

		   void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		   {
			   if (e->Button == System::Windows::Forms::MouseButtons::Left)
			   {
				   isMouseDown = true;
				   System::Drawing::Point clientPoint = this->PointToClient(Control::MousePosition);
				   // Зберігаємо початкову точку натискання (відносно PictureBox)
				   lastX = e->X;
				   lastY = e->Y;

				   // Обчислюємо зміщення на основі натискання
				   offsetX = clientPoint.X - pictureBox1->Location.X;  // Рахуємо відстань від лівого краю PictureBox до місця натискання
				   offsetY = clientPoint.Y - pictureBox1->Location.Y;  // Рахуємо відстань від верхнього краю PictureBox до місця натискання

			   }
			   else if (e->Button == System::Windows::Forms::MouseButtons::XButton2) {
				   NavigateImage(true);
			   }
			   else if (e->Button == System::Windows::Forms::MouseButtons::XButton1) {
				   NavigateImage(false);
			   }

		   }
		   private: System::Void MyForm_MouseDownBack(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (e->Button == System::Windows::Forms::MouseButtons::XButton2) {
			NavigateImage(true);
		}
		else if (e->Button == System::Windows::Forms::MouseButtons::XButton1) {
			NavigateImage(false);
		}

	}
		   void NavigateImage(bool forward)
		   {
			   if (forward)
			   {
				   LoadImageAtIndex(currentImageIndex + 1, forward);
			   }
			   else
			   {
				   LoadImageAtIndex(currentImageIndex - 1, forward);
			   }
		   }

		 
		   void LoadImageAtIndex(int index, bool forward)
		   {
			   if (index >= 0 && index < imagePaths->Count)
			   {
				   currentImageIndex = index;
				   try
				   {
					   // Завантажуємо зображення
					   loadedImage = Image::FromFile(imagePaths[currentImageIndex]);
					   try
					   {
					   // Перевіряємо орієнтацію зображення (EXIF)
					   PropertyItem^ propItem = loadedImage->GetPropertyItem(0x0112); // 0x0112 - тег для орієнтації
					   if (propItem != nullptr)
					   {
						   int orientation = propItem->Value[0];
						   switch (orientation)
						   {
						   case 1: // Оригінальний
							   break;
						   case 3: // Поворот на 180 градусів
							   loadedImage->RotateFlip(RotateFlipType::Rotate180FlipNone);
							   break;
						   case 6: // Поворот на 90 градусів по годинниковій стрілці
							   loadedImage->RotateFlip(RotateFlipType::Rotate90FlipNone);
							   break;
						   case 8: // Поворот на 90 градусів проти годинникової стрілки
							   loadedImage->RotateFlip(RotateFlipType::Rotate270FlipNone);
							   break;
						   default:
							   break;
						   }
					   }
					   }
					   catch (Exception^)
					   {
					   }
					   // Встановлюємо зображення на PictureBox
					   pictureBox1->Image = loadedImage;
					   currentScale = 1.0f;
					   // Масштабуємо зображення для відображення
					   ResizeImageToFitScreen();

					   // Отримуємо мета-інформацію
					   System::IO::FileInfo^ fileInfo = gcnew System::IO::FileInfo(imagePaths[currentImageIndex]);
					   double fileSizeMB = fileInfo->Length / (1024.0 * 1024.0); // Перетворення в МБ
					   int width = loadedImage->Width, scWidth= pictureBox1->Width;
					   int height = loadedImage->Height, scHeight = pictureBox1->Height;
					   float scale = 1;
					   if (width < scWidth && height < scHeight && radioButtonSizeSingle->Checked)
					   {
						   
						   if (scWidth >= width)
							   scale = (float)width/ (float)scWidth;
						   else
							   scale = (float)height/ (float)scHeight;
						   

					   }
					   pictureBox1->Width = (int)(pictureBox1->Width * scale);
					   pictureBox1->Height = (int)(pictureBox1->Height * scale);
					   // Центруємо зображення, враховуючи зміщення
					   pictureBox1->Location = System::Drawing::Point(
						   (this->ClientSize.Width - pictureBox1->Width) / 2,
						   (this->ClientSize.Height - pictureBox1->Height) / 2);
					   // Формуємо текст для labelInfo
					   String^ infoText = String::Format("File: {0}\nSize: {1:F2} MB\nDimensions: {2}x{3} px",
						   System::IO::Path::GetFileName(imagePaths[currentImageIndex]), fileSizeMB, width, height);

					   // Виводимо інформацію в labelInfo
					   labelInfo->Text = infoText;
					  
					   currentScale = scale;
				   }
				   catch (Exception^)
				   {
					   // Якщо файл проблемний, переходимо до наступного
					   if (forward && currentImageIndex + 1 < imagePaths->Count)
					   {
						   LoadImageAtIndex(currentImageIndex + 1, forward); // Пропускаємо файл і переходимо до наступного
					   }
					   else if (!forward && currentImageIndex - 1 >= 0)
					   {
						   LoadImageAtIndex(currentImageIndex - 1, forward); // Пропускаємо файл і переходимо до попереднього
					   }
				   }
			   }
		   }


		   void MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		   {
			   if (isMouseDown)
			   {
				   // Отримуємо координати курсора відносно клієнтської області форми
				   System::Drawing::Point clientPoint = this->PointToClient(Control::MousePosition);

				   // Обчислюємо зміщення
				   int deltaX = clientPoint.X - lastX;
				   int deltaY = clientPoint.Y - lastY;

				   // Оновлюємо позицію зображення так, щоб курсор залишався на точці натискання
				   pictureBox1->Location = System::Drawing::Point(
					   clientPoint.X - offsetX, // Встановлюємо позицію зображення так, щоб курсор залишався на місці
					   clientPoint.Y - offsetY
				   );

				   // Оновлюємо останню позицію миші
				   lastX = clientPoint.X;
				   lastY = clientPoint.Y;

				   // Перерисовка PictureBox
				   pictureBox1->Invalidate();
			   }
			   else if (!isMouseDown ) {
				   // Масив всіх checkBox елементів, які ви хочете ховати/показувати
				   // Масив всіх елементів, які ви хочете ховати/показувати
				   array<System::Windows::Forms::Control^>^ controls = { checkBox1,buttonHelp, buttonClose,buttonEsc,panel1,buttonFolder }; // додайте свої елементи сюди
				   array<System::Windows::Forms::Control^>^ controlsDown = { labelInfo }; // додайте свої елементи сюди
				   array<System::Windows::Forms::Control^>^ controlsLeft = { listBoxImages }; // додайте свої елементи сюди
				   // Викликаємо функцію для показу/приховування
				   ShowHideControls(controls);
				   ShowDownControls(controlsDown);
				   ShowLeftControls(controlsLeft);
			   }
			  

		   }

		   void MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		   {
			   isMouseDown = false;
		   }

		   void DownloadImg(String^ imagePath)
		   {
			   try
			   {
				   // Поточний код для завантаження зображення
				   String^ directory = System::IO::Path::GetDirectoryName(imagePath);
				   System::IO::DirectoryInfo^ dirInfo = gcnew System::IO::DirectoryInfo(directory);
				   array<System::IO::FileInfo^>^ files = dirInfo->GetFiles("*.*");

				   imagePaths = gcnew List<String^>();
				   listBoxImages->Items->Clear(); // Очищаємо список перед завантаженням нових файлів

				   // Додаємо файли в список
				   for each (System::IO::FileInfo ^ file in files)
				   {
					   String^ ext = file->Extension->ToLower();
					   if (ext == ".jpg" || ext == ".jpeg" || ext == ".png" || ext == ".bmp" ||
						   ext == ".gif" || ext == ".tiff" || ext == ".ico")
					   {
						   imagePaths->Add(file->FullName);

						   // Отримуємо ім'я файлу без розширення
						   String^ fileNameWithoutExt = System::IO::Path::GetFileNameWithoutExtension(file->Name);
						   // Отримуємо розширення
						   String^ fileExtension = file->Extension;

						   // Формуємо нову назву
						   String^ displayName = fileNameWithoutExt->Substring(0, Math::Min(18, fileNameWithoutExt->Length)); // Беремо перші 15 символів
						   if (fileNameWithoutExt->Length > 18)
						   {
							   displayName += ".."; // Додаємо "..." якщо назва довша за 15 символів
						   }
						   displayName += fileExtension; // Додаємо розширення

						   // Додаємо відформатовану назву в список
						   listBoxImages->Items->Add(displayName);
					   }
				   }

				   // Встановлюємо поточний індекс і завантажуємо вибране зображення
				   currentImageIndex = imagePaths->IndexOf(imagePath);
				   if (currentImageIndex >= 0)
				   {
					   // Викликаємо LoadImageAtIndex для завантаження зображення
					   LoadImageAtIndex(currentImageIndex, true);
				   }
			   }
			   catch (Exception^ ex)
			   {
				   MessageBox::Show("Error loading image: " + ex->Message);
			   }
		   }


	private: System::Void ListBoxImages_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		int selectedIndex = listBoxImages->SelectedIndex;
		if (selectedIndex >= 0 && selectedIndex < imagePaths->Count)
		{
			// Встановлюємо поточний індекс
			currentImageIndex = selectedIndex;

			// Завантажуємо зображення за допомогою LoadImageAtIndex
			LoadImageAtIndex(currentImageIndex, true); // "true" або "false" залежно від напрямку
		}
	}



		   // Обробник зміни розміру форми
		   void MyForm_Resize(System::Object^ sender, System::EventArgs^ e)
		   {
			  // currentScale = 1;
			   //pictureBox1->Location = System::Drawing::Point(0, 0);
			   //pictureBox1->Size = this->ClientSize;
		   }

		  
		   // Змінює тему форми в залежності від вибору
		   void ChangeTheme()
		   {
			   // Перевіряємо, чи активна галочка в checkBox1
			   bool darkMode = checkBox1->Checked;

			   if (darkMode)
			   {
				   // Змінюємо на темну тему (тільки фон форми)
				   this->BackColor = System::Drawing::Color::Black;      // Темний фон
				   listBoxImages->BackColor = System::Drawing::Color::Black;      // Темний фон
				   listBoxImages->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
					   static_cast<System::Int32>(static_cast<System::Byte>(255)));
				   labelInfo->BackColor = System::Drawing::Color::Black;      // Темний фон
				   labelInfo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
					   static_cast<System::Int32>(static_cast<System::Byte>(255)));
			   }
			   else
			   {
				   // Змінюємо на світлу тему (тільки фон форми)
				   this->BackColor = System::Drawing::Color::LightGray;  // Світлий фон
				   listBoxImages->BackColor = System::Drawing::Color::LightGray;      // Темний фон
				   listBoxImages->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
					   static_cast<System::Int32>(static_cast<System::Byte>(255)));
				   labelInfo->BackColor = System::Drawing::Color::LightGray;      // Темний фон
				   labelInfo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
					   static_cast<System::Int32>(static_cast<System::Byte>(255)));
			   }

			   // Зберігаємо новий вибір теми
			   SaveThemeSetting(darkMode);
		   }


		   void HideControlsAll(array<System::Windows::Forms::Control^>^ controls) {
			   for (int i = 0; i < controls->Length; i++)
			   {
				   controls[i]->Visible = false;
			   }
		   }
		   void ShowHideControls(array<System::Windows::Forms::Control^>^ controls)
		   {
			   // Отримуємо поточну позицію миші по осі Y
			   int mouseY = this->PointToClient(MousePosition).Y;

			   // Якщо миша знаходиться в верхніх 50 пікселях, показуємо всі елементи
			   if (mouseY >= 0 && mouseY <= 50)
			   {
				   // Показуємо всі елементи
				   for (int i = 0; i < controls->Length; i++)
				   {
					   controls[i]->Visible = true;
				   }
			   }
			   else
			   {
				   // Якщо миша не в верхній частині екрану, ховаємо всі елементи
				   for (int i = 0; i < controls->Length; i++)
				   {
					   controls[i]->Visible = false;
				   }
			   }
		   }
		   void ShowDownControls(array<System::Windows::Forms::Control^>^ controls)
		   {
			   // Отримуємо поточну позицію миші по осі Y
			   int mouseY = this->PointToClient(MousePosition).Y;
			   int mouseX = this->PointToClient(MousePosition).X;
			   // Якщо миша знаходиться в верхніх 50 пікселях, показуємо всі елементи
			   if (mouseY >= this->labelInfo->Location.Y && mouseY <= this->Height && mouseX <= this->labelInfo->Size.Width)
			   {
				   // Показуємо всі елементи
				   for (int i = 0; i < controls->Length; i++)
				   {
					   controls[i]->Visible = true;
				   }
			   }
			   else
			   {
				   // Якщо миша не в верхній частині екрану, ховаємо всі елементи
				   for (int i = 0; i < controls->Length; i++)
				   {
					   controls[i]->Visible = false;
				   }
			   }
		   }
		   void ShowLeftControls(array<System::Windows::Forms::Control^>^ controls)
		   {
			   // Отримуємо поточну позицію миші по осі Y
			   int mouseY = this->PointToClient(MousePosition).Y;
			   int mouseX = this->PointToClient(MousePosition).X;
			   // Якщо миша знаходиться в верхніх 50 пікселях, показуємо всі елементи
			   if (mouseY >= this->listBoxImages->Location.Y && mouseY <= this->listBoxImages->Size.Height + this->listBoxImages->Location.Y && mouseX >= this->Width - this->listBoxImages->Size.Width / 4)
			   {
				   // Показуємо всі елементи
				   for (int i = 0; i < controls->Length; i++)
				   {
					   controls[i]->Visible = true;
				   }
			   }
			   else
			   {
				   // Якщо миша не в верхній частині екрану, ховаємо всі елементи
				   for (int i = 0; i < controls->Length; i++)
				   {
					   controls[i]->Visible = false;
				   }
			   }
		   }

		
		   // Зберігає налаштування теми
		   void SaveThemeSetting(bool darkMode)
		   {
			   String^ exePath = System::Windows::Forms::Application::StartupPath;

			   // Використовуємо Path::Combine для коректного комбінування шляху
			   String^ themeFilePath = System::IO::Path::Combine(exePath, "theme_setting.txt");
			   System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter(themeFilePath);

			  
			   writer->WriteLine(darkMode); // Зберігаємо значення true/false
			   writer->Close();
		   }

		   // Встановлює іконку для checkBox
		   void SetCheckBoxIcon(bool isChecked)
		   {
			   // Отримуємо шлях до папки, де знаходиться .exe
			   String^ exePath = System::Windows::Forms::Application::StartupPath;

			   // Формуємо шлях до потрібного файлу
			   String^ iconPath;
			   if (isChecked)
			   {
				   iconPath = System::IO::Path::Combine(exePath, "Images\\sun_icon.png");
			   }
			   else
			   {
				   iconPath = System::IO::Path::Combine(exePath, "Images\\moon_icon.png");
			   }

			   // Встановлюємо іконку для checkBox
			   try {
				   this->checkBox1->BackgroundImage = System::Drawing::Image::FromFile(iconPath);
			   }
		   
		   catch (Exception^) {}
		   }



		   // Обробник події для checkBox1
		   void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		   {
			   // Перемикаємо тему в залежності від стану checkBox1
			   ChangeTheme();

			   // Встановлюємо відповідну іконку
			   SetCheckBoxIcon(checkBox1->Checked);
		   }


		   // Завантажує налаштування теми
		   void LoadThemeSetting()
		   {
			   String^ exePath = System::Windows::Forms::Application::StartupPath;
			   String^ settingsPath = System::IO::Path::Combine(exePath, "theme_setting.txt");
			   try {
				   if (System::IO::File::Exists(settingsPath))
				   {
					   System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(settingsPath);
					   bool darkMode = reader->ReadLine() == "True"; // Читаємо значення true/false
					   reader->Close();

					   

					   // Встановлюємо відповідне значення для checkBox1
					   checkBox1->Checked = darkMode;
					   ChangeTheme();
				   }
			   }
			   catch (Exception^) { Console::WriteLine(settingsPath); }
		   }
		   // Метод для збереження вибору RadioButton у файл
		   void SaveRadioButtonSetting(bool isSingle)
		   {
			   String^ exePath = System::Windows::Forms::Application::StartupPath;
			   String^ radioFilePath = System::IO::Path::Combine(exePath, "radio_setting.txt");
			   System::IO::StreamWriter^ radioWriter = gcnew System::IO::StreamWriter(radioFilePath);

			   radioWriter->WriteLine(isSingle); // Зберігаємо true (Single) або false (Auto)
			   radioWriter->Close();
		   }
		   // Метод для завантаження налаштувань RadioButton
		   bool LoadRadioButtonSetting()
		   {
			   String^ exePath = System::Windows::Forms::Application::StartupPath;
			   String^ settingsPath = System::IO::Path::Combine(exePath, "radio_setting.txt");
			   Console::WriteLine(settingsPath);
			   try {
			   if (System::IO::File::Exists(settingsPath))
			   {
			   
				   System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(settingsPath);
				   bool isSingle = System::Convert::ToBoolean(reader->ReadLine()); // Читаємо значення
				   reader->Close();
				   return isSingle;
			   }
			   }
			   catch (Exception^) {}
			   return true; // За замовчуванням режим Single
		   }

		   // Метод для оновлення зображень RadioButton'ів
		   void MyForm::UpdateRadioButtons(System::Object^ sender, System::EventArgs^ e)
		   {
			   // Отримуємо шлях до папки, де знаходиться .exe
			   String^ exePath = System::Windows::Forms::Application::StartupPath;
			   // Формуємо шляхи до зображень
			   String^ pathSingleSelected = System::IO::Path::Combine(exePath, "Images\\radio_single_selected.png");
			   String^ pathSingleDeselected = System::IO::Path::Combine(exePath, "Images\\radio_single_deselected.png");

			   String^ pathAutoSelected = System::IO::Path::Combine(exePath, "Images\\radio_auto_selected.png");
			   String^ pathAutoDeselected = System::IO::Path::Combine(exePath, "Images\\radio_auto_deselected.png");
			   try {
			   // Змінюємо зображення в залежності від обраного стану
			   if (this->radioButtonSizeSingle->Checked)
			   {

				   this->radioButtonSizeSingle->BackgroundImage = System::Drawing::Image::FromFile(pathSingleSelected);
				   this->radioButtonSizeAuto->BackgroundImage = System::Drawing::Image::FromFile(pathAutoDeselected);
				   SaveRadioButtonSetting(true); // Зберігаємо вибір
			   }
			   else if (this->radioButtonSizeAuto->Checked)
			   {
				   this->radioButtonSizeSingle->BackgroundImage = System::Drawing::Image::FromFile(pathSingleDeselected);
				   this->radioButtonSizeAuto->BackgroundImage = System::Drawing::Image::FromFile(pathAutoSelected);
				   SaveRadioButtonSetting(false); // Зберігаємо вибір
			   }
			   if (radioButtonSizeAuto->Checked)
			   ResizeImageToFitScreen();
			   else if(loadedImage!=nullptr)
			   {
				   int width = loadedImage->Width, scWidth = pictureBox1->Width;
				   int height = loadedImage->Height, scHeight = pictureBox1->Height;
				   float scale = 1;
				   if (width < scWidth && height < scHeight && radioButtonSizeSingle->Checked)
				   {

					   if (scWidth >= width)
						   scale = (float)width / (float)scWidth;
					   else
						   scale = (float)height / (float)scHeight;


				   }
				   pictureBox1->Width = (int)(pictureBox1->Width * scale);
				   pictureBox1->Height = (int)(pictureBox1->Height * scale);
				   // Центруємо зображення, враховуючи зміщення
				   pictureBox1->Location = System::Drawing::Point(
					   (this->ClientSize.Width - pictureBox1->Width) / 2,
					   (this->ClientSize.Height - pictureBox1->Height) / 2);
				   currentScale = scale;
			   }
			   }
			   catch (Exception^) {}
		   }


		   void InitializeEventHandlers()
		   {
			   

			   LoadThemeSetting(); // Завантажуємо налаштування теми
			   this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			   SetCheckBoxIcon(checkBox1->Checked);
			   this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			   this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDownBack);
			   this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			   this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			   this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
			   this->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseWheel);
			   this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			   this->buttonClose->Click += gcnew System::EventHandler(this, &MyForm::buttonClose_Click);
			   this->buttonFolder->Click += gcnew System::EventHandler(this, &MyForm::OpenDolder);
			   this->buttonEsc->Click += gcnew System::EventHandler(this, &MyForm::buttonEsc_Click);
			   this->checkBox1->MouseEnter += gcnew System::EventHandler(this, &MyForm::checkBox1_MouseEnter);
			   this->listBoxImages->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::ListBoxImages_SelectedIndexChanged);


			   
			   // Додаємо обробник подій для оновлення стану
			   this->radioButtonSizeSingle->CheckedChanged += gcnew System::EventHandler(this, &MyForm::UpdateRadioButtons);
			   this->radioButtonSizeAuto->CheckedChanged += gcnew System::EventHandler(this, &MyForm::UpdateRadioButtons);


			   bool isSingle = LoadRadioButtonSetting();
			   this->radioButtonSizeSingle->Checked = isSingle;
			   this->radioButtonSizeAuto->Checked = !isSingle;

			   UpdateRadioButtons(nullptr, nullptr); // Оновлюємо зображення





			   this->toolTip1 = gcnew System::Windows::Forms::ToolTip();
			   this->toolTip1->AutomaticDelay = 500000; // Затримка для появи Tooltip
			   this->toolTip1->InitialDelay = 50;   // Початкова затримка
			   this->toolTip1->ReshowDelay = 50;    // Затримка між повторними показами Tooltip
			   this->toolTip1->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Info;
			   this->toolTip1->ToolTipTitle = L"Гарячі клавіші"; // Назва для підказки

			   // Додаємо підказки для знаку питання
			   this->toolTip1->SetToolTip(this->buttonHelp,
				   L"Попередня фотографія -> A, Left, XButton1\n"
				   L"Наступна фотографія -> D, Right, XButton2\n"
				   L"Приблизити -> Колесо вверх\n"
				   L"Віддалити -> Колесо вниз\n"
				   L"Повернути картинку -> W-S, Up-Down\n"
				   L"Двигати картинку -> ЛКМ\n"
				   L"Вийти/Зайти в повноекранний режим -> ESC\n"
				   L"Вибрати файл -> O");


			   chFix();
		   }
		   void chFix() {
			   this->checkBox1->BackColor = System::Drawing::Color::Transparent; // Примусове повернення до прозорого
		   }
	private: System::Void checkBox1_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		this->checkBox1->BackColor = System::Drawing::Color::Transparent; // Примусове повернення до прозорого
	}

		   void EscapeBut() {
			   // Перевірка, чи форма розгорнута на весь екран
			   if (this->FormBorderStyle == System::Windows::Forms::FormBorderStyle::None)
			   {
				   // Повертаємось до нормального вікна
				   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Sizable;
				   this->WindowState = FormWindowState::Normal; // Вікно в звичайний режим
			   }
			   else
			   {
				   // Розгортаємо вікно на весь екран без рамки
				   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
				   this->WindowState = FormWindowState::Maximized; // Розгорнути на весь екран
			   }
			   pictureBox1->Location = System::Drawing::Point(0, 0);
			   pictureBox1->Size = this->ClientSize;
			   MyForm_Resize(this, EventArgs::Empty);
			  
			   ResizeImageToFitScreen();
			  
		   }
		   void MyForm::buttonClose_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   this->Close();
		   }
		   void MyForm::buttonEsc_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   EscapeBut();
			   array<System::Windows::Forms::Control^>^ controls = { checkBox1, buttonClose,buttonEsc,panel1,buttonFolder,labelInfo,listBoxImages }; // додайте свої елементи сюди

			   HideControlsAll(controls);
		   }
		   System::Void  OpenDolder(System::Object^ sender, System::EventArgs^ e) {
			   openFileDialog1->Filter = L"Image Files|*.jpg;*.jpeg;*.png;*.bmp;*.gif;*.tiff;*.ico|All Files|*.*";

			   if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			   {
				   DownloadImg(openFileDialog1->FileName);
			   }
		   }
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void buttonClose_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void checkBox1_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void listBoxImages_SelectedIndexChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void radioButtonSizeSingle_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void buttonEsc_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void labelInfo_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
