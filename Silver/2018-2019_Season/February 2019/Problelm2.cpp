#include <algorithm>
#include <fstream>
using namespace std;

int N;
int K;
int Barn[1001][1001];

int main() {

	ifstream inputFile("2.in");
	ofstream outputFile("2.out");

  inputFile >> N >> K;

	int x1 = 0;
	int x2 = 0;
	int y1 = 0;
	int y2 = 0;

	for (int i = 0; i <  N; i ++) {
		inputFile >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j < x2; j ++) {
			for (int k = y1; k < y2; k ++) {
				Barn[j][k] += 1;
			}
		}
	}

	int answer = 0;

	for (int i = 0; i <= 1000; i ++) {
		for (int j = 0; j <= 1000; j ++) {
			if (Barn[i][j] == K) {
				answer ++;
			}
		}
	}

  outputFile << answer;

  return 0;

}
