//USACO Bronze Division 2011 November Problem 3 Moo Sick
/* How the program works
	* We have a function that determines if two arrays, only checking a certain length, are equal
	* We import N, notes[], C, and ruminantSeventh[]
	* We sort the ruminantSeventh[] so that we don't worry about reordering
	* We transpose the ruminantSeventh[] starting at 0 so we don't worry about transposing
	* For each index i from 0 to N - C, inclusive
		* We set the possibleRuminant[] with notes[i] to notes[i + C - 1]
		* We sort the possibleRuminant[] so that we don't worry about reordering
		* We transpose the possibleRuminant[] starting at 0 so we don't worry about transposing
		* If the possibleRuminant[] and ruminantSeventh[] are equal:
			* In the ruminantChords[], set the lastIndex's value to be the index of the starting chord
			* Increment the lastIndex by 1
		* Output the lastIndex
		* Output each of the ruminantChords
*/

#include <fstream>
#include <algorithm>
using namespace std;

int N;								//The number of notes
int notes[1000];					//The array of notes
int C;								//The number of notes in the ruminant seventh chord
int ruminantSeventh[10];			//The array of notes in the ruminant seventh chord
int possibleRuminant[10];			//The list of the possibly ruminant chords, each selected from notes[]
int ruminantChords[1000];			//The list of the ruminant chords

//Function to check if two arrays are equal up to a certain length
bool equalArray(int a[], int b[], int length) {
	for (int i = 0; i < length; i++) {

		//If some element in the first is not equal to the same position element in the second, return false
		if (a[i] != b[i])
			return false;
	}

	//If it passes everything, return true
	return true;
}

int main() {

	//Start the streams
	ifstream inputFile("moosick.in");
	ofstream outputFile("moosick.out");

	//Import N
	inputFile >> N;

	//Import the notes
	for (int i = 0; i < N; i++)
		inputFile >> notes[i];

	//Import C
	inputFile >> C;

	//Import the notes in the ruminantSeventh
	for (int i = 0; i < C; i++)
		inputFile >> ruminantSeventh[i];

	//Sort so we don't worry about reordering
	sort(ruminantSeventh, ruminantSeventh + C);

	//Transpose starting at 0 so  we don't worry about transposing
	for (int i = C - 1; i >= 0; i--)
		ruminantSeventh[i] -= ruminantSeventh[0];

	//Start from the lastIndex as 0
	int lastIndex = 0;

	for (int i = 0; i <= N - C; i++) {

		//Set the notes of the possibleRuminant from the array notes[]
		for (int j = 0; j < C; j++)
			possibleRuminant[j] = notes[i + j];

		//Sort so we don't worry about reordering
		sort(possibleRuminant, possibleRuminant + C);

		//Transpose starting at 0 so  we don't worry about transposing
		for (int j = C - 1; j >= 0; j--)
			possibleRuminant[j] -= possibleRuminant[0];

		//If the two arrays are equal
		if (equalArray(possibleRuminant, ruminantSeventh, C)) {

			//Add the chord to ruminantChords
			ruminantChords[lastIndex] = (i + 1);

			//Add 1 to the lastIndex
			lastIndex++;
		}
	}

	//Output the lastIndex
	outputFile << lastIndex << endl;

	//Output each of the ruminantChords
	for (int i = 0; i < lastIndex; i++)
		outputFile << ruminantChords[i] << endl;
}
