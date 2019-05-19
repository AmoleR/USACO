#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

int N;
vector<int> cows;
vector<int> cows2;

void min() {
  bool start = true;
  if (cows2.at(1) - cows2.at(0) < cows2.at(N - 1) - cows2.at(N - 2)) {
    start = false;
  }
  int smallestIndex = 0;
  int minimum = 1000000;
  for (int i = 1; i < N - 2; i ++) {
    if ((cows2.at(i + 1) - cows2.at(i)) < minimum && cows2.at(i + 1) - cows2.at(i) != 1) {
      minimum = cows2.at(i + 1) - cows2.at(i);
      smallestIndex = i;
    }
  }
  cows2.pop_back();
  minimum = cows2.at(smallestIndex) + 1;
  cows2.insert(cows2.begin() + smallestIndex + 1, minimum);
}

int max () {
  return 0;
}

int main() {

	ifstream inputFile("1.in");
	ofstream outputFile("1.out");

  inputFile >> N;

  int x;

  for (int i = 0; i < N; i ++) {
    inputFile >> x;
    cows.push_back(x);
  }

  sort (cows.begin(), cows.end());

  cows2 = cows;

  int minimum = 0;

  while (cows2.end() - cows2.begin() > N) {
    min();
    minimum ++;
  }

  outputFile << minimum;

  return 0;

}
