#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {

	fstream			inputFile("input.txt");
	string			line;
	long long			result = 0;
	
    while (getline(inputFile, line)) {
        stringstream ss(line);         
        string token;
        
        while (getline(ss, token, ',')) {
            size_t pos = token.find('-');
			long long start = stoll(token.substr(0, pos));
			long long end = stoll(token.substr(pos + 1));

			for (long long i = start; i <= end; i++) {
				string number = to_string(i);
			
				for (size_t patternLen = 1; patternLen <= number.length() / 2; patternLen++) {
					if (number.length() % patternLen == 0) {
						string pattern = number.substr(0, patternLen);
						bool isRepeating = true;
						
						for (size_t j = patternLen; j < number.length(); j += patternLen) {
							if (number.substr(j, patternLen) != pattern) {
								isRepeating = false;
								break;
							}
						}
						
						if (isRepeating) {
							cout << number << " (patrón: " << pattern << ")" << endl;
							result += stoll(number);
							break;  // Encontró un patrón, salir
						}
					}
				}
        	}
    	}
    }

	cout << "Result: " << result << endl;
	return (0);
}