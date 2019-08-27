#include <iostream>
#include <vector>
#include <ctime>

using std::vector;



/*long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  


  return number_of_inversions;
}*/

long long merge(vector<int> arr,int l,int m,int r) {
  int i,j,k;

  vector<int> temp(arr.size());

  long long number_of_inversions = 0;


  i=l;
  j = m;
  k=l;
  while ((i <= m-1) && (j <= r)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
  
            number_of_inversions = number_of_inversions + (m - i); 
        } 
    } 
  
    while (i <= m - 1) 
        temp[k++] = arr[i++]; 
  
    /* Copy the remaining elements of right subarray 
   (if there are any) to temp*/
    while (j <= r) 
        temp[k++] = arr[j++]; 
  
    /*Copy back the merged elements to original array*/
    for (i = l; i <= r; i++) 
        arr[i] = temp[i]; 
  
    return number_of_inversions;

  }

long long get_number_of_inversions(vector<int> a, size_t left, size_t right) {
  long long number_of_inversions = 0;
   size_t mid = 0;
  if (left < right)
  {
  
    mid = (left+right) / 2;
    number_of_inversions = get_number_of_inversions(a, left, mid);
    number_of_inversions += get_number_of_inversions(a, mid + 1, right);

    number_of_inversions += merge(a,left, mid+1, right);
  }
  return number_of_inversions;
}


long long inversions_naive(vector<int> a) {
  long long number_of_inversions = 0;
  for (int i = 0; i < a.size()-1; ++i)
  {
    for (int j = i+1; j < a.size(); ++j)
    {
      if (a[i] > a[j])
      {
        number_of_inversions++;
      }
    }
  }

  return number_of_inversions;
}

int main() {
  while(true) {
    srand(time(NULL));

    int n = rand() % 10 + 2;
    std :: cout<<n<< "\n";

    vector<int> v(n);

    for (int i = 0; i < n; ++i)
    {
      v[i] = rand() % 100;
    }

    for (int i = 0; i < n; ++i)
    {
      std :: cout<<v[i]<<" ";
    }
    std :: cout<<"\n";
    long long res1 = get_number_of_inversions(v, 0, v.size()-1);
    long long res2 = inversions_naive(v);

    if (res1 == res2)
    {
      std :: cout<<"OK\n";
    }
    else {
      std :: cout<<"Wrong Answer "<<res1<<" "<<res2<<endl;
      break;
    }

  }

}
