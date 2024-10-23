#pragma once

using namespace System;
using namespace System::Windows::Forms;


public ref class Matrixs {
private:
	int satir_sayisi;
	int sutun_sayisi;
	int p_su = 0;
	int p_sa = 0;
	RichTextBox^ log;
	RichTextBox^ kapsamalar_rtextbox;
    Panel^ panel;
	array<int, 2>^ matris; // 2 boyutlu dizi, CLI ortamýna uygun

	System::Collections::Generic::List<int>^ engellenen_satirlar = gcnew System::Collections::Generic::List<int>();
	System::Collections::Generic::List<int>^ engellenen_sutunlar = gcnew System::Collections::Generic::List<int>();

	System::Collections::Generic::List<int>^ secilen_satirlar = gcnew System::Collections::Generic::List<int>();
	System::Collections::Generic::List<int>^ enaz_agir_sutunlar = gcnew System::Collections::Generic::List<int>();

public: System::Collections::Generic::List<int>^ mutlak_satirlar = gcnew System::Collections::Generic::List<int>();
public: System::Collections::Generic::List<int>^ kapsama = gcnew System::Collections::Generic::List<int>();

public:
	
	Matrixs(int r, int c, RichTextBox^ rb, Panel^ panel, RichTextBox^ kapsamalar_rtextbox) {
		this->satir_sayisi = r;
		this->sutun_sayisi = c;
		this->log = rb;
		this->panel = panel;
		this->kapsamalar_rtextbox = kapsamalar_rtextbox;
		matris = gcnew array<int, 2>(r, c);
	}
	int dondur(int satir, int sutun)
	{
		return matris[satir, sutun];
	}
	void yazdir() //matrisi panele yazdirir
	{
		this->panel->Controls->Clear(); //matris panelini temizler


		int boxSize = 20;
		int spacing = 5;
		p_su = 0;
		p_sa = 0;
		for (int a = 0; a < satir_sayisi; a++) {
			if (satir_engellimi(a))
				continue;
			p_su = 0;
			for (int i = 0; i < sutun_sayisi; i++) {
				if (sutun_engellimi(i))
					continue;
				TextBox^ textBox = gcnew TextBox();
				textBox->Location = System::Drawing::Point(20 + (p_su) * (boxSize + spacing), (p_sa + 1) * (boxSize + spacing)); // TextBox konumu
				textBox->Size = System::Drawing::Size(boxSize, boxSize);
				textBox->Text = System::Convert::ToString(dondur(a, i));
				this->panel->Controls->Add(textBox);

				Label^ header = gcnew Label();
				header->Text = i.ToString();
				header->Location = System::Drawing::Point(25 + p_su * (boxSize + spacing), +5); // sutun baslik konumu
				header->Size = System::Drawing::Size(boxSize, boxSize);
				this->panel->Controls->Add(header);
				p_su++;
			}

			Label^ rowHeader = gcnew Label(); //satir basliklari olusturur
			rowHeader->Text = a.ToString();
			rowHeader->Location = System::Drawing::Point(0, (p_sa + 1) * (boxSize + spacing));
			rowHeader->Size = System::Drawing::Size(40, boxSize);
			this->panel->Controls->Add(rowHeader);
			p_sa++;
		}

	}
	void ilkhal_yazdir() //matrisi panele yazdirir
	{
		this->panel->Controls->Clear(); //matris panelini temizler

		int boxSize = 20;
		int spacing = 5;
		p_su = 0;
		p_sa = 0;
		for (int a = 0; a < satir_sayisi; a++) {
			p_su = 0;
			for (int i = 0; i < sutun_sayisi; i++) {
				TextBox^ textBox = gcnew TextBox();
				textBox->Location = System::Drawing::Point(20 + (p_su) * (boxSize + spacing), (p_sa + 1) * (boxSize + spacing)); // TextBox konumu
				textBox->Size = System::Drawing::Size(boxSize, boxSize);
				textBox->Text = System::Convert::ToString(dondur(a, i));
				this->panel->Controls->Add(textBox);

				Label^ header = gcnew Label();
				header->Text = i.ToString();
				header->Location = System::Drawing::Point(25 + p_su * (boxSize + spacing), +5); // sutun baslik konumu
				header->Size = System::Drawing::Size(boxSize, boxSize);
				this->panel->Controls->Add(header);
				p_su++;
			}

			Label^ rowHeader = gcnew Label(); //satir basliklari olusturur
			rowHeader->Text = a.ToString();
			rowHeader->Location = System::Drawing::Point(0, (p_sa + 1) * (boxSize + spacing));
			rowHeader->Size = System::Drawing::Size(40, boxSize);
			this->panel->Controls->Add(rowHeader);
			p_sa++;
		}

	}
	void satir_yanina_yazi(int satir, String^ str)
	{
		for (int i = 0; i < engellenen_satirlar->Count; i++)
		{
			if (engellenen_satirlar[i] < satir)
				satir--;
		}
		Label^ yazi = gcnew Label();
		yazi->Text = "--> " + str;
		yazi->Location = System::Drawing::Point(15 + p_su * (25), 5 + ((25) * (satir + 1)));
		yazi->Size = System::Drawing::Size(150, 20);
		this->panel->Controls->Add(yazi);
	}
	void satir_agirlik_yazdir(int satir, float agirlik)
	{
		for (int i = 0; i < engellenen_satirlar->Count; i++)
		{
			if (engellenen_satirlar[i] < satir)
				satir--;
		}
		Label^ yazi = gcnew Label();
		yazi->Text = "--> " + agirlik;
		yazi->Location = System::Drawing::Point(15 + p_su * (25), 5 + ((25) * (satir + 1)));
		yazi->Size = System::Drawing::Size(60, 20);
		this->panel->Controls->Add(yazi);
	}
	void sutun_agirlik_yazdir(int sutun, int agirlik)
	{
		for (int i = 0; i < engellenen_sutunlar->Count; i++)
		{
			if (engellenen_sutunlar[i] < sutun)
				sutun--;
		}
		Label^ header = gcnew Label();
		header->Text = "" + agirlik;
		header->Location = System::Drawing::Point(20 + (sutun) * (25), (p_sa + 1) * (25));
		header->Size = System::Drawing::Size(20, 20);
		this->panel->Controls->Add(header);
	}

	int contains(int sayi, System::Collections::Generic::List<int>^ selected) // selected vektörünün içinde olup olmadýðýný kontrol eder
	{
		for (int i = 0; i < selected->Count; i++) {
			if (selected[i] == sayi)
				return 1;
		}
		return 0;
	}
	void ekle(int satir, int sutun, int value) {
		matris[satir, sutun] = value;
	}
	int satir_engellimi(int satir)
	{
		if (contains(satir, engellenen_satirlar))
			return 1;
		return 0;
	}
	int sutun_engellimi(int sutun)
	{
		if (contains(sutun, engellenen_sutunlar))
			return 1;
		return 0;
	}
	void satir_engelle(int satir)
	{
		engellenen_satirlar->Add(satir);
	}
	void sutun_engelle(int sutun)
	{
		engellenen_sutunlar->Add(sutun);
	}
	int sutun_agirligi(int sutun)
	{
		int w = 0;
		for (int a = 0; a < satir_sayisi; a++) //satirlar
		{
			if (satir_engellimi(a))//eger satir silinmis ise
				continue;

			if (matris[a,sutun] == 1)
				w++;
		}
		return w;
	}

	int karsilik_gelen_satir(int sutun) //mutlak satiri bulmaya yardimci olur.
	{
		for (int a = 0; a < satir_sayisi; a++)
		{
			if (satir_engellimi(a))//eger satir silinmis ise
				continue;

			if (matris[a,sutun] == 1)
				return a;
		}
		return -1; //mutlak satir bulunmadi
	}
	int tum_kapsama_var_mi()
	{
		for (int a = 0; a < satir_sayisi; a++) //tum sutunlari kapsayan satir mevcut mu diye bak
		{
			if (satir_engellimi(a))
				continue;
			bool hepsini_kapsiyor = 1;
			for (int i = 0; i < sutun_sayisi; i++)
			{
				if (sutun_engellimi(i))
					continue;
				if (matris[a,i] == 0)
					hepsini_kapsiyor = 0;
			}
			if (hepsini_kapsiyor) {
				log->AppendText("\n" + a + ". satir hepsini kapsiyor, o nedenle kapsamaya dahil edilir.\n");
				kapsamalar_rtextbox->AppendText("" + a + "  ");
				kapsama->Add(a);
				satir_yanina_yazi(a,"Hepsini kapsiyor");
				return 999;
			}
		}
		return 0; //bulunamadi.
	}
	int mutlak_satir_bul()
	{
		mutlak_satirlar->Clear();
		bool ms_var = 0; //mutlak satirin bulunup bulunmadigini gosterir
		for (int i = 0; i < sutun_sayisi; i++) //tum sutunlarin agirligini cikarir
		{
			if (sutun_engellimi(i))
				continue;

			if (sutun_agirligi(i) == 1) // eger sutunun agirligi 1 ise, karsilik gelen satiri bul
			{
				if (!contains(karsilik_gelen_satir(i), mutlak_satirlar)) //eger mutlak_satirlar icinde yok 
					mutlak_satirlar->Add(karsilik_gelen_satir(i));
				ms_var = true;
			}
		}
		if (ms_var)
		{
			log->AppendText("mutlak satir bulundu: ");
			for (int i = 0; i < mutlak_satirlar->Count;i++)
			{
				log->AppendText(mutlak_satirlar[i] + " ");
				satir_yanina_yazi(mutlak_satirlar[i], "Mutlak satir");
			}
			log->AppendText("\n");
		}
		else
		{
			log->AppendText("mutlak satir bulunamadi!");
		}
		return ms_var;
	}
	void mutlak_satir_sil()
	{
		for (int x = 0; x < mutlak_satirlar->Count; x++)
		{
			kapsama->Add(mutlak_satirlar[x]); //mutlak satir kapsamaya alinir
			engellenen_satirlar->Add(mutlak_satirlar[x]); //mutlak satir silinir
			log->AppendText("Mutlak satir " + mutlak_satirlar[x] + " kapsamaya alindi.\n" + mutlak_satirlar[x] + ". satir silindi.\n");
			kapsamalar_rtextbox->AppendText("" + mutlak_satirlar[x] + "  ");
			for (int i = 0; i < satir_sayisi; i++)
			{
				if (matris[mutlak_satirlar[x],i] == 1) {
					engellenen_sutunlar->Add(i); //mutlak satirin aktif sutunlari silinir
					log->AppendText(i + ".sutun silindi. ");
				}
			}
		}
		log->AppendText("\n");
	}

	void enaz_agir_sutun_bul()
	{
		secilen_satirlar->Clear();
		enaz_agir_sutunlar->Clear();

		int sel = sutun_sayisi;
		for (int i = 0; i < sutun_sayisi; i++) //en az agirlikli sutunlar bulunur
		{
			if (sutun_engellimi(i))
				continue;
			int w = sutun_agirligi(i);
			sutun_agirlik_yazdir(i, w);
			if (w < sel)
			{
				enaz_agir_sutunlar->Clear();
				enaz_agir_sutunlar->Add(i);
				sel = w;
				continue;
			}
			if (w == sel)
			{
				enaz_agir_sutunlar->Add(i);
				continue;
			}
		}

		for (int x = 0; x < enaz_agir_sutunlar->Count; x++) //en az agir sutunlara karsilik gelen satirlari bul
		{
			for (int a = 0; a < satir_sayisi; a++)
			{
				if (satir_engellimi(a))//eger satir silinmis ise
					continue;

				if (matris[a,enaz_agir_sutunlar[x]] == 1)
				{
						secilen_satirlar->Add(a);
				}
			}
		}
	}
	void enaz_agir_sutun_sil()
	{
		enaz_agir_sutun_bul();
		float enAzAgirlik = 100;
		int enAzAgir_satir = -1;


		for (int a = 0; a < satir_sayisi; a++) //satirlar yazilir
		{
			if (satir_engellimi(a))
				continue;
			float agirlik = 0;

			for (int i = 0; i < sutun_sayisi; i++)
			{
				if (sutun_engellimi(i))
					continue;

				if (matris[a, i] == 1) //eger sutun 1 ise agirligi hesaplanir.
				{
					agirlik += 1.0f / (sutun_agirligi(i));
				}
			}
			if (contains(a, secilen_satirlar)) { //eger bu satir, baktiklarimiz arasinda ise

				if (agirlik < enAzAgirlik)
				{
					enAzAgir_satir = a;
					enAzAgirlik = agirlik;
				}

				satir_agirlik_yazdir(a, agirlik * satir_sayisi);
			}
		}

		log->AppendText("\nEn az agir satir= " + enAzAgir_satir);
		log->AppendText("\n" + enAzAgir_satir + ". satir siliniyor.\n");
		engellenen_satirlar->Add(enAzAgir_satir);
	}

	void kapsamalari_yazdir()
	{
		log->AppendText("KAPSAMA:\n");
		for (int x = 0; x < kapsama->Count; x++)
		{
			log->AppendText(kapsama[x] + " ");
		}
		log->AppendText("\n----------BITTI------------\n");
	}
};