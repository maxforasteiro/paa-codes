#include <iostream>
using namespace std;
const int MAX = 1000;
int graph[MAX+1][MAX+1]; //Matriz de adjacência L
int current_clique[MAX + 1]; //Solução atual
int clique[MAX + 1]; //Solução ótima
int current_size; //Número atual de vértices
int clique_size; //Ńúmero máximo atual de vértices

void backtrack(int level, int vertices){
  //Calcular grupo máximo
  if(level > vertices){
    for(int j=0;j<vertices;j++){
      clique[j] = current_clique[j];
    }
    clique_size = current_size;
    return;
  }
  //Verifica a conexão do vértice atual com os demais vértices
  int connected = 1;
  for(int j=0;j<level;j++){
    if(current_clique[j] && graph[level][j] == 0){
      //i e j não estão ligados
      connected = 0;
      break;
    }
  }
  if(connected){
    current_clique[level] = 1;
    current_size++;
    backtrack(level + 1, vertices);
    current_clique[level] = 0;
    current_size--;
  }
  if(current_size + vertices - level > clique_size){
    current_clique[level] = 0;
    backtrack(level + 1, vertices);
  }
}


int main(){
  int v, e;
  int x, y;
  cin >> v >> e; //Número de vértices e arestas

  for(int i=0;i<e;i++){
    cin >> x >> y;
    graph[x][y] = graph[y][x] = 1; //Matriz de adjacência
  }

  backtrack(0, v);
  cout << clique_size << endl;

  return 0;
}