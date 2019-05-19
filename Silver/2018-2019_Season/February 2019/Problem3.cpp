#include <algorithm>
#include <fstream>
using namespace std;

struct Cow {
  bool same;
  int pasture1;
  int pasture2;
  bool grouped;
};

int M;
int N;
Cow cows[100000];
int pastures[100000];

int main() {

	ifstream inputFile("revegetate.in");
	ofstream outputFile("revegetate.out");

  inputFile >> N >> M;

  char x;
  int y;
  int z;

  bool pastureFill (int pasture1, int pasture2, bool same) {
    if (same) {
      if(pastures[pasture2] != 0 && pastures[pasture2] != pastures[pasture1]) {
        return false;
      }
      pastures[pasture2] = pastures[pasture1];
      return true;
    }
    if(pastures[pasture1] == 1) {
      if (pastures[pasture2] == 1) {
        return false;
      }
      pastures[pasture2] = 2;
      return;
    }
    if (pastures[pasture2] == 2) {
      return false;
    }
    pastures[pasture2] = 1;
    return true;
  }

  for (int i = 0; i < N; i ++) {
    pastures[i] = 0;
  }

  pastures[0] = 1;

  for (int i = 0; i < M; i ++) {
    inputFile >> x >> y >> z;
    if (x == 'S') {
      cows[i].same = true;
    }
    else {
      cows[i].same = false;
    }
    cows[i].pasture1 = min(y, z) - 1;
    cows[i].pasture2 = max(y, z) - 1;
    cows[i].grouped = false;
  }

  pastures[cows[0].pasture1] = 1;



  return 0;

}
