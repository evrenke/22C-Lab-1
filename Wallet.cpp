#include "Wallet.h"

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
	switch (index)
	{
	case 1: return c[0];
	case 2: return c[1];
	case 3: return c[2];
	case 4: return c[3];
	case 5: return c[4];
	default: exit(1);
	}
}

bool Wallet::isEmptyCurrency(CurrencyType cT)
{
	switch (cT)
	{
	case DOLLAR:
		return c[0].getWholeParts() == 0 && c[0].getFractionalParts() == 0;
	case EURO:
		return c[1].getWholeParts() == 0 && c[1].getFractionalParts() == 0;
	case YEN:
		return c[2].getWholeParts() == 0 && c[2].getFractionalParts() == 0;
	case RUPEE:
		return c[3].getWholeParts() == 0 && c[3].getFractionalParts() == 0;
	case YUAN:
		return c[4].getWholeParts() == 0 && c[4].getFractionalParts() == 0;
	}
	return false;
}

int Wallet::nonZeroCurrencyCount()
{
	int count = 0;
	for (int ind = 0; ind < 5; ind++)
	{
		CurrencyType type = static_cast<CurrencyType> (ind);
		if (isEmptyCurrency(type))
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
		cur.setWholeParts(whole);
		cur.setFractionalParts(fraction);
		c[0] = c[0] + cur;
		break;
	case EURO:
		cur = Euro();
		cur.setWholeParts(whole);
		cur.setFractionalParts(fraction);
		c[1] = c[1] + cur;
		break;
	case YEN:
		cur = Yen();
		cur.setWholeParts(whole);
		cur.setFractionalParts(fraction);
		c[2] = c[2] + cur;
		break;
	case RUPEE:
		cur = Rupee();
		cur.setWholeParts(whole);
		cur.setFractionalParts(fraction);
		c[3] = c[3] + cur;
		break;
	case YUAN:
		cur = Yuan();
		cur.setWholeParts(whole);
		cur.setFractionalParts(fraction);
		c[4] = c[4] + cur;
		break;
	}
}

bool Wallet::removeCurrency(int type, int whole, int fraction)
{
	Currency cur, temp;
	int index = type - 1;
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
	cur.setWholeParts(c[index].getWholeParts());
	cur.setFractionalParts(c[index].getFractionalParts());
	temp.setWholeParts(whole);
	temp.setFractionalParts(fraction);
	temp = temp - cur;
	temp.rollOver();
	if (temp.getWholeParts() <= 0 || temp.getFractionalParts() <= 0)
		return !canWithdraw;
	c[index] = c[index] - cur;
	
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
		if (!isEmptyCurrency(static_cast<CurrencyType>(ind)))
			return false;
	}
	return isAllEmpty;
}
