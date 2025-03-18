#define _CRT_SECURE_NO_WARNINGS
#include "SSDeshnik.h"
#include <iostream>

using namespace std;

int SSDeshnik::kolvo = 0; //инициализация статической переменной 

SSDeshnik::SSDeshnik(const char* ekzemplyar) {
    this->ekzemplyar = new char[strlen(ekzemplyar) + 1];
    strcpy(this->ekzemplyar, ekzemplyar);
    kolvo++;
}

SSDeshnik::SSDeshnik(const char* ekzemplyar, double pamyat) : SSDeshnik(ekzemplyar) { //делегирущий конструктор
    this->pamyat = pamyat;
}

SSDeshnik::SSDeshnik(const char* ekzemplyar, double pamyat, int zena) : SSDeshnik(ekzemplyar, pamyat) { //делегирущий конструктор
    this->zena = zena;
}
SSDeshnikM2::SSDeshnikM2(const char* ekzemplyar, double pamyat, int zena, const char* sposobredakzii) : SSDeshnik(ekzemplyar, pamyat, zena) { //делегирущий конструктор
    this->sposobredakzii = new char [strlen(sposobredakzii)+1];
    strcpy(this->sposobredakzii, sposobredakzii);
}
Portable::Portable(const char* ekzemplyar, double pamyat, int zena, double razmer, const char*cabel) : SSDeshnik(ekzemplyar, pamyat, zena) { //делегирущий конструктор
    this->razmer = razmer;
    this->cabel = new char[strlen(cabel) + 1];
    strcpy(this->cabel, cabel);
}
SSDeshnik::SSDeshnik(double pamyat, int zena) : pamyat(pamyat), zena(zena) {
    kolvo++;
}

SSDeshnik::SSDeshnik() : ekzemplyar(nullptr), pamyat(0.0), zena(0) {
    kolvo++;
}

SSDeshnik::~SSDeshnik() {
    delete[] ekzemplyar;
}

void SSDeshnik::set_ekzemplyar(const char* ekzemplyar) {
    delete[] this->ekzemplyar; // чтобы избежать утечки памяти при повторных вызовах
    this->ekzemplyar = new char[strlen(ekzemplyar) + 1];
    strcpy(this->ekzemplyar, ekzemplyar);
}

void SSDeshnik::set_pamyat(double pamyat) {
    this->pamyat = pamyat;
}

void SSDeshnik::set_zena(int zena) {
    this->zena = zena;
}

double SSDeshnik::get_pamyat() const {
    return pamyat;
}

int SSDeshnik::get_zena() const {
    return zena;
}

int SSDeshnik::get_kolvo() {
    return kolvo;
}

void SSDeshnik::print_inf() {
    cout << "ekzemplyar: " << ekzemplyar << endl;
    cout << "pamyat: " << pamyat << endl;
    cout << "zena: " << zena << endl;
}
void SSDeshnikM2::print_inf() {
    cout << "ekzemplyar: " << ekzemplyar << endl;
    cout << "pamyat: " << pamyat << endl;
    cout << "zena: " << zena << endl;
    cout << "sposobredakzii: " << sposobredakzii << endl;
}
void SSDeshnik::print_Hardi(const Hardi& hardi) {
    cout << "Hardi ekzemplyar: " << hardi.get_ekzemplyar() << endl;
    cout << "Hardi pamyat: " << hardi.get_pamyat() << endl;
    cout << "Hardi zena: " << hardi.get_zena() << endl;
}
void Portable::print_inf() {
    cout << "ekzemplyar: " << ekzemplyar << endl;
    cout << "pamyat: " << pamyat << endl;
    cout << "zena: " << zena << endl;
    cout << "razmer: " << razmer << endl;
    cout << "cabel: " << cabel << endl;
}
//перегрузка =, устан знач одного объекта равными знач другого
SSDeshnik& SSDeshnik::operator= (const SSDeshnik& other) {
    pamyat = other.pamyat; //копируются из объекта other в текущий объект
    zena = other.zena;
    //сначала освобождается текущ память под экзем
    delete[] ekzemplyar; //нельзя просто копировать указ, иначе будет два указ на одну область
    ekzemplyar = new char[strlen(other.ekzemplyar) + 1]; //создание нового массива символов в дин памяти, размер это длина строки other
    //+1 для 0 символа в виде конца строки
    strcpy(ekzemplyar, other.ekzemplyar); //strcpy копир содержимое строки other в экзм

    return *this; //возвращение ссылки на текущий объект
}

//перегрузка ==, тру, если поля обоих равны
bool SSDeshnik::operator== (const SSDeshnik& other) {
    return pamyat == other.pamyat && zena == other.zena && strcmp(ekzemplyar, other.ekzemplyar) == 0;

}

//перегрузка !=, делает обратное
bool SSDeshnik::operator!= (const SSDeshnik& other) {
    return !(pamyat == other.pamyat && zena == other.zena && strcmp(ekzemplyar, other.ekzemplyar) == 0);

}

