//KODE SOAL C
//Nama: Zahra Salsabila
//NIM: 2400018206

#include <iostream>
#include <fstream>
using namespace std;

#define MAX 100

class Produk {
public:
	string kode[MAX];
	string nama[MAX];
	int jumlah[MAX];
	int harga[MAX];
	int n;
	
	Produk() {
		n = 0;
	}
	
	void bacaFile(string namaFile) {
		ifstream file(namaFile.c_str());
		while (file >> kode[n]){
			file.ignore();
			getline(file, nama[n]);
			file >> jumlah[n];
			file >> harga[n];
			n++;
		}
		file.close();
	}
	
	void tampilkan() {
		cout << "\nKode\tNama\tjumlah\tHarga\tTotal\n";
		for(int i = 0; i < n; i++) {
			cout << kode[i] << "\t" << nama[i] << "\t" << jumlah[i] << "\t" << harga[i]
			<< "\t" << jumlah[i] * harga[i] << endl;
		}
	}
	
	void cariKode(string k) {
		for(int i = 0; i < n; i++) {
			if(kode[i] == k) {
				cout << "Kode ditemukan: " << kode[i] << " Produk " << nama[i] << ", Jumlah " << jumlah[i] << ", Harga " << harga[i] << endl;
				return;
			}
		}
		cout << "Tidak ditemukan Kode\n";	
	}
	
	void cariTermurah() {
		int idx = 0;
		for(int i = 0; i < n; i++) {
			if(harga[i] < harga[idx]) {
			cout << "Harga Termurah: " << nama[idx] << " - " << harga[idx] << endl;
			}
		}
	}
	
	void sortTermahal() {
		for(int i = 0; i < n-1; i++) {
			for(int j = 0; j < n-i-1; j++) {
				if(harga[j] < harga[j+1]) tukar(j, j+1);
			}
		}
	}
	
	void sortTermurah() {
		for(int i = 0; i < n-1; i++) {
			for(int j = 0; j < n-i-1; j++) {
				if(harga[j] > harga[j+1]) tukar(j, j+1);
			}
		}
	}
	
	void tukar(int i, int j) {
		string tempKode = kode[i], tempNama = nama[i];
		int tempJumlah = jumlah[i], tempHarga = harga[i];
		kode[i] = kode [j]; nama[i] = nama[j];
		jumlah[i] = jumlah[j]; harga[i] = harga[j];
		kode[j] = tempKode; nama[j] = tempNama;
		jumlah[j] = tempJumlah; harga[j] = tempHarga;
	}
	
	int totalPendapatan() {
		int total = 0;
		for(int i = 1; i < n; i++) {
			total += jumlah[i] * harga[i];
			return total;
		}
	}
	
	void simpanFile(string  namaFile) {
		ofstream file(namaFile.c_str());
		for(int i = 0; i < n; i++) {
			file << kode[i] << " " << nama[i] << " " << jumlah[i] << " " << harga[i] << " " << jumlah[i] * harga[i] << endl;
		}
		file.close();
		cout << "Data Berhasil disimpan ke hasil_Analisis.txt\n";
	}
	
};

int main() {
	Produk toko;
	toko.bacaFile("transaksi.txt");
	
	int pilih;
	string kodeCari;
	do {
		cout << "\n====== MENU =====\n";
		cout << "1. Tampilkan Data Transaksi\n";
		cout << "2. Cari Produk Berdasarkan Kode\n";
		cout << "3. Cari Produk Berdasarkan Harga Termurah\n";
		cout << "4. Sort Harga Termahal\n";
		cout << "5. Sort Harga Termurah\n";
		cout << "6. Total Pendapatan\n";
		cout << "7. Hasil Analisis Penjualan\n";
		cout << "8. Hasil Sort Penjualan\n";
		cout << "0. Keluar\n";
		
		cout << "Pilih (1-8): ";
		cin >> pilih;
		
		if(pilih == 1)
		toko.tampilkan();
		else if(pilih == 2) {
			cout << "Masukkan Kode: ";
			cin >> kodeCari;
			toko.cariKode(kodeCari);
		}
		else if(pilih == 3) 
		toko.cariTermurah();
		else if(pilih == 4) {
			toko.sortTermahal();
			cout << "\nSorting Harga Termahal ke Termurah\n";
			toko.tampilkan();
		}
		else if(pilih == 5) {
			toko.sortTermurah();
			cout << "\nSorting Harga Termurah ke Termahal\n";
			toko.tampilkan();
		}
		else if(pilih == 6) {
			cout << "Total Pendapatan: " << toko.totalPendapatan() << endl;
		}
		else if(pilih == 7) {
			toko.simpanFile("hasil_analisis.txt");
		}
		else if(pilih == 8) {
			cout << "Bonus yang ini yaa\n";
		}
		else {
			cout << "Pilihan Anda Tidak Valid\n";
		}
		
	}while (pilih != 0);
	
	return 0;
}
