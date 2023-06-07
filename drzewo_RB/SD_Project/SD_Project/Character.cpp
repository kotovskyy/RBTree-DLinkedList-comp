#include "Character.h"

Character::Character(){}

Character::Character(const char& value, const int& n_occurences) {
	this->value = value;
	this->n_occurences = n_occurences;
}

void Character::addOccrences() {
	this->n_occurences++;
}

bool Character::operator<(const Character& other) const {
	return n_occurences < other.n_occurences;
}

bool Character::operator>(const Character& other) const {
	return n_occurences > other.n_occurences;
}

bool Character::operator<=(const Character& other) {
	return n_occurences <= other.n_occurences;
}

bool Character::operator>=(const Character& other) {
	return n_occurences >= other.n_occurences;
}

bool Character::operator==(const Character& other) {
	return n_occurences == other.n_occurences;
}

bool Character::operator!=(const Character& other) {
	return n_occurences != other.n_occurences;
}

std::ostream& operator<<(std::ostream& os, const Character& character) {
	os << "(" << character.value << " : " << character.n_occurences << ")";
	return os;
}