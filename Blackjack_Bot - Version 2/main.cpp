#include "Hand.h"

void runSimulation(int &numOfTurns, int &successCount, int &failCount){
  Deck deck;
  bool player1Win = false;
  bool player1Lose = false;
  bool player1Push = false;
  double player1Bet = 0;
  double player1Pot = 200;
  int turnCount = 1;
  bool play = true;

  while (play == true){
    deck.shuffle();
    cout << "Your pot is $" << player1Pot << endl;
    cout << "This is hand " << turnCount << endl;

    if(turnCount == 1){
      player1Bet = 100;
      cout << "Current Bet is $" << player1Bet << endl;
    }

    else if(player1Win == true){
      player1Bet = 100;
      cout << "Current Bet is $" << player1Bet << endl;
    }
    else{
      player1Bet = 50;
      cout << "Current Bet is $" << player1Bet << endl;
    }


    player1Win  = false;
    player1Lose = false;
    player1Push = false;

    playHand(deck, player1Win, player1Lose, player1Push);
    if(player1Win == true){
      player1Pot += player1Bet;
    }
    else if(player1Lose == true){
      player1Pot -= player1Bet;
    }
    else {
      cout << "No change in pot." << endl;
    }

    turnCount += 1;
    if(player1Pot > 1000){
      cout << "You got to $1000! You did it!" << endl;
      cout << "Your total pot is $" << player1Pot << endl;
      successCount += 1;
      numOfTurns = turnCount;
      play = false;
    }
    if(player1Pot <= 0){
      cout << "You lost all of your Money!" << endl;
      numOfTurns = turnCount;
      failCount += 1;
      play = false;
    }
  }
  cout << endl;
  cout << "Thanks for playing!" << endl << endl;
}


int main(){
  int numOfTurns;
  int successCount = 0;
  int failCount = 0;
  vector <int> numOfTurnsArray;
  int runs = 0;

  cout << "How many times do you want to run the system?" << endl;
  cin >> runs;

  if(runs > 100){
    cout << "Invalid number!" << endl;
    return -1;
  }

  for(int i = 0; i < runs; i++){
    numOfTurns = 0;
    runSimulation(numOfTurns, successCount, failCount);
    numOfTurnsArray.push_back(numOfTurns);
  }

  for(int j = 0; j < numOfTurnsArray.size(); j++){
    cout << "The amount of hands it took for simulation " << j+1 << " was " << numOfTurnsArray[j] << endl;
  }

  cout << "The simulation was successful " << successCount <<
          " times and was unsuccessful " << failCount << " times." << endl;
  return 0;
}