#pragma once
#include "Object.h"
#include <iostream>

using namespace std;

class Person : public object {
	friend istream& operator>>(istream& in, Person& p) {
		cout << "������� ���: " << endl;
		getline(in, p.name);
		cout << endl << "������� �������: " << endl;
		(in >> p.age).ignore();
		cout << endl << endl;
		return in;
	}
	friend ostream& operator <<(ostream& out, const Person& p) {
		cout << "���: " << p.name;
		cout << endl << "�������: " << p.age;
		cout << endl << endl;
		return out;
	}
protected:
	string name;
	int age;
public:
	~Person() {};
	Person() {
		name = "";
		age = 0;
	}
	Person(int NewAge, string NewName) {
		name = NewName;
		age = NewAge;
	}
	Person(const Person& p) {
		name = p.name;
		age = p.age;
	}
	string getName() {
		return name;
	}
	int getAge() {
		return age;
	}
	void setName(string name) {
		this->name = name;
	}
	void setAge(int age) {
		this->age = age;
	}
	Person& operator = (const Person& p) {
		age = p.age;
		name = p.name;
		return *this;
	}
	void output() override {
		cout << endl << "���: " << name;
		cout << endl << "�������: " << age;
	}
};

class Student : public Person {
	friend istream& operator>>(istream& stream, Student& s) {
		cout << "������� ���: " << endl;
		getline(stream, s.name);
		cout << endl << "������� �������: " << endl;
		(stream >> s.age).ignore();
		cout << "�������: " << endl;
		stream >> s.subject;
		cout << "������: " << endl;
		stream >> s.mark;
		return stream;
	}

	friend ostream& operator<<(ostream& stream, const Student* s) {
		cout << "���: " << s->name << endl;
		cout << "�������: " << s->age << endl;
		cout << "�������: " << s->subject << endl;
		if (s->mark <= 5 || s->mark >= 2) {
			stream << "������ : " << s->mark << endl;
			if (s->mark > 5 || s->mark < 2) {
				stream << "������������ ������" << endl;
			}
			if (s->mark == 5) {
				stream << "�������� ������" << endl;
			}
			if (s->mark == 4) {
				stream << "������� ������" << endl;
			}
			if (s->mark < 4) {
				stream << "�����" << endl;
			}
		}
		return stream;
		return stream;
	}
protected:
	string subject;
	int mark;
public:
	~Student() {};
	Student() {
		subject = "";
		mark = 0;
	}
	Student(const Student& s) {
		subject = s.subject;
		mark = s.mark;
	}
	Student(const string& name, const int& age, const string& subject, const int& mark) : Person(age, name) {
		this->setMark(mark);
		this->setSubject(subject);
	};
	Student(const int& age, const string& name, const string& subject, const int& mark) : Student(name, age, subject, mark) {};
	void setMark(const int& mark){
		if (mark <= 0 || mark >= 6) {
			cout << "�������� ������" << endl;
		}
	}
	void setSubject(const string& subject) { this->subject = subject; }
	int getMark() const { return this->mark; };
	string getSubgect() const { return this->subject; };
};


