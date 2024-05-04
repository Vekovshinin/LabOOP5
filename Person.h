#pragma once
#include "Object.h"
#include <iostream>

using namespace std;

class Person : public object {
	friend istream& operator>>(istream& in, Person& p) {
		cout << "Введите имя: " << endl;
		getline(in, p.name);
		cout << endl << "Введите возраст: " << endl;
		(in >> p.age).ignore();
		cout << endl << endl;
		return in;
	}
	friend ostream& operator <<(ostream& out, const Person& p) {
		cout << "Имя: " << p.name;
		cout << endl << "Возраст: " << p.age;
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
		cout << endl << "Имя: " << name;
		cout << endl << "Возраст: " << age;
	}
};

class Student : public Person {
	friend istream& operator>>(istream& stream, Student& s) {
		cout << "Введите имя: " << endl;
		getline(stream, s.name);
		cout << endl << "Введите возраст: " << endl;
		(stream >> s.age).ignore();
		cout << "Предмет: " << endl;
		stream >> s.subject;
		cout << "Оценка: " << endl;
		stream >> s.mark;
		return stream;
	}

	friend ostream& operator<<(ostream& stream, const Student* s) {
		cout << "Имя: " << s->name << endl;
		cout << "Возраст: " << s->age << endl;
		cout << "предмет: " << s->subject << endl;
		if (s->mark <= 5 || s->mark >= 2) {
			stream << "Оценка : " << s->mark << endl;
			if (s->mark > 5 || s->mark < 2) {
				stream << "Неправильная оценка" << endl;
			}
			if (s->mark == 5) {
				stream << "Отличная оценка" << endl;
			}
			if (s->mark == 4) {
				stream << "Хорошая оценка" << endl;
			}
			if (s->mark < 4) {
				stream << "Зачет" << endl;
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
			cout << "неверная оценка" << endl;
		}
	}
	void setSubject(const string& subject) { this->subject = subject; }
	int getMark() const { return this->mark; };
	string getSubgect() const { return this->subject; };
};


