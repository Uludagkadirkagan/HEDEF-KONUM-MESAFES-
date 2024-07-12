

// KAD�R KA�AN ULUDA�  

// Gerekli k�t�phanalerin kurulmas�-tan�mlanmas�
#include <iostream> 
#include <random>
#include <vector>

// Koordinatlar�n saklanmas�
std::vector <int> koordinatlar;

// Rastgele koordinatlar�n �retilmesi
int Rastgele_Koordinat_Uretme(std::mt19937& gen, std::uniform_int_distribution <>& dis) {
	return dis(gen);
}



// Koordinatlar�n ekrana yazd�r�lma fonksiyonu
void Koordinatlari_Yaz(const std::vector <int>& koordinatar) {
	std::cout << "KOORDINATLAR: ";
	// Koordinatlar�n yazd�r�lmas� i�in s�rayla d�ng�ye girmesi i�lemi.
	for (int i = 0; i < koordinatlar.size(); i++) {
		std::cout << koordinatar[i] << " ";
	}
	std::cout << std::endl;
}

// Koordinat kontrol�
void Koordinat_Ekle(std::vector <int>& koordinatlar, int anlik_koordinat) {

	// Burada anlat�lmak istenen begin ve end aral���nda anl�k koordinat�n bulunup bulunmad���n�n kontrol�d�r. B�ylece izlenecek koordinatlarda her koordinata bir defa gidilir. 
	if (std::find(koordinatlar.begin(), koordinatlar.end(), anlik_koordinat) != koordinatlar.end()) {

		// Kod sat�r� yorum haline getirilmi�tir. Projede, mevcut koordinat �retilmesi halinde uyar� verilmesi istenmemektedir. 
		//std::cout << "Algoritmanin olusturdugu Koordinat zaten mevcut!" << std::endl;

		return;
	}

	// Abs fonksiyonu girilen koordinatlar�n fark�n�n mutlak de�erini almam�z� sa�lar. 
	if (!koordinatlar.empty() && std::abs(anlik_koordinat - koordinatlar.back()) < 5) {

		// Kod sat�r� yorum haline getirilmi�tir. Projede, ard���k �retilen koordinatlar�n fark� 5'ten k���k oldu�u takdirde uyar� verilmesi istenmemektedir.
		//std::cout << "Ardisik koordinatlarin Farki minimum 5 olmalidir!" << std::endl;

		return;
	}

	koordinatlar.push_back(anlik_koordinat);
}


// Temel algoritma
int main() {

	// Burada rk de�erimiz Random Koordinatlar� ifade eder.
	std::random_device rk;
	std::mt19937 gen(rk());
	std::uniform_int_distribution <> dis(1, 20);

	bool Hatali_Koordinat;
	do {

		int ilk_koordinat = Rastgele_Koordinat_Uretme(gen, dis);
		
		// Bu kodda ilk ataca�� ad�m�n da 5 birimden k���k olmamas�n� ifade eder.
		Hatali_Koordinat = (ilk_koordinat < 5);
		if (!Hatali_Koordinat) {
			koordinatlar.push_back(ilk_koordinat);

		}
		else {
			std::cout << "Hatali Koordinat Uretildi!" << std::endl;
		}


	} while (Hatali_Koordinat);

	// Buradaki 10 say�s�n� art�rd���m�z takdirde, Mini Ada robotumuzun g,dece�i koordinat say�s� artacak.
	while (koordinatlar.size() < 10) {
		int anlik_koordinat = Rastgele_Koordinat_Uretme(gen, dis);
		Koordinat_Ekle(koordinatlar, anlik_koordinat);
	}
	// Bu sat�rdaki temel mesele d�ng� i�erisinde olsayd�, koordinatlar�n 10 defa yaz�lmas�n� sa�layacakt�.
	Koordinatlari_Yaz(koordinatlar);
	return 0;
}
