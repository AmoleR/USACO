//USACO Bronze Division 2012 January Problem 1 Gifts
/* How the program works
	* We have a struct of costs consisting of the gift and shipping costs
	* We sort the array of costs
	* Then we see if we can buy no gifts, even using the coupon; if so, we output 0
	* If we can only buy the cheapest gift USING the coupon, we output 1
	* Otherwise, we keep adding to our sum the cost; we note the breaking point as almostAnswer
	* We store the maximum value of half the maximum gift cost in maximumDifferenceWithCouponAppliedBefore
	* If we can apply the coupon, we output almostAnswer + 1
	* If applying the coupon before allows us to add one more gift, we output almostAnswer + 1
	* If not, we output almostAnswer
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct cost {
	int gift, shipping;
};

int N;                  //Number of Cows
int B;                  //Total Budget
cost costs[1000];		//Array of Gift and Shipping Costs
int difference;			//Difference Between Budget and Different Cow's Costs (Used at End)
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

	for (int i = 0; i < N; i++) {
		//Input the ith value of costs
		cin >> costs[i].gift >> costs[i].shipping;
	}

	//Sorts the array as described
	sort(costs, costs + N, comparisonInterval);

	//Reset the sum counter
	difference = B;

	//Maximum Difference when we apply the coupon before we go to the second loop
	int maximumDifferenceWithCouponAppliedBefore = 0;

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

		//If the gift cost over 2 is greater than the previous maximum, rewrite it as the new maximum
		if (costs[i].gift / 2 > maximumDifferenceWithCouponAppliedBefore)
			maximumDifferenceWithCouponAppliedBefore = costs[i].gift / 2;
	}

	//We test all values after our breaking point
	for (int i = almostAnswer; i < N; i++) {
		//If applying the coupon keeps it below the budget
		if (difference - costs[i].gift / 2 - costs[i].shipping >= 0) {
			
			//Add 1 to the answer
			almostAnswer ++;

			//Terminate the loop
			break;
		}

		//If we can apply the coupon before but still have positive difference
		if (difference + maximumDifferenceWithCouponAppliedBefore - costs[i].gift - costs[i].shipping >= 0) {

			//Add 1 to the answer
			almostAnswer ++;

			//Terminate the loop
			break;
		}
	}
	
	//Print the answer
	cout << almostAnswer;
}
