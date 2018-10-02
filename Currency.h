#pragma once
#include <string>
class Currency {
protected:
	std::string bigName, littleName;
	int units, parts;
public:
	Currency();

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
};

class Dollar: public Currency {
	Dollar();
};
class Euro : public Currency {
	Euro();
};
class Yen : public Currency {
	Yen();
};
class Rupee : public Currency {
	Rupee();
};
class Yuan : public Currency {
	Yuan();
};
