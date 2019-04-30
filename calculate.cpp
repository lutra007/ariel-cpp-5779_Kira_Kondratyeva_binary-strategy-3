#include <string>
#include <iostream>
#include "calculate.hpp"
using namespace std;

namespace bullpgia {
string calculateBullAndPgia(string choice, string guess) {
  int bull = 0;
  int pgia = 0;

  for (int i1 = 0; i1 < choice.size(); i1++){
    char c1 = choice[i1];
    for (int i2 = 0; i2 < guess.size(); i2++){
      char c2 = guess[i2];
      if (c1 == c2) {
        if (i1 == i2) {
          bull++;
        } else {
          pgia++;
        }
      }
    };
  };
  
  cout << "choice: " << choice << "\n";
  cout << "guess: " << guess << "\n";
  cout << "bull: " << bull << "\n";
  cout << "pgia: " << pgia << "\n";
  
  string result = to_string(bull) + "," + to_string(pgia);
  return result;
}
}

int main() {
  string reply1 = bullpgia::calculateBullAndPgia("5234","1234");
  cout << "Reply: " <<  reply1 << "\n\n";

  string reply2 = bullpgia::calculateBullAndPgia("4173","4321");
  cout << "Reply: " <<  reply2 << "\n\n";
}
