#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision
#include <limits>  // For std::numeric_limits

using namespace std;

int main() {
    int kode, harga, i = 1;
    int total_pembelian = 0, diskon, total_bayar, bayar, kembalian;
    char kar = 'y';

    // Clear screen for UNIX-based systems
    system("clear");

    cout << "\t\t\t\t============================\n";
    cout << "\t\t\t\t||  WELCOME TO KEDAIKU     ||\n";
    cout << "\t SEDIA : \n";
    cout << "\t 1. Kode 1: Ayam Goreng \n";
    cout << "\t 2. Kode 2: Ayam Bakar \n";
    cout << "\t 3. Kode 3: Ikan Goreng \n";
    cout << "\t 4. Kode 4: Ikan Bakar \n";
    cout << "\t 5. Kode 5: Dendeng Balado \n";

    while (kar == 'y') {
        cout << "BARANG KE - " << i << " : ";
        cin >> kode;

        switch (kode) {
            case 1:
                harga = 15000;
                cout << "\tHarga Ayam Goreng : Rp. " << harga << endl << endl;
                break;
            case 2:
                harga = 17000;
                cout << "\tHarga Ayam Bakar : Rp. " << harga << endl << endl;
                break;
            case 3:
                harga = 12000;
                cout << "\tHarga Ikan Goreng : Rp. " << harga << endl << endl;
                break;
            case 4:
                harga = 20000;
                cout << "\tHarga Ikan Bakar : Rp. " << harga << endl << endl;
                break;
            case 5:
                harga = 25000;
                cout << "\tHarga Dendeng Balado : Rp. " << harga << endl << endl;
                break;
            default:
                cout << "Input Salah \n";
                harga = 0;  // Ensure no addition to total_pembelian
                break;
        }

        total_pembelian += harga;

        cout << "MAU TRANSAKSI LAGI? [y/t] = ";
        cin >> kar;

        // Clear input buffer to handle any extra newline characters
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        i++;
    }

    cout << "============================\n";
    cout << "\t TOTAL PEMBELIAN : Rp. " << total_pembelian << endl;

    // Calculate discount
    if (total_pembelian > 50000) {
        diskon = static_cast<int>(total_pembelian * 0.1); // Using casting for integer result
        cout << "\t ANDA MENDAPAT DISKON SEBESAR = Rp. " << diskon << endl;
        total_bayar = total_pembelian - diskon;
    } else {
        total_bayar = total_pembelian;
    }

    cout << "\tTOTAL YANG HARUS DIBAYAR : Rp. " << total_bayar << endl;
    cout << "\t MASUKKAN UANG YANG ANDA BAYARKAN : Rp. ";
    cin >> bayar;

    kembalian = bayar - total_bayar;

    if (bayar >= total_bayar) {
        cout << "\t UANG KEMBALIAN ANDA : Rp. " << kembalian << endl;
    } else {
        cout << "\t UANG ANDA KURANG: Rp. " << (total_bayar - bayar) << endl;
    }

    return 0;
}