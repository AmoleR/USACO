//USACO Bronze Division 2012 January Problem 2 Haybale Stacking
/* How the program works
	* Input N and K
	* Create an array of "differences" between consecutive elements
	* When we have 2 numbers, a and b, imported, we:
		* Add 1 to the ath position
		* Subtract 1 from (b + 1)th position
	* Once done, create a final array of the number of haybales in each stack
	* Sort the final array with quicksort
	* Find the middle number
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N;							//Number of Stacks
int K;						    //Total Instructions
int differencesArray[1000001];	//Array of differences
int finalArray[1000000];		//Final Haybale Array

int main() {
	//Input N and K
	cin >> N >> K;

	//Clear value of differencesArray
	for (int i = 0; i <= N; i++) {
		differencesArray[i] = 0;
	}

	//Create 2 dummy variables
	int a;
	int b;

	//Input values for differencesArray
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		differencesArray[a - 1] = differencesArray[a - 1] + 1;
		differencesArray[b] = differencesArray[b] - 1;
	}

	//We are using a as another dummy variable
	a = 0;

	//Create the final array
	for (int i = 0; i < N; i++) {
		a = a + differencesArray[i];
		finalArray[i] = a;
	}

	//Sorts the first N elements of the finalArray
	sort(finalArray, finalArray + N);

	//Print out median
	cout << finalArray[(N - 1) / 2];
}
