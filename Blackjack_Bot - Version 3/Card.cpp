//reference: C++ Programming 49 - Deck of Cards
//https://www.youtube.com/watch?v=NAAEMILMt-Q
#include "Card.h"

Card::Card() {
}

Card::Card(string cardValue,char cardSuit){
    value = cardValue;
    suit = cardSuit;
}

string Card::print() const{
  return (value + "of" + suit);
}