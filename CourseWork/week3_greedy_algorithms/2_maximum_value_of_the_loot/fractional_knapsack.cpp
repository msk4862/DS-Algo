#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item 
{ 
    int value, weight; 
  
};

bool compare(struct Item a, struct Item b) 
{ 
    double r1 = (double)a.value / a.weight; 
    double r2 = (double)b.value / b.weight; 

    //Decreasing order
    return r1 > r2; 
} 

double get_optimal_value(int capacity, int n, Item items[]) {
  double value = 0.0;

  sort(items, items + n, compare);
  
  int item = 0;
  
  for (item = 0; item < n; item++) {

    if(items[item].weight <= capacity) {
      capacity -= items[item].weight;
      value += items[item].value;
    }
    else {
      value += capacity * ((double)items[item].value/items[item].weight);
      capacity = 0; 
      break;
    }

  }
  
  

  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;

  struct Item items[n]; 

  for (int i = 0; i < n; i++) {
    cin >> items[i].value >> items[i].weight;
  }

  double optimal_value = get_optimal_value(capacity, n, items);

  cout.precision(10);
  cout.fixed;
  cout << optimal_value << endl;
  return 0;
}
