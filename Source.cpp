#include "Header.h"
#include <fstream>
#include <iostream>
using namespace std;
using namespace names;

string Film::name() {
	return _name;
}

int Film::year() {
	return _year;
}

float Film::rating() {
	return _rating;
}

Film::Film(string name, int year, float rating) : _name(name), _year(year), _rating(rating) {}

ostream& names::operator << (ostream & out, const Film& f) {
	out << f._name << " " << f._year << " " << f._rating << endl;
	return out;
}

istream& names::operator >> (istream & in, Film& f) {
	in >> f._name >> f._year >> f._rating;
	return in;
}

Film * names::readText(int & count) {
	ifstream in("kinopoisk.txt");
	if (!in.is_open())
		return nullptr;
	Film *films = new Film[count];
	for (int i = 0; i < count; i++)
		in >> films[i];
	in.close();
	return films;
}

void names::saveFilm(Film *films, int count) {
	ofstream out("kinopoisk.txt");
	out << count << endl;
	for (int i = 0; i < count; i++) {
		out << films[i] << endl;
	}
	out.close();
}

void names::addFilm(Film** films, int* count) {
	Film* temp = new (nothrow) Film[*count + 1];
	if (temp == nullptr) {
		cout << "Oshibka: ne udalos vydelit pamyat" << endl;
		return;
	}

	for (int i = 0; i < *count; i++) {
		temp[i] = (*films)[i];
	}
	string name = "";
	int year = 0;
	float rating = 0;
	cout << "Vvedite nazvanie filma: " << endl;
	cin >> name;
	cout << "Vvedite god vihoda filma: " << endl;
	cin >> year;
	cout << "Vvedite ocenku filma: " << endl;
	cin >> rating;
	temp[*count].setName(name);
	temp[*count].setYear(year);
	temp[*count].setRating(rating);
	delete[] * films;

	*films = temp;
	(*count)++;
}

void names::editFilm(Film *films, int count) {
	int id = 0;
	displayFilms(films, count);
	cout << "Vvedite nomer filma, kotorogo hotite izmenit: " << endl;
	cin >> id;
	if (id < 0 || id >= count) {
		cout << "Nevernoe znachenie" << endl;
		return;
	}
	string temp = "";
	cout << "Vvedite novoe nazvanie filma(vvedite ODNU lyubyu bukvu ili cifru dlya propuska): " << endl;
	cin >> temp;
	if (temp.length() > 1) {
		films[id].setName(temp);
	}
	int year = 0;
	cout << "Vvedite noviy god vihoda filma(vvedite '-1' dlya propuska): " << endl;
	cin >> year;
	if (year != -1) {
		films[id].setYear(year);
	}
	float rating = 0;
	cout << "Vvedite novuyu ocenku filma(vvedite '-1' dlya propuska): " << endl;
	cin >> rating;
	if (rating != -1) {
		films[id].setRating(rating);
	}
}

void names::deleteFilm(Film *films, int *count) {
	int id = 0;
	displayFilms(films, *count);
	cout << "Vvedite nomer filma, kotorogo hotite udalit: " << endl;
	cin >> id;
	if (id < 0 || id >= *count) {
		cout << "Nevernoe znachenie" << endl;
		return;
	}

	for (int i = id; i < *count - 1; i++) {
		films[i] = films[i + 1];
	}
	(*count)--;
}

void names::searchYearFilm(Film *films, int count) {
	int year = 0;
	cout << "Vvedite god vipuska filma: " << endl;
	cin >> year;
	for (int i = 0; i < count; i++) {
		if (films[i].year() == year) {
			cout << films[i] << endl;
		}
	}
}

void names::searchRatingFilm(Film *films, int count) {
	int rating = 0;
	cout << "Vvedite ocenku filma: " << endl;
	cin >> rating;
	for (int i = 0; i < count; i++) {
		if (films[i].rating() == rating) {
			cout << films[i] << endl;
		}
	}
}

void names::displayFilms(Film* films, int count) {
	for (int i = 0; i < count; i++) {
		cout << i << " " << films[i] << endl;
	}
}