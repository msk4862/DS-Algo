#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int min_coins(int money) {
	int tens, fives, ones, coins = 0;

	tens = money/10;
	coins += tens;

	money -= tens*10;
	if (money > 0) {
		fives = money/5;
		coins += fives;
		money -= fives*5;

		if(money > 0) {
			coins += money;
		}
	}

	return coins;
	
}

int main() {
	int n;
	cin>>n;

	cout<<min_coins(n);
}