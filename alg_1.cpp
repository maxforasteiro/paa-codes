/*
Author: Maximillian Forasteiro
Date: 2017-04-01 (April Fools rs)
Problem: with 1 <= k <= 10.000 and 1 <= inter <= n <= 100.000 and k arrays no longer than n.
Remove the smallest value from the k arrays for each inter and then present k array after inter interations
Using vector, list, heap (some kind of heap-sort too). worst case <= 0.5s
*/
#include <iostream>
#include <vector>
#include <list>

using namespace std;

typedef struct{
  int val;
  list<vector<int>*>::iterator index;
}elem;

vector<elem> minimums;

void fix_heap(int i, int n){
  elem aux;
  aux = minimums[i];
  int f;
  while(2*i+1 < n){
    if(2*i+2 < n){
      if(minimums[2*i+1].val < minimums[2*i+2].val)
        f=2*i+1;
      else
        f=2*i+2;
    }
    else
      f=2*i+1;
    if(aux.val > minimums[f].val){
      minimums[i] = minimums[f];
      minimums[f] = aux;
      i=f;
    }
    else
      break;
  }
}

void build_heap(int n){
  int i;
  for(i=(n/2)-1;i>=0;i--){
    refaz(i, n);
  }
}

int main(){
  int k, inter, n, aux;
  list<vector<int>*> vecs;
  cin >> k >> inter;
  vector<int> vec[k];
  for(int i=0;i<k;i++){
    cin >> n;
    vecs.push_back(&vec[i]);
    for(int j=0;j<n;j++){
      cin >> aux;
      vec[i].push_back(aux);
    }
  }
  elem a;
  for(auto it = vecs.begin(); it != vecs.end(); it++){
    if((*it)->size() != 0){
      a.val = (*it)->front();
      a.index= it;
      minimums.push_back(a);
      (*it)->erase((*it)->begin());
    } else{
      k--;
    }
  }
  constroi(k);
  vector<elem>::iterator ite;
  for(int i=0;i<inter-1;i++){
    if((*minimums[0].index)->size() != 0){
      a.val = (*minimums[0].index)->front();
      a.index = minimums[0].index;
      (*minimums[0].index)->erase((*minimums[0].index)->begin());
      minimums[0] = a;
    } else{
      minimums[0] = minimums[k-1];
      k--;
    }
    refaz(0,k);
  }
  for(int i=k-1;i>=0;i--){
    a = minimums[0];
    minimums[0]=minimums[i];
    refaz(0,i);
    cout << a.val << " ";
  }
  return 0;
}
