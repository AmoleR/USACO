#include <algorithm>
#include <fstream>
using namespace std;

struct mountain {
  int x1;
  int x2;
  int value;
};

int N;
mountain mountains[10000];

int compareInterval1 (mountain mountain1, mountain mountain2) {
  return (mountain1.x1 < mountain2.x1);
}

int compareInterval2 (mountain mountain1, mountain mountain2) {
  return (mountain1.x2 < mountain2.x2);
}

int main() {

	ifstream inputFile("3.in");
	ofstream outputFile("3.out");

  mountain temporary;

  inputFile >> N;

  for (int i = 0; i < N; i ++) {
    inputFile >> temporary.x1 >> temporary.x2;
    mountains[i].x1 = temporary.x1 + temporary.x2;
    mountains[i].x2 = temporary.x1 - temporary.x2;
  }

  sort(mountains, mountains + N, compareInterval1);

  int totalNumber = N;

  for(int i = 0; i < N; i ++) {
    for (int j = 0; j < i; j ++) {
      if(mountains[j].x2 > mountains[i].x2) {
        totalNumber --;
        break;
      }
    }
  }

  outputFile << totalNumber;

  return 0;

}
