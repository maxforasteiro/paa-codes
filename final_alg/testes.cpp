#include <iostream>

using namespace std;

long long ne[1000], N;

int main(){
  int v, x, y;
  cin >> N >> v;
  for(int i=0;i<v;i++){
    cin >> x >> y;
    ne[x] |= (1LL << y);
  }

  for(int i=0; i<N;i++){
    for(int j=0; j<N;j++){
      cout << ne[i] << ' ';
    }
    cout << '\n';
  }
}