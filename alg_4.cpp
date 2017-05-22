#include <iostream>

using namespace std;

int street[1000100], t1, t2, houses[1010], maximum; //global variables are initiated with 0's

int bottom_up(int position, int house){
  if(position >= maximum){
    return 0;
  }
  else{
    while(houses[house] <= position)
      house++;
    position = houses[house];
    if(street[position] == 0)
      street[position] = min(t2+bottom_up(position+t2, house), t1+bottom_up(position+t1, house));
    return street[position];
  }
}

int main() {
  int n, c;
  cin >> n >> c >> t1 >> t2;
  for(int i=0;i<n;i++){
    cin >> houses[i];
  }
  maximum = houses[n-1]; //last positionition = max
  cout << bottom_up(0, 0); //begin from the 0 position and 0 house
  return 0;
}
