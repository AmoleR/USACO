//USACO Bronze Division 2013 February Problem 2 Cow Crossings
/* How the program works:
	* We input N and a and b for each cow and store it in N and set occupied[a][b] to true
	* We have a recursive function that requires 2 integers, i and j:
		* If the square is occupied, add 1 to the perimeter and exit the function
		* If it has already been visited, exit the function
		* Set that this place has been visited
		* Do the same for each neighboring square if it is a valid square
	* Call goToHaybale for the point (0, 0)
	* Output the perimeter
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N;						//The number of cows
int perimeter = 0;			//The perimeter, set at 0 currently
bool visited[102][102];		//Boolean array of visited places
bool occupied[102][102];	//Boolean array of the occupied places with haybales

//Find if given i and j, if it is in bounds
int valid(int i, int j) {

	//Return true if each are between -1 and 102
	if (i > -1 && i < 102 && j > -1 && j < 102)
		return true;
	return false;
}

//Recursive function to calculate the number of haybales near each spot; i.e. the perimeter
void goToHaybale(int i, int j) {

	//If it is occupied, add 1 to the perimeter
	if (occupied[i][j]) {
		perimeter++;
		return;
	}

	//If it has been visited, add 1 to the perimeter
	if (visited[i][j])
		return;

	//Say that we have visited the square
	visited[i][j] = true;

	//If the place to the left is valid, check that square
	if (valid(i - 1, j))
		goToHaybale(i - 1, j);

	//If the place to the right is valid, check that square
	if (valid(i + 1, j))
		goToHaybale(i + 1, j);

	//If the place to the top is valid, check that square
	if (valid(i, j - 1))
		goToHaybale(i, j - 1);

	//If the place to the bottom is valid, check that square
	if (valid(i, j + 1))
		goToHaybale(i, j + 1);
}

int main() {

	//Input N
	cin >> N;

	//Create dummy variables a and b
	int a = 0;
	int b = 0;

	for (int i = 0; i < N; i++) {
		//Import a and b and set that square as true
		cin >> a >> b;
		occupied[a][b] = true;
	}

	//Find the perimeter from (0, 0)
	goToHaybale(0, 0);

	//Output the perimeter
	cout << perimeter;
}