#include <iostream>
#include <iomanip>
using namespace std;

// Abstract Base Class
class RekeningBank
{
protected:
    string namaNasabah;
    double saldo;

public:
    RekeningBank(string nama, double s)
    {
        namaNasabah = nama;
        saldo = s;
    }

    // Pure virtual function
    virtual void potongAdmin() = 0;

    // Menampilkan data rekening
    void tampilkanSaldo()
    {
        cout << "Nama Nasabah : " << namaNasabah << endl;
        cout << "Saldo Akhir  : Rp " << fixed << setprecision(0) << saldo << endl;
        cout << "-----------------------------" << endl;
    }

    virtual ~RekeningBank() {}
};

// Rekening Syariah
class RekeningSyariah : public RekeningBank
{
public:
    RekeningSyariah(string nama, double s)
        : RekeningBank(nama, s) {}

    void potongAdmin()
    {
        cout << "Rekening Syariah -> Tidak ada potongan admin." << endl;
    }
};

// Rekening Konvensional
class RekeningKonvensional : public RekeningBank
{
public:
    RekeningKonvensional(string nama, double s)
        : RekeningBank(nama, s) {}

    void potongAdmin()
    {
        saldo -= 15000;
        cout << "Rekening Konvensional -> Potongan admin Rp 15.000" << endl;
    }
};

// Rekening Premium
class RekeningPremium : public RekeningBank
{
public:
    RekeningPremium(string nama, double s)
        : RekeningBank(nama, s) {}

    void potongAdmin()
    {
        if (saldo > 100000)
        {
            cout << "Rekening Premium -> Bebas biaya admin." << endl;
        }
        else
        {
            saldo -= 50000;
            cout << "Rekening Premium -> Potongan admin Rp 50.000" << endl;
        }
    }
};

int main()
{
    // Array pointer base class
    RekeningBank *rekening[3];

    rekening[0] = new RekeningSyariah("Ahmad", 50000);
    rekening[1] = new RekeningKonvensional("Budi", 30000);
    rekening[2] = new RekeningPremium("Citra", 80000);

    // Proses akhir bulan
    for (int i = 0; i < 3; i++)
    {
        rekening[i]->potongAdmin();
        rekening[i]->tampilkanSaldo();
    }

    // Hapus memori
    for (int i = 0; i < 3; i++)
    {
        delete rekening[i];
    }

    return 0;
}