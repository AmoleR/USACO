//USACO Bronze Division 2012 March Problem 1 Times17
/* How the program works:
	* We start off with an input as a character
	* It is based on the principle that 17 is 10001 in base 2:
		* We take the number
		* We take the number with 4 more zeroes at the end
		* We add them together
	* I said variant1 was the number with 5 zeroes as at the beginning as a buffer
	* Since I could not find a function for the length, I created my own
	* Here is how the addition works:
		* Each digit of the answer is the sum of the digits of the two strings
		* If the digit is greater than 1, subtract 2 from it
	* After adding, we check if the first digit is 0
		* If it is, we output starting from the first character
		* Otherwise, we output starting from the zeroeth character
*/

#include <fstream>
using namespace std;

int length;							//Length of the number and buffers
char variant1[1005] = { 0 };		//The number with 5 zeroes at the beginning
char variant2[1005] = { 0 };		//The number that is multiplied by 10000
char number[1005] = { 0 };			//The original number with no modifications
char answer[1005] = { 0 };			//The final answer to output

int main(void) {

	//Start the streams
	ifstream inputFile("times17.in");
	ofstream outputFile("times17.out");

	//Input the number
	inputFile >> number;

	//Add the buffers to the numbers
	sprintf_s(variant1, "00000%s", number);
	sprintf_s(variant2, "0%s0000", number);

	//To find the length, we keep going until we hit null; that is the length
	for (int i = 0; i < 1005; i++) {
		if (variant1[i] == 0) {
			length = i;
			break;
		}
	}

	//Add the numbers
	for (int i = length - 1; i > 0; i--) {

		//Add the value of the characters
		answer[i] += variant1[i] - '0' + variant2[i] - '0';

		//If the answer is more than 2
		if (answer[i] >= 2) {

			//Subtract 2 from that digit
			answer[i] -= 2;

			//Add 1 to the next digit
			answer[i - 1] += 1;
		}

		//Make it back to the regular character
		answer[i] += '0';
	}

	//Start with our integer for our while loop as 0
	int i = 0;

	//If the zeroeth character is 0, then go to the first
	if (answer[0] == 0)
		i = 1;

	//Depending on the zeroeth character, output answer
	while (i < length) {
		outputFile << answer[i];
		i++;
	}
}
