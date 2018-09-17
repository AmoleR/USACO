//USACO Bronze Division 2013 February Problem 2 Cow Crossings
/* How the program works:
	* We have a struct of cow that consists of the a value, b value, and the index
	* We input N and a and b for each cow and store it in N and crossings[i].a and crossings[i].b
	* We sort based on the a value
	* We set the index to the position in the new array
	* We sort based on the b value
	* We have our answer as 0 and largestIndex as -1
	* For each index i in the new array
		* If the index is the same in both arrays
		* If there are no numbers larger than that index before it
		* Add 1 to the answer
		* Set the largestIndex as the maximum of the index and largestIndex
	* Output the answer
*/

#include <iostream>
#include <algorithm>
using namespace std;

//Our struct containing a, b, and index
struct cow {
	int a;
	int b;
	int index;
};

int N;					//Number of Cows
cow crossings[100000];	//Array of cow and their values
int answer = 0;			//Answer as 0
int largestIndex = -1;	//Largest Current Index is -1

//Comparison Interval Based on the value of a
bool compareIntervalA(cow i, cow j) {

	//Return whatever i.a < j.a gives us
	return i.a < j.a;
}

//Comparison Interval Based on the value of b
bool compareIntervalB(cow i, cow j) {

	//Return whatever i.b < j.b gives us
	return i.b < j.b;
}

int main() {
	
	//Input N
	cin >> N;

	for (int i = 0; i < N; i++) {

		//Input each value of the crossing
		cin >> crossings[i].a >> crossings[i].b;
	}

	//Sort based on highest a
	sort(crossings, crossings + N, compareIntervalA);

	//Set the index as the current value
	for (int i = 0; i < N; i++) {
		crossings[i].index = i;
	}

	//Sort based on highest b
	sort(crossings, crossings + N, compareIntervalB);

	for (int i = 0; i < N; i++) {
		//If the index is the same and largest Index is the previous value
		if (crossings[i].index == i && largestIndex == i - 1) {

			//Increment the answer by 1
			answer++;
		}

		//Find the larger of the two values
		largestIndex = max(largestIndex, crossings[i].index);
	}
	
	//Output the answer
	cout << answer;
}