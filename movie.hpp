#ifndef movie_hpp
#define movie_hpp

#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

class Movie {
public:
    Movie() {

    } // Empty Constructor

    Movie(string name, string rating, string cat, unsigned short year, unsigned short ranking) {
        this->name = name;
        this->rating = rating;
        this->cat = cat;
        this->year = year;
        this->ranking = ranking;
    } // Default constructor

    string getName() {
        return name;
    } // Returns the name of movie

    string getRating() {
        return rating;
    } // Returns the rating of movie

    string getCat() {
        return cat;
    } // Returns the category of the movie

    unsigned short getYear() {
        return year;
    } // Returns the year that the movie was made

    unsigned short getRanking() {
        return ranking;
    } // Returns the ranking of the movie

    Movie& setName(string name) {
        this->name = name;
        return *this;
    } // Stores the name of the movie

    Movie& setRating(string rating) {
        this->rating = rating;
        return *this;
    } // Stores the rating of the movie

    Movie& setCat(string cat) {
        this->cat = cat;
        return *this;
    } // Stores the category of the movie

    Movie& setYear(unsigned short year) {
        this->year = year;
        return *this;
    } // Stores the year that the movie was made


    Movie& setRanking(unsigned short ranking) {
        this->ranking = ranking;
        return *this;
    } // Stores the ranking of the movie

    /* 
        Following functions and below are overloading operators to print
        out Movie information in a formatted manner.
     */
    friend ostream& operator<<(ostream& lhs, Movie& rhs);

    bool operator==(Movie& rhs) {
        if(name == rhs.getName() && year == rhs.getYear()) {
            return true;
        }
        else {
            return false;
        }
    } // Overloading == operator

    bool operator!=(Movie& rhs) {
        if (name != rhs.getName() && year != rhs.getYear()) {
            return true;
        }
        else {
            return false;
        }
    } // Overloading != operatror

    bool operator>(Movie&rhs) {
        if(name > rhs.getName() && year > rhs.getYear()) {
            return true;
        }
        else {
            return false;
        }
    } // Overloading > operator

private:
    string name;
    string rating;
    string cat;
    unsigned short year;
    unsigned short ranking;
};

ostream& operator<<(ostream& lhs, Movie& rhs) {
    string p = "";

    lhs << rhs.getName() << endl 
        << "Year: " << rhs.getYear() << endl
        << "Category: " << rhs.getCat() << endl
        << "Rated: " << rhs.getRating() << endl;

    // Appends stars to string to indicate ranking
    for(unsigned short i = 0; i < rhs.getRanking(); i++) {
        p.append("*");
    } 

    lhs << "Rank: " << p << endl;
    return lhs;
} // Prints out the movie with formatting

#endif //!movie_hpp



