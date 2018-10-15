//USACO Bronze Division 2012 March Problem 2 Connect the Cows
/* How the program works:
	* We have a basic struct that stores an x-position and a y-position
	* A small tweak is that the first cow is always at (0, 0) as well as the last cow
	* Once we input N and each of the cows coordinates, we use a recursive checkReordering that
		* Takes an input n to be the current index. Originally passed as 0
		* Initializes an answer with value 0
		* For every integer between the number of cows and the current index, we need to set the permutation array with the cow number
		* We need to swap the ith cow with the nth cow from the back
		* Find the add the number given by checking with the n+1th index
		* Swap them back
		* If n and N are equal
			* If there is no way to get from one cow to the next, return 0
			* If there is no direction change, return 0
			* If it satisfies both values, then return 1
	* We have a very simple direction function that returns 0 if it is not possible and another integer depending on the relative locations
*/

#include <algorithm>
#include <fstream>
using namespace std;

//A struct with each cow's x value and y value
struct position {
	int xPosition;
	int yPosition;
};

int N;																//The number of cows
position cows[12];													//An array of positions
int alreadyDone[12] = { 0 };										//The order of cows in the permutation
int cowsLeft[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };				//A list of cows as well that helps with finding the order of the cows

//Function to convert angle changed into an integer
int direction(int i, int j) {

	//If it is not possible, return 0
	if (cows[i].xPosition != cows[j].xPosition && cows[i].yPosition != cows[j].yPosition)
		return 0;

	//If the second cow is above the first, return 1
	else if (cows[i].xPosition == cows[j].xPosition && cows[i].yPosition < cows[j].yPosition)
		return 1;

	//If the second cow is below the first, return 2
	else if (cows[i].xPosition == cows[j].xPosition && cows[i].yPosition > cows[j].yPosition)
		return 2;

	//If the second cow is to the right of the first, return 3
	else if (cows[i].xPosition < cows[j].xPosition && cows[i].yPosition == cows[j].yPosition)
		return 3;

	//If the second cow is to the left of the first, return 4
	else if (cows[i].xPosition > cows[j].xPosition && cows[i].yPosition == cows[j].yPosition)
		return 4;
}

//Recursive function to find the total number of ways
int checkReordering(int n) {

	//Initialize an answer
	int answer = 0;

	//If we are already at N
	if (n == N) {

		//If we can not go from one cow to the next or do not turn at a cow, return 0
		for (int i = 1; i <= N; i++) {
			if (direction(alreadyDone[i], alreadyDone[i - 1]) == direction(alreadyDone[i + 1], alreadyDone[i]) || direction(alreadyDone[i], alreadyDone[i - 1]) == 0)
				return 0;
		}

		//If we can not go from the second last cow to the last cow, return 0
		if (direction(alreadyDone[N + 1], alreadyDone[N]) == 0)
			return 0;

		//If it passes both tests, return 1
		return 1;
	}
	//For each i between 0 and N - n
	for (int i = 0; i < N - n; i++) {
		//Store the nth value of the permutation as the ith value of cowsLeft
		alreadyDone[n + 1] = cowsLeft[i];

		//Swap the ith and (N - n - 1)th position of cowsLeft
		swap(cowsLeft[i], cowsLeft[N - n - 1]);

		//Do it once again recursively going down an index
		answer += checkReordering(n + 1);

		//Swap the ith and (N - n - 1)th position again to reset
		swap(cowsLeft[i], cowsLeft[N - n - 1]);
	}

	//Return the answer
	return answer;
}

int main() {

	//Start the streams
  ifstream inputFile("connect.in");
	ofstream outputFile("connect.out");

	//Import N
	inputFile >> N;

	//Import each cow's x and y position
	for (int i = 1; i <= N; i++)
		inputFile >> cows[i].xPosition >> cows[i].yPosition;

	//Output the number of total ways starting with index 0, cowsLeft[i] = i, and alreadyDone[i] = 0
	outputFile << checkReordering(0);
}
