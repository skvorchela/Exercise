#define _CRT_SECURE_NO_WARNINGS
#include "Data.h"
#include <iostream>

using namespace std;

Data::Data() :base(nullptr), size(0) {}; //конструктор по умолчанию

Data::~Data() { //деструктор
	delete[] base;
	base = nullptr;
}

void Data::add(SSDeshnik * sSDeshnik) {
	size++;
	SSDeshnik** new_base = new SSDeshnik * [size]; //для копирования прошлой базы
	for (int i = 0; i < size - 1; i++) {
		new_base[i] = base[i];
	}
	new_base[size - 1] = sSDeshnik;

	delete[] base; //освобождение памяти прошлой базы

	base = new_base;
}

void Data::remove(SSDeshnik* SSDeshnik) {
	for (int i = 0; i < size; i++) {  //поиск элемента
		if (base[i] == SSDeshnik) {
			for (int j = i; j < size - 1; j++) { // перезаписывание элементов
				base[j] = base[j + 1];
			}
			size--;
			break;
		}
	}
}

void Data::sorted_zena(bool flag) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			bool sravnit = false;
			if (flag) {
				sravnit = base[j]->get_zena() < base[j + 1]->get_zena();
			}
			else {
				sravnit = base[j]->get_zena() > base[j + 1]->get_zena();
			}
			if (sravnit) {
				SSDeshnik* SSDeshnik = base[j];
				base[j] = base[j + 1];
				base[j + 1] = SSDeshnik;
			}
		}
	}
}

void Data::search_by_pamyat(double pamyat) const {
	for (int i = 0; i < size; i++) {
		if (base[i]->get_pamyat() == pamyat) {
			cout << "SSDeshnik_adress: " << base[i] << endl;
			base[i]->print_inf();
		}
	}

}

void Data::print_base() const {
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ". SSDeshnik_adress: " << base[i] << endl;
		base[i]->print_inf();
	}

}
