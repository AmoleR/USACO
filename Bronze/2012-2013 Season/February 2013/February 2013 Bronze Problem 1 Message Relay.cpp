//USACO Bronze Division 2013 February Problem 1 Message Relay
/* How the program works:
	* We import N and where each cow points into N and pointerArray
	* We have a recursive function that:
		* Takes input of value
		* If any cow points to that value, increment the answer and find all cows that point to it
	* Call the function for a value of 0
	* Output the answer
*/

#include <iostream>;
using namespace std;

int N;						//The number of cows
int answer;					//The answer
int pointerArray[1000];		//Where each cow points

//Count the number of non-loopy cows
void findNonLoopy(int value) {

	for (int i = 0; i < N; i++) {

		//If the value that the cow points to is the input value
		if (pointerArray[i] == value) {

			//Increase the answer by 1
			answer++;

			//Find all cows that point to that cow's number
			findNonLoopy(i + 1);
		}
	}
}

int main() {
	//Input N
	cin >> N;

	for (int i = 0; i < N; i++) {

		//Input each cow's pointer
		cin >> pointerArray[i];
	}

	//Find the number of non-loopy cows
	findNonLoopy(0);

	//Output the answer
	cout << answer;
}