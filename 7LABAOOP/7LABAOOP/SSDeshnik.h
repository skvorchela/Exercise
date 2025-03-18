#pragma once
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef SSDeshnik_H
#define SSDeshnik_H
#include <cstring>
#include <iostream>
using namespace std;

enum Zapolnen { //вложенное перечисление
    nikak,
    slabo,
    sredne,
    silno
};
class Hranilishe { //абстрактый класс
public:
    virtual void Shum() = 0; //чисто виртуальная функция
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
    Hardi* hard; // Добавлено поле для ссылки на объекты Hardi
public:
    // Конструкторы
    SSDeshnik(const char* ekzemplyar); // Конструктор с одним параметром
    SSDeshnik(const char* ekzemplyar, double pamyat); // Конструктор с двумя параметрами, делегирущий конструктор
    SSDeshnik(const char* ekzemplyar, double pamyat, int zena); // Конструктор с тремя параметрами, делегирущий конструктор
    SSDeshnik(double pamyat, int zena); // Конструктор с двумя параметрами
    SSDeshnik(double pamyat, int zena, int skorostzap); //констр с тремя параметрами, скорость
    SSDeshnik(const char* ekzemplyar, double pamyat, int zena, int skorostzap); // Конструктор с тремя параметрами, делегирущий конструктор
    SSDeshnik(); // Конструктор по умолчанию
    ~SSDeshnik(); // Деструктор

    // Сеттеры, установление значения
    void set_ekzemplyar(const char* ekzemplyar);
    void set_pamyat(double pamyat);
    void set_zena(int zena);
    void set_skorostzap(int skorostzap);
    void set_hardi(Hardi* hard) {
        this->hard = hard;
    }

    // Геттеры, получение значения, возвращает тип устан данных
    double get_pamyat() const;
    int get_zena() const;
    static int get_kolvo();
    int get_skorostzap() const;
    Hardi* get_hardi() const {
        return hard;
    }

    // Другие методы
    virtual void print_inf();
    void print_Hardi(const Hardi& hardi);

    //перегрузка =
    SSDeshnik& operator= (const SSDeshnik& other);
    //перегрузка == 
    bool operator== (const SSDeshnik& other);



    //перегрузка !=
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
