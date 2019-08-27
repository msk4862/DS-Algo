#include <iostream>
#include <vector>

using std::vector;



/*long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  


  return number_of_inversions;
}*/

int merge(vector<int> &arr, vector<int> &temp,int l,int m,int r) {
  int i,j,k;


  int number_of_inversions = 0;


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

int _mergeSort(vector<int> &a, vector<int> &temp, int left, int right) {
  int number_of_inversions = 0;
   int mid = 0;
  if (left < right)
  {
  
    mid = (left + right) / 2;
    number_of_inversions = _mergeSort(a, temp, left, mid);
    number_of_inversions += _mergeSort(a,temp, mid + 1, right);

    number_of_inversions += merge(a,temp, left, mid+1, right);
  }
  return number_of_inversions;
}

int mergeSort(vector<int> &a, int array_size) 
{ 
  vector<int> temp(array_size); 
  return _mergeSort(a, temp, 0, array_size - 1); 
} 

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std :: cout<<  mergeSort(a,a.size())<<"\n";
}
