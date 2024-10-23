//Melih Efe Sevinç 434330
#include <iostream>
#include <vector>

struct Matrix {
    int satir_sayisi;
    int sutun_sayisi;          

    std::vector<std::vector<int>> matris;
	std::vector<int> mutlak_satirlar;
	std::vector<int> silinen_satirlar;
	std::vector<int> silinen_sutunlar;
	std::vector<int> enaz_agir_sutunlar; //satir agirligi hesaplanacak indeksler
	std::vector<int> secilen_satirlar; //en az agir sutunlarin karsilik geldigi satirlar
	std::vector<int> kapsama;
	
	int contains(int sayi, std::vector<int> selected) //selected vektorunun icinde olup olmadigini kontrol eder
	{
		for (int i = 0; i < selected.size(); i++) {
			if (selected[i] == sayi)
				return 1;
		}
		return 0;
	}

    Matrix(int sat, int sut, int initial_value = 0) : satir_sayisi(sat), sutun_sayisi(sut) { //matrisi yapilandir.
        matris.resize(satir_sayisi, std::vector<int>(sutun_sayisi, initial_value));
    }
    int& ekle(int satir, int sutun) { //matris elemanlarini ekle
        return matris[satir][sutun];
    }
	void satir_sil(int satir) { 
		silinen_satirlar.push_back(satir);
	}
	void sutun_sil(int satir) {
		silinen_sutunlar.push_back(satir);
	}
	int silinmis_satir(int sayi) 
	{
		for (int i = 0; i < silinen_satirlar.size(); i++) {
			if (silinen_satirlar[i] == sayi)
				return 1;
		}
		return 0;
	}
	int silinmis_sutun(int sayi) 
	{
		for (int i = 0; i < silinen_sutunlar.size(); i++) {
			if (silinen_sutunlar[i] == sayi)
				return 1;
		}
		return 0;
	}
	int sutun_agirligi(int sutun)
	{
		int w = 0;
		for (int a = 0; a < satir_sayisi; a++) //satirlar
		{
			if (silinmis_satir(a))//eger satir silinmis ise
				continue;

			if (matris[a][sutun] == 1)
				w++;
		}
		return w;
	}
	int karsilik_gelen_satir(int sutun) //utlak satiri bulmaya yardimci olur.
	{
		for (int a = 0; a < satir_sayisi; a++)
		{
			if (silinmis_satir(a))//eger satir silinmis ise
				continue;

			if (matris[a][sutun] == 1)
				return a;
		}
		return -1; //mutlak satir bulunmadi
	}
	int mutlak_satir_bul()
	{
		mutlak_satirlar.clear();
		bool ms_var = 0; //mutlak satirin bulunup bulunmadigini gosterir
		for (int i = 0; i < sutun_sayisi; i++) //tum sutunlarin agirligini cikarir
		{
			if (silinmis_sutun(i))
				continue;

			if (sutun_agirligi(i) == 1) // eger sutunun agirligi 1 ise, karsilik gelen satiri bul
			{
				if(!contains(i,mutlak_satirlar)) //eger mutlak_satirlar icinde yok 
                                   mutlak_satirlar.push_back(karsilik_gelen_satir(i));
				ms_var = true;
			}
		}
		if (ms_var)
		{
			std::cout << "mutlak satir bulundu: ";
			for (int i = 0; i < mutlak_satirlar.size();i++)
				std::cout << mutlak_satirlar[i] << " ";
			std::cout << "\n";
		}
		else
		{
			std::cout << "mutlak satir bulunamadi!\n";
		}
		return ms_var;
	}
	void enaz_agir_sutun_bul()
	{
		secilen_satirlar.clear();
		enaz_agir_sutunlar.clear();

		int sel = sutun_sayisi;
		for (int i = 0; i < sutun_sayisi; i++) //en az agirlikli sutunlar bulunur
		{
			if (silinmis_sutun(i))
				continue;
			int w = sutun_agirligi(i);
			if (w < sel)
			{
				enaz_agir_sutunlar.clear();
				enaz_agir_sutunlar.push_back(i);
				sel = w;
				continue;
			}
			if (w == sel)
			{
				enaz_agir_sutunlar.push_back(i);
				continue;
			}
		}

		for (int x = 0; x < enaz_agir_sutunlar.size(); x++) //en az agir sutunlara karsilik gelen satirlari bul
		{
			for (int a = 0; a < satir_sayisi; a++)
			{
				if (silinmis_satir(a))//eger satir silinmis ise
					continue;

				if (matris[a][enaz_agir_sutunlar[x]] == 1)
				{
					if (!silinmis_sutun(a));
					secilen_satirlar.push_back(a);
				}
			}
		}
	}	
	void enaz_agir_sutun_sil()
	{
		enaz_agir_sutun_bul();
		float enAzAgirlik = 100;
		int enAzAgir_satir = 0;

		printf("------------------------------\n");
		printf("   ");
		for (int i = 0; i < sutun_sayisi; i++) //sutunlari yazdir
		{
			if (silinmis_sutun(i))
				continue;
			printf("%d  ", i);
		}
		printf("\n");
		for (int a = 0; a < satir_sayisi; a++) //satirlar yazilir
		{
			if (silinmis_satir(a))
				continue;
			float agirlik = 0;
			printf("%d ", a); //satir yazdirilir
			for (int i = 0; i < sutun_sayisi; i++)
			{
				if (silinmis_sutun(i))
					continue;
				printf("|%d|", matris[a][i]); //sutun yan yana degerleri yazdirilir

				if (matris[a][i] == 1) //eger sutun 1 ise agirligi hesaplanir.
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

				printf(" ->%.2f\n", satir_sayisi * agirlik); //agirligi yazdirdik
			}
			else { printf("\n"); } //agirligi yazdirmaz
		}
		printf("\nEn az agir satir= %d\n", enAzAgir_satir);
		printf("%d. satir siliniyor.\n", enAzAgir_satir);
		silinen_satirlar.push_back(enAzAgir_satir);
		printf("------------------------------\n");
	}
	void yazdir()
	{
		printf("------------------------------\n");
		printf("   ");
		for (int i = 0; i < sutun_sayisi; i++) //sutunlari yazdir
		{
			if (silinmis_sutun(i))
				continue;
			printf("%d  ", i);
		}
		printf("\n");
		for (int a = 0; a < satir_sayisi; a++) //satirlar yazilir
		{
			if (silinmis_satir(a))
				continue;
			printf("%d ", a); //satir yazdirilir
			for (int i = 0; i < sutun_sayisi; i++)
			{
				if (silinmis_sutun(i))
					continue;
				printf("|%d|", matris[a][i]); //sutun yan yana degerleri yazdirilir
			}
			printf("\n");
		}
		printf("------------------------------\n");
	}
	void mutlak_satir_sil()
	{
		for (int x = 0; x < mutlak_satirlar.size(); x++)
		{
			kapsama.push_back(mutlak_satirlar[x]); //mutlak satir kapsamaya alinir
			silinen_satirlar.push_back(mutlak_satirlar[x]); //mutlak satir silinir
			printf("Mutlak satir %d kapsamaya alindi.\n%d. satir silindi.\n", mutlak_satirlar[x], mutlak_satirlar[x]);
			for (int i = 0; i < satir_sayisi; i++)
			{
				if (matris[mutlak_satirlar[x]][i] == 1) {
					silinen_sutunlar.push_back(i); //mutlak satirin aktif sutunlari silinir
					printf("%d. sutun silindi. ", i);
				}
			}
		}
		std::cout << "\n";
	}
	int tum_kapsama_var_mi()
	{
		for (int a = 0; a < satir_sayisi; a++) //tum sutunlari kapsayan satir mevcut mu diye bak
		{
			if (silinmis_satir(a))
				continue;
			bool hepsini_kapsiyor = 1;
			for (int i = 0; i < sutun_sayisi; i++)
			{
				if (silinmis_sutun(i))
					continue;
				if (matris[a][i] == 0)
					hepsini_kapsiyor = 0;
			}
			if (hepsini_kapsiyor) {
				printf("%d. satir hepsini kapsiyor, o nedenle kapsamaya dahil edilir.\n", a);
				kapsama.push_back(a);
				return 999;
			}
		}
		return 0; //bulunamadi.
	}
	void kapsamalari_yazdir()
	{
		printf("KAPSAMA: ");
		for (int x = 0; x < kapsama.size(); x++)
		{
			std::cout << kapsama[x] << " ";
		}
		printf("\n----------BITTI------------\n");
	}
};

int main() {

	/*
	//MATRISI KULLANICIDAN AL
	int satirs;
	int sutuns;
	int deger;
	std::cout << "Satir sayisini giriniz: ";
	std::cin >> satirs;
	std::cout << "Sutun sayisini giriniz: ";
	std::cin >> sutuns;
	Matrix mat(satirs, sutuns);
	for (int a = 0; a < satirs; a++)
	{
		for (int i = 0; i < sutuns; i++)
		{
			printf("%d. satir %d. sutun elemanini giriniz: ",a,i);
			std::cin >> mat.ekle(a, i);
		}
	}
	*/

	//matrisi derlemeden once belirle
	Matrix mat(9, 10);
	if (1)
	{
		mat.ekle(0, 0) = 1;
		mat.ekle(0, 1) = 0;
		mat.ekle(0, 2) = 0;
		mat.ekle(0, 3) = 1;
		mat.ekle(0, 4) = 0;
		mat.ekle(0, 5) = 0;
		mat.ekle(0, 6) = 0;
		mat.ekle(0, 7) = 1;
		mat.ekle(0, 8) = 0;
		mat.ekle(0, 9) = 0;

		mat.ekle(1, 0) = 0;
		mat.ekle(1, 1) = 1;
		mat.ekle(1, 2) = 1;
		mat.ekle(1, 3) = 0;
		mat.ekle(1, 4) = 1;
		mat.ekle(1, 5) = 0;
		mat.ekle(1, 6) = 0;
		mat.ekle(1, 7) = 1;
		mat.ekle(1, 8) = 0;
		mat.ekle(1, 9) = 0;

		mat.ekle(2, 0) = 0;
		mat.ekle(2, 1) = 1;
		mat.ekle(2, 2) = 0;
		mat.ekle(2, 3) = 0;
		mat.ekle(2, 4) = 0;
		mat.ekle(2, 5) = 1;
		mat.ekle(2, 6) = 1;
		mat.ekle(2, 7) = 0;
		mat.ekle(2, 8) = 0;
		mat.ekle(2, 9) = 0;

		mat.ekle(3, 0) = 0;
		mat.ekle(3, 1) = 0;
		mat.ekle(3, 2) = 1;
		mat.ekle(3, 3) = 1;
		mat.ekle(3, 4) = 0;
		mat.ekle(3, 5) = 0;
		mat.ekle(3, 6) = 0;
		mat.ekle(3, 7) = 1;
		mat.ekle(3, 8) = 0;
		mat.ekle(3, 9) = 1;

		mat.ekle(4, 0) = 0;
		mat.ekle(4, 1) = 0;
		mat.ekle(4, 2) = 0;
		mat.ekle(4, 3) = 1;
		mat.ekle(4, 4) = 0;
		mat.ekle(4, 5) = 0;
		mat.ekle(4, 6) = 1;
		mat.ekle(4, 7) = 0;
		mat.ekle(4, 8) = 1;
		mat.ekle(4, 9) = 0;

		mat.ekle(5, 0) = 1;
		mat.ekle(5, 1) = 0;
		mat.ekle(5, 2) = 1;
		mat.ekle(5, 3) = 0;
		mat.ekle(5, 4) = 0;
		mat.ekle(5, 5) = 1;
		mat.ekle(5, 6) = 0;
		mat.ekle(5, 7) = 0;
		mat.ekle(5, 8) = 0;
		mat.ekle(5, 9) = 0;

		mat.ekle(6, 0) = 0;
		mat.ekle(6, 1) = 0;
		mat.ekle(6, 2) = 0;
		mat.ekle(6, 3) = 0;
		mat.ekle(6, 4) = 1;
		mat.ekle(6, 5) = 0;
		mat.ekle(6, 6) = 1;
		mat.ekle(6, 7) = 0;
		mat.ekle(6, 8) = 0;
		mat.ekle(6, 9) = 0;

		mat.ekle(7, 0) = 1;
		mat.ekle(7, 1) = 0;
		mat.ekle(7, 2) = 0;
		mat.ekle(7, 3) = 0;
		mat.ekle(7, 4) = 1;
		mat.ekle(7, 5) = 0;
		mat.ekle(7, 6) = 0;
		mat.ekle(7, 7) = 1;
		mat.ekle(7, 8) = 1;
		mat.ekle(7, 9) = 0;

		mat.ekle(8, 0) = 1;
		mat.ekle(8, 1) = 0;
		mat.ekle(8, 2) = 1;
		mat.ekle(8, 3) = 0;
		mat.ekle(8, 4) = 1;
		mat.ekle(8, 5) = 0;
		mat.ekle(8, 6) = 1;
		mat.ekle(8, 7) = 0;
		mat.ekle(8, 8) = 0;
		mat.ekle(8, 9) = 1;

	}

	int x = 0;
	while (mat.tum_kapsama_var_mi() != 999)
	{
		mat.yazdir();
		if (mat.mutlak_satir_bul())
			mat.mutlak_satir_sil();
		else
			mat.enaz_agir_sutun_sil();
		x++; 
		if (x == 100) //sezgisel rota algoritmasi ile cozulemez
			return 1;
	}
	mat.yazdir();
	mat.kapsamalari_yazdir();
}
