#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>

class Character {
private:
	char value;
	int n_occurences;
public:
	Character();
	Character(const char& value, const int& n_occurences=1);
	void addOccrences();
	bool operator<(const Character& other) const;
	bool operator>(const Character& other) const;
	bool operator<=(const Character& other);
	bool operator>=(const Character& other);
	bool operator==(const Character& other);
	bool operator!=(const Character& other);

	friend std::ostream& operator<<(std::ostream& os, const Character& character);
};

#endif
