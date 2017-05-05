#include <iostream>
#include <vector>
#include <list>

using namespace std;


typedef struct{
  int ind;
  int indicated_count;
}elem;

vector<elem> vec (100000);
vector<int> not_indicateds;

void group(int n, int begin, int end){
  if(end > begin){
    vec[not_indicateds[begin]].indicated_count--;
    vec[vec[not_indicateds[begin]].ind].indicated_count--;
    if(vec[vec[not_indicateds[begin]].ind].indicated_count <= 0){
      not_indicateds.push_back(vec[not_indicateds[begin]].ind);
    }
    group(n, begin+1, not_indicateds.size());
  }
}

int main(){
  int n, indication, indicator;
  cin >> n;

  for(int i=0;i<=n;i++){
    vec[i].indicated_count=0;
  }

  for(int i=0;i<n;i++){
    cin >> indicator >> indication;
    vec[indicator].ind = indication;
    vec[indication].indicated_count++;
  }
  for(int i=1;i<=n;i++){
    if(vec[i].indicated_count == 0){
      not_indicateds.push_back(i);
    }
  }

  group(n, 0, not_indicateds.size());

  for(int i=1;i<=n;i++){
    if(vec[i].indicated_count > 0){
      cout << i << ' ';
    }
  }

}