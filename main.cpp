#include <iostream>
using namespace std;
#include "filmislemleri.h"
#define MAX_FILM 30
FilmInfo *filmDatabase = new FilmInfo[MAX_FILM];
int iAddedFilm;
void showMainMenu();
void showMenuTypes(int);
int main() {
    cout << "-----------------------------------------" << endl;
    cout << "Film Veritabani Uygulamasina Hosgeldiniz" << endl;
    cout << "-----------------------------------------" << endl;
    showMainMenu();
    delete[] filmDatabase;
    return 0;
}
void showMenuTypes(int iType) {
    switch(iType) {
        case 1:{
            iAddedFilm++;
            cout << "Film  Ekleme" << endl;
            cout << "Filmin Adi:";
            cin.ignore();
            getline(cin,filmDatabase[iAddedFilm].Ad);
            cout << "Filmin Yonetmeni:";
            getline(cin,filmDatabase[iAddedFilm].Yonetmen);
            cout << "Filmin Yapim Yili:";
            cin >> filmDatabase[iAddedFilm].YapimYili;
            cout << "Filmin Turu (0-Aksiyon, 1-Gerilim, 2-Komedi, 3-Dram):";
            cin >> filmDatabase[iAddedFilm].Tur;
            filmDatabase[iAddedFilm].filmID = iAddedFilm;
            showMainMenu();
            break;
        }
        case 2: {
            int iID;
            cout << "Filmlerin Listesi" << endl;
            for(int i = 0; i < MAX_FILM; i++) {
                if(filmDatabase[i].filmID == 0) continue;
                cout << "Filmin ID " << filmDatabase[i].filmID << endl;
                cout << "Filmin Adi: " << filmDatabase[i].Ad << endl;
                cout << "Filmin Yonetmeni: " << filmDatabase[i].Yonetmen << endl;
                cout << "Filmin Yapim Yili: " << filmDatabase[i].YapimYili << endl;
                cout << "Filmin Turu: " << szFilmTypes[filmDatabase[i].Tur] << endl << endl;
            }
            cout << "Yukaridaki listeden silmek istediginiz filmin ID'sini giriniz:";
            cin >> iID;
            for(int i = 0; i < MAX_FILM; i++) {
                if(filmDatabase[i].filmID == iID) {
                    filmDatabase[i].filmID = 0;
                    filmDatabase[i].Ad = "";
                    filmDatabase[i].Yonetmen = "";
                    filmDatabase[i].YapimYili = 0;
                    filmDatabase[i].Tur = 0;
                    cout << "Girdiginiz ID'deki film silindi!";
                    break;
                }
            }
            showMainMenu();
            break;
        }
        case 3: {
            cout << "Filmlerin Listesi" << endl;
            for(int i = 1; i < MAX_FILM; i++) {
                if(filmDatabase[i].filmID == 0) continue;
                cout << "Filmin ID " << filmDatabase[i].filmID << endl;
                cout << "Filmin Adi: " << filmDatabase[i].Ad << endl;
                cout << "Filmin Yonetmeni: " << filmDatabase[i].Yonetmen << endl;
                cout << "Filmin Yapim Yili: " << filmDatabase[i].YapimYili << endl;
                cout << "Filmin Turu: " << szFilmTypes[filmDatabase[i].Tur] << endl << endl;
            }
            showMainMenu();
            break;
        }
    }
}
void showMainMenu() {
    int iIslem;
    cout << "Ana Menu" << endl;
    cout << "(1) Film Ekle" << endl;
    cout << "(2) Film Cikar" << endl;
    cout << "(3) Tum Filmleri Listele" << endl;
    cout << "(0) Kapat" << endl;
    cout << "Yapmak istediginiz islemi giriniz:";
    cin >> iIslem;
    showMenuTypes(iIslem);
}