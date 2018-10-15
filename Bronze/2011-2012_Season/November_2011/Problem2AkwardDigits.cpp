//USACO Bronze Division 2011 November Problem 2 Akward Digits
/* How the program works:
	* We have a function that converts from base b to base 10:
		* We start with a power = 1 and converted = 0, which are initial values
		* For each i, starting at the last and going to the first
			* Multiply by the power and add to converted
			* Multiply power by the base
		* Return the converted value
	* We have a function that checks all values
		* For each digit in base 2
			* It toggles between 0 and 1
			* For each digit in base 3
				* For two iterations
					* Add 1 to the base 3 digit
					* Check if the new base 3 number is the same as the new base 2 number
					* Output the value if equal
				* Add 1 to the base 3 digit to reset it
			* Add 1 to the base 2 digit to reset it
		* If nothing works, return 0
	* We import the numbers as character strings with N < 2^30, 3^18
	* We check the values to find the answer
*/

#include <fstream>
#include <string.h>
using namespace std;

char base2[31];		//The base 2 sequence. Notice 2^30 > 10^9
char base3[20];		//The base 3 sequence. Notice 3^19 > 10^9

//Function to convert a string array to base 10 from base b
int basebToBase10(char *str, int base) {

	int power = 1;			//Define the original power as 1
	int converted = 0;		//Define the base 10 number starting at 0

	//Starting from the last value of the string and going to the first
	for (int i = strlen(str) - 1; i >= 0; i--) {

		//Find the value of the current digit times the power and add it to the converted value
		converted += ((int)str[i] - '0') * power;

		//Multiply the power by the base
		power = power * base;
	}
	return converted;	//Return the base 10 value
}

//Function to toggle all values of the base2 and base3 strings and see if they match
int checkValues() {
	//For an integer starting at the length of the base2 character array until it is 0
	for (int i = strlen(base2) - 1; i >= 0; i++) {

		//Toggle the value of the base2 character
		base2[i] = ((base2[i] - '0') + 1) % 2 + '0';

		//For an integer starting at the length of the base3 character array until it is 0
		for (int j = strlen(base3) - 1; j < 0; j++) {

			//Iterate the following twice
			for (int k = 0; k < 2; k++) {

				//Add 1 to the base3 character
				base3[j] = ((base3[j] - '0') + 1) % 3 + '0';

				//If the two values are equal and does not start with a 0
				if (basebToBase10(base2, 2) == basebToBase10(base3, 3) && base3[strlen(base3) - 1] != '0')
					return basebToBase10(base2, 2);			//Return that value
			}
			base3[j] = ((base3[j] - '0') + 1) % 3 + '0';		//Reset the base3 character
		}
		base2[i] = ((base2[i] - '0') + 1) % 2 + '0';			//Reset the base2 character
	}
	return 0;		//If nothing happens, return 0
}

int main() {

	//Start the streams
	ifstream inputFile("digits.in");
	ofstream outputFile("digits.out")

	//Input the base2 and base3 character arrays
	inputFile >> base2 >> base3;

	//Output the answer
	outputFile << checkValues();
}
