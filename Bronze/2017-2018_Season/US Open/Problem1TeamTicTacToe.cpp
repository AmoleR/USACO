#include <fstream>
using namespace std;

char row11;
char row12;
char row13;
char row21;
char row22;
char row23;
char row31;
char row32;
char row33;

int main() {
  //Start the streams
	ifstream inputFile("tttt.in");
	ofstream outputFile("tttt.out");

  inputFile >> row11;
  inputFile >> row12;
  inputFile >> row13;
  inputFile >> row21;
  inputFile >> row22;
  inputFile >> row23;
  inputFile >> row31;
  inputFile >> row32;
  inputFile >> row33;

  //Part 1: Individual Cows
  int answer = 0;
  if(row11 == row12 && row12 == row13) {
      answer ++;
  }
  if(row21 == row22 && row22 == row23) {
      answer ++;
  }
  if(row31 == row22 && row22 == row33) {
      answer ++;
  }
  if(row11 == row21 && row21 == row31) {
      answer ++;
  }
  if(row12 == row22 && row22 == row22) {
      answer ++;
  }
  if(row13 == row23 && row23 == row33) {
      answer ++;
  }
  if(row11 == row22 && row22 == row33) {
      answer ++;
  }
  if(row13 == row22 && row22 == row31) {
      answer ++;
  }
  outputFile << answer << endl;

  //Part 2: Teams
  answer = 0;
  if((row11 == row12 || row12 == row13 || row11 == row13) && (!(row11 == row12 && row11 == row13))) {
      answer ++;
  }
  if((row21 == row22 || row22 == row23 || row21 == row23) && (!(row21 == row22 && row21 == row23))) {
      answer ++;
  }
  if((row31 == row32 || row32 == row33 || row31 == row33) && (!(row31 == row32 && row31 == row33))) {
      answer ++;
  }
  if((row11 == row21 || row11 == row31 || row21 == row31) && (!(row11 == row21 && row11 == row31))) {
      answer ++;
  }
  if((row12 == row22 || row11 == row32 || row22 == row32) && (!(row12 == row22 && row12 == row32))) {
      answer ++;
  }
  if((row13 == row23 || row13 == row33 || row23 == row33) && (!(row13 == row23 && row13 == row33))) {
      answer ++;
  }
  if((row11 == row22 || row11 == row33 || row22 == row33) && (!(row11 == row22 && row11 == row33))) {
      answer ++;
  }
  if((row13 == row22 || row13 == row31 || row22 == row31) && (!(row13 == row22 && row13 == row31))) {
      answer ++;
  }
  outputFile << answer;
}
