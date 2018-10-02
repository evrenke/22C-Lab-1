#include "Currency.h"
#include <iostream>

Currency::Currency() {
	bigName = "DefCurrency";
	littleName = "DefPortions";
	units = 0;
	parts = 0;
}

Currency& Currency::operator+(Currency const &obj) {
	//Failsfe to ensure currencies of different types are not added
	if (!(bigName.compare(obj.bigName) && littleName.compare(obj.littleName))) { throw "Currency type mismatch"; }
	Currency temp;
	temp.units = units + obj.units;
	temp.parts = parts + obj.parts;
	temp.rollOver();
	return temp;
}

Currency& Currency::operator-(Currency const &obj) {
	//Failsfe to ensure currencies of different types are not added
	if (!(bigName.compare(obj.bigName) && littleName.compare(obj.littleName))) { throw "Currency type mismatch"; }
	Currency temp;
	temp.units = units - obj.units;
	temp.parts = parts - obj.parts;
	temp.rollOver();
	return temp;
}

std::ostream& operator<<(std::ostream& out, const Currency& obj) {
	out << obj.getWholeParts << " " << obj.getName << "(s) and " << obj.getFractionalParts << " " << obj.getPortionName << "(s)";
	return out;
}

std::istream& operator>>(std::istream& in, Currency& obj) {
	int iTemp;
	std::string sTemp;
	std::cin >> sTemp;
	obj.setName(sTemp);
	std::cin >> sTemp;
	obj.setPortionName(sTemp);
	std::cin >> iTemp;
	obj.setWholeParts(iTemp);
	std::cin >> iTemp;
	obj.setFractionalParts(iTemp);
}

void Currency::rollOver() {
	units += parts / 100;
	parts %= 100;
}

Dollar::Dollar() {
	setName("Dollar");
	setPortionName("Cent");
	setWholeParts(0);
	setFractionalParts(0);
}
Euro::Euro() {
	setName("Euro");
	setPortionName("Cent");
	setWholeParts(0);
	setFractionalParts(0);
}Yen::Yen() {
	setName("Yen");
	setPortionName("Sen");
	setWholeParts(0);
	setFractionalParts(0);
}Rupee::Rupee() {
	setName("Rupee");
	setPortionName("Paise");
	setWholeParts(0);
	setFractionalParts(0);
}Yuan::Yuan() {
	setName("Yuan");
	setPortionName("Fen");
	setWholeParts(0);
	setFractionalParts(0);
}
