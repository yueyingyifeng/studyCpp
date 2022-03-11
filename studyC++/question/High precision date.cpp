#include<iostream>
using namespace std;

class Date {
	unsigned int day, month, year;


public:
	Date() {
		year = (unsigned)0;
		month = (unsigned)0;
		day = (unsigned)0;
	}
	Date(unsigned int year, unsigned int month, unsigned int day)
		: year(year), month(month), day(day)
	{}

	bool isLeapYear(unsigned int year) {
		if (year % 4 == 0 && year % 100 != 0 && year % 400 == 0) {
			return true;
		}
		return false;
	}

	bool isBigMonth(unsigned int month) {
		switch (month) {
		case 1:
			return true;
		case 2:
			return false;
		case 3:
			return true;
		case 4:
			return false;
		case 5:
			return true;
		case 6:
			return false;
		case 7:
			return true;
		case 8:
			return true;
		case 9:
			return false;
		case 10:
			return true;
		case 11:
			return false;
		case 12:
			return true;
		}
	}

	void addOneDay() {
		if (isLeapYear(year)) {
			if (isBigMonth(month)) {
				(month == 2) ? (day > 29 ? day = 1, month++ : day++) : (day > 31 ? day = 1, month++ : day++);
			}
			else {
				(month == 2) ? (day > 29 ? day = 1, month++ : day++) : (day > 30 ? day = 1, month++ : day++);
			}
		}
		else {
			if (isBigMonth(month)) {
				(month == 2) ? (day > 28 ? day = 1, month++ : day++) : (day > 31 ? day = 1, month++ : day++);
			}
			else {
				(month == 2) ? (day > 28 ? day = 1, month++ : day++) : (day > 30 ? day = 1, month++ : day++);
			}
		}
	}

	void addOneMonth() {
		if (month > 12) {
			month = 1;
			year++;
		}
		else {
			month++;
		}
	}

	void addOneYear() {
		year++;
	}

	unsigned int getDay() { return day; }
	unsigned int getMonth() { return month; }
	unsigned int getYear() { return year; }
	void showDate() {
		cout << getYear() << '-' << getMonth() << '-' << getDay() << endl;
	}

};