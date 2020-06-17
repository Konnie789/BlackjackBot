#include "Deck.h"
#include <vector>
using std::vector;

char hitOrStand(vector<string> currentHand, vector<string> dealerHand, int score, int successCount, int failCount);
void playHand(Deck deck, bool &player1Win, bool &player1Lose, bool &player1Push, int &successCount, int &failCount);
int getCardValue(string cardInHand);
int calculateHand(vector<string> currentHand);
bool bust(int score);
char printANumber(string cardInHand);
