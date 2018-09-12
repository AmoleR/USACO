//USACO Bronze Division 2012 January Problem 1 Gifts
/* How the program works
	* Otherwise, we sort
	* Then we see if we can buy no gifts, even using the coupon; if so, we output 0
	* If we can only buy the cheapest gift USING the coupon, we output 1
	* Otherwise, we keep adding to our sum the cost; we note the breaking point as almostAnswer
	* If we can apply the coupon, we output almostAnswer + 1
	* If not, we output almostAnswer
*/

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

struct cost {
	float gift, shipping;
};

int N;                  //Number of Cows
int B;                  //Total Budget
cost costs[1000];		//Array of Gift and Shipping Costs
int almostAnswer;       //Index of "Failed" Sum

//Comparison for gifts
bool comparisonInterval(cost i, cost j) {

	//If the total cost is less or equal but have a less than or equal to gift value
	if (i.gift + i.shipping < j.gift + j.shipping || (i.gift + i.shipping == j.gift + j.shipping && i.gift <= j.gift))
		return true;
	return false;
}

int main() {
	//Input N and B
	cin >> N >> B;

	//Difference Between Budget and Different Cow's Costs (Used at End)
	float difference;

	for (int i = 0; i < N; i++) {
		//Input the ith value of costs
		cin >> costs[i].gift >> costs[i].shipping;
	}

	//Sorts the array as described
	sort(costs, costs + N, comparisonInterval);

	//Reset the sum counter
	difference = B;

	for (int i = 0; i < N; i++) {

		//If the current difference is negative, we know we have a "critical point"
		if (difference - costs[i].gift - costs[i].shipping < 0) {
			//The number of cows (excluding the coupon) is stored in almostAnswer
			almostAnswer = i;

			//Break the loop
			break;
		}

		//The difference minus the new costs
		difference -= costs[i].gift + costs[i].shipping;
	}

	//We test all values after our breaking point
	for (int i = almostAnswer; i < N; i++) {
		//If applying the coupon keeps it below the budget
		if (difference - costs[i].gift / 2 - costs[i].shipping >= 0) {

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
