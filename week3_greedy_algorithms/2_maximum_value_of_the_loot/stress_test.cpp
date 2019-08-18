#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include<cstdlib>

using namespace std;

double get_optimal_value_incorrect(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int n = weights.size();

  vector<double> value_per_unit_weight(n);

  for (int i = 0; i < n; ++i)
  {
    value_per_unit_weight[i] = (double)values[i]/weights[i];
  }

  sort(value_per_unit_weight.begin(), value_per_unit_weight.end());
  
  int item = value_per_unit_weight.size() - 1;
  
  while (capacity > 0) {

    if(weights[item] <= capacity) {
      capacity -= weights[item];
      value += value_per_unit_weight[item]*weights[item];
    }
    else {
      value += (capacity * value_per_unit_weight[item]);
      capacity = 0;  
    }

    item -= 1;
  }
  
  

  return value;
}



struct Item 
{ 
    int value, weight; 
  
}; 
  
// Comparison function to sort Item according to val/weight ratio 
bool cmp(struct Item a, struct Item b) 
{ 
    double r1 = (double)a.value / a.weight; 
    double r2 = (double)b.value / b.weight; 
    return r1 > r2; 
} 
  
// Main greedy function to solve problem 
double get_optimal_value_correct(int W, struct Item arr[], int n) 
{ 
    //    sorting Item on basis of ratio 
    sort(arr, arr + n, cmp); 
  
    //    Uncomment to see new order of Items with their ratio 
    /* 
    for (int i = 0; i < n; i++) 
    { 
        cout << arr[i].value << "  " << arr[i].weight << " : " 
             << ((double)arr[i].value / arr[i].weight) << endl; 
    } 
    */
  
    int curWeight = 0;  // Current weight in knapsack 
    double finalvalue = 0.0; // Result (value in Knapsack) 
  
    // Looping through all Items 
    for (int i = 0; i < n; i++) 
    { 
        // If adding Item won't overflow, add it completely 
        if (curWeight + arr[i].weight <= W) 
        { 
            curWeight += arr[i].weight; 
            finalvalue += arr[i].value; 
        } 
  
        // If we can't add current Item, add fractional part of it 
        else
        { 
            int remain = W - curWeight; 
            finalvalue += arr[i].value * ((double) remain / arr[i].weight); 
            break; 
        } 
    } 
  
    // Returning final value 
    return finalvalue; 
} 




int main() {
    while(true) {
    srand(time(NULL));


    int n = rand() % 5 + 2;
    cout<<n<< " ";

    int capacity = rand() % 100;
    cout<<capacity<< "\n";

    vector<int> values(n);
    vector<int> weights(n);

    struct Item arr[n];

    for (int i = 0; i < n; ++i)
    {
      values[i] = rand() % 200;
      weights[i] = rand() % 200;

      arr[i].value = values[i];
      arr[i].weight = weights[i];

    }



    for (int i = 0; i < n; ++i)
    {
      cout<<values[i]<<" "<<weights[i]<<endl;
    }
    cout<<"\n\n\n";
    double res1 = get_optimal_value_incorrect(capacity, weights, values);
    double res2 = get_optimal_value_correct(capacity, arr, n);

    if (res1 == res2)
    {
      cout<<"OK\n";
    }
    else {
      cout<<"Wrong Answer "<<res1<<" "<<res2<<endl;
      break;
    }

  }
  return 0;
}
