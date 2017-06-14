#include <iostream>
using namespace std;
const int MAX = 1000;
int a[MAX+1][MAX+1]; //Matriz de adjacência L
int x[MAX + 1]; //Solução atual
int bestx[MAX + 1]; //Solução ótima
int cn; //Número atual de vértices
int bestn; //Ńúmero máximo atual de vértices

void backtrack(int i, int n){
  //Calcular grupo máximo
  if(i > n){
    for(int j=0;j<n;j++){
      bestx[j] = x[j];
    }
    bestn = cn;
    return;
  }
  //Verifica a conexão do vértice atual com os demais vértices
  int OK = 1;
  for(int j=0;j<i;j++){
    if(x[j] && a[i][j] == 0){
      //i e j não estão ligados
      OK = 0;
      break;
    }
  }
  if(OK) { //sub-árvore esquerda
    x[i] = 1;
    cn++;
    backtrack(i + 1, n);
    x[i] = 0;
    cn --;
  }
  if(cn + n - i > bestn){
    x[i] = 0;
    backtrack(i + 1, n);
  }
}


int main(){
  int v, e;
  int x, y;
  cin >> v >> e; //Número de vértices e arestas

  for(int i=0;i<e;i++){
    cin >> x >> y;
    a[x][y] = a[y][x] = 1; //Matriz de adjacência
  }

  backtrack(0, v);

  for(int i=0;i<v;i++){
    if(bestx[i]){
      cout<<i<<" "; //Grupo de saída máxima
    }
  }

  cout<<endl;

  cout<<"Maior grupo de vértices:"<<bestn<<endl;

  return 0;
}