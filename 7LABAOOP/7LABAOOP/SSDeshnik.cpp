#define _CRT_SECURE_NO_WARNINGS
#include "SSDeshnik.h"
#include <iostream>

using namespace std;

int SSDeshnik::kolvo = 0; //������������� ����������� ���������� 

SSDeshnik::SSDeshnik(const char* ekzemplyar) {
    this->ekzemplyar = new char[strlen(ekzemplyar) + 1];
    strcpy(this->ekzemplyar, ekzemplyar);
    kolvo++;
}

SSDeshnik::SSDeshnik(const char* ekzemplyar, double pamyat) : SSDeshnik(ekzemplyar) { //����������� �����������
    this->pamyat = pamyat;
}

SSDeshnik::SSDeshnik(const char* ekzemplyar, double pamyat, int zena) : SSDeshnik(ekzemplyar, pamyat) { //����������� �����������
    this->zena = zena;
}
SSDeshnikM2::SSDeshnikM2(const char* ekzemplyar, double pamyat, int zena, const char* sposobredakzii) : SSDeshnik(ekzemplyar, pamyat, zena) { //����������� �����������
    this->sposobredakzii = new char [strlen(sposobredakzii)+1];
    strcpy(this->sposobredakzii, sposobredakzii);
}
Portable::Portable(const char* ekzemplyar, double pamyat, int zena, double razmer, const char*cabel) : SSDeshnik(ekzemplyar, pamyat, zena) { //����������� �����������
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
    delete[] this->ekzemplyar; // ����� �������� ������ ������ ��� ��������� �������
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
//���������� =, ����� ���� ������ ������� ������� ���� �������
SSDeshnik& SSDeshnik::operator= (const SSDeshnik& other) {
    pamyat = other.pamyat; //���������� �� ������� other � ������� ������
    zena = other.zena;
    //������� ������������� ����� ������ ��� �����
    delete[] ekzemplyar; //������ ������ ���������� ����, ����� ����� ��� ���� �� ���� �������
    ekzemplyar = new char[strlen(other.ekzemplyar) + 1]; //�������� ������ ������� �������� � ��� ������, ������ ��� ����� ������ other
    //+1 ��� 0 ������� � ���� ����� ������
    strcpy(ekzemplyar, other.ekzemplyar); //strcpy ����� ���������� ������ other � ����

    return *this; //����������� ������ �� ������� ������
}

//���������� ==, ���, ���� ���� ����� �����
bool SSDeshnik::operator== (const SSDeshnik& other) {
    return pamyat == other.pamyat && zena == other.zena && strcmp(ekzemplyar, other.ekzemplyar) == 0;

}

//���������� !=, ������ ��������
bool SSDeshnik::operator!= (const SSDeshnik& other) {
    return !(pamyat == other.pamyat && zena == other.zena && strcmp(ekzemplyar, other.ekzemplyar) == 0);

}

