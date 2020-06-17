#include "Hand.h"
#include <algorithm>

void runSimulation(int &numOfTurns, int &successCount, int &failCount, int &gameCount, vector <int> &successArray){
  Deck deck;
  bool player1Win = false;
  bool player1Lose = false;
  bool player1Push = false;
  double player1Bet = 0;
  double player1Pot = 200;
  int turnCount = 1;
  int streak = 0;
  bool play = true;

  while (play == true){
    deck.shuffle();
    if(turnCount == 1){
      cout << "This is game " << gameCount << endl;
    }
    cout << "Jim pot is $" << player1Pot << endl;
    cout << "This is hand " << turnCount << endl;

    if(turnCount == 1){
      player1Bet = 100;
    }

    else if(player1Win == true){
      if(streak > 2){
        if(streak > 4){
          if(streak > 6){
            player1Bet = 500;
          }
          else{
            player1Bet = 200;
          }
        }
        else{
          player1Bet = 150;
        }
      }
      else{
        player1Bet = 100;
      }
    }
    else if(player1Push == true){
      player1Bet = 100;
    }
    else{
      player1Bet = 50;
    }
    cout << "Current Bet is $" << player1Bet << endl;

    player1Win  = false;
    player1Lose = false;
    player1Push = false;

    playHand(deck, player1Win, player1Lose, player1Push, successCount, failCount);
    if(player1Win == true){
      player1Pot += player1Bet;
      streak += 1;
    }
    else if(player1Lose == true){
      player1Pot -= player1Bet;
      streak = 0;
    }
    else {
      cout << "No change in pot." << endl;
    }

    turnCount += 1;
    if(player1Pot >= 5000){
      cout << "Jim got to $5000! Jim did it!" << endl;
      cout << "Jim's total pot is $" << player1Pot << endl;
      successCount += 1;
      numOfTurns = turnCount;
      successArray.push_back(gameCount);
      gameCount += 1;
      play = false;
    }
    if(player1Pot <= 0){
      cout << "Jim lost all of his money!" << endl;
      numOfTurns = turnCount;
      failCount += 1;
      gameCount += 1;
      play = false;
    }
  }
  cout << endl;
  cout << "Thanks for playing!" << endl << endl;
}


int main(){
  char close;
  int numOfTurns;
  int successCount = 0;
  int failCount = 0;
  vector <int> numOfTurnsArray;
  vector <int> successArray;
  int runs = 0;
  int gameCount = 1;
  int max = 0;
  double average, total;

  cout << "How many simulations do you want to run? (between 1 or 1000)" << endl;
  cin >> runs;

  if(runs > 1000){
    cout << "Invalid number!" << endl;
    return -1;
  }

  for(int i = 0; i < runs; i++){
    numOfTurns = 0;
    runSimulation(numOfTurns, successCount, failCount, gameCount, successArray);
    numOfTurnsArray.push_back(numOfTurns);
  }

  for(int j = 0; j < numOfTurnsArray.size(); j++){
    total += numOfTurnsArray[j];
    cout << "The number of hands that game " << j+1 << " took was " << numOfTurnsArray[j] << endl;
  }

  average = total / numOfTurnsArray.size();
  cout << "The average number of hands for the simulation is " << average << endl;
  cout << "Jim was successful " << successCount <<
          " times and was unsuccessful " << failCount << " times." << endl;

  cout << endl << "The successful simulations where: " << endl;
  if(successArray.size() > 0){
    for(int k = 0; k < successArray.size(); k++){
        cout << successArray[k] << endl;
    }
  }
  else{
    cout << "The simulation was never successful" << endl;
  }

  cout <<"Press any key to close." << endl;
  cin >> close;

  return 0;
}