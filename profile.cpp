#include <string>

#include "profile.hpp"

using namespace std;

profile::profile() {

}

profile::profile(string label, string first, string last, int age) {
	this->label = label;
	this->fName = first;
	this->lName = last;
	this->age = age;
}
profile::profile(string label, string first, string last, int age, profile& anotherProfile) {
	/*constructor for a WHOLE move to add to someones profile*/
}
string profile::getFname() {
	return fName;
}
string profile::getLname() {
	return lName;
}
string profile::getLabel() {
	return label;
}
int profile::getAge() {
	return age;
}
int profile::getAllMovies() {
	return totalMovies;
}
int profile::getAllCategories() {
	return numCategories;
}
void profile::addMovie() {

	/*adds movie to person's profile*/
}
void profile::removeMovie() {
	/*removes movie from person profile*/
}
void profile::editMovie() {
	/*edits a movie in a persons profile*/
}
void profile::findMovie() {
	/*finds a movie in a person's profile*/
}
profile& profile::setFirst(string first) {
	this->fName = first;
	return *this;
}
profile& profile::setLast(string last) {
	this->lName = last;
	return *this;
}
profile& profile::setLabel(string label) {
	this->label = label;
	return *this;
}
profile& profile::setAge(int age) {
	this->age = age;
	return *this;
}
//category profile::getCategory(string name) {
//	
//}
//category& profile::getCategoryByIndex(int index) {
//
//}