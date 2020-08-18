#include <iostream>
#include <vector>
#include <ctime>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  int n = a.size()+1;
  int m = b.size()+1;
  int distance[n][m];

  for (int i = 0; i < n; ++i)
  {
    distance[i][0] = 0;
  }
  for (int i = 0; i < m; ++i)
  {
    distance[0][i] = 0;
  }

  int insert, del, match;
  for (int j = 1; j < m; ++j)
  {
    for (int i = 1; i < n; ++i)
    { 
      //inserting a space in second string
      insert = distance[i][j-1];
      //inserting a space in first string
      del = distance[i-1][j];

      match = distance[i-1][j-1]; 

      //find max
      distance[i][j] = (insert > del) ? ((insert > match) ? insert : match) : 
                                  ((del > match) ? del : match);
      //one more commmon element
      if (a[i-1] == b[j-1])
      {
        distance[i][j]++;
      }
    }
  }

  return distance[n-1][m-1];
}

int naive(vector<int> &a, vector<int> &b, int index_a, int index_b) {
  if (index_a == -1 || index_b == -1)
  {
    return 0;
  }
  else {
    if (a[index_a] == b[index_b])
    {
      return 1 + naive(a, b, index_a-1, index_b-1);
    }
    else {
      return std :: max(naive(a, b, index_a-1, index_b), naive(a, b, index_a, index_b-1));
    }
  }
}


int main() {
  while(true) {
    srand(time(NULL));

    int n = rand() % 10 + 2;
    cout<<n<< "\n";

    vector<int> a(n);

    for (int i = 0; i < n; ++i)
    {
      a[i] = rand() % 100;
    }

    for (int i = 0; i < a1.size(); ++i)
    {
      cout<<a1[i]<<" ";
    }

    int m = rand() % 10 + 2;
    cout<<m<< "\n";

    vector<int> b(m);

    for (int i = 0; i < m; ++i)
    {
      b[i] = rand() % 100;
    }

    for (int i = 0; i < b1.size(); ++i)
    {
      cout<<b1[i]<<" ";
    }

    cout<<"\n";
    int res1 = naive(a1, b1,a1.size()-1, b1.size()-1);
    int res2 = lcs2(a1, b1 );

    if (res1 == res2)
    {
      cout<<"OK\n";
    }
    else {
      cout<<"Wrong Answer "<<res1<<" "<<res2<<endl;
      break;
    }
  }
  
}
