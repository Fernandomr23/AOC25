#include <iostream>
#include <fstream>

using namespace std;

int main() {

	fstream	inputFile("input.txt");
	string	line;
	int step = 50;
	int count = 0;

	cout << "Counted! " << count << endl;
	
	while (getline(inputFile, line)) {
		string numbers = line.substr(1);
		if (line.find("R") != string::npos) {
			// cout << "+" << numbers << endl;
			step += stoi(numbers);
		} else {
			// cout << "-" << numbers << endl;
			step -= stoi(numbers);
		}
		if (step < 0) {
			while (step < 0) {
				step += 100;
				count++;
				cout << "Counted! " << count << endl;
			}
		} else if (step >= 100) {
			while (step >= 100) {
				step -= 100;
				count++;
				cout << "Counted! " << count << endl;
			}
		}
		cout << "Step: " << step << endl;
		// if (step == 0) {
		// 	count++;
		// 	cout << "Counted! " << count << endl;
		// }
	}

	cout << "Total count: " << count << endl;
	return (0);
}