#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

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
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            cout << "Exit Program\n";
            break;

        default:
            cout << "Pilihan tidak valid\n";
            system("pause");
            system("cls");
        }

    } while (choice != 5);
    {
        return 0;
    }
}
