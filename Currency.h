#pragma once
#include <string>
class Currency {
protected:
	std::string bigName, littleName;
	int units, parts;
public:
	//Currency();

	void rollOver();

	std::string getName() { return bigName; }
	std::string getPortionName() { return littleName; }
	int getWholeParts() { return units; }
	int getFractionalParts() { return parts; }
	void setName(std::string);
	void setPortionName(std::string);
	void setWholeParts(int);
	void setFractionalParts(int);

	Currency& operator+(Currency const &obj);
	Currency& operator-(Currency const &obj);
	friend std::ostream& operator<<(std::ostream& out, const Currency& obj);
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

