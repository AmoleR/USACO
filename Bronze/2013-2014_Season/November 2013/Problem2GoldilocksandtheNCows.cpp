//USACO Bronze Division 2013 November Problem 2 Goldilocks and the N Cows

#include <fstream>
#include <algorithm>
using namespace std;

struct cowPreference {
  int A;
  int B;
};

int N;
int X;
int Y;
int Z;
cowPreference tempRange[20000];
int interestingTemps[40000];

int removeDuplicates(int arr[], int n)
{
    if (n == 0 || n == 1)
        return n;

    // To store index of next unique element
    int j = 0;

    // Doing Novembesame as done in Method 1
    // Just maintaining another updated index i.e. j
    for (int i = 0; i < n - 1; i++)
        if (arr[i] != arr[i + 1])
            arr[j ++] = arr[i];

    arr[j ++] = arr[n - 1];

    return j;
}

int main() {
  //Start the streams
	ifstream inputFile("milktemp.in");
	ofstream outputFile("milktemp.out");
  inputFile >> N >> X >> Y >> Z;
  for(int i = 0; i < N; i++) {
    inputFile >> tempRange[i].A >> tempRange[i].B;
    interestingTemps[2 * i] = tempRange[i].A;
    interestingTemps[2 * i + 1] = tempRange[i].B;
  }
  sort(interestingTemps, interestingTemps + 2 * N);
  int length = removeDuplicates(interestingTemps, 2 * N);
  int maxMilk = -1;
  int milk = 0;
  for(int i = 0; i < length; i++) {
    for(int j = 0; j < N; j ++) {
      if(tempRange[j].A > interestingTemps[i]) {
        milk += X;
      }
      else if(tempRange[j].B < interestingTemps[i]) {
        milk += Z;
      }
      else {
        milk += Y;
      }
    }
    maxMilk = max(milk, maxMilk);
    milk = 0;
  }
  outputFile << maxMilk;
}
