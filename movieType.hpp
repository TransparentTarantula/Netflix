#ifndef movieType_hpp
#define movieType_hpp

#include <string>
#include <iostream>
#include <stdio.h>
#include "movie.hpp"
#include "movieList.hpp"

using namespace std;

class Type {
public:
    Type(){
        //empty constructor to initialize data
    }
    Type(string t) {
        this->category = t;
        movieList temp;
        this->list = temp;
    }
    
    string getType() {
        return category;
    }
    
    bool operator == (Type& temp1) {
        if (category == temp1.getType()) {
            return true;
        }
        else
            return false;
    }
    
    void addMovie(Movie& other) {
        if (list.check(other) == true) {
            return;
        }
        else
            list.insert(other);
    }
    
    Movie getMovie(unsigned short index) {
        return list[index];
    }
    
    unsigned short totalMovie() {
        return list.size();
    }
    
    friend ostream& operator<<(ostream& lhs,Type& rhs);
    
    void removeMovie(unsigned short index) {
        list.erase(index);
    }
    
    void editMovie(unsigned short index) {
        unsigned short year, rank;
        string name, rating, category;
        cin.ignore();
        printf("Enter movie name: ");
        getline(cin, name);
        while (true) {
            printf("Enter year: ");
            cin >> year;
            if (year < 1800 || year > 2100)
                continue;
            else
                break;
        }
        cin.ignore();
        printf("Enter Category: ");
        getline(cin, category);
        while (true) {
            printf("Rating: ");
            getline(cin, rating);
            if ((rating != "PG") && (rating != "PG-13") && (rating != "G") && (rating != "R") && (rating != "NC-17")) {
                continue;
            }
            else
                break;
        }
        while (true) {
            printf("Ranking: ");
            cin >> rank;
            if (rank < 0 || rank > 5) {
                continue;
            }
            else
                break;
        }
        list[index].setName(name);
        list[index].setYear(year);
        list[index].setCat(category);
        list[index].setRanking(rank);
        list[index].setRating(rating);
    }
    
private:
    movieList list;
    string category;
};

ostream& operator<<(ostream& lhs, Type& rhs) {
    lhs << rhs.getType();
    return lhs;
}

#endif
