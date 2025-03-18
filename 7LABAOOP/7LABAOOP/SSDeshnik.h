#pragma once
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef SSDeshnik_H
#define SSDeshnik_H
#include <cstring>
#include <iostream>
using namespace std;

enum Zapolnen { //��������� ������������
    nikak,
    slabo,
    sredne,
    silno
};
class Hranilishe { //���������� �����
public:
    virtual void Shum() = 0; //����� ����������� �������
};
class Hardi {
private:
    char* ekzemplyar;
    double pamyat;
    int zena;
public: 
    Hardi(const char* ekzemplyar, double pamyat, int zena) {
        this->ekzemplyar = new char[strlen(ekzemplyar) + 1];
        strcpy(this->ekzemplyar, ekzemplyar);
        this->pamyat = pamyat;
        this->zena = zena;
    }
    ~Hardi() {
        delete[] ekzemplyar;
    }
    char* get_ekzemplyar() const {
        return ekzemplyar;
    };
    double get_pamyat() const {
        return pamyat;
    };
    int get_zena() const {
        return zena;
    };
};

class SSDeshnik : public Hranilishe {
public:
    char* ekzemplyar;
    double pamyat;
    int zena;
    int skorostzap;
    static int kolvo;
    Zapolnen kak;
    Hardi* hard; // ��������� ���� ��� ������ �� ������� Hardi
public:
    // ������������
    SSDeshnik(const char* ekzemplyar); // ����������� � ����� ����������
    SSDeshnik(const char* ekzemplyar, double pamyat); // ����������� � ����� �����������, ����������� �����������
    SSDeshnik(const char* ekzemplyar, double pamyat, int zena); // ����������� � ����� �����������, ����������� �����������
    SSDeshnik(double pamyat, int zena); // ����������� � ����� �����������
    SSDeshnik(double pamyat, int zena, int skorostzap); //������ � ����� �����������, ��������
    SSDeshnik(const char* ekzemplyar, double pamyat, int zena, int skorostzap); // ����������� � ����� �����������, ����������� �����������
    SSDeshnik(); // ����������� �� ���������
    ~SSDeshnik(); // ����������

    // �������, ������������ ��������
    void set_ekzemplyar(const char* ekzemplyar);
    void set_pamyat(double pamyat);
    void set_zena(int zena);
    void set_skorostzap(int skorostzap);
    void set_hardi(Hardi* hard) {
        this->hard = hard;
    }

    // �������, ��������� ��������, ���������� ��� ����� ������
    double get_pamyat() const;
    int get_zena() const;
    static int get_kolvo();
    int get_skorostzap() const;
    Hardi* get_hardi() const {
        return hard;
    }

    // ������ ������
    virtual void print_inf();
    void print_Hardi(const Hardi& hardi);

    //���������� =
    SSDeshnik& operator= (const SSDeshnik& other);
    //���������� == 
    bool operator== (const SSDeshnik& other);



    //���������� !=
    bool operator!= (const SSDeshnik& other);
    void Shum() override {
        cout << "SH SH SH" << endl;
    };
};
class SSDeshnikM2 : public SSDeshnik {
public:
    char* sposobredakzii;
    SSDeshnikM2(const char* ekzemplyar, double pamyat, int zena, const char* sposobredakzii);
       
    void print_inf();
    void Shum() override {
        cout << "SH SH" << endl;
    }
};
class Student {
public:
    void Shum(Hranilishe* hranilishe) {
        hranilishe->Shum();
    }
};
class Fleshka : public Hranilishe {
public:
    double razmer;
    char* cabel;
    void Shum() override {
        cout << "SH SH SH SH" << endl;
    }
};
class Portable : public SSDeshnik, public Fleshka {
public:
    Portable(const char* ekzemplyar, double pamyat, int zena, double razmer, const char* cabel);
    void print_inf();
    void Shum() override {
        cout << "SH SH SH SH SH" << endl;
    }
};
#endif
