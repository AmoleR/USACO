#include <algorithm>
#include <fstream>
using namespace std;

int cOne [101];
int cTwo [101];
int cThree [101];
int mOne;
int mTwo;
int mThree;

void swapMilk(int pos) {
  if (pos % 3 == 0) {
    cThree[pos + 1] = cThree[pos];
    if(cOne[pos] + cTwo[pos] <= mTwo) {
      cOne[pos + 1] = 0;
      cTwo[pos + 1] = cOne[pos] + cTwo[pos];
      return;
    }
    cOne[pos + 1] = cOne[pos] + cTwo[pos] - mTwo;
    cTwo[pos + 1] = mTwo;
    return;
  }
  if (pos % 3 == 1) {
    cOne[pos + 1] = cOne[pos];
    if(cTwo[pos] + cThree[pos] <= mThree) {
      cTwo[pos + 1] = 0;
      cThree[pos + 1] = cTwo[pos] + cThree[pos];
      return;
    }
    cTwo[pos + 1] = cTwo[pos] + cThree[pos] - mThree;
    cThree[pos + 1] = mThree;
    return;
  }
  if (pos % 3 == 2) {
    cTwo[pos + 1] = cTwo[pos];
    if(cThree[pos] + cOne[pos] <= mOne) {
      cThree[pos + 1] = 0;
      cOne[pos + 1] = cThree[pos] + cOne[pos];
      return;
    }
    cThree[pos + 1] = cThree[pos] + cOne[pos] - mOne;
    cOne[pos + 1] = mOne;
    return;
  }
  return;
}

int main() {

	ifstream inputFile("mixmilk.in");
	ofstream outputFile("mixmilk.out");

	inputFile >> mOne >> cOne[0] >> mTwo >> cTwo[0] >> mThree >> cThree[0];

  for (int i = 0; i < 100; i++) {
    swapMilk(i);
  }

	outputFile << cOne[100] << endl << cTwo[100] << endl << cThree[100] << endl;

  return 0;

}
