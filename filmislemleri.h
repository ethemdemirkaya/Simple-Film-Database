//
// Created by Ethem on 5.04.2024.
//

#ifndef FILMDATABASE_FILMISLEMLERI_H
#define FILMDATABASE_FILMISLEMLERI_H
enum FilmTypes {
    DRAM,
    KOMEDI,
    AKSIYON,
    GERILIM,
    TYPE_COUNT
};
const string szFilmTypes[TYPE_COUNT] {
    "Dram",
    "Komedi",
    "Aksiyon",
    "Gerilim"
};
struct FilmInfo {
    int filmID {0};
    string Ad;
    string Yonetmen;
    int YapimYili{};
    int Tur {};
};
#endif //FILMDATABASE_FILMISLEMLERI_H

