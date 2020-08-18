#include <iostream>
#include<vector>

using namespace std;

//Demonitions(coins) are 1,3,4
int get_change(int m) {
  //write your code here
	vector<int> minNumCoins(m+1);
	vector<int> coins;
	coins.push_back(1);
	coins.push_back(3);
	coins.push_back(4);

	minNumCoins[0] = 0;

	for (int curr_money = 1; curr_money <= m; ++curr_money)
	{
		minNumCoins[curr_money] = 999999;
		for (int c = 0; c < coins.size(); ++c)
		{
			if (curr_money >= coins[c])
			{
				//minNumCoins[curr_money-coins[c]] = using previous coins
				//+1  = for coins[c]'th 
				int minCoin = minNumCoins[curr_money-coins[c]] + 1;
				if (minCoin < minNumCoins[curr_money])
				{
					minNumCoins[curr_money] = minCoin;
				}
			}
		}
	}


  return minNumCoins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
