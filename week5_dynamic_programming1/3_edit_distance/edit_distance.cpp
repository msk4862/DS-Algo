#include <iostream>
#include <string>

using std::string;

int edit_distance(const string &str1, const string &str2) {
	int n = str1.length()+1;
	int m = str2.length()+1;
 	int distance[n][m];
 	for (int i = 0; i < n; ++i)
 	{
 		distance[i][0] = i;
 	}
 	for (int i = 0; i < m; ++i)
 	{
 		distance[0][i] = i;
 	}

 	int insert, del, match, mismatch;
 	for (int j = 1; j < m; ++j)
 	{
 		for (int i = 1; i < n; ++i)
 		{	
 			//inserting a space in second string
 			insert = distance[i][j-1] + 1;
 			//inserting a space in first string
 			del = distance[i-1][j] + 1;

 			mismatch = distance[i-1][j-1] + 1;
 			match = distance[i-1][j-1]; 

 			if (str1[i-1] == str2[j-1])
 			{
 				distance[i][j] = (insert < del) ? ((insert < match) ? insert : match) : 
                                  ((del < match) ? del : match);
 			} else {
 				distance[i][j] = (insert < del) ? ((insert < mismatch) ? insert : mismatch) : 
                                  ((del < mismatch) ? del : mismatch);
 			}
 		}
 	}

 	for (int i = 0; i < n; ++i)
 	{
 		for (int j = 0; j < m; ++j)
 		{
 			std::cout<<distance[i][j]<<" ";
 		}
 		std::cout<<"\n";
 	}

  return distance[n-1][m-1];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
