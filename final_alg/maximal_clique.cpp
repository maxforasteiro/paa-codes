#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

int **graph;

int find_maximal_clique(int subgraph[], int len){
  int deg[len], min_node = 0;
  while(1){
    int min_deg = len + 5, max_deg = 0;
    memset(deg, 0, sizeof(deg));
    for(int i=0;i<len;i++){
      for(int j=0;j<len;j++){
        if(graph[subgraph[i]][subgraph[j]] && i != j){
          deg[i]++;
        }
      }
    }
    for(int i=0;i<len;i++){
      if(deg[i] < min_deg)
        min_deg = deg[i], min_node = i;
      if(deg[i] > max_deg)
        max_deg = deg[i];
    }
    if(min_deg == max_deg)
      return len;
    else{
      len--;
      for(int i=1;i<min_node;i++)
        subgraph[i] = subgraph[i];
      for(int i=min_node;i<=len;i++)
        subgraph[i] = subgraph[i+1];
    }
  }
}


int main(){
  int maximal_clique = 0;
  int v, e;
  int x, y;
  cin >> v >> e;

  graph = (int**) malloc(e*sizeof(int*));
  for(int i=0;i<e;i++){
    graph[i] = (int*) malloc(e*sizeof(int));
  }

  for(int i=0;i<e;i++){
    cin >> x >> y;
    graph[x][y] = graph[y][x] = 1;
  }

  for(int i=0;i<e;i++){
    int neighborhood[1000] = {i},len = 1;
    for(int j=0;j<e;j++){
      if(graph[i][j]){
        neighborhood[len++] = j;
      }
    }
    maximal_clique = max(maximal_clique,find_maximal_clique(neighborhood, len));
  }

  cout << maximal_clique << endl;
  return 0;
}