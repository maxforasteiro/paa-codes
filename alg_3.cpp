#include <iostream>

using namespace std;

int cabin[11]= {};

int is_a_solution(int n){
  for(int i=1;i<=n;i++){
    if(cabin[i] == 0){
      return 0;
    }
  }
  return 1;
}

void process_solution(int n){
  for(int i=1;i<=n;i++){
    cout << cabin[i] << ' ';
  }
  cout << '\n';
}

int next_k(int n){
  for(int i=1;i<=n;i++){
    if(cabin[i]==0){
      return i;
    }
  }
}

void backtracking(int n){
  int c[11], ncandidates=0, k;
  if(is_a_solution(n)){
    process_solution(n);
  } else {
    k = next_k(n);
    //begin cronstruct_candidates
    int aux[11]={};
    for(int i=1;i<=n;i++){
      aux[cabin[i]] = -1;
    }
    for(int i=1;i<=n;i++){
      if(aux[i] == 0){
        c[ncandidates] = i;
        ncandidates++;
      }
    }
    // end cronstruct_candidates
    for(int i=0;i<ncandidates;i++){
      cabin[k] = c[i];
      backtracking(n);
      cabin[k] = 0;
    }
  }
}


int main(){
  int n, m;
  int col, row;
  cin >> n >> m;
  for(int i=1;i<=m;i++){
    cin >> col >> row;
    cabin[row] = col;
  }
  backtracking(n);
  return 0;
}
