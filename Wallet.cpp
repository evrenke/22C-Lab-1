#include "Wallet.h"
#include <iostream>

Wallet::Wallet(Currency currencies[])
{
	c[0] = currencies[0];
	c[1] = currencies[1];
	c[2] = currencies[2];
	c[3] = currencies[3];
	c[4] = currencies[4];
}

Currency& Wallet::operator [](int index)
{
	if(index >= 0 && index < 5)
		return c[index];
	exit(1);
}

bool Wallet::isEmptyCurrency(int currencyIndex)
{
	if(currencyIndex >= 0 && currencyIndex < 5)
		return c[currencyIndex].getWholeParts() == 0 && c[currencyIndex].getFractionalParts() == 0;
	return false;
}

int Wallet::nonZeroCurrencyCount()
{
	int count = 0;
	for (int ind = 0; ind < 5; ind++)
	{
		if (! isEmptyCurrency(ind))
			count++;
	}
	return count;
}

void Wallet::addCurrency(int type, int whole, int fraction)
{
	Currency cur;
	CurrencyType cT = static_cast<CurrencyType>(type);
	switch (cT)
	{
	case DOLLAR:
		cur = Dollar();
		break;
	case EURO:
		cur = Euro();
		break;
	case YEN:
		cur = Yen();
		break;
	case RUPEE:
		cur = Rupee();
		break;
	case YUAN:
		cur = Yuan();
		break;
	}
	cur.setWholeParts(whole);
	cur.setFractionalParts(fraction);
	c[type] = c[type] + cur;
}

bool Wallet::removeCurrency(int type, int whole, int fraction)
{
	Currency cur, temp;
	bool canWithdraw = true;
	CurrencyType cT = static_cast<CurrencyType>(type);
	switch (cT)
	{
	case DOLLAR:
		cur = Dollar();
		temp = Dollar();
		break;
	case EURO:
		cur = Euro();
		temp = Euro();
		break;
	case YEN:
		cur = Yen();
		temp = Yen();
		break;
	case RUPEE:
		cur = Rupee();
		temp = Rupee();
		break;
	case YUAN:
		cur = Yuan();
		temp = Yuan();
		break;
	default: return !canWithdraw;
	}
	cur.setWholeParts(whole);
	cur.setFractionalParts(fraction);
	temp.setWholeParts(c[type].getWholeParts());
	temp.setFractionalParts(c[type].getFractionalParts());
	temp = temp - cur;
	temp.rollOver();
	if (temp.getWholeParts() < 0 || temp.getFractionalParts() < 0)
		return !canWithdraw;
	c[type] = c[type] - cur;
	
	return canWithdraw;
}

void Wallet::emptyWallet()
{
	for (int ind = 0; ind < 5; ind++)
	{
		c[ind].setWholeParts(0);
		c[ind].setFractionalParts(0);
	}
}

bool Wallet::isEmpty()
{
	bool isAllEmpty = true;
	for (int ind = 0; ind < 5; ind++)
	{
		if (!isEmptyCurrency(ind))
			return false;
	}
	return isAllEmpty;
}
