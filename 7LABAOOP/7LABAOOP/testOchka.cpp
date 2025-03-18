#include "SSDeshnik.h"
#include "Data.h"
#include <iostream>

using namespace std;

//перегрузка <<
ostream& operator<< (ostream& cout, const SSDeshnik& other) {
	//вывод объектов класса с помощью стандар вывода
	cout << other.get_zena();


	return cout;
};




int main() {
	SSDeshnik a("Silicon", 996, 7599);
	SSDeshnik b("WD", 996, 7899);
	SSDeshnikM2 d("WD", 998, 10000, "NVME");//
	Hardi c("WD", 1980, 6970);
	Student student;
	a.print_inf();
	b.print_inf();
	a.print_Hardi(c);
	d.print_inf(); //
	student.Shum(&d);
	Portable key("MSI", 996, 11000, 14.6, "usb - c");
	key.print_inf();
	key.Fleshka::Shum();
	system("pause");
	return 0;
}


