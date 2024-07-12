

// KADÝR KAÐAN ULUDAÐ  

// Gerekli kütüphanalerin kurulmasý-tanýmlanmasý
#include <iostream> 
#include <random>
#include <vector>

// Koordinatlarýn saklanmasý
std::vector <int> koordinatlar;

// Rastgele koordinatlarýn üretilmesi
int Rastgele_Koordinat_Uretme(std::mt19937& gen, std::uniform_int_distribution <>& dis) {
	return dis(gen);
}



// Koordinatlarýn ekrana yazdýrýlma fonksiyonu
void Koordinatlari_Yaz(const std::vector <int>& koordinatar) {
	std::cout << "KOORDINATLAR: ";
	// Koordinatlarýn yazdýrýlmasý için sýrayla döngüye girmesi iþlemi.
	for (int i = 0; i < koordinatlar.size(); i++) {
		std::cout << koordinatar[i] << " ";
	}
	std::cout << std::endl;
}

// Koordinat kontrolü
void Koordinat_Ekle(std::vector <int>& koordinatlar, int anlik_koordinat) {

	// Burada anlatýlmak istenen begin ve end aralýðýnda anlýk koordinatýn bulunup bulunmadýðýnýn kontrolüdür. Böylece izlenecek koordinatlarda her koordinata bir defa gidilir. 
	if (std::find(koordinatlar.begin(), koordinatlar.end(), anlik_koordinat) != koordinatlar.end()) {

		// Kod satýrý yorum haline getirilmiþtir. Projede, mevcut koordinat üretilmesi halinde uyarý verilmesi istenmemektedir. 
		//std::cout << "Algoritmanin olusturdugu Koordinat zaten mevcut!" << std::endl;

		return;
	}

	// Abs fonksiyonu girilen koordinatlarýn farkýnýn mutlak deðerini almamýzý saðlar. 
	if (!koordinatlar.empty() && std::abs(anlik_koordinat - koordinatlar.back()) < 5) {

		// Kod satýrý yorum haline getirilmiþtir. Projede, ardýþýk üretilen koordinatlarýn farký 5'ten küçük olduðu takdirde uyarý verilmesi istenmemektedir.
		//std::cout << "Ardisik koordinatlarin Farki minimum 5 olmalidir!" << std::endl;

		return;
	}

	koordinatlar.push_back(anlik_koordinat);
}


// Temel algoritma
int main() {

	// Burada rk deðerimiz Random Koordinatlarý ifade eder.
	std::random_device rk;
	std::mt19937 gen(rk());
	std::uniform_int_distribution <> dis(1, 20);

	bool Hatali_Koordinat;
	do {

		int ilk_koordinat = Rastgele_Koordinat_Uretme(gen, dis);
		
		// Bu kodda ilk atacaðý adýmýn da 5 birimden küçük olmamasýný ifade eder.
		Hatali_Koordinat = (ilk_koordinat < 5);
		if (!Hatali_Koordinat) {
			koordinatlar.push_back(ilk_koordinat);

		}
		else {
			std::cout << "Hatali Koordinat Uretildi!" << std::endl;
		}


	} while (Hatali_Koordinat);

	// Buradaki 10 sayýsýný artýrdýðýmýz takdirde, Mini Ada robotumuzun g,deceði koordinat sayýsý artacak.
	while (koordinatlar.size() < 10) {
		int anlik_koordinat = Rastgele_Koordinat_Uretme(gen, dis);
		Koordinat_Ekle(koordinatlar, anlik_koordinat);
	}
	// Bu satýrdaki temel mesele döngü içerisinde olsaydý, koordinatlarýn 10 defa yazýlmasýný saðlayacaktý.
	Koordinatlari_Yaz(koordinatlar);
	return 0;
}
