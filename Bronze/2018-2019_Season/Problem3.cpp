#include <algorithm>
#include <fstream>
using namespace std;

int barnOne [11];
int barnTwo [11];
int newBarnOne [11];
int newBarnTwo [11];
int values [12100];
int barnOneSum = 0;
int barnTwoSum = 0;

struct position {
  int Tuesday;
  int Wednesday;
  int Thursday;
  int Friday;
};

void permutation (position identify) {
  newBarnTwo [10] = newBarnOne [identify.Tuesday];
  newBarnOne [identify.Tuesday] = newBarnOne [9];
  newBarnOne [9] = 0;
  newBarnOne [9] = newBarnTwo[identify.Wednesday];
  newBarnTwo [identify.Wednesday] = newBarnTwo [10];
  newBarnTwo [10] = 0;
  newBarnTwo [10] = newBarnOne [identify.Thursday];
  newBarnOne [identify.Thursday] = newBarnOne [9];
  newBarnOne [9] = 0;
  newBarnOne [9] = newBarnTwo[identify.Friday];
  newBarnTwo [identify.Friday] = newBarnTwo [10];
  newBarnTwo [10] = 0;
  return;
}

int main() {

	ifstream inputFile("backforth.in");
	ofstream outputFile("backforth.out");

  for(int i = 0; i < 10; i ++) {
    inputFile >> barnOne [i];
    barnOneSum += barnOne [i];
  }

  for(int i = 0; i < 10; i ++) {
    inputFile >> barnTwo [i];
    barnTwoSum += barnTwo [i];
  }

  position identify;
  identify.Tuesday = 0;
  identify.Wednesday = 0;
  identify.Thursday = 0;
  identify.Friday = 0;

  int numbers = 0;
  int reading = 0;

  while (identify.Tuesday < 10) {
    int newBarnOneSum = 0;
    for (int i = 0; i < 10; i ++){
      newBarnOne[i] = barnOne[i];
      newBarnTwo[i] = barnTwo[i];
    }

    permutation (identify);

    for(int i = 0; i < 10; i ++) {
      newBarnOneSum += newBarnOne[i];
    }

    reading = newBarnOneSum - barnOneSum;

    if (numbers == 0) {
      values[0] = reading;
      numbers ++;
    }

    for (int i = 0; i < numbers; i ++) {
      if(reading == values[i]) {
        break;
      }
      if (i == numbers - 1) {
        values [i + 1] = reading;
        numbers ++;
      }
    }

    identify.Friday ++;

    if(identify.Friday > 10) {
      identify.Friday -= 11;
      identify.Thursday += 1;
    }
    if(identify.Thursday > 9) {
      identify.Thursday -= 10;
      identify.Wednesday += 1;
    }
    if(identify.Wednesday > 10) {
      identify.Wednesday -= 11;
      identify.Tuesday += 1;
    }
  }

	outputFile << numbers;

}
