#include <iostream>
#include "BudgetMainApp.h"


#include "UserManager.h"

using namespace std;

int main()
{
    BudgetMainApp budgetMainApp("users.xml");

    budgetMainApp.registerUser();
    //userManager.registerUser();
    //userManager.displayAllUsers();
    budgetMainApp.loginUser();
    //userManager.displayLoggedUserId();
    budgetMainApp.changeUserPassword();

    char choice;

   /* while (true)
    {
        if (!budgetMainApp.isUserLoggedIn())
        {
            choice = Utils::getCharacter();

            switch (wybor)
            {
            case '1':
                //ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                //ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                //ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
                //ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                //ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                //ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
               // ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
                //ksiazkaAdresowa.edytujAdresata();
                break;
            case '7':
               // ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
               // ksiazkaAdresowa.wylogujUzytkownika();
                break;
            }
        }
    }
    return 0;
}*/

    return 0;
}
