#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct playstation {
    char nama[5];
    char ruang[10];
    char harga[20];
    char durasi[10];
};

playstation daftarPS[] = {
    {"PS3", "NON-VIP", "Rp.  5.000", "1 Jam"},
    {"PS3", "VIP",     "Rp.  8.000", "1 Jam"},
    {"PS4", "NON-VIP", "Rp. 10.000", "1 Jam"},
    {"PS4", "VIP",     "Rp. 15.000", "1 Jam"},
    {"PS5", "NON-VIP", "Rp. 15.000", "1 Jam"},
    {"PS5", "VIP",     "Rp. 20.000", "1 Jam"},
};

struct node {
    string nama;
    node *kanan, *kiri;
};

node *awal = NULL, *akhir = NULL, *NB, *bantu, *hapus;

void enqueue(string IB) {
    NB = new node;
    NB->nama = IB;
    NB->kanan = NULL;
    NB->kiri = NULL;
    if (awal == NULL) {
        awal = akhir = NB;
    } else {
        NB->kiri = akhir;
        akhir->kanan = NB;
        akhir = NB;
    }
}

void dequeue() {
    if (awal == NULL) {
        cout << "Antrian kosong!\n";
    } else {
        hapus = awal;
        awal = awal->kanan;
        if (awal) awal->kiri = NULL;
        delete hapus;
    }
}

void bacaqueue() {
    bantu = awal;
    int i = 1;
    while (bantu != NULL) {
        cout << i++ << ". " << bantu->nama << endl;
        bantu = bantu->kanan;
    }
    if (awal == NULL) {
        cout << "Tidak ada pelanggan dalam antrian\n";
    }
}

void listhargaps() {
    cout << "\n==============================================\n";
    cout << "|               ADIT GAMERS                    |\n";
    cout << "================================================\n";
    cout << "| No | Nama PS |  Ruang  |   Harga    | Durasi |\n";
    cout << "================================================\n";
    for (int i = 0; i < 6; i++) {
        printf("| %2d | %-7s | %-7s | %-8s | %-6s |\n", i+1, daftarPS[i].nama, daftarPS[i].ruang, daftarPS[i].harga, daftarPS[i].durasi);
    }
    cout << "==========================================\n\n";
}

void sewaPS() {
    listhargaps();
    int pilihan;
    char nama[50];
    cout << "Masukkan nama penyewa: ";
    cin.ignore();
    cin.getline(nama, 50);
    cout << "Pilih nomor PS yang ingin disewa (1-6): ";
    cin >> pilihan;

    if (pilihan < 1 || pilihan > 6) {
        cout << "Pilihan tidak valid!\n";
        return;
    }

    FILE *file = fopen("sewa.txt", "a");
    if (file == NULL) {
        cout << "Gagal membuka file sewa.txt!\n";
        return;
    }

    playstation ps = daftarPS[pilihan - 1];
    fprintf(file, "Nama: %s, PS: %s, Ruang: %s, Harga: %s, Durasi: %s\n",
            nama, ps.nama, ps.ruang, ps.harga, ps.durasi);
    fclose(file);

    cout << "\nTransaksi Berhasil Disimpan!\n";
    cout << "Nama    : " << nama << endl;
    cout << "PS      : " << ps.nama << endl;
    cout << "Ruang   : " << ps.ruang << endl;
    cout << "Harga   : " << ps.harga << endl;
    cout << "Durasi  : " << ps.durasi << endl << endl;
}

void tambahMember() {
    char nama[50];
    cout << "Masukkan nama member baru: ";
    cin.ignore();
    cin.getline(nama, 50);

    FILE *file = fopen("member.txt", "a");
    if (file == NULL) {
        cout << "Gagal membuka file member.txt!\n";
        return;
    }
    fprintf(file, "%s\n", nama);
    fclose(file);

    cout << "Member berhasil ditambahkan.\n";
}

void tampilkanMember() {
    FILE *file = fopen("member.txt", "r");
    if (file == NULL) {
        cout << "Gagal membuka file member.txt atau belum ada member.\n";
        return;
    }
    char nama[100];
    int i = 1;
    cout << "\nDaftar Member:\n";
    while (fgets(nama, sizeof(nama), file)) {
        nama[strcspn(nama, "\n")] = 0; // hapus newline
        cout << i++ << ". " << nama << endl;
    }
    fclose(file);
    cout << endl;
}

void menuQueue() {
    int pilih;
    string nama;
    do {
        system("cls");
        cout << "Adit Gamers - Waiting List\n";
        cout << "1. Tambah nama ke antrian\n";
        cout << "2. Hapus nama dari antrian\n";
        cout << "3. Tampilkan antrian\n";
        cout << "4. Kembali\n";
        cout << "Pilih: ";
        cin >> pilih;
        switch (pilih) {
            case 1:
                cout << "Masukkan nama pelanggan: ";
                cin >> nama;
                enqueue(nama);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                bacaqueue();
                system("pause");
                break;
            case 4:
                return;
        }
    } while (true);
}

int main() {
    int choice;
    do {
        system("cls");
        cout << "=============================\n";
        cout << "|         ADIT GAMERS       |\n";
        cout << "=============================\n";
        cout << "| 1. List Harga             |\n";
        cout << "| 2. Sewa PS                |\n";
        cout << "| 3. List Member            |\n";
        cout << "| 4. Daftar Member          |\n";
        cout << "| 5. Waiting List           |\n";
        cout << "| 6. Exit                   |\n";
        cout << "=============================\n";
        cout << "Pilih Menu: ";
        cin >> choice;
        switch (choice) {
            case 1:
                listhargaps();
                system("pause");
                break;
            case 2:
                sewaPS();
                system("pause");
                break;
            case 3:
                tampilkanMember();
                system("pause");
                break;
            case 4:
                tambahMember();
                system("pause");
                break;
            case 5:
                menuQueue();
                break;
        }
    } while (choice != 6);

    return 0;
}
