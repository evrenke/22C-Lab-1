#include "Currency.h"
#include <iostream>
#include <iomanip>


Currency::Currency() {
	bigName = "DefCurrency";
	littleName = "DefPortions";
	units = 0;
	parts = 0;
}

Currency::~Currency()
{

}



Currency& Currency::operator+(Currency const obj) {
	//Failsafe to ensure currencies of different types are not added
	if (!(bigName.compare(obj.bigName) == 0 && littleName.compare(obj.littleName) == 0)) { throw "Currency type mismatch"; }
	setWholeParts(units + obj.units);
	setFractionalParts(parts + obj.parts);
	rollOver();
	return *this;
}


Currency&  Currency::operator-(Currency const obj) {
	//Failsafe to ensure currencies of different types are not added
	if (!(bigName.compare(obj.bigName) == 0 && littleName.compare(obj.littleName) == 0)) { throw "Currency type mismatch"; }
	setWholeParts(units - obj.units);
	setFractionalParts(parts - obj.parts);
	rollOver();
	return *this;
}


std::ostream & operator<<(std::ostream & out, Currency & obj)
{
	out << std::left << std::setw(5) << obj.getWholeParts() << " " << std::right << std::setw(10) << obj.getName() << "(s) and "
		<< std::left << std::setw(5) << obj.getFractionalParts() << " " << std::right << std::setw(10) << obj.getPortionName() << "(s)\n";
	return out;
}

std::istream& operator>>(std::istream& in, Currency& obj) {
	
	int iTemp;
	in >> iTemp;
	obj.setWholeParts(iTemp);
	in >> iTemp;
	obj.setFractionalParts(iTemp);
	return in;
}

void Currency::rollOver() {
	units += parts / 100;
	while (parts < 0)
	{
		units--;
		parts += 100;
	}
	parts %= 100;
}

void Currency::setName(std::string s)
{
	bigName = s;
}
void Currency::setPortionName(std::string s)
{
	littleName = s;
}
void Currency::setWholeParts(int i)
{
	units = i;
}
void Currency::setFractionalParts(int i)
{
	parts = i;
}

Dollar::Dollar()
{
	setName("Dollar");
	setPortionName("Cent");
	setWholeParts(0);
	setFractionalParts(0);
}
Euro::Euro()
{
	setName("Euro");
	setPortionName("Cent");
	setWholeParts(0);
	setFractionalParts(0);
}
Yen::Yen()
{
	setName("Yen");
	setPortionName("Sen");
	setWholeParts(0);
	setFractionalParts(0);
}
Rupee::Rupee()
{
	setName("Rupee");
	setPortionName("Paise");
	setWholeParts(0);
	setFractionalParts(0);
}
Yuan::Yuan()
{
	setName("Yuan");
	setPortionName("Fen");
	setWholeParts(0);
	setFractionalParts(0);
}

Dollar::~Dollar()
{

}
Euro::~Euro()
{

}
Yen::~Yen()
{

}
Rupee::~Rupee()
{

}
Yuan::~Yuan()
{

}
