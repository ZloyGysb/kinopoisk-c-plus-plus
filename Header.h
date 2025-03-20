#include <iostream>
#include <string>
namespace names {
	class Film {
		std::string _name;
		int _year;
		float _rating;
	public:
		Film() = default;
		Film(std::string name, int year, float rating);
		std::string name();
		int year();
		float rating();
		friend std::ostream& operator << (std::ostream & out, const Film& f);
		friend std::istream& operator >> (std::istream & in, Film& f);
		void setName(const std::string& name) { _name = name; }
		void setYear(int year) { _year = year; }
		void setRating(float rating) { _rating = rating; }
	};
	Film * readText(int & count);
	void saveFilm(Film *films, int count);
	void addFilm(Film **films, int *count);
	void editFilm(Film *films, int count);
	void deleteFilm(Film *films, int *count);
	void searchYearFilm(Film *films, int count);
	void searchRatingFilm(Film *films, int count);
	void displayFilms(Film *films, int count);
}