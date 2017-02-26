// for MVS
#include "stdafx.h"

/*
Version 0.7
*/

#include <iostream>
#include <fstream>
#include <string>

// HelpToWrite
#include "htw.h"

using namespace std;

class Calc : public HelpToWrite
{
public:
	void header()
	{
		space(80);
		tab(2);

		write("\t\t The program for the calculaion of armor");
		tab(1);
		write("\t\t Version 0.7");

		tab(2);
		space(80);
	}
};

enum list { calculator, getOut };

void addSymbol();
void addSpace(int);
void addResult(float, float, float, float, float, string, const char, short int);

int main()
{
	short int menu, frrBack;
	const char symbol = '%';
	const float greatArmor = 55.6;
	const float littleArmor = 27.8;
	const string dot = ".txt";
	string nameFail;
	float frr, dhl, life, enemyDamageOne, enemyDamageTwo, enemyBreaking, armor, check, checkTwo;

	Calc Do;
	Do.header();

	do
	{
		addSpace(2);
		cout << "\t\t Menu" << endl;
		cout << endl

			<< "\t\t 0 - Calculator" << endl
			<< "\t\t 1 - Exit" << endl << endl
			<< "\t\t Enter: ";

		cin >> menu;
		cout << endl;

		switch (menu)
		{
		case calculator:
			cout << "\t\t Level: ";
			cin >> dhl;
			cout << endl;

			cout << "\t\t Armor: ";
			cin >> frr;
			cout << endl;

			cout << "\t\t Basic armor (0 or 1 (55.6) or 2 (27.8)): ";
			cin >> check;
			cout << endl;

			cout << "\t\t Do you want to enter any values? 0 or 1: ";
			cin >> checkTwo;

			if (checkTwo == 0)
			{
				cout << "\t\t Lives: ";
				cin >> life;
				cout << endl;

				cout << "\t\t Enemy damage: ";
				cin >> enemyDamageOne;
				cout << endl;

				cout << "\t\t Enemy breaking: ";
				cin >> enemyBreaking;
				cout << endl;
			}

			if (checkTwo == 1)
			{
				cout << endl;
				cout << "\t\t OK" << endl;
			}

			// adding a basic armor (big)
			if (check == 1)
			{
				frr += greatArmor;
			}

			// adding a basic armor (small)
			if (check == 2)
			{
				frr += littleArmor;
			}

			// max armor in the game
			if (frr > 1732)
			{
				frr = 1732;
			}

			// creating two armors, before pen and after pen	
			armor = frr;

			// if it has enemy pen - minus armor by enemy pen
			if (enemyBreaking > 0)
			{
				frr -= enemyBreaking;
			}

			// max level in the game
			if (dhl > 15) { dhl = 15; }

			// min level in the game
			if (dhl < 1) { dhl = 1; }

			// if user wrote value "-" - we're doing +
			if (frr < 0) { frr = 0; }
			if (armor < 0) { armor = 0; }
			if (life < 0) { life = 0; }
			if (enemyDamageOne < 0) { enemyDamageOne = 0; }
			if (enemyBreaking < 0) { enemyBreaking = 0; }

			// doing 2 values of damage, damage after pen and before pen				
			enemyDamageTwo = enemyDamageOne;

			// it's magic (by Paragon)		
			frr /= (100 + frr + ((dhl - 1) * 10));

			// doing the gamage
			enemyDamageTwo *= frr;

			// from float to int
			frrBack = (int)(frr * 100);

			// damage after enemy pen	
			enemyDamageOne -= enemyDamageTwo;

			if (life > 0)
			{
				// how many hits
				life /= enemyDamageOne;
			}

			addSymbol();
			addSpace(2);

			cout << "\t\t On " << dhl << " lvl" << endl << endl;

			// check out the damage		
			if (enemyDamageOne == 0)
			{
				cout << "\t\t An enemy will hit by damage (you wrote nothing)" << endl;
				cout << endl;
			}
			else
			{
				cout << "\t\t An enemy will hit by damage " << enemyDamageOne << endl;
				cout << endl;
			}

			cout << "\t\t An enemy pen your armor " << enemyBreaking << " of " << armor << endl;
			cout << endl;

			// check out the life
			if (life == 0)
			{
				cout << "\t\t hits before u'll be dead (you wrote nothing)" << endl;
				cout << endl;
			}
			else
			{
				cout << "\t\t hits before u'll be dead " << life << endl;
				cout << endl;
			}

			cout << "\t\t  u'll get damage on " << frrBack << symbol;

			addSpace(2);
			addSymbol();
			addSpace(2);

			cout << "\t\t Do you wanna save you progress? (0 - yes, 1 - no): ";
			cin >> check;

			if (check == 0)
			{
				cout << "\t\t Enter file name: ";
				cin >> nameFail;

				// we're doing file dot
				nameFail + dot;

				addResult(dhl, enemyDamageOne, life, enemyBreaking, armor, nameFail, symbol, frrBack);

				cout << "\t\t Done!";
			}
			else
			{
				cout << "\t\t You saved nothing";
			}
			addSpace(2);
			addSymbol();

			break;

		case getOut:
			cout << "\t\t The program has closed" << endl;
			cout << "\t\t Thank you for using the program" << endl;
			break;

		default:
			cout << "\t\t Please, repeat" << endl;
			break;
		}
	} while (menu != getOut);

	return 0;
}

void addSymbol()
{
	for (int i = 0; i < 60; i++)
		cout << "-";
}

void addSpace(int num)
{
	for (int i = 0; i < num; i++)
		cout << endl;
}

void addResult(float dhl, float enemyDamageOne, float life, float enemyBreaking, float armor, string nameFail, const char symbol, short int frrBack)
{
	ofstream textFile(nameFail, ios_base::app);

	if (textFile.is_open())
	{
		textFile << nameFail << endl << endl;

		textFile << "On " << dhl << " lvl" << endl;

		// check out the damage	
		if (enemyDamageOne == 0)
		{
			textFile << "An enemy will hit by damage (you wrote nothing)" << endl;
		}
		else
		{
			textFile << "An enemy will hit by damage " << enemyDamageOne << endl;
		}

		textFile << "An enemy pen your armor " << enemyBreaking << " of " << armor << endl;

		// check out the life	
		if (life == 0)
		{
			textFile << "Hits before u'll be dead (you wrote nothing)" << endl;
		}
		else
		{
			textFile << "Hits before u'll be dead " << life << endl;
		}

		textFile << "You'll get damage on " << frrBack << symbol << endl;

		cout << endl;

		textFile << "--------------------------------------------------------------------------------";

		textFile.close();
	}
	else
	{
		cout << "Error!";
	}
}