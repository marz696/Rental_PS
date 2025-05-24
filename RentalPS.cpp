#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
using namespace std;

struct Member
{
    char nama[50];
    char noTelp[20];
    int transaksi;
    Member *next;
};

Member *head = NULL;

void login()
{
    const char *username = "AkbarKece";
    const char *password = "123456";
    char input_username[20];
    char input_password[20];

    while (true)
    {
        cout << "================================\n";
        cout << "|            LOGIN             |\n";
        cout << "================================\n";
        cout << "Username: ";
        cin >> input_username;
        cout << "Password: ";
        cin >> input_password;
        if (strcmp(input_username, username) == 0 && strcmp(input_password, password) == 0)
        {
            cout << " >> Berhasil Login\n";
            system("pause");
            system("cls");
            break;
        }
        else
        {
            cout << "Username atau Password salah!\n";
            system("pause");
            system("cls");
        }
    }
}

struct PlayStation
{
    const char *nama;
    int harga;
    const char *durasi;
    const char *kelas;
};

struct Makanan
{
    const char *nama;
    int harga;
};

PlayStation reguler[] = {
    {"PS3", 5000, "1 Jam", "Reguler"},
    {"PS3", 13000, "3 Jam", "Reguler"},
    {"PS3", 20000, "5 Jam", "Reguler"},
    {"PS4", 10000, "1 Jam", "Reguler"},
    {"PS4", 27000, "3 Jam", "Reguler"},
    {"PS4", 45000, "5 Jam", "Reguler"},
};

PlayStation vip[] = {
    {"PS4", 15000, "1 Jam", "VIP"},
    {"PS4", 42000, "3 Jam", "VIP"},
    {"PS4", 70000, "5 Jam", "VIP"},
    {"PS5", 25000, "1 Jam", "VIP"},
    {"PS5", 70000, "3 Jam", "VIP"},
    {"PS5", 115000, "5 Jam", "VIP"},
};

Makanan snack[] = {
    {"Indomie (Goreng/Rebus)", 7000},
    {"Indomie + Telur", 10000},
    {"French Fries", 10000},
    {"Sosis", 10000},
    {"Nugget", 10000},
    {"Mix Platter", 17000},
    {"Teh", 3000},
    {"Jeruk", 3000},
    {"Mineral", 4000},
    {"Kopi Hitam", 3000},
    {"Good Day", 4000},
    {"Milo", 4000},
};

void muatMemberDariFile() 
{
    FILE *file = fopen("member.txt", "r");
    if (file == NULL)
    {
        return;
    }

    char baris[100];
    Member *tail = NULL;

    while (fgets(baris, sizeof(baris), file))
    {
        if (strncmp(baris, "Nama: ", 6) == 0)
        {
            Member *baru = new Member;
            strcpy(baru->nama, baris + 6);
            baru->nama[strcspn(baru->nama, "\n")] = 0;

            fgets(baris, sizeof(baris), file);
            strcpy(baru->noTelp, baris + 8);
            baru->noTelp[strcspn(baru->noTelp, "\n")] = 0;

            fgets(baris, sizeof(baris), file);
            sscanf(baris, "Transaksi: %d", &baru->transaksi);

            baru->next = NULL;

            if (head == NULL)
            {
                head = baru;
                tail = baru;
            }
            else
            {
                tail->next = baru;
                tail = baru;
            }

            fgets(baris, sizeof(baris), file); // skip -----
        }
    }

    fclose(file);
}

void listHarga()
{
    system("cls");
    int kategori;
    while (true)
    {
        cout << "=============================" << endl;
        cout << "|       ADA PLAYSTATION     |\n";
        cout << "=============================" << endl;
        cout << "| 1. Regular                |" << endl;
        cout << "| 2. VIP                    |" << endl;
        cout << "| 3. Kembali                |" << endl;
        cout << "=============================" << endl;
        cout << "Pilih Menu: ";
        cin >> kategori;

        if (kategori == 3)
        {
            system("cls");
            return;
        }
        if (kategori < 1 || kategori > 3)
        {
            cout << "Pilihan tidak valid! Silakan pilih 1, 2, atau 3" << endl;
            system("pause");
            system("cls");
            continue;
        }
        system("cls");

        PlayStation *daftar = (kategori == 1) ? reguler : vip;
        const char *kelas = (kategori == 1) ? "Reguler" : "VIP";

        const char *pilihSnackNama[12];
        int pilihSnackHarga[12];
        int snackCount = 0;

        int pilihanPS = 0;
        int total = 0;

        cout << "=====================================================" << endl;
        cout << "|                    " << setw(13) << left << kelas << "                  |" << endl;
        cout << "=====================================================" << endl;
        cout << "| No | PlayStation |   Harga   |  Durasi            |" << endl;
        cout << "-----------------------------------------------------" << endl;
        for (int i = 0; i < 6; i++)
        {
            cout << "| " << setw(2) << i + 1 << " | "
                 << setw(12) << daftar[i].nama << "| "
                 << setw(10) << daftar[i].harga << "| "
                 << setw(19) << daftar[i].durasi << "|" << endl;
        }
        cout << "=====================================================" << endl;
        cout << endl;

        cout << "=====================================================" << endl;
        cout << "|                 SNACK AND MINUMAN                 |\n";
        cout << "=====================================================" << endl;
        cout << "| No | Nama                       |     Harga       |" << endl;
        cout << "-----------------------------------------------------" << endl;
        for (int i = 0; i < 12; i++)
        {
            cout << "| " << setw(2) << i + 1 << " | "
                 << setw(27) << snack[i].nama << "| "
                 << setw(16) << snack[i].harga << "|" << endl;
        }
        cout << "=====================================================" << endl;

         // INPUT PESANAN
        do
        {
            cout << "Pilih PlayStation (1-6): ";
            cin >> pilihanPS;
            if (pilihanPS < 1 || pilihanPS > 6)
                cout << "Pilihan PlayStation tidak valid! Coba lagi." << endl;
        } while (pilihanPS < 1 || pilihanPS > 6);
        cout << "-> " << daftar[pilihanPS - 1].nama << " " << daftar[pilihanPS - 1].durasi << endl;
        total += daftar[pilihanPS - 1].harga;
        
        int pilihanSnack;
        do
        {
            cout << "Pilih Snack (1-12, 0 untuk selesai): ";
            cin >> pilihanSnack;
            if (pilihanSnack == 0)
                break;
            if (pilihanSnack < 1 || pilihanSnack > 12)
            {
                cout << "Pilihan Snack tidak valid! Coba lagi." << endl;
            }
            else
            {
                // simpan nama dan harga snack terpilih
                pilihSnackNama[snackCount] = snack[pilihanSnack - 1].nama;
                pilihSnackHarga[snackCount] = snack[pilihanSnack - 1].harga;
                snackCount++;
                total += snack[pilihanSnack - 1].harga;

                cout << "-> " << snack[pilihanSnack - 1].nama << endl;
            }
        } while (true);

        int beforediskon = total;
        int diskon = 0;

        // Cek member dengan searching
        char namaPelanggan[50];
        cout << "\nMasukkan Nama Pelanggan: ";
        cin.ignore();
        cin.getline(namaPelanggan, 50);

        // Cetak rincian transaksi 
        system("pause");
        system("cls");
        cout << "\n======= Rincian Transaksi =======" << endl;
        cout << "Nama Pelanggan: " << namaPelanggan << endl;
        cout << "PlayStation: " << daftar[pilihanPS - 1].nama
             << " (" << daftar[pilihanPS - 1].durasi << ") - "
             << daftar[pilihanPS - 1].harga << endl;

        if (snackCount > 0)
        {
            cout << "Snack:\n";
            for (int i = 0; i < snackCount; i++)
            {
                cout << "-> " << pilihSnackNama[i]
                     << " - " << pilihSnackHarga[i] << endl;
            }
        }
        if (diskon > 0)
        {
            cout << "Total               : " << beforediskon << endl;
            cout << "Potongan Diskon(10%): " << diskon << endl;
        }
        cout << "Total Bayar         : " << total << endl;
        cout << "================================" << endl;

        system("pause");
        system("cls");
    }
}

void tambahMember() // fungsi untuk menambahkan member yang akan dimasukan file 
{
    Member *baru = new Member;

    cout << "Masukkan Nama: ";
    cin.ignore();
    cin.getline(baru->nama, 50);

    cout << "Masukkan No. Telp: ";
    cin.getline(baru->noTelp, 20);

    baru->transaksi = 0;
    baru->next = NULL;

    if (head == NULL)
    {
        head = baru;
    }
    else
    {
        Member *bantu = head;
        while (bantu->next != NULL)
        {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
    FILE *file = fopen("member.txt", "a");
    if (file != NULL)
    {
        fprintf(file, "Nama: %s\n", baru->nama);
        fprintf(file, "NoTelp: %s\n", baru->noTelp);
        fprintf(file, "Transaksi: %d\n", baru->transaksi);
        fprintf(file, "-----\n");
        fclose(file);
    }

    cout << "Member berhasil ditambahkan.\n";
}

void tampilkanMember() // fungsi untuk menampilkan member yang akan tersorting oleh fungsi sortMembers()
{
    system("cls");
    cout << "=============================" << endl;
    cout << "|         LIST MEMBER       |\n";
    cout << "=============================" << endl;
    if (head == NULL)
    {
        cout << "Belum ada data member\n";
        return;
    }

    Member *bantu = head;
    int no = 1;

    while (bantu != NULL)
    {
        cout << no++ << ". Nama     : " << bantu->nama << endl;
        cout << "   No Telp  : " << bantu->noTelp << endl;
        cout << "   Transaksi: " << bantu->transaksi << endl
             << endl;
        bantu = bantu->next;
    }
}


int main() // fungsi utama
{
    system("cls");
    login();
    int choice;
    do
    {
        cout << "=============================\n";
        cout << "|       ADA PLAYSTATION     |\n";
        cout << "=============================\n";
        cout << "| Menu:                     |\n";
        cout << "| 1. List Harga             |\n"; // STRUCT AND SEARCHING SIMPAN FILE
        cout << "| 2. List Member            |\n"; // POINTER SORTING FILE 
        cout << "| 3. Daftar Member          |\n"; // POINTER FILE LINKED LIST DAN SISIP 
        cout << "| 4. Exit                   |\n";
        cout << "=============================\n";
        cout << "Pilih Menu: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            listHarga();
            break;
        case 2:
            tampilkanMember();
            system("pause");
            system("cls");
            break;
        case 3:
            tambahMember();
            system("pause");
            system("cls");
            break;
        case 4:
            cout << "Exit Program\n";
            break;

        default:
            cout << "Pilihan tidak valid\n";
            system("pause");
            system("cls");
        }

    } while (choice != 4);
    {
        return 0;
    }
}
