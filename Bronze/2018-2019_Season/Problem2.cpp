#include <algorithm>
#include <fstream>
using namespace std;

struct cow {
  int startTime;
  int endTime;
  int noOfBuckets;
};

int N;
cow cows [100];
int criticalTimes [200];
int bucketNumbers = 0;

bool compareCows (cow cow1, cow cow2) {
  return (cow1.startTime < cow2.startTime);
}

int analyzeAtTime (int time) {
  int newBuckets = 0;
  for (int i = 0; i < N; i ++) {
    if(cows[i].startTime > time) {
      return newBuckets;
    }
    if(cows[i].endTime >= time) {
      newBuckets += cows[i].noOfBuckets;
    }
  }
  return newBuckets;
}

int main() {

	ifstream inputFile("blist.in");
	ofstream outputFile("blist.out");

	inputFile >> N;

  for (int i = 0; i < N; i ++) {
    inputFile >> cows[i].startTime >> cows[i].endTime >> cows[i].noOfBuckets;
  }

  sort (cows, cows + N, compareCows);

  bucketNumbers = cows[0].noOfBuckets;

  for (int i = 0; i < N; i ++) {
    bucketNumbers = max(analyzeAtTime(cows[i].startTime), bucketNumbers);
    bucketNumbers = max(analyzeAtTime(cows[i].endTime + 1), bucketNumbers);
  }

	outputFile << bucketNumbers;

}
