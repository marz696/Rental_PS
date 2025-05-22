#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct node
{
    string info;
    node *kanan, *kiri;
};

node *awal, *akhir, *bantu, *hapus, *NB, *depan, *list;

void buatqueuebaru()
{
    list = new node;
    list = NULL;
    awal = list;
    akhir = list;
}

int queuekosong()
{
    if (awal == NULL)
        return (true);
    else
        return (false);
}

void enqueue(string IB)
{
    NB = new node;
    NB->info = IB;
    NB->kanan = NULL;
    NB->kiri = NULL;
    if (queuekosong())
    {
        awal = NB;
        akhir = NB;
    }
    else
    {
        bantu = akhir;
        NB->kanan = bantu->kanan;
        NB->kiri = bantu;
        bantu->kanan = NB;
        akhir = NB;
    }
}

void dequeue()
{
    if (queuekosong())
    {
        cout << "List masih kosong";
    }
    else if (awal == akhir)
    {
        // Hapus jika hanya ada satu node
        free(awal);
        awal = akhir = NULL;
        cout << "list sudah kosong";
    }
    else
    {
        hapus = awal; // Hapus di awal
        awal = hapus->kanan;
        if (awal != NULL)
            awal->kiri = NULL;
        free(hapus);
    }
}

void bacaqueue()
{
    int i = 0;
    bantu = awal;
    while (bantu != NULL)
    {
        cout << i + 1 << ". " << bantu->info;
        cout << endl;
        bantu = bantu->kanan;
        i++;
    }
    if (bantu == NULL)
    {
        cout << "Antrian sudah kosong" << endl;
    }
}

void daftarMember() {
    system("cls");
    string nama;
    cout << "masukkan nama member: ";
    cin.ignore(); 
    getline(cin, nama);

    Member *baru = new Member;
    baru->nama = nama;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Member *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }

    // Simpan ke file
    ofstream file("member.txt", ios::app);
    if (file.is_open()) {
        file << nama << endl;
        file.close();
    } else {
        cout << "Gagal membuka file!" << endl;
    }

    cout << "Member berhasil didaftarkan.\n";
    system("pause");
    system("cls");
}

void login()
{
    const char *username = "AdminGanteng";
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

void daftar()
{
    string nama;
    cout << "Masukkan Nama Pelanggan: ";
    cin >> nama;
    enqueue(nama);
    system("pause");
    cout << "Nama Pelanggan sudah ditambahkan ke antrian" << endl;
}

void menghapus()
{
    dequeue();
    system("pause");
    cout << "Nama Pelanggan sudah dihapus dari antrian" << endl;
}

void waitinglist()
{
    cout << "Waiting List\n";
    cout << "=============================\n";
    cout << "|         ADIT GAMERS       |\n";
    cout << "=============================\n";
    cout << "| Waiting List:             |\n";
    cout << "=============================\n";
    bacaqueue();
    system("pause");
}

int main()
{
    system("cls");
    login();

    int choice;
    do
    {
        cout << "=============================\n";
        cout << "|         ADIT GAMERS       |\n";
        cout << "=============================\n";
        cout << "| Menu:                     |\n";
        cout << "| 1. List Harga             |\n"; // bentuk file dan ptb
        cout << "| 2. List Member            |\n"; // bentuk file dan linked list
        cout << "| 3. Daftar Member          |\n"; // bentuk file nah sisipnya mau digmnain bebas bg
        cout << "| 4. Waiting List           |\n"; // bentuk queue
        cout << "| 5. Exit                   |\n";
        cout << "=============================\n";
        cout << "Pilih Menu: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            daftarmember();
            break;
        case 4:
            string nama;
            int pilih;
            do
            {
                system("cls");
                cout << "Adit Gamers" << endl;
                cout << "==========================================" << endl;
                cout << "1. Tambah nama pelanggan ke antrian" << endl;
                cout << "2. Hapus nama pelanggan dari antrian" << endl;
                cout << "3. Tampilkan nama pelanggan dalam antrian" << endl;
                cout << "4. Kembali" << endl;
                cout << "===========================================" << endl;
                cout << "Pilih menu : ";
                cin >> pilih;
                int jumlah;
                switch (pilih)
                {
                case 1:
                    daftar();
                    break;
                case 2:
                    menghapus();
                    break;
                case 3:
                    waitinglist();
                    system("pause");
                    break;
                case 4:
                    return 0;
                    break;
                default:
                    system("cls");
                    cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                    break;
                }
            } while (true);
        }

    } while (choice != 5);
    {
        return 0;
    }
}
