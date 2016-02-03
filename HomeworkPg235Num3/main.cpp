//This program gets a month, day and 2 digit year
//Then checks if it is "magic"... What?
#include <iostream>
#include <cctype>

using namespace std;

int main()
{
	const int LEAP_YEAR_MODULUS = 4;
	const int JAN = 31; //1
	const int FEB = 28; //2
	const int FEB_LY = 29;
	const int MAR = 31; //3
	const int APR = 30; //4
	const int MAY = 31; //5
	const int JUN = 30; //6
	const int JUL = 31; //7
	const int AUG = 31; //8
	const int SEP = 30; //9
	const int OCT = 31; //10
	const int NOV = 30; //11
	const int DEC = 31; //12

	//Variables to be gotten from input
	int dayInput;
	int monthInput;
	int twoDigitYearInput;
	bool dayIsOutsideMonth = true; //Checks if the month has this day in it

	cout << "Please enter the following data in numeric form." << endl;

	//Runs once to get input and checks if it is between 0 and 99 and is a digit
	do
	{
		cout << "Please enter a two digit year in numeric form: ";
		cin >> twoDigitYearInput;
	} while (!isdigit(twoDigitYearInput) && twoDigitYearInput <= 0 && twoDigitYearInput > 99);

	//Runs once to get input and checks if it is between 1 and 12 and is a digit
	do
	{	
		cout << "Please enter a month in numeric form: ";
		cin >> monthInput;
		
	} while (!isdigit(monthInput) && monthInput <= 0 && monthInput > 12);

	//Runs based on the assumtion the data was bad then breaks out if it is correct.
	while (dayIsOutsideMonth)
	{
		cout << "Please enter a day in numeric form: ";
		cin >> dayInput;
		if (dayInput > 0) //Checks if day input is greater than 0
		{
			switch (monthInput) //Switches the input from user for month
			{
				//31 days
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if (dayInput <= 31)
					dayIsOutsideMonth = false;
				break;
			case 2:
				if (twoDigitYearInput % LEAP_YEAR_MODULUS == 0)
				{
					if (dayInput <= 29)
						dayIsOutsideMonth = false;

				}
				else if (dayInput <= 28)
					dayIsOutsideMonth = false;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if (dayInput <= 30)
					dayIsOutsideMonth = false;
				break;
			default:
				cout << "You should never have gotten here. Review logic.";
			}
		}
		else
		{
			cout << "The day must be greater than 0" << endl;
		}
	}
	cout << monthInput << "/" << dayInput << "/" << twoDigitYearInput;
	
	return 0;
}
