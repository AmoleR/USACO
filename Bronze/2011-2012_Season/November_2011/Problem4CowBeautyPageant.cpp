//USACO Bronze Division 2011 November Problem 4 Cow Beauty Pageant
/* How the program works:
	* We have a function that creates a patch of twos from two patches of one by:
		* Taking input of something that is in one patch
		* Changing it to two
		* Finding all others surrounding it
	* We have a function that makes every 0 surrounding a patch of twos to a three
		* Taking the input of something that is in the patch of twos
		* Set that the point is visited
		* Finding all zeroes surrounding it and setting the value to three
		* Doing the process for all neighboring twos
	* We have a function that clears the visited array and sets the 3s as 2s
	* We have a recursive BFS floodfill algorithm to solve the problem
		* We first add the 3s around the patch
		* We change it to twos and reset the visited array
		* For each point in the grid that is filled, if it is next to a one, return 1
		* If no such point exists, do the same thing again
	* We first import N and M
	* In a character array of maximum length 50, we store the line
	* For each character, we associate a '1' to the X and a '0' to the .
	* Then, we change one patch of 1's to 2's
	* Then, we output the answer given by the recursiveFloodFill
*/

#include <fstream>
using namespace std;

int N;						//Number of Rows
int M;						//Number of Columns
int cowhide[50][50];		//The cowhide pattern
bool visited[50][50];		//Visited points on the cowhide pattern
int twoPatternX = -1;		//One coordinate of a point on the patch of twos
int twoPatternY = -1;		//The other coordinate of the point on the patch of twos

//A recursive function to switch one patch of ones to a patch of twos
void doChange(int a, int b) {

	//If we are not on a '1', exit
	if (cowhide[a][b] != 1)
		return;

	//Set the value of the point as 2
	cowhide[a][b] = 2;

	//If we are inbounds, check the point to above
	if (a != 0)
		doChange(a - 1, b);

	//If we are inbounds, check the point to below
	if (a != N - 1)
		doChange(a + 1, b);

	//If we are inbounds, check the point to the left
	if (b != 0)
		doChange(a, b - 1);

	//If we are inbounds, check the point to the right
	if (b != M - 1)
		doChange(a, b + 1);
}

//A recursive function to surround a patch of twos with neighboring threes
void addNumbers(int c, int d) {

	//If we are inbounds
	if (c >= 0 && c < N && d >= 0 && d < M) {

		//If we have visited this point, exit
		if (visited[c][d])
			return;

		//If this is a 0, set it to 3 and exit
		if (cowhide[c][d] == 0) {
			cowhide[c][d] = 3;
			return;
		}

		//If this is a 2
		else if (cowhide[c][d] == 2) {

			//Say the point is visited
			visited[c][d] = true;

			//Add it in all 4 directions
			addNumbers((c - 1), d);
			addNumbers((c + 1), d);
			addNumbers(c, (d - 1));
			addNumbers(c, (d + 1));
		}
	}
}

//Function to clear the visited array and make all 3s as 2s
void clearThreesAndVisited() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			//If we are on a 3, make it a 2
			if (cowhide[i][j] == 3)
				cowhide[i][j] = 2;

			//If we have that we have visited this point, reset it
			if (visited[i][j])
				visited[i][j] = false;
		}
	}
}

//This is a recursive function that adds numbers around the patch of 2 until it touches the patch of 1
int recursiveFloodFill() {

	//Add numbers around the patch of twos
	addNumbers(twoPatternX, twoPatternY);

	//Clear the visited array and the threes
	clearThreesAndVisited();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			//If we have a 2 next to a 1, return 1
			if (cowhide[i][j] == 2) {
				if (cowhide[i - 1][j] == 1 || cowhide[i + 1][j] == 1 || cowhide[i][j - 1] == 1 || cowhide[i][j + 1] == 1) {
					return 1;
				}
			}
		}
	}

	//Otherwise, the answer is 1 more than what happens when we do it again
	return (recursiveFloodFill() + 1);
}

int main() {

	//Start the streams
	ifstream inputFile("pageant.in");
	ofstream outputFile("pageant.out");

	//Import N and M
	inputFile >> N >> M;

	//Initialize a character array
	char a[50];

	for (int i = 0; i < N; i++) {

		//Import the string into the character array
		inputFile >> a;
		for (int j = 0; j < M; j++) {

			//If we have an X, set it as a 1
			if (a[j] == 'X')
				cowhide[i][j] = 1;

			//Otherwise, set it as a 0
			else
				cowhide[i][j] = 0;
		}
	}

	//By looping through the entire grid, find where we have a 1
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			//If the coordinates have a value of 1, set them as twoPatternX and twoPatternY and exit the loop
			if (cowhide[i][j] == 1) {
				twoPatternX = i;
				twoPatternY = j;
				break;
			}
		}

		//If the twoPatternX value is not the default, exit this loop too
		if (twoPatternX != -1)
			break;
	}

	//Change one patch of 1's to 2's
	doChange(twoPatternX, twoPatternY);

	//Print out the answer from our recursive function
	outputFile << recursiveFloodFill();
}
