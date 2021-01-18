#pragma once

namespace Project4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace IO;

	/// <summary>
	/// Summary for MyForm4
	/// </summary>
	public ref class MyForm4 : public System::Windows::Forms::Form
	{
	public:
		MyForm4(void)
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
		~MyForm4()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ proname;
	protected:

	protected:
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm4::typeid));
			this->proname = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// proname
			// 
			this->proname->Location = System::Drawing::Point(120, 144);
			this->proname->Name = L"proname";
			this->proname->Size = System::Drawing::Size(291, 24);
			this->proname->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DarkRed;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Yu Gothic Light", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(200, 224);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(131, 71);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Delete";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm4::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Yu Gothic Light", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(156, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(219, 31);
			this->label1->TabIndex = 3;
			this->label1->Text = L"PRODUCT DELETE";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Yu Gothic Light", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(116, 119);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(160, 22);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Enter Product Name";
			// 
			// MyForm4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->ClientSize = System::Drawing::Size(531, 426);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->proname);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm4";
			this->Text = L"Delete product";
			this->Load += gcnew System::EventHandler(this, &MyForm4::MyForm4_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
		int counter = 0;
		int counter2 = 0;
		String^ check;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		StreamReader deletee("delte.txt", System::Text::Encoding::UTF8);
		StreamWriter file("market.txt", false);
		bool flag = true;
		bool flag2 = false;
		String^ input = "Name:" + proname->Text + "|";
		while (!deletee.EndOfStream)
		{
			check = deletee.ReadLine();
			for (int x = 0; input[x] != '|'; x++)
			{
				if (input[x] != check[x])
				{
					file.WriteLine(check);
					
					counter2++;
					break;
				}
			}
			}
		file.Close();

		if (counter== counter2)
		{
			MessageBox::Show("Notfound");
		}
		else
		{
			MessageBox::Show("deleted");
		}
	
	}
	
	private: System::Void MyForm4_Load(System::Object^ sender, System::EventArgs^ e) {
		StreamReader file("market.txt", System::Text::Encoding::UTF8);
		StreamWriter deletee("delte.txt", false);
		while (!file.EndOfStream)
		{
			String^ write = file.ReadLine();
			deletee.WriteLine(write);
			
			counter++;
		}
		file.Close();
		deletee.Close();
	}
	};
}
