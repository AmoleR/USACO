#include <algorithm>
#include <fstream>
using namespace std;

struct areaType {
  int area;
  int perimeter;
  int value;
};

int N;
int blobShapes[1000][1000];
areaType areas[1000000];
int perimeter;
int ones = 0;

int finishBlob (int number, int x, int y) {
  if(x < 0 || x >= N || y < 0 || y >= N) {
    return 0;
  }
  if (blobShapes[x][y] == 0) {
    return 0;
  }
  int sum = 1;
  blobShapes[x][y] = number;
  sum += finishBlob(number, x + 1, y);
  sum += finishBlob(number, x - 1, y);
  sum += finishBlob(number, x, y + 1);
  sum += finishBlob(number, x, y - 1);
}

int renumber(int start) {
  if (ones == 0) {
    return 0;
  }
  int x = 0;
  int y = 0;
  for(int i = 0; i < N; i ++ ){
    for (int j = 0; j < N; j ++) {
      if(blobShapes[i][j] == 1) {
        x = i;
        y = j;
      }
    }
    if (i == N - 1) {
      return 0;
    }
  }
  int temporary = finishBlob(start, x, y);
  areas[start].area = temporary;
  areas[start].value = start;
  ones -= temporary;
  return renumber(start + 1) + 1;
}

int neighbors(int value, int i, int j) {
  int neighbor = 0;
  if (i > 0 && blobShapes[i - 1][j] == value) {
    neighbor ++;
  }
  if (j > 0 && blobShapes[i][j - 1] == value) {
    neighbor ++;
  }
  if (i < N - 1 && blobShapes[i + 1][j] == value) {
    neighbor ++;
  }
  if (j < N - 1 && blobShapes[i][j + 1] == value) {
    neighbor ++;
  }
  return neighbor;
}

int perimeters (int amount) {
  perimeter = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (blobShapes[i][j]) {
        perimeter += (4 - neighbors(amount, i ,j));
      }
    }
  }
  return perimeter;
}

bool compareInterval (areaType area1, areaType area2) {
  return (area1.area > area2.area);
}

int main() {

	ifstream inputFile("1.in");
	ofstream outputFile("1.out");

  inputFile >> N;

  char temp[1000];

  for(int i = 0; i < N; i ++ ) {
    inputFile >> temp;
    for (int j = 0; j < N; j ++ ) {
      if(temp[j] == '#') {
        blobShapes[i][j] = 1;
        ones ++;
      }
      else {
        blobShapes[i][j] = 0;
      }
    }
  }

  int maxNumber = renumber(2);

  sort(areas, areas + maxNumber, compareInterval);

  int workingIndeces = 0;

  outputFile << areas[i].area << ' ';

  for (int i = 1; i < maxNumber; i++) {
    if(areas[i].area != areas[0].area) {
      workingIndeces = i;
      break;
    }
  }

  int minPerimeter = perimeters(areas[0].value + 2);

  for(int i = 1; i < workingIndeces; i++) {
    maxNumber = perimeter(areas[i].value + 2);
    if(maxNumber < minPerimeter) {
      minPerimeter = maxNumber;
    }
  }

  outputFile << minPerimeter;

  return 0;

}
