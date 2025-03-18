#pragma once
#ifndef DATA_H
#define DATA_H

#include "SSDeshnik.h"

class Data {
private:
	SSDeshnik** base;
	int size;

public:
	Data();
	~Data();

public:
	void add(SSDeshnik* SSDeshnik);
	void remove(SSDeshnik* SSDeshnik);
	void sorted_zena(bool flag = false);
	void search_by_pamyat(double pamyat) const;
	void print_base() const;


};



#endif

