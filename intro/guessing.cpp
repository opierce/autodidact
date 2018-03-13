// guessing.cpp: Owen Pierce
// Description: Play a guessing game with your computer!

#include <iostream>
#include <random>
using namespace std;

int gimmeRandom() {
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(1,10);

	return dist6(rng);
}

int main() {
	int inputNumber = 0;
	int secretNumber = gimmeRandom();
	do {
		cout << "Enter a number (-1 = quit): ";
		if (!(cin >> inputNumber)) {
      		cin.clear();
		    cin.ignore(10000, '\n');
		    cout << "Please enter numbers only." << endl;
    		continue;
	    }

		if (inputNumber != -1) {
    		cout << "You entered " << inputNumber << endl;
    		if (inputNumber != secretNumber) {
    			cout << "WRONG GUESS!" << endl;
    			cout << "Try Again?: ";
    		} else {
    			cout << "Great guess! You win!" << endl;
    			break;
    		}
    	}

	} while (inputNumber != -1);

	cout << "Goodbye!" << endl;

	return 0;
}
