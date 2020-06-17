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