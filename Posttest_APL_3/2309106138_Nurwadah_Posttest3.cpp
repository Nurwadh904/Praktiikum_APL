#include <iostream>
using namespace std;

#define max 15
string ListDaftarBuah[max], loop;
double HargaBuah[max];
int index = 0;

void tampilkan() {
    if (index > 0) {
        cout << "Daftar Buah Yang Tersimpan" << endl;
        double totalHarga = 0.0;
        for (int a = 0; a < index; a++) {
            cout << a + 1 << ". " << ListDaftarBuah[a] << " - Rp" << HargaBuah[a] << endl;
            totalHarga += HargaBuah[a];
        }
        cout << "Total Harga: Rp" << totalHarga << endl;
    } else {
        cout << "Tidak ada daftar buah yang tersimpan" << endl;
    }
}

double hitungTotalHarga(int i, double totalHarga = 0.0) {
    if (i < index) {
        totalHarga += HargaBuah[i];
        return hitungTotalHarga(i + 1, totalHarga);
    } else {
        return totalHarga;
    }
}

void tambahBuah() {
    do {
        tampilkan();
        if (index < max) {
            cin.ignore();
            cout << "Tambah buah yang anda inginkan: ";
            getline(cin, ListDaftarBuah[index]);
            cout << "Masukkan harga buah: Rp";
            cin >> HargaBuah[index];
            index++;
            tampilkan();
            cout << "Apakah anda ingin menambahkan daftar buah lagi? (ya/tidak) : ";
            cin >> loop;
        } else {
            cout << "Kapasitas maksimum tercapai" << endl;
            cout << "Tekan 'tidak' untuk kembali : ";
            cin >> loop;
        }
    } while (loop == "ya");
}

void ubahBuah() {
    int indeks;
    do {
        tampilkan();
        cout << "Pilih nomor buah yang ingin anda diubah: ";
        cin >> indeks;
        cin.ignore();
        cout << "Ubah menjadi buah: ";
        getline(cin, ListDaftarBuah[indeks - 1]);
        cout << "Masukkan harga baru: Rp";
        cin >> HargaBuah[indeks - 1];
        tampilkan();
        cout << "Apakah anda ingin ubah daftar buah lagi? (ya/tidak) : ";
        cin >> loop;
    } while (loop == "ya");
}

void hapusBuah() {
    int indeks;
    do {
        tampilkan();
        if (index > 0) {
            cout << "Hapus nomor buah yang anda inginkan: ";
            cin >> indeks;
            for (int i = indeks; i < index; i++) {
                ListDaftarBuah[i - 1] = ListDaftarBuah[i];
                HargaBuah[i - 1] = HargaBuah[i];
            }
            index--;
            tampilkan();
            cout << "Apakah anda ingin ingin menghapus lagi? (ya/tidak) : ";
            cin >> loop;
        } else {
            cout << "Daftar buah kosong. Tekan 'tidak' untuk kembali : ";
            cin >> loop;
        }
    } while (loop == "ya");
}

int main() {
    string username;
    string password;
    int ulang = 0;
    do {
        cout << "Username: ";
        cin >> username;

        cout << "Password: ";
        cin >> password;

        if (username == "Nurwadah" && password == "138") {
            cout << "Login berhasil" << endl;
            break;
        } else {
            cout << "Username atau password salah. Silakan coba lagi." << endl;
            ulang++;
        }
    } while (ulang < 3);

    if (ulang == 3) {
        cout << "Anda telah mencoba login sebanyak 3 kali. Aplikasi akan keluar." << endl;
    }

    int pilihan;
    do {
        cout << "===== Toko Buah =====" << endl;
        cout << "1. Tambah Buah" << endl;
        cout << "2. Ubah Buah" << endl;
        cout << "3. Hapus Buah" << endl;
        cout << "4. Tampilkan Daftar Buah" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                tambahBuah();
                break;
            case 2:
                ubahBuah();
                break;
            case 3:
                hapusBuah();
                break;
            case 4:
                tampilkan();
                break;
            case 5:
                cout << "Keluar dari program\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih 1 - 5\n";
                break;
        }
    } while (pilihan != 5);
    cout << "Total Harga Semua Buah: Rp" << hitungTotalHarga(0) << endl;
    cout << "Terima kasih telah menggunakan aplikasi Toko Buah\n";
    return 0;
}