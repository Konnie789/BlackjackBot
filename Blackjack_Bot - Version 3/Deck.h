//reference: C++ Programming 49 - Deck of Cards
//https://www.youtube.com/watch?v=NAAEMILMt-Q
#include <cstdlib>
#include <ctime>
#include "Card.h"

const int cardsInDeck = 52;

class Deck{
  private:
    Card *deck;
    int current;

  public:
    Deck();
    void shuffle();
    Card dealCard();
    void printDeck() const;
};

