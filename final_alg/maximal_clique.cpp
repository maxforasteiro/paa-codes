#include <iostream>
#include <vector>
#define MAX 1000
using namespace std;

long long count, N;
long long graph[MAX][MAX], ne[MAX];
vector<long long> clique;

void BronKerbosch(long long r, long long p, long long x){
  if((p == 0LL) && (x == 0LL)){
    clique.push_back(r);
  }
  else{
    int u=0;
    for(; u<N; u++){
      if((p | x) & (1LL << u)){
        break;
      }
    }
    for(int i=0; i<N; i++){
      if((p & ~ne[u]) & (1LL << i)){
        BronKerbosch(r | (1LL << i), p & ne[i], x & ne[i]);
        p -= (1LL << i);
        x |= (1LL << i);
      }
    }
  }
}

int normalize_answer(int p){
  int answer = 0, i = 0;
  while(p){
    if(p & 1LL){
      answer += graph[i / N][i % N];
    }
    p >>= 1;
    i++;
  }
}

int main(){
  int v, x, y;
  cin >> N >> v;
  for(int i=0;i<v;i++){
    cin >> x >> y;
    graph[x][y] = graph[y][x] = 1;
    ne[x] |= (1LL << y);
  }

  BronKerbosch(0, ~0LL, 0);

  int answer = -1;
  for(int i=0; i<clique.size(); i++){
    if(3*clique[i] >= 2*N){
      answer = max(answer, normalize_answer(clique[i]));
      // cout << clique[i] << ' ';
    }
  }

  return 0;
}