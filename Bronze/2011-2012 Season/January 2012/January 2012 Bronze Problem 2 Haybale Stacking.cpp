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
using namespace std;

int N;                  //Number of Stacks
int K;                  //Total Instructions

//Swapping Function for quicksort; given 2 indeces in 0 <= i, j < N, swap them
void swapme(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

//This is the partitioning in the quicksort. We choose a last element pivot and then we arrange all the numbers with lower total sum or equal sum but lower or equal gift cost before the pivot and everything else after.
int partition(int array[], int low, int high) {
	//Choose last element pivot
	int pivot = array[high];

	//Set smallest index of variable that is less than pivot's sum value
	int k = low - 1;

	for (int i = low; i < high; i++) {
		//If number is less than pivot
		if (array[i] < pivot) {
			k++;            //Increment the smallest index
			swapme(&array[i], &array[k]);   //Swap the two values. Note that k <= i.
		}
	}

	swapme(&array[k + 1], &array[high]);    //Swaps pivot and smallest index
	return (k + 1);         //Returns position of the pivot
}

//This is where we first partition the array based on the last element, break it into 1 or 2 arrays, and keep sorting the remaining arrays until we are done.
void quickSort(int array[], int low, int high) {
	//If we have a subarray with length > 1
	if (low < high) {
		//Reorder the elements according to the partition
		int partitionIndex = partition(array, low, high);

		//Do it for the new sets before and after the partitionIndex
		quickSort(array, low, partitionIndex - 1);
		quickSort(array, partitionIndex + 1, high);
	}
}

int main() {
	//Input N and B
	cin >> N >> K;

	//Create 2 arrays: Differences array and Final array
	int differencesArray[N + 1];
	int finalArray[N];

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
		differencesArray[a - 1] ++;
		differencesArray[b] --;
	}

	//We are using a as another dummy variable
	a = 0;

	//Create the final array
	for (int i = 0; i < N; i++) {
		a += differencesArray[i];
		finalArray[i] = a;
	}

	//Sort the array
	quickSort(finalArray, 0, N - 1);

	//Print out median
	cout << finalArray[(N - 1) / 2];
}