#include <iostream>
#include <vector>

using std::vector;

int is_partition_possible(vector<int> arr, vector<int> subsetSum, vector<bool> taken, 
                   int subset, int K, int N, int curIdx, int limitIdx) 
{ 
    if (subsetSum[curIdx] == subset) 
    { 
        /*  current index (K - 2) represents (K - 1) subsets of equal 
            sum last partition will already remain with sum 'subset'*/
        if (curIdx == K - 2) 
            return 1; 
  
        //  recursive call for next subsetition 
        return is_partition_possible(arr, subsetSum, taken, subset, 
                                            K, N, curIdx + 1, N - 1); 
    } 
  
    //  start from limitIdx and include elements into current partition 
    for (int i = limitIdx; i >= 0; i--) 
    { 
        //  if already taken, continue 
        if (taken[i]) 
            continue; 
        int tmp = subsetSum[curIdx] + arr[i]; 
  
        // if temp is less than subset then only include the element 
        // and call recursively 
        if (tmp <= subset) 
        { 
            //  mark the element and include into current partition sum 
            taken[i] = true; 
            subsetSum[curIdx] += arr[i]; 
            bool nxt = is_partition_possible(arr, subsetSum, taken, 
                                            subset, K, N, curIdx, i - 1); 
  
            // after recursive call unmark the element and remove from 
            // subsetition sum 
            taken[i] = false; 
            subsetSum[curIdx] -= arr[i]; 
            if (nxt) 
                return 1; 
        } 
    } 
    return 0; 
} 
  

int partition3(vector<int> &A) {
  //write your code here
	int sum = 0;

	for (int i = 0; i < A.size(); ++i)
	{
		sum += A[i];
	}

	if (sum%3 != 0)
	{
		return 0;
	}

	int total_subset_sum = sum/3;
	vector<int> subset_sums(3, 0);
	vector<bool> taken;

    //  mark all elements as not taken 
    for (int i = 0; i < A.size(); i++) 
        taken.push_back(false); 
  
    // initialize first subsubset sum as last element of 
    // array and mark that as taken 
    subset_sums[0] = A[A.size() - 1]; 
    taken[A.size() - 1] = true; 

	return is_partition_possible(A, subset_sums, taken, total_subset_sum, 3, A.size(), 0, A.size()-1);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
