//reference: C++ Programming 49 - Deck of Cards
//https://www.youtube.com/watch?v=NAAEMILMt-Q
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

class Card{
  private:
    char suit;
    string value;

  public:
    Card();
    Card(string cardValue, char cardSuit);
    string print() const;
};
