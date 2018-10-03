#pragma once
#include <string>
class Currency {
protected:
	std::string bigName, littleName;
	int units, parts;
public:
	Currency();

	//a method that fixes the values of units and parts of currency to be accurate to how money works
	void rollOver();

	std::string getName() { return bigName; }
	std::string getPortionName() { return littleName; }
	int getWholeParts() { return units; }
	int getFractionalParts() { return parts; }
	void setName(std::string);
	void setPortionName(std::string);
	void setWholeParts(int);
	void setFractionalParts(int);

	//adds the value of money from another object of the same money type
	Currency& operator+(Currency const obj);
	//subtracts the value of money from another object of the same money type
	Currency& operator-(Currency const obj);
	//turns object into string for output 
	friend std::ostream& operator<<(std::ostream& out, Currency& obj);
	//reads in values into money object
	friend std::istream& operator>>(std::istream& in, Currency& obj);
};

class Dollar: public Currency {
public:
	Dollar();
};
class Euro : public Currency {
public:
	Euro();
};
class Yen : public Currency {
public:
	Yen();
};
class Rupee : public Currency {
public:
	Rupee();
};
class Yuan : public Currency {
public:
	Yuan();
};
