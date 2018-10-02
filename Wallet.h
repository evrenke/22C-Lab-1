#include "Wallet.h"

Wallet::Wallet(Currency currencies[])
{
	c[1] = currencies[1];
}

Currency& Wallet::operator [](int index)
{
	switch (index)
	{
	case 1: return c[1];
	case 2: return c[2];
	case 3: return c[3];
	case 4: return c[4];
	case 5: return c[5];
	default: exit(1);
	}
}

bool Wallet::isEmptyCurrency(CurrencyType cT)
{
	switch (cT)
	{
	case DOLLAR:
		return c[1].getWholeParts() == 0 && c[1].getFractionalParts() == 0;
	case EURO:
		return c[2].getWholeParts() == 0 && c[2].getFractionalParts() == 0;
	case YEN:
		return c[3].getWholeParts() == 0 && c[3].getFractionalParts() == 0;
	case RUPEE:
		return c[4].getWholeParts() == 0 && c[4].getFractionalParts() == 0;
	case YUAN:
		return c[5].getWholeParts() == 0 && c[5].getFractionalParts() == 0;
	}
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

void Wallet::addCurrency(CurrencyType cT, int whole, int fraction)
{
	Currency cur;
	switch (cT)
	{
	case DOLLAR:
		cur = Dollar();
		cur.setWholeParts(whole);
		cur.setFractionalParts(fraction);
		c[1] = c[1] + cur;
		break;
	case EURO:
		cur = Euro();
		cur.setWholeParts(whole);
		cur.setFractionalParts(fraction);
		c[2] = c[2] + cur;
		break;
	case YEN:
		cur = Yen();
		cur.setWholeParts(whole);
		cur.setFractionalParts(fraction);
		c[3] = c[3] + cur;
		break;
	case RUPEE:
		cur = Rupee();
		cur.setWholeParts(whole);
		cur.setFractionalParts(fraction);
		c[4] = c[4] + cur;
		break;
	case YUAN:
		cur = Yuan();
		cur.setWholeParts(whole);
		cur.setFractionalParts(fraction);
		c[5] = c[5] + cur;
		break;
	}
}

void Wallet::removeCurrency(CurrencyType cT, int whole, int fraction)
{

}

void Wallet::emptyWallet()
{

}

bool Wallet::isEmpty()
{

}
