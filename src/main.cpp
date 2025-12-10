#include "main.h"

using namespace std;

int main()
{
	bool running = true;

	cout << "Welcome!." << endl << "=========================" << endl << endl;
	
	while (running) {
		cout << endl << "Please select which challenge you want to run:";
		cout << endl << "1. Day 1 Challenge" << endl;
		cout << "0. Exit" << endl << endl;

		int choice;
		cin >> choice;
		switch (choice) {
			case 0:
				running = false;
				break;
			case 1:
				cout << "Please enter the file path for the input data: ";
				string filePath;
				cin >> filePath;
				int result = RunDay1Challenge1(filePath);
				cout << "The result of the Day 1 Challenge 1 is: " << result << endl;
				cout << "And the result of Challenge 2 is: " << RunDay1Challenge2(filePath);
				break;
		}
	}



	return 0;
}
