/*
	Authors: Evren Keskin and Jason Hagene
	Date: 10/03/2018
	Description:
		This program showcases the use of polymorhpism, and inheritance
		by creating a wallet manager that can keep track of different currency values
		that the user enters into the program
		Any user interaction is done through WalletManager.cpp
		and any non-user input related calculations are done in the other files
*/

#include <iostream>
#include "Currency.h"
#include "Wallet.h"

using namespace std;

void WalletPanel(int cc, Wallet *wallet);
void printCurrencies(Wallet w);
int takeNumberInput(int range);
double takeValueInput();
void addMoney(Wallet *w);
void withdrawMoney(Wallet *w);

int main()
{
	int currencyCount = 0;
	Wallet w = Wallet();
	WalletPanel(currencyCount, &w);

	w.~Wallet();
	return 0;
}

/*
Function: WalletPanel(int,Wallet)
Description:
	This is the main menu the user will interact with.
	It shows the options the user has, and if they have added money to their wallet,
	it shows the table of money they have.
*/
void WalletPanel(int cc, Wallet *wallet)
{
	bool isExiting = false;
	while (!isExiting)
	{
		cout << "        Welcome to Wallet Manager    " << endl;
		cout << "          You have " << cc << " currencies" << endl;
		
		printCurrencies(*wallet);

		cout << "1) Add money" << endl;
		cout << "2) Withdraw money" << endl;
		cout << "3) Empty wallet" << endl;
		cout << "4) Exit" << endl;
		int input = takeNumberInput(4);
		switch (input)
		{
		case 1: addMoney(wallet);  break;
		case 2: withdrawMoney(wallet);  break;
		case 3: (*wallet).emptyWallet(); break;
		case 4: isExiting = true; break;
		}
		cc = (*wallet).nonZeroCurrencyCount();
	}
}

/*Function: printCurrencies(Wallet)
Description:This function prints a table of used currencies
	and if some currencies are being used it prints a line above and below the table
	to make for a clearer ui

*/
void printCurrencies(Wallet w)
{
	if (!w.isEmpty())
		cout << "--------------------------------------------" << endl;
	for (int ind = 0; ind < 5; ind++)
	{
		if (! w.isEmptyCurrency(ind) )
			cout << w[ind];
	}
	if(!w.isEmpty())
		cout << "--------------------------------------------" << endl;
}
/*
Function: takeNumberInput(int)
Description: This function takes an int input from the user,
and doesnt allow any other type of input to be put in.
It also only allows input from a range given by its parameter
*/
int takeNumberInput(int range)
{
	int chosen = -1;
	cout << endl;
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
	} while (chosen <= 0 || chosen > range);
	system("CLS");
	return chosen;
}
/*
Function: takeNumberInput(int)
Description: This function takes a double input from the user,
and doesnt allow any other type of input to be put in.
*/
double takeValueInput()
{
	double chosen = -1;
	do
	{
		cout << "Enter a valid number: ";
		string input = "";
		getline(cin, input);
		try {
			chosen = stod(input);
		}
		catch (...)
		{
			chosen = -1;
		}
	} while (chosen < 0);
	system("CLS");
	return chosen;
}
/*
Function: addMoney(Wallet)
Description: This function asks the user for what currency type 
they want to add to their wallet, and how much they want to add.
*/
void addMoney(Wallet *w)
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

	cout << "How much " << (*w)[input - 1].getName() << "(s) do you want to add? " << endl;
	double addition = takeValueInput();
	int wholeAddition = (int)addition;
	int fractionAddition = (int)(addition * 100) % 100;

	(*w).addCurrency(input - 1, wholeAddition, fractionAddition);

	system("CLS");
}
/*
Function: withdraw(Wallet)
Description: This function asks the user for what currency type
they want to withdraw from their wallet, and how much they want to withdraw.
It doesn't let them do so if they try to withdraw more than they have.
*/
void withdrawMoney(Wallet *w)
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

	printCurrencies(*w);

	cout << "How much " << (*w)[input - 1].getName() << "(s) do you want to withdraw? " << endl;
	double withdrawal = takeValueInput();
	int whole = (int)withdrawal;
	int fraction = (int)(withdrawal * 100) % 100;


	if ((*w).removeCurrency(input - 1, whole, fraction))
		cout << "Withdrawal complete!" << endl;
	else
		cout << "That is too much money to withdraw!" << endl;

	cout << "--------------------------------------------" << endl;
}
