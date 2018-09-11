//USACO Bronze Division 2012 January Problem 3 Grazing Patterns
/* How the program works
	* We start by inputing K
	* We then set all values of the grassArea array as false; meaning they have grass
	* We then call selfNonIntersectingWalks, which:
		* Is a recursive sequence based on 2 starting coordinates and the number of remaining grass
		* We define a variable to return
		* If we are out of bounds or at (5, 5) but have > 1 remaining square, we return 0
		* If we are at (5, 5) but have only 1 remaining square, we return 1
		* If we are on a barren square, we return 1
		* Otherwise, it is the sum of the 4 other directions we can go
		* Return our count
	* We print our answer, selfNonIntersectingWalks(0, 0, (25 - K)), which is the number of self-nonintersecting walks from (1, 1) with (25 - K) non-barren squares
*/

#include <iostream>
using namespace std;

int K;                  //Number of Illegal Positions
bool grassArea[5][5];	//Total Grass Area

//Create a function to recursively count self-nonintersecting walks on this 5x5 board
int selfNonIntersectingWalks(int start1, int start2) {
	//Variable to return
	int count;

	//Make sure we are in bounds. If not, we return 0.
	if (0 > start1 || 4 < start1 || 0 > start2 || 4 < start2) {
		return 0;
	}

	//If we are at (5, 5), return 1 only if there are no remaining squares
	if (start1 == 4 && start2 == 4) {
		if (K == 24) {
			return 1;
		}
		return 0;
	}

	//Make sure we are not on a barren square
	if (grassArea[start1][start2] == true) {
		return 0;
	}

	//First, we put this square we are on as barren
	grassArea[start1][start2] = true;

	//We increment the number of barren lands by 1
	K++;

	//Otherwise, we have satisfied all conditions so far. Now, what we need to do is to do the recursion.

	//We do the recursive sum
	count = selfNonIntersectingWalks(start1 - 1, start2) + selfNonIntersectingWalks(start1 + 1, start2) + selfNonIntersectingWalks(start1, start2 - 1) + selfNonIntersectingWalks(start1, start2 + 1);

	//Reset back to normal square
	grassArea[start1][start2] = false;

	//We decrease the number of barren lands by 1
	K--;

	//Return the value
	return count;
}

int main() {
	//Input K
	cin >> K;

	//Set each part of the grass to false as a default
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			grassArea[i][j] = false;
		}
	}

	//Dummy variables a and b for input
	int a = 0;
	int b = 0;

	//Set the barren lands with a code of true
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		grassArea[a - 1][b - 1] = true;
	}

	//Print a self-nonintersecting walk from (1,  1) to (5, 5)
	cout << selfNonIntersectingWalks(0, 0);
}
