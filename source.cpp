#include <iostream>
#include <vector>
#include <Windows.h>

struct matris {
	int sutun[10];
};

std::vector<int> silinen_satir;
std::vector<int> silinen_sutun;

int contains(int sayi, std::vector<int> selected) //selected vektorunun icinde olup olmadigini kontrol eder
{
	for (int i = 0; i < selected.size(); i++) {
		if (selected[i] == sayi)
			return 1;
	}
	return 0;
}

std::vector<int> satirlariSec(matris satir[], std::vector<int>secilen_sutun, int size)
{
	std::vector <int> secilensatir;
	for (int x = 0; x < secilen_sutun.size(); x++)
	{
		for (int a = 0; a < size; a++)
		{
			if (contains(a, silinen_satir))//eger satir silinmis ise
				continue;

			if (satir[a].sutun[secilen_sutun[x]] == 1)
			{
				if (!contains(a, secilensatir));
				secilensatir.push_back(a);
			}
		}
	}
	return secilensatir;
}

int w_sutun(matris satir[], int ind, int size)
{
	int w = 0;
	for (int a = 0; a < size; a++) //satirlar
	{
		if (contains(a, silinen_satir))//eger satir silinmis ise
			continue;

		if (satir[a].sutun[ind] == 1)
			w++;
	}
	return w;
}

int bul_mutlaksatir(matris satir[], int ind, int size)
{
	for (int a = 0; a < size; a++)
	{
		if (contains(a, silinen_satir))//eger satir silinmis ise
			continue;

		if (satir[a].sutun[ind] == 1)
			return a;
	}
	return -1; //mutlak satir bulunmadi
}

void yazdir(matris satir[], int satir_sayisi,int sutun_sayisi)
{
	printf("\n------------------------------\n");
	printf("   ");
	for (int i = 0; i < sutun_sayisi; i++) //sutunlari yazdir
	{
		if (contains(i, silinen_sutun))
			continue;
		printf("%d  ", i);
	}
	printf("\n");
	for (int a = 0; a < satir_sayisi; a++) //satirlar yazilir
	{
		if (contains(a, silinen_satir))
			continue;
		printf("%d ", a); //satir yazdirilir
		for (int i = 0; i < sutun_sayisi; i++)
		{
			if (contains(i, silinen_sutun))
				continue;
			printf("|%d|", satir[a].sutun[i]); //sutun yan yana degerleri yazdirilir
		}
		printf("\n");
	}
	printf("------------------------------\n");
}

void bitis_yazdir(std::vector<int> kapsama)
{
	printf("KAPSAMA: ");
	for (int x = 0; x < kapsama.size(); x++)
	{
		std::cout << kapsama[x] << " ";
	}
	printf("\n----------BITTI------------\n");
}

int main()
{
	const int satir_sayisi = 9;
	const int sutun_sayisi = 10;

	float satir_a[satir_sayisi]; //satir agirliklari depolanir
	int sutun_a[sutun_sayisi]; //her bir sutunun agirliginin depolandigi
	std::vector<int> selected; //satir agirligi hesaplanacak indeksler
	std::vector<int> mutlaksatir;
	std::vector<int> kapsama;
	bool ismutlaksatir = 0; //mutlak satir var mi yok mu kontrol

	matris satir[9];

	satir[0].sutun[0] = 1;
	satir[0].sutun[1] = 0;
	satir[0].sutun[2] = 0;
	satir[0].sutun[3] = 1;
	satir[0].sutun[4] = 0;
	satir[0].sutun[5] = 0;
	satir[0].sutun[6] = 0;
	satir[0].sutun[7] = 1;
	satir[0].sutun[8] = 0;
	satir[0].sutun[9] = 0;

	satir[1].sutun[0] = 0;
	satir[1].sutun[1] = 1;
	satir[1].sutun[2] = 1;
	satir[1].sutun[3] = 0;
	satir[1].sutun[4] = 1;
	satir[1].sutun[5] = 0;
	satir[1].sutun[6] = 0;
	satir[1].sutun[7] = 1;
	satir[1].sutun[8] = 0;
	satir[1].sutun[9] = 0;

	satir[2].sutun[0] = 0;
	satir[2].sutun[1] = 1;
	satir[2].sutun[2] = 0;
	satir[2].sutun[3] = 0;
	satir[2].sutun[4] = 0;
	satir[2].sutun[5] = 1;
	satir[2].sutun[6] = 1;
	satir[2].sutun[7] = 0;
	satir[2].sutun[8] = 0;
	satir[2].sutun[9] = 0;

	satir[3].sutun[0] = 0;
	satir[3].sutun[1] = 0;
	satir[3].sutun[2] = 1;
	satir[3].sutun[3] = 1;
	satir[3].sutun[4] = 0;
	satir[3].sutun[5] = 0;
	satir[3].sutun[6] = 0;
	satir[3].sutun[7] = 1;
	satir[3].sutun[8] = 0;
	satir[3].sutun[9] = 1;

	satir[4].sutun[0] = 0;
	satir[4].sutun[1] = 0;
	satir[4].sutun[2] = 0;
	satir[4].sutun[3] = 1;
	satir[4].sutun[4] = 0;
	satir[4].sutun[5] = 0;
	satir[4].sutun[6] = 1;
	satir[4].sutun[7] = 0;
	satir[4].sutun[8] = 1;
	satir[4].sutun[9] = 0;

	satir[5].sutun[0] = 1;
	satir[5].sutun[1] = 0;
	satir[5].sutun[2] = 1;
	satir[5].sutun[3] = 0;
	satir[5].sutun[4] = 0;
	satir[5].sutun[5] = 1;
	satir[5].sutun[6] = 0;
	satir[5].sutun[7] = 0;
	satir[5].sutun[8] = 0;
	satir[5].sutun[9] = 0;

	satir[6].sutun[0] = 0;
	satir[6].sutun[1] = 0;
	satir[6].sutun[2] = 0;
	satir[6].sutun[3] = 0;
	satir[6].sutun[4] = 1;
	satir[6].sutun[5] = 0;
	satir[6].sutun[6] = 1;
	satir[6].sutun[7] = 0;
	satir[6].sutun[8] = 0;
	satir[6].sutun[9] = 0;

	satir[7].sutun[0] = 1;
	satir[7].sutun[1] = 0;
	satir[7].sutun[2] = 0;
	satir[7].sutun[3] = 0;
	satir[7].sutun[4] = 1;
	satir[7].sutun[5] = 0;
	satir[7].sutun[6] = 0;
	satir[7].sutun[7] = 1;
	satir[7].sutun[8] = 1;
	satir[7].sutun[9] = 0;

	satir[8].sutun[0] = 1;
	satir[8].sutun[1] = 0;
	satir[8].sutun[2] = 1;
	satir[8].sutun[3] = 0;
	satir[8].sutun[4] = 1;
	satir[8].sutun[5] = 0;
	satir[8].sutun[6] = 1;
	satir[8].sutun[7] = 0;
	satir[8].sutun[8] = 0;
	satir[8].sutun[9] = 1;


bas:
	ismutlaksatir = 0;
	for (int a = 0; a < satir_sayisi; a++) //tum sutunlari kapsayan satir mevcut mu diye bak
	{
		if (contains(a, silinen_satir))
			continue;
		bool hepsini_kapsiyor = 1;
		for (int i = 0; i < sutun_sayisi; i++)
		{
			if (contains(i, silinen_sutun))
				continue;
			if (satir[a].sutun[i] == 0)
				hepsini_kapsiyor = 0;	
		}
		if (hepsini_kapsiyor) {
			printf("%d. satir hepsini kapsiyor, o nedenle kapsamaya dahil edilir.\n",a);
			kapsama.push_back(a);
			bitis_yazdir(kapsama);
			return 999;
		}
	}

	for (int i = 0; i < sutun_sayisi; i++) //tum sutunlarin agirligini cikarir
	{
		if (contains(i, silinen_sutun))
			continue;
		sutun_a[i] = w_sutun(satir, i, satir_sayisi); //sutunun agirligini cikarir
		if (sutun_a[i] == 1) // eger sutunun agirligi 1 ise, mutlak satiri bulmaya baslar
		{
			mutlaksatir.push_back(bul_mutlaksatir(satir, i, satir_sayisi));
			ismutlaksatir = true;
		}
	}

	if (ismutlaksatir)
	{
		printf("Mutlak satir mevcut! ");
		for (int x = 0; x < mutlaksatir.size(); x++)
		{
			kapsama.push_back(mutlaksatir[x]); //mutlak satir kapsamaya alinir
			silinen_satir.push_back(mutlaksatir[x]); //mutlak satir silinir
			printf("Mutlak satir %d kapsamaya alindi.\n%d. satir silindi.\n", mutlaksatir[x], mutlaksatir[x]);
			for (int i = 0; i < satir_sayisi; i++)
			{
				if (satir[mutlaksatir[x]].sutun[i] == 1) {
					silinen_sutun.push_back(i); //mutlak satirin aktif sutunlari silinir
					printf("%d. sutun silindi.\n", i);
				}
			}

		}
		yazdir(satir, satir_sayisi,sutun_sayisi); //satir + sutun sayisina gore olcak
		mutlaksatir.clear(); //kaydedilen mutlak satirlar silinir
		goto bas;
	}

	int sel = sutun_sayisi;
	for (int i = 0; i < sutun_sayisi; i++) //en az agirlikli sutunlar bulunur
	{
		if (contains(i, silinen_sutun))
			continue;
		if (sutun_a[i] < sel)
		{
			selected.clear();
			selected.push_back(i);
			sel = sutun_a[i];
			continue;
		}
		if (sutun_a[i] == sel)
		{
			selected.push_back(i);
			continue;
		}
	}

	std::vector<int> secilen_satir = satirlariSec(satir, selected, satir_sayisi); //? idk
	float enAzAgirlik = 100;
	int enAzAgir_satir;

	printf("\n------------------------------\n");
	printf("   ");
	for (int i = 0; i < sutun_sayisi; i++) //sutunlari yazdir
	{
		if (contains(i, silinen_sutun))
			continue;
		printf("%d  ", i);
	}
	printf("\n");
	for (int a = 0; a < satir_sayisi; a++) //satirlar yazilir
	{
		if (contains(a, silinen_satir))
			continue;
		float agirlik = 0;
		printf("%d ", a); //satir yazdirilir
		for (int i = 0; i < sutun_sayisi; i++)
		{
			if (contains(i, silinen_sutun))
				continue;
			printf("|%d|", satir[a].sutun[i]); //sutun yan yana degerleri yazdirilir

			if (satir[a].sutun[i] == 1) //eger sutun 1 ise agirligi hesaplanir.
			{
				agirlik += 1.0f / (w_sutun(satir, i, satir_sayisi));
			}
		}
		if (contains(a, secilen_satir)) { //eger bu satir, baktiklarimiz arasinda ise

			if (agirlik < enAzAgirlik)
			{
				enAzAgir_satir = a;
				enAzAgirlik = agirlik;
			}

			printf(" ->%.2f\n", satir_sayisi * agirlik); //agirligi yazdirdik
		}
		else { printf("\n"); } //agirligi yazdirmaz
	}
	if (!ismutlaksatir)
		printf("\nMutlak satir bulunamadi\n");
	printf("En az agir satir= %d\n", enAzAgir_satir);
	printf("%d. satir siliniyor.\n", enAzAgir_satir);
	silinen_satir.push_back(enAzAgir_satir);
	printf("------------------------------\n");

	yazdir(satir, satir_sayisi, sutun_sayisi);
	goto bas;

}
