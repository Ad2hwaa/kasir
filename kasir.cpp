#include <iostream>
#include <iomanip>
#include <string>
#include <numeric>

using namespace std;

struct transaksi
{
    string namaBarang;
    int hargaBarang;
    int jumlahBeli;
};

void inputPembelian(int jumlahBarang, transaksi pembelian[]){
    for (size_t i = 0; i < jumlahBarang; i++)
    {
        cout << "Masukan Nama Barang" << endl;
        cin >> pembelian[i].namaBarang;
        cout << "Masukan Harga Barang" << endl;
        cin >> pembelian[i].hargaBarang;
        cout << "Masukan Jumlah Beli Barang" << endl;
        cin >> pembelian[i].jumlahBeli;
    }   
    
}

int tampilkanPembelian(int jumlahBarang, transaksi pembelian[]){
    int totalHarga;
    cout << setfill('=') << setw(50) << '=' << endl;
    cout << "Nama Barang        Harga     Qty       Subtotal" << endl;
    cout << setfill('-') << setw(50) << '-' << endl;

    int SubTotal[jumlahBarang];
    for (size_t i = 0; i < jumlahBarang; i++)
    {
        cout << pembelian[i].namaBarang << "                ";
        cout << pembelian[i].hargaBarang << "           ";
        cout << pembelian[i].jumlahBeli << "            ";
        SubTotal[i]= pembelian[i].hargaBarang * pembelian[i].jumlahBeli;
        cout << SubTotal[i] << endl;
    }

    cout << setfill('-') << setw(50) << '-' << endl;
    totalHarga = accumulate(SubTotal, SubTotal + jumlahBarang, 0);
    cout << "Total Harga: " << totalHarga << endl;

    

    return totalHarga;
}

void pembayaran(int totalHarga){
    
    cout << "Bayar: ";
    int UangPembayaran;
    cin >> UangPembayaran;
    if (UangPembayaran < totalHarga)
    {
        cout << "Uang Tidak Cukup!" << endl;
        return;
    }
    int Kembalian = UangPembayaran - totalHarga;
    cout << "kembalian: " << Kembalian << endl;


    cout << "Terimakasih Telah Berbelanja di Sevelmart :^)" << endl;
    
}

void headerStruk(){
    cout << setfill('=') << setw(50) << '=' << endl;
    cout << "PROGRAM KASIR TOKO" << endl;
    cout << setfill('=') << setw(50) << '=' << endl;
}

int main(){
    int jumlahBarang;
    
    // blok kode menampilkan header
    headerStruk();    
    
    // blok kode 1
    cout << "Masukkan jumlah barang: ";
    cin >> jumlahBarang;
    transaksi pembelian[jumlahBarang];
    inputPembelian(jumlahBarang, pembelian);
    
    // blok kode 2
    int totalHarga = tampilkanPembelian(jumlahBarang, pembelian);

    // blok kode 3
    pembayaran(totalHarga);
    
    return 0;
}