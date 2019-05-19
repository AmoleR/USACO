#include <fstream>
using namespace std;

struct Node {
  int dirconn
};

int N;
Node *nodes[100001];

int main() {
  cin >> N;

  int j = 0;
  int k = 0;

  for (int i = 1; i <= N; i++) {
    nodes[i] = new Node;
    nodes[i]->indirconn = 0;
    nodes[i]->dirconnlength = 0;
  }

  for (int i = 1; i < N; i++) {
     cin >> j;
     cin >> k;
     for (int x = 0; x < nodes[j]->dirconnlength; x ++) {
       nodes[nodes[j]->dirconn[x]]->indirconn ++;
       nodes[k]->indirconn ++;
     }
     for (int x = 0; x < nodes[k]->dirconnlength; x ++) {
       nodes[nodes[j]->dirconn[x]]->indirconn ++;
       nodes[j]->indirconn ++;
     }
     nodes[j]->dirconn[nodes[j]->dirconnlength] = k;
     nodes[k]->dirconn[nodes[k]->dirconnlength] = j;
     nodes[j]->dirconnlength ++;
     nodes[k]->dirconnlength ++;
   }

   int max = 0;

   for (int i = 1; i <= N; i ++) {
     j = nodes[i]->dirconnlength + nodes[i]->indirconn + 1;
     if (max < j) {
       max = j;
     }
   }

   cout << max;

  return 0;
}
