// Kaleab Teka
// Roberto Urbina 
// HW 3 

#include<iostream>
using namespace std;

// The Struct Travel for (blue print)
struct Travel {
	float planesLanded = 0.0;
	float planesDeparted = 0.0;
	float greatestLanded = 0.0;
	float leastLanded = 0.0;
};

//size of months
const float monthSize = 12.0;

int main()
{
	// local variables to place hold information
	float totalLanded = 0.0, totalDeparted = 0.0, greatestL, leastL;

	// Creating 12 dynamic array of the struct and pointing to them with ptr months
	Travel * months = new Travel[monthSize];

	//Collecting information with a do whiile loop for input validation
	for (int i = 0; i < monthSize; i++)
	{
		do
		{
			cout << "Enter the total # of planes that landed for month " << i + 1 << " PS. No Negetive numbers" << endl;
			cin >> months[i].planesLanded;
		} while (months[i].planesLanded < 0);

		do
		{
			cout << "Enter the total # of planes that departed for month " << i + 1 << endl;
			cin >> months[i].planesDeparted;
		} while (months[i].planesDeparted < 0);

		do
		{
			cout << "Enter the least # of planes that landed in a given day for month " << i + 1 << endl;
			cin >> months[i].leastLanded;
		} while (months[i].leastLanded < 0);

		do
		{
			cout << "Enter the greatest # of planes that landed in a given day for month " << i + 1 << endl;
			cin >> months[i].greatestLanded;
		} while (months[i].greatestLanded < 0);
	}

	// Collecting the total numbers of plane landings and departings for the whole year
	for (int i = 0; i < monthSize; i++)
	{
		totalLanded = totalLanded + months[i].planesLanded;
		totalDeparted = totalDeparted + months[i].planesDeparted;
	}

	//counter to help determine which month has the greatest landings
	int counter = 1;

	// Searching for the greatest number of landings 
	greatestL = months[0].greatestLanded;
	for (int i = 1; i < monthSize; i++)
	{
		if (greatestL < months[i].greatestLanded)
		{
			greatestL = months[i].greatestLanded;
			counter = i + 1;
		}
	}

	//counter to help determine which month has the least landings
	int counter1 = 1;

	// Searching for the least number of landings 
	leastL = months[0].leastLanded;
	for (int i = 1; i < monthSize; i++)
	{
		if (leastL > months[i].leastLanded)
		{
			leastL = months[i].leastLanded;
			counter1 = i + 1;
		}
	}

	cout << "***********************************************************************************************" << endl << endl;
	cout << "The Average monthly number of planes that landed is " << totalLanded / monthSize << endl << endl;                            // Calculation and display of average landing
	cout << "The Average monthly number of planes that departed is " << totalDeparted / monthSize << endl << endl;                        // Calculation and display of average departing
	cout << "The total number of planes that landed and departed is " << totalLanded + totalDeparted << endl << endl;                     // Total number of landings and departings
	cout << "the greatest number of planes landed on month: " << counter << ", with " << greatestL << " landings" << endl << endl;    // Greatest and least 
	cout << "the least number of planes landed on month " << counter1 << "  with " << leastL << " landings" << endl << endl;

	delete[]months;
	months = nullptr;
	system("pause");
	return 0;
}
