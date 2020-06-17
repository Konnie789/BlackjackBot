#include "Hand.h"


int main(){
  Deck deck;
  bool player1Win = false;
  bool player1Lose = false;
  bool player1Push = false;
  double player1Pot = 200;
  double player1Bet = 0;
  int turnCount = 0;
  bool play = true;
  char option;

  while (play == true){
    deck.shuffle();
    cout << "Your pot is " << player1Pot << endl;
    cout << "How much would you like to bet? " << endl;
    cin >> player1Bet;
    playHand(deck, player1Win, player1Lose, player1Push);
    if(player1Win == true){
      player1Pot += player1Bet;
    }
    else if(player1Lose == true){
      if((player1Pot-player1Bet) < 0){
        cout << "You are out of money!" << endl;
        play = false;
      }
      else{
        player1Pot -= player1Bet;
      }
    }
    else {
      cout << "No change in pot." << endl;
    }
    player1Win  = false;
    player1Lose = false;
    player1Push = false;

    cout << "Your pot is now " << player1Pot << endl;
    cout << endl << "Would you like to continue?" << endl;
    cin >> option;
    if(option == 'n'){
      play = false;
    }
  }
  cout << endl;
  cout << "Thanks for playing!" << endl << endl;
  cout << "Your total pot is " << player1Pot << endl;
  return 0;
}