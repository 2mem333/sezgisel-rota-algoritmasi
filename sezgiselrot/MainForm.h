#include "sezgisel_rota.h"

namespace sezgiselrot {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		Matrixs^ matta; //matrisimiz burada olusturuldu.
		bool devam = 0;
		bool bitti = 0;
	private: System::Windows::Forms::Label^ kapsama_text;
	private: System::Windows::Forms::RichTextBox^ kapsamalar_textbox;


	private: System::Windows::Forms::Button^ ilkhal;

	public:
		MainForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ matrisolustur;
	protected:
	private: System::Windows::Forms::TextBox^ satir_sayisi;
	private: System::Windows::Forms::TextBox^ sutun_sayisi;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RichTextBox^ olaylar;
	private: System::Windows::Forms::Panel^ panel;

	private: System::Windows::Forms::Button^ rastgele_matrisolusutur;
	private: System::Windows::Forms::Button^ matrisi_coz;
	private: System::Windows::Forms::Button^ matrisi_yukle;
	private: System::Windows::Forms::Button^ button1;



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
			this->matrisolustur = (gcnew System::Windows::Forms::Button());
			this->satir_sayisi = (gcnew System::Windows::Forms::TextBox());
			this->sutun_sayisi = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->olaylar = (gcnew System::Windows::Forms::RichTextBox());
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->rastgele_matrisolusutur = (gcnew System::Windows::Forms::Button());
			this->matrisi_coz = (gcnew System::Windows::Forms::Button());
			this->matrisi_yukle = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->ilkhal = (gcnew System::Windows::Forms::Button());
			this->kapsama_text = (gcnew System::Windows::Forms::Label());
			this->kapsamalar_textbox = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// matrisolustur
			// 
			this->matrisolustur->Location = System::Drawing::Point(15, 60);
			this->matrisolustur->Name = L"matrisolustur";
			this->matrisolustur->Size = System::Drawing::Size(92, 26);
			this->matrisolustur->TabIndex = 0;
			this->matrisolustur->Text = L"sýfýr matris";
			this->matrisolustur->UseVisualStyleBackColor = true;
			this->matrisolustur->Click += gcnew System::EventHandler(this, &MainForm::matrisolustur_Click);
			// 
			// satir_sayisi
			// 
			this->satir_sayisi->Location = System::Drawing::Point(60, 10);
			this->satir_sayisi->Name = L"satir_sayisi";
			this->satir_sayisi->Size = System::Drawing::Size(47, 20);
			this->satir_sayisi->TabIndex = 1;
			// 
			// sutun_sayisi
			// 
			this->sutun_sayisi->Location = System::Drawing::Point(60, 34);
			this->sutun_sayisi->Name = L"sutun_sayisi";
			this->sutun_sayisi->Size = System::Drawing::Size(47, 20);
			this->sutun_sayisi->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label1->Location = System::Drawing::Point(12, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Satir:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label2->Location = System::Drawing::Point(12, 34);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(49, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Sutun:";
			// 
			// olaylar
			// 
			this->olaylar->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->olaylar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->olaylar->Location = System::Drawing::Point(131, 10);
			this->olaylar->Name = L"olaylar";
			this->olaylar->Size = System::Drawing::Size(525, 101);
			this->olaylar->TabIndex = 5;
			this->olaylar->Text = L"";
			// 
			// panel
			// 
			this->panel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->panel->Location = System::Drawing::Point(36, 154);
			this->panel->Name = L"panel";
			this->panel->Size = System::Drawing::Size(644, 410);
			this->panel->TabIndex = 6;
			// 
			// rastgele_matrisolusutur
			// 
			this->rastgele_matrisolusutur->Location = System::Drawing::Point(15, 92);
			this->rastgele_matrisolusutur->Name = L"rastgele_matrisolusutur";
			this->rastgele_matrisolusutur->Size = System::Drawing::Size(92, 26);
			this->rastgele_matrisolusutur->TabIndex = 7;
			this->rastgele_matrisolusutur->Text = L"rastgele matris";
			this->rastgele_matrisolusutur->UseVisualStyleBackColor = true;
			this->rastgele_matrisolusutur->Click += gcnew System::EventHandler(this, &MainForm::rastgele_matrisolusutur_Click);
			// 
			// matrisi_coz
			// 
			this->matrisi_coz->Location = System::Drawing::Point(523, 117);
			this->matrisi_coz->Name = L"matrisi_coz";
			this->matrisi_coz->Size = System::Drawing::Size(133, 24);
			this->matrisi_coz->TabIndex = 8;
			this->matrisi_coz->Text = L"çöz";
			this->matrisi_coz->UseVisualStyleBackColor = true;
			this->matrisi_coz->Click += gcnew System::EventHandler(this, &MainForm::matrisi_coz_Click);
			// 
			// matrisi_yukle
			// 
			this->matrisi_yukle->Location = System::Drawing::Point(395, 117);
			this->matrisi_yukle->Name = L"matrisi_yukle";
			this->matrisi_yukle->Size = System::Drawing::Size(122, 23);
			this->matrisi_yukle->TabIndex = 9;
			this->matrisi_yukle->Text = L"matrisi yükle";
			this->matrisi_yukle->UseVisualStyleBackColor = true;
			this->matrisi_yukle->Click += gcnew System::EventHandler(this, &MainForm::matrisi_yukle_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(15, 124);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(92, 23);
			this->button1->TabIndex = 10;
			this->button1->Text = L"9x10 default";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// ilkhal
			// 
			this->ilkhal->Location = System::Drawing::Point(304, 117);
			this->ilkhal->Name = L"ilkhal";
			this->ilkhal->Size = System::Drawing::Size(85, 23);
			this->ilkhal->TabIndex = 11;
			this->ilkhal->Text = L"ilk halini göster";
			this->ilkhal->UseVisualStyleBackColor = true;
			this->ilkhal->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// kapsama_text
			// 
			this->kapsama_text->AutoSize = true;
			this->kapsama_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->kapsama_text->Location = System::Drawing::Point(129, 120);
			this->kapsama_text->Name = L"kapsama_text";
			this->kapsama_text->Size = System::Drawing::Size(71, 17);
			this->kapsama_text->TabIndex = 12;
			this->kapsama_text->Text = L"Kapsama:";
			// 
			// kapsamalar_textbox
			// 
			this->kapsamalar_textbox->BackColor = System::Drawing::SystemColors::Control;
			this->kapsamalar_textbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->kapsamalar_textbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->kapsamalar_textbox->Location = System::Drawing::Point(197, 121);
			this->kapsamalar_textbox->Name = L"kapsamalar_textbox";
			this->kapsamalar_textbox->ReadOnly = true;
			this->kapsamalar_textbox->Size = System::Drawing::Size(100, 18);
			this->kapsamalar_textbox->TabIndex = 13;
			this->kapsamalar_textbox->Text = L"";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(703, 599);
			this->Controls->Add(this->kapsamalar_textbox);
			this->Controls->Add(this->kapsama_text);
			this->Controls->Add(this->ilkhal);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->matrisi_yukle);
			this->Controls->Add(this->matrisi_coz);
			this->Controls->Add(this->rastgele_matrisolusutur);
			this->Controls->Add(this->panel);
			this->Controls->Add(this->olaylar);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->sutun_sayisi);
			this->Controls->Add(this->satir_sayisi);
			this->Controls->Add(this->matrisolustur);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
private: System::Void matrisolustur_Click(System::Object^ sender, System::EventArgs^ e) { //sýfýr matris olustur
	kapsamalar_textbox->Clear();
	olaylar->Clear();
	devam = 0;
	bitti = 0;
	int satirSayisi = Int32::Parse(satir_sayisi->Text);
	int sutunSayisi = Int32::Parse(sutun_sayisi->Text);
	matta = gcnew Matrixs(satirSayisi, sutunSayisi,olaylar,panel,kapsamalar_textbox);
	System::Random^ rand = gcnew System::Random();

	for (int a = 0; a < satirSayisi; a++)
	{
		for (int i = 0; i < sutunSayisi; i++)
		{
			matta->ekle(a, i, 0);
		}
	}
	matta->yazdir();
	}
private: System::Void rastgele_matrisolusutur_Click(System::Object^ sender, System::EventArgs^ e) {
	kapsamalar_textbox->Clear();
	olaylar->Clear();
	devam = 0;
	bitti = 0;
	int satirSayisi = Int32::Parse(satir_sayisi->Text);
	int sutunSayisi = Int32::Parse(sutun_sayisi->Text);
	matta = gcnew Matrixs(satirSayisi, sutunSayisi,olaylar,panel, kapsamalar_textbox);
	System::Random^ rand = gcnew System::Random();

	for (int a = 0; a < satirSayisi; a++)
	{
		for (int i = 0; i < sutunSayisi; i++)
		{
			matta->ekle(a, i, rand->Next(0, 2));
		}
	}

	matta->yazdir();
}
private: System::Void matrisi_coz_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!devam && !bitti)
	{
		if (matta->tum_kapsama_var_mi() == 999)
		{
			matta->kapsamalari_yazdir();
			bitti = true;
		}
		else
		{
			if (matta->mutlak_satir_bul() == 1)
			{
				matta->mutlak_satir_sil();
				olaylar->AppendText("--------------------\n");
			}
			else
			{
				//sezgisel rota algoritmasýna geciliyor
				matta->enaz_agir_sutun_sil();
				olaylar->AppendText("--------------------\n");
			}
		}
		devam = true;
	}
	else {
		matta->yazdir();
		devam = false;
	}
}
private: System::Void matrisi_yukle_Click(System::Object^ sender, System::EventArgs^ e) {
	int satirSayisi = Int32::Parse(satir_sayisi->Text);
	int sutunSayisi = Int32::Parse(sutun_sayisi->Text);

	int a = 0;
	int i = 0;
	for each (Control ^ control in panel->Controls) {
		if (TextBox::typeid->IsInstanceOfType(control)) 
		{
			TextBox^ textBox = dynamic_cast<TextBox^>(control);
			if (i == sutunSayisi)
			{
				i = 0;
				a++;
			}
			matta->ekle(a, i, Int32::Parse(textBox->Text));
			i++;
		}
	
	}
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { //default matris
	olaylar->Clear();
	devam = 0;
	bitti = 0;
	kapsamalar_textbox->Clear();
	matta = gcnew Matrixs(9, 10, olaylar, panel, kapsamalar_textbox);
	matta->ekle(0, 0, 1);
	matta->ekle(0, 1, 0);
	matta->ekle(0, 2, 0);
	matta->ekle(0, 3, 1);
	matta->ekle(0, 4, 0);
	matta->ekle(0, 5, 0);
	matta->ekle(0, 6, 0);
	matta->ekle(0, 7, 1);
	matta->ekle(0, 8, 0);
	matta->ekle(0, 9, 0);

	matta->ekle(1, 0, 0);
	matta->ekle(1, 1, 1);
	matta->ekle(1, 2, 1);
	matta->ekle(1, 3, 0);
	matta->ekle(1, 4, 1);
	matta->ekle(1, 5, 0);
	matta->ekle(1, 6, 0);
	matta->ekle(1, 7, 1);
	matta->ekle(1, 8, 0);
	matta->ekle(1, 9, 0);

	matta->ekle(2, 0, 0);
	matta->ekle(2, 1, 1);
	matta->ekle(2, 2, 0);
	matta->ekle(2, 3, 0);
	matta->ekle(2, 4, 0);
	matta->ekle(2, 5, 1);
	matta->ekle(2, 6, 1);
	matta->ekle(2, 7, 0);
	matta->ekle(2, 8, 0);
	matta->ekle(2, 9, 0);

	matta->ekle(3, 0, 0);
	matta->ekle(3, 1, 0);
	matta->ekle(3, 2, 1);
	matta->ekle(3, 3, 1);
	matta->ekle(3, 4, 0);
	matta->ekle(3, 5, 0);
	matta->ekle(3, 6, 0);
	matta->ekle(3, 7, 1);
	matta->ekle(3, 8, 0);
	matta->ekle(3, 9, 1);

	matta->ekle(4, 0, 0);
	matta->ekle(4, 1, 0);
	matta->ekle(4, 2, 0);
	matta->ekle(4, 3, 1);
	matta->ekle(4, 4, 0);
	matta->ekle(4, 5, 0);
	matta->ekle(4, 6, 1);
	matta->ekle(4, 7, 0);
	matta->ekle(4, 8, 1);
	matta->ekle(4, 9, 0);

	matta->ekle(5, 0, 1);
	matta->ekle(5, 1, 0);
	matta->ekle(5, 2, 1);
	matta->ekle(5, 3, 0);
	matta->ekle(5, 4, 0);
	matta->ekle(5, 5, 1);
	matta->ekle(5, 6, 0);
	matta->ekle(5, 7, 0);
	matta->ekle(5, 8, 0);
	matta->ekle(5, 9, 0);

	matta->ekle(6, 0, 0);
	matta->ekle(6, 1, 0);
	matta->ekle(6, 2, 0);
	matta->ekle(6, 3, 0);
	matta->ekle(6, 4, 1);
	matta->ekle(6, 5, 0);
	matta->ekle(6, 6, 1);
	matta->ekle(6, 7, 0);
	matta->ekle(6, 8, 0);
	matta->ekle(6, 9, 0);

	matta->ekle(7, 0, 1);
	matta->ekle(7, 1, 0);
	matta->ekle(7, 2, 0);
	matta->ekle(7, 3, 0);
	matta->ekle(7, 4, 1);
	matta->ekle(7, 5, 0);
	matta->ekle(7, 6, 0);
	matta->ekle(7, 7, 1);
	matta->ekle(7, 8, 1);
	matta->ekle(7, 9, 0);

	matta->ekle(8, 0, 1);
	matta->ekle(8, 1, 0);
	matta->ekle(8, 2, 1);
	matta->ekle(8, 3, 0);
	matta->ekle(8, 4, 1);
	matta->ekle(8, 5, 0);
	matta->ekle(8, 6, 1);
	matta->ekle(8, 7, 0);
	matta->ekle(8, 8, 0);
	matta->ekle(8, 9, 1);
	
	matta->yazdir();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	matta->ilkhal_yazdir();
}
};
}
