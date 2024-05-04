#pragma once
#include "Object.h"
#include <iostream>
using namespace std;
class Vector {
public:
	friend	ostream& operator<<(ostream& out, const Vector& v) {
		if (v.size == 0) {
			cout << endl << "Вектор пустой" << endl;
		}
		else {
			object** ptr = v.beg;
			for (int i = 0; i < v.cur; i++) {
				(*ptr)->output();
				ptr++;
			}
		}
		return out;
	}
	Vector() {
		beg = 0;
		size = 0;
		cur = 0;
	};
	Vector(int lin) {
		beg = new object * [lin];
		beg = new object* [lin];
		cur = 0;
		size = lin;
	}
	~Vector() {};
	void Add(object* ptr) {
		if (cur < size) {
			beg[cur] = ptr;
			cur++;
		}
	};
private:
	object** beg;
	int size;
	int cur;
};