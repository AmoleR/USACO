//USACO Bronze Division 2013 November Problem 1 Contest Timing
/* How the program works:
	* We have a function that:
		* Takes input of number of days, hours, and minutes
		* Sets a constant to be the number of minutes since November 11 at 11:11 A.M.
			* Does (days - 11) to get number of days, multiplies by 1440 to get it in terms of minutes
			* Does (hours - 11) to get number of hours, multiplies by 60 to get it in terms of minutes
			* Does (minutes - 11) to get number of minutes
		* If this is nonnegative, return time
		* Otherwise, return -1
	* Use this function on the imported values of days, hours, and minutes
*/

#include <iostream>
using namespace std;

int D;		//Number of Days
int H;		//Number of Hours
int M;		//Number of Minutes

//Function to determine time since November 11 at 11:11 AM
int timeSinceStart(int day, int hour, int minute) {

	//Set time, the constant, to be the time as described above
	int time = ((day - 11) * 1440 + (hour - 11) * 60 + minute - 11);

	//If it is nonnegative, return the value of the time
	if (time >= 0)
		return time;

	//Otherwise, return -1
	return -1;
}

int main() {

	//Input D, H, and M
	cin >> D >> H >> M;

	//Print out the time since November 11 at 11:11 AM using our function
	cout << timeSinceStart(D, H, M);
}