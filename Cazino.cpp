#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void drawLine(int n, char symbol);
void rules();

int main()
{
    string playerName;
    int amount;
    int bettingAmount;
    int guess;
    int dice;
    char choice;

    srand(time(0));

    drawLine(60,'_');
    cout << "\n\n\n\t\tCAZINO \n\n\n\n";
    drawLine(60,'_');

    cout << "\n\nIntrodu numele : ";
    getline(cin, playerName);

    cout << "\n\nIntrodu depositu pentru pariat in lei :";
    cin >> amount;

    do
    {
        system("cls");
        rules();
        cout << "\n\nSoldul dumneavoastra  " << amount << " lei\n";


        do
        {
            cout <<playerName<<", introdu suma pe care doresti sa o pariezi : ";
            cin >> bettingAmount;
            if(bettingAmount > amount)
                cout << "Nu ai bani suficienti pentru a paria atat\n"
                       <<"\n Reintrodu suma \n ";
        }while(bettingAmount > amount);


        do
        {
            cout << "Alege un numar de la 1 la 10:";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "Numarul introdus nu se afla in intervalul 1-10\n"
                    <<"\nIntrodu alt numar \n ";
        }while(guess <= 0 || guess > 10);

        dice = rand()%10 + 1;

        if(dice == guess)
        {
            cout << "\n\nFelicitari!! Ai castigat." << bettingAmount * 10<<"lei!\n";
            amount = amount + bettingAmount * 10;
        }
        else
        {
            cout << "Necastigator !! Ai pierdut "<< bettingAmount <<"lei!\n";
            amount = amount - bettingAmount;
        }

        cout << "\nNumarul castigator a fost : " << dice <<"\n";
        cout << "\n"<<playerName<<", ai in cont " << amount << " lei\n";
        if(amount == 0)
        {
            cout << "Nu mai ai bani in cont ";
            break;
        }
        cout << "\n\n-->Vrei sa mai incerci odata ?(y/n)? ";
        cin >> choice;
    }while(choice =='Y'|| choice=='y');

    cout << "\n\n\n";
    drawLine(70,'=');
    cout << "\n\nMultumim ca ai jucat jocul. Soldul tau este de   " << amount << "lei\n\n";
    drawLine(70,'=');

    return 0;
}

void drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
        cout << symbol;
    cout << "\n" ;
}

void rules()
{
    system("cls");
    cout << "\n\n";
    drawLine(80,'-');
    cout << "\t\tREGURILE JOCULUI\n";
    drawLine(80,'-');
    cout << "\t1. Alege un numar de la 1 la 10\n";
    cout << "\t2. Daca castigi primesti de 10 ori cat ai pariat\n";
    cout << "\t3. Daca nu ghicesti corect pierzi suma pariata\n\n";
    drawLine(80,'-');
}

