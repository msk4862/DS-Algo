#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence_correct(int n) {
  vector<int> minMoves(n+1);
  int Move1, Move2, Move3;

  //Calculating optimal moves till n
  minMoves[0] = 0;
  minMoves[1] = 0;

  for (int num = 2; num <= n; ++num)
  {
    Move1 = 99999999;
    Move2 = 99999999;
    Move3 = 99999999;

    Move1 = minMoves[num - 1] + 1;
    if (num % 2 == 0) {
      Move2 =  minMoves[ num / 2] + 1; 
    }
    if (num % 3 == 0) {
      Move3 =  minMoves[num / 3] + 1;
    }

    minMoves[num] = (Move1 < Move2) ? ((Move1 < Move3) ? Move1 : Move3) : 
                                      ((Move2 < Move3) ? Move2 : Move3);
  }


  //Finding moves of nth number
  int number = n;
  vector<int> sequence;
  sequence.push_back(number);
  
  while(number != 1) {
    Move1 = 99999999;
    Move2 = 99999999;
    Move3 = 99999999;

    Move1 = minMoves[number-1];
    if (number % 2 == 0) {
      Move2 =  minMoves[ number / 2]; 
    }
    if (number % 3 == 0) {
      Move3 =  minMoves[number / 3];
    }

    int minMove = (Move1 < Move2) ? ((Move1 < Move3) ? Move1 : Move3) : 
                                      ((Move2 < Move3) ? Move2 : Move3);

    if (minMove == Move1)
    {
      number = number -1;
    }
    else if (minMove == Move2)
    {
      number = number / 2;
    }
    else {
      number = number / 3;
    }

    sequence.push_back(number);
  }

  //inserting value of minimum operations
  sequence.push_back(minMoves[n]);
  reverse(sequence.begin(), sequence.end());
  return sequence;
}


vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence_correct(n);
  std::cout << sequence[0]<< std::endl ;
  for (size_t i = 1; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
