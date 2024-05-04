#include <iostream>
#include <string>
#include "Person.h"
#include "Vector.h"

using namespace std;

int main() {
	system("chcp 1251");
	Vector vec(4);
	Person per;
	Student stud;
	cin >> per;
	cout << per;
	cin >> stud;
	cout << stud;
	object* p = &per;
	vec.Add(p);
	p = &stud;
	vec.Add(p);
	cout << vec;

}