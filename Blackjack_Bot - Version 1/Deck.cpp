#include "Deck.h"

Deck::Deck(){
  string values[] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
  char suits[] = {'C', 'H', 'S', 'D'};
  deck = new Card[cardsInDeck];
  current = 0;

  for(int i = 0; i < cardsInDeck; i++){
    deck[i] = Card(values[i % 13], suits[i/13]);
  }
}

void Deck::shuffle(){
  current = 0;
  for(int i = 0; i < cardsInDeck; i++){
    int j = (rand()+ time(0)) % cardsInDeck;
    Card temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }
}

Card Deck::dealCard(){
  if(current > cardsInDeck) {shuffle();}
  if(current < cardsInDeck) {return (deck[current++]);}
  return (deck[0]);
}

void Deck::printDeck()const{
  for(int i = 0; i < cardsInDeck; i++){
    cout << deck[i].print();
    cout << endl;
  }
}