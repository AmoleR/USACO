//USACO Bronze Division 2012 January Problem 1 Gifts
/* How the program works
	* We start off with our own version of quicksort which sorts based on:
		1. Sum of elements of a 1000 x 2 array
		2. The first element if sum is same
	* We then first see if we can buy all gifts with no coupons; if so, we output N
	* Otherwise, we sort
	* Then we see if we can buy no gifts, even using the coupon; if so, we output 0
	* If we can only buy the cheapest gift USING the coupon, we output 1
	* Otherwise, we keep adding to our sum the cost; we note the breaking point as almostAnswer
	* If we can apply the coupon, we output almostAnswer + 1
	* If not, we output almostAnswer
*/

#include <iostream>
using namespace std;

int N;                  //Number of Cows
int B;                  //Total Budget
int costs[1000][2];     //Array of Gift and Shipping Costs
int sum;                //Sum of Different Cow's Costs (Used at End)
int almostAnswer;       //Index of "Failed" Sum

//Swapping Function for quicksort; given 2 indeces in 0 <= i, j < N, swap them
void swapme(int a, int b) {
	int t[2];
	t[0] = costs[a][0];
	t[1] = costs[a][1];
	costs[a][0] = costs[b][0];
	costs[a][1] = costs[b][1];
	costs[b][0] = t[0];
	costs[b][1] = t[1];
}

//This is the partitioning in the quicksort. We choose a last element pivot and then we arrange all the numbers with lower total sum or equal sum but lower or equal gift cost before the pivot and everything else after.
int partition(int low, int high) {
	//Choose last element pivot
	int pivot[2];
	pivot[0] = costs[high][0];
	pivot[1] = costs[high][1];

	//Set smallest index of variable that is less than pivot's sum value
	int k = low - 1;

	for (int i = low; i < high; i++) {
		//If sum is less than pivot's total sum
		if (costs[i][0] + costs[i][1] <= pivot[0] + pivot[1]) {
			//If sum is less than pivot's total sum or equal and the cost of the gift is less than or equal to the cost of the pivot
			if (costs[i][0] <= pivot[0] || costs[i][0] + costs[i][1] < pivot[0] + pivot[1]) {
				k++;            //Increment the smallest index
				swapme(i, k);   //Swap the two values. Note that k <= i.
			}
		}
	}

	swapme(k + 1, high);    //Swaps pivot and smallest index
	return (k + 1);         //Returns position of the pivot
}

//This is where we first partition the array based on the last element, break it into 1 or 2 arrays, and keep sorting the remaining arrays until we are done.
void quickSort(int low, int high) {
	//If we have a subarray with length > 1
	if (low < high) {
		//Reorder the elements according to the partition
		int partitionIndex = partition(low, high);

		//Do it for the new sets before and after the partitionIndex
		quickSort(low, partitionIndex - 1);
		quickSort(partitionIndex + 1, high);
	}
}

int main() {
	//Input N and B
	cin >> N >> B;

	for (int i = 0; i < N; i++) {
		//Input the ith value of costs
		cin >> costs[i][0] >> costs[i][1];
	}

	//Sorts the array as described
	quickSort(0, N - 1);

	//Reset the sum counter
	difference = B;

	for (int i = 0; i < N; i++) {

		//If the current difference is negative, we know we have a "critical point"
		if (difference - costs[i][0] - costs[i][1] < 0) {
			//The number of cows (excluding the coupon) is stored in almostAnswer
			almostAnswer = i;

			//Break the loop
			break;
		}

		//The difference minus the new costs
		difference -= costs[i][0] + costs[i][1];
	}

	//We test all values after our breaking point
	for (int i = almostAnswer; i < N; i++) {
		//If applying the coupon keeps it below the budget
		if (B - sum - costs[i][0] / 2 - costs[i][1] >= 0) {

			//Add 1 and print the answer
			cout << almostAnswer + 1;

			//Terminate the loop
			break;
		}

		//If we have exhausted all of our options
		else if (i == N - 1) {
			//Write our answer
			cout << almostAnswer;

			//Break the loop in case
			break;
		}
	}
}
