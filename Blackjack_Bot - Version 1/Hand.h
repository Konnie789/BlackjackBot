#include "Deck.h"
#include <vector>
using std::vector;


void playHand(Deck deck, bool &player1Win, bool &player1Lose, bool &player1Push);
int getCardValue(string cardInHand);
int calculateHand(vector<string> currentHand);
bool bust(int score);
char printANumber(string cardInHand);
