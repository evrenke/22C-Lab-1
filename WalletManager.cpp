#include <iostream>
#include <iomanip>
#include <string>
//#include "Currency.h"
#include "Wallet.h"

using namespace std;

int main()
{
	int currencyCount = 0;
	//Wallet w;
	WalletPanel(currencyCount);

	return 0;
}

void WalletPanel(int cc)
{
	bool isExiting = false;
	while (!isExiting)
	{
		cout << "    Welcome to Wallet Manager    " << endl;
		cout << " You have " << cc << " currencies" << endl;
		cout << "---------------------------------" << endl;
		printCurrencies();

		cout << "1) Add money" << endl;
		cout << "2) Withdraw money" << endl;
		cout << "3) Empty wallet" << endl;
		cout << "4) Exit" << endl;
		int input = takeNumberInput(4);
		switch (input)
		{
		case 1: addMoney();  break;
		case 2: withdrawMoney();  break;
		case 3: clearWallet(); break;
		case 4: isExiting = true; break;
		}

		// cc = wallet.nonZeroCurrencyCount();
	}
}

void printCurrencies()//wallet w
{
	for (int ind = 0; ind < 5; ind++)
	{
		//if w.checkCurrency(0);
		//cout << w[0];
	}
}

int takeNumberInput(int range)
{
	int chosen = -1;
	do
	{
		cout << "Enter a valid number: ";
		string input = "";
		getline(cin, input);
		try {
			chosen = stoi(input);
		}
		catch (...)
		{
			chosen = -1;
		}
	} while (chosen < 0 || chosen > range);
	system("CLS");
	return chosen;
}

double takeValueInput()
{
	double chosen = -1;
	do
	{
		cout << "Enter a valid number: ";
		string input = "";
		getline(cin, input);
		try {
			chosen = stoi(input);
		}
		catch (...)
		{
			chosen = -1;
		}
	} while (chosen < 0);
	system("CLS");
	return chosen;
}

void addMoney() // wallet w
{
	cout << "What currency are you adding to your wallet?" << endl;
	cout << "1) US Dollars " << endl;
	cout << "2) Euroes " << endl;
	cout << "3) Yen " << endl;
	cout << "4) Rupees " << endl;
	cout << "5) Yuan " << endl;
	cout << "6) Cancel add" << endl;
	int input = takeNumberInput(6);
	if (input == 6)
		return;

	cout << "How much " << /* Wallet[input].getWholeName << */ "do you want to add? " << endl;
	int wholeAddition = 0;
	int fractionAddition = 0;
	double addition = takeValueInput();

	//TURN VALUE INPUT INTO wholeAddition and fractionAddition

	switch (input)
	{
	case 1: //wallet.addTo(1, wholeAddition, fractionAddition); break;
	case 2: //wallet.addTo(1, wholeAddition, fractionAddition); break;
	case 3: //wallet.addTo(1, wholeAddition, fractionAddition); break;
	case 4: //wallet.addTo(1, wholeAddition, fractionAddition); break;
	case 5: //wallet.addTo(1, wholeAddition, fractionAddition); break;

	}
	system("CLS");
}

void withdrawMoney()
{
	cout << "What currency are you withdrawing from your wallet?" << endl;
	cout << "1) US Dollars " << endl;
	cout << "2) Euroes " << endl;
	cout << "3) Yen " << endl;
	cout << "4) Rupees " << endl;
	cout << "5) Yuan " << endl;
	cout << "6) Cancel withdrawal" << endl;
	int input = takeNumberInput(6);
	if (input == 6)
		return;

	printCurrencies();

	cout << "How much " << /* Wallet[input].getWholeName << */ "do you want to withdraw? " << endl;
	int wholeAddition = 0;
	int fractionAddition = 0;
	double addition = takeValueInput();

	//TURN VALUE INPUT INTO wholeAddition and fractionAddition

	//if its more than the amount in bank
	// cout << " You cannot withdraw more than you have" << endl;
	//  return;

	switch (input)
	{
	case 1: //wallet.addTo(1, wholeAddition, fractionAddition); break;
	case 2: //wallet.addTo(1, wholeAddition, fractionAddition); break;
	case 3: //wallet.addTo(1, wholeAddition, fractionAddition); break;
	case 4: //wallet.addTo(1, wholeAddition, fractionAddition); break;
	case 5: //wallet.addTo(1, wholeAddition, fractionAddition); break;

	}
	system("CLS");
}

void clearWallet()
{

}
