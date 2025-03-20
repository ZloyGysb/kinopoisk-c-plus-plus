#include "Header.h"
using namespace std;
using namespace names;

int main() {
	Film* films = nullptr;
	int count = 0;
	addFilm(&films, &count);

	int choice = 0;
	do {
		cout << "Menu:" << endl;
		cout << "1. Spisok fimov" << endl;
		cout << "2. Dobavit film" << endl;
		cout << "3. Redaktirovat film" << endl;
		cout << "4. Udalit film" << endl;
		cout << "5. Poisk filma po godu vipuska" << endl;
		cout << "6. Poisk filma po ocenke" << endl;
		cout << "7. Sohranit i viyti" << endl;
		cout << "Vvedite nomer:" << endl;

		cin >> choice;

		switch (choice) {
		case 1:
			displayFilms(films, count);
			break;
		case 2:
			addFilm(&films, &count);
			break;
		case 3:
			editFilm(films, count);
			break;
		case 4:
			deleteFilm(films, &count);
			break;
		case 5:
			searchYearFilm(films, count);
			break;
		case 6:
			searchRatingFilm(films, count);
			break;
		case 7: 
			saveFilm(films, count);
			break;
		default:
			cout << "Nevernoe znachenie, poprobuyte snova" << endl;
		}
	} while (choice != 7);

	delete[] films;
	return 0;
}