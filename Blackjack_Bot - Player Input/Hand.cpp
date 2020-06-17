#include "Hand.h"


void playHand(Deck deck, bool &player1Win, bool &player1Lose, bool &player1Push){
  Card card1, card2, newCard, dealerCard1, dealerCard2, dealerNewCard;
  vector <string> yourHand;
  vector <string> dealerHand;
  char ans;
  int score = 0;
  int dealerScore = 0;
  int exit = 0;

  //Player Cards
  card1 = deck.dealCard();
  card2 = deck.dealCard();
  yourHand.push_back(card1.print());
  yourHand.push_back(card2.print());

  //Dealer Cards
  dealerCard1 = deck.dealCard();
  dealerCard2 = deck.dealCard();
  dealerHand.push_back(dealerCard1.print());
  dealerHand.push_back(dealerCard2.print());

  //This section calculates your score at the top of the game
  score = calculateHand(yourHand);
  cout << "Your Hand is " << yourHand[0] << " and " << yourHand[1] << endl;
  cout << "Your score is " << score << endl;

  //This section shows the dealers hand
  dealerScore = calculateHand(dealerHand);
  cout << "The dealer has " << dealerHand[1] << " showing." << endl;

  while(exit == 0){
    cout << "Would you like to hit or stand?" << endl;
    cin >> ans;
    cout << endl;
    if(ans == 'h'){ //press h to hit
      newCard = deck.dealCard();
      yourHand.push_back(newCard.print());
      cout << "Your Hand is ";
      for(int i = 0; i < yourHand.size(); i++){
        cout << yourHand[i] << " ";
      }
      cout << endl;
      score = calculateHand(yourHand);
      cout << "Your Score is " << score << endl;
      //Check for Bust
      if(bust(score) == true){
        cout << "You Bust!" << endl;
        player1Lose = true;
        exit = 1;
      }
    }
    else if(ans == 's'){
      cout << "Dealer's original hand" << endl;
      cout << dealerHand[0] << " " << dealerHand[1] << endl << endl;
      cout << "Dealer's score is " << dealerScore << endl;
      while(dealerScore <= 16){
        cout << "dealer hits!" << endl;
        dealerNewCard = deck.dealCard();
        dealerHand.push_back(dealerNewCard.print());
        for (int i = 0; i < dealerHand.size(); i++){
          cout << dealerHand[i] << " ";
        }
        cout << endl;
        dealerScore = calculateHand(dealerHand);
        cout << "Dealer's Score " << dealerScore << endl << endl;
      }

      cout << endl;
      if(bust(dealerScore) == true){
        cout << "Dealer busts!" << endl;
        cout << "You Win!" << endl;
        player1Win = true;
        exit = 1;
      }

      else if(dealerScore > score){
        cout << "You Lose!" << endl;
        player1Lose = true;
        exit = 1;
      }

      else if(score > dealerScore){
        cout << "You Win!" << endl;
        player1Win = true;
        exit = 1;
      }
      else if(score = dealerScore){
        cout << "You Push!" << endl;
        player1Push = true;
        exit = 1;
      }
      else{
        exit = 1;
      }
    }
    else{
      cout << "Oops!" << endl;
      exit = 1;
    }
  }
}

int getCardValue(string cardInHand){
  int score;
  if(cardInHand[0] == 'J' || cardInHand[0] == 'Q' || cardInHand[0] == 'K'){
    score = 10;
  }
  else if(cardInHand[0] == '1' && cardInHand[1] == '0'){
    score = 10;
  }
  else if(cardInHand[0] == 'A'){
    score = 1;
  }
  else{
    score = static_cast<int>(cardInHand[0]) - 48;
  }

  return score;
}

int calculateHand(vector<string> currentHand){
  int score = 0;
  bool aceCase = false;
  for(int i = 0; i < currentHand.size(); i++){
    score += getCardValue(currentHand[i]);

    if(currentHand[i][0] == 'A'){
      aceCase = true;
    }
  }
  if(aceCase == true &&  bust(score+10) == false){
    score += 10;
  }

  return score;
}

bool bust(int score){
  if(score > 21){
    return true;
  }
  else{
  return false;
  }
}

char printANumber(string cardInHand){

  return cardInHand[0];
}