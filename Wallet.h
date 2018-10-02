#pragma once
//#include "Currency.h"

class Wallet
{
private:
	//Currency[] c;
public:
	enum CurrencyType { DOLLAR, EURO, YEN, RUPEE, YUAN };
	//Wallet(Currency[] c);

	/*
	Checks if a currency is empty of value
	*/
	//bool checkCurrency(CurrencyType cT);
	
	/*
	Adds a currency value to the right object
	*/
	//void addCurrency(CurrencyType cT, int whole, int fraction);

	/*
	Removes a currency value from the right object
	THIS HAS TO BE USED ONLY AFTER IT HAS BEEN CONFIRMED THAT THE VALUE PASSED CAN BE REMOVED
	(so it doesnt reach a negative value)
	*/
	//void removeCurrency(CurrencyType cT, int whole, int fraction)

	/*
	This clears all the money from the wallet
	*/
	//void emptyWallet()

	/*
	This tells if the wallet is empty of money
	*/
	//bool isEmpty();
};
