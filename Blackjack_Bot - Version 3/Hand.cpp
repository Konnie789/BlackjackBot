#include "Hand.h"


void playHand(Deck deck, bool &player1Win, bool &player1Lose, bool &player1Push, int &successCount, int &failCount){
  Card card1, card2, newCard, dealerCard1, dealerCard2, dealerNewCard;
  vector <string> yourHand, dealerHand;
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
  cout << "Jim's Hand is " << yourHand[0] << " and " << yourHand[1] << endl << "Jim's score is " << score << endl;
  //This section shows the dealers hand
  dealerScore = calculateHand(dealerHand);
  cout << "The dealer has " << dealerHand[1] << " showing." << endl;
  //Loop for until hand is done
  while(exit == 0){
    ans = hitOrStand(yourHand, dealerHand, score, successCount, failCount);
    cout << endl;
    //if a hit is made
    if(ans == 'h'){
      cout << "Hitting" << endl;
      newCard = deck.dealCard();
      yourHand.push_back(newCard.print());
      cout << "Jim's Hand is ";
      for(int i = 0; i < yourHand.size(); i++){
        cout << yourHand[i] << " ";
      }
      cout << endl;
      score = calculateHand(yourHand);
      cout << "Jim's Score is " << score << endl;
      //Check for Bust
      if(bust(score) == true){
        cout << "Jim Busts!" << endl << endl;
        player1Lose = true;
        exit = 1;
      }
    }
    //if standing
    else if(ans == 's'){
      cout << "Standing" << endl;
      cout << "Dealer's original hand" << endl << dealerHand[0] << " " << dealerHand[1] << endl << endl << "Dealer's score is " << dealerScore << endl;
      //Dealer check
      while(dealerScore < 16){
        cout << "dealer hits!" << endl;
        dealerNewCard = deck.dealCard();
        dealerHand.push_back(dealerNewCard.print());
        for (int i = 0; i < dealerHand.size(); i++){
          cout << dealerHand[i] << " ";
        }
        cout << endl;
        dealerScore = calculateHand(dealerHand);
        cout << "Dealer's Score " << dealerScore << endl;
      }
      cout << endl;
      if(bust(dealerScore) == true){
        cout << "Dealer busts!" << endl;
        cout << "Jim Wins!" << endl << endl;
        player1Win = true;
        exit = 1;
      }
      else if(dealerScore > score){
        cout << "Jim Lost!" << endl << endl;
        player1Lose = true;
        exit = 1;
      }

      else if(score > dealerScore){
        cout << "Jim Wins!" << endl << endl;
        player1Win = true;
        exit = 1;
      }
      else if(score = dealerScore){
        cout << "Jim Pushes!" << endl << endl;
        player1Push = true;
        exit = 1;
      }
      else{exit = 1;}
    }
    else{ cout << "Oops!" << endl; exit = 1;}
  }
}

char hitOrStand(vector<string> currentHand, vector<string> dealerHand, int score, int successCount, int failCount){
  char move;
  float chances;
  int dealerCardScore = getCardValue(dealerHand[1]);

  //Jim's hand is 21 or 20
  if(score == 21 || score == 20){
    move = 's';
  }

  //Jim's is 19 or 18 or 17
  else if((score == 19 || score == 18 || score == 17)){
    //Dealer's show card is less than 5
    if(dealerCardScore < 5){
      //Currently on a streak where there more than double wins over losses
      if(successCount > (3 * failCount)){
        move = 'h';
      }
      else{
        move = 's';
      }
    }
    //dear has a 10 or 9, only two cards in player's hand
    else if((dealerCardScore == 10 || dealerCardScore == 9) && currentHand.size() == 2){
      move = 'h';
    }
    else{
      move = 's';
    }
  }

  //Jim's hand is between 10 and 16
  else if((score >= 10 && score <= 16)){
    //Dealers best chance of victory, most likely to lose, best to go for it
    if(dealerCardScore == 10 || dealerCardScore == 9){
      move = 'h';
    }
    //Dealer's best hand without hitting is 19,
    //worse hand without hitting is 16
    else if(dealerCardScore == 8){
      //no chance of busting with a hand score of 10 or 11
      if(score == 10 || score == 11){
        move = 'h';
      }
      //Chance of busting on a 10, J, Q, K, 30% chance to bust
      else if(score == 12 || score == 13){
        //Bigger chance to get a card that will bust
        if(currentHand.size() == 5){
          move = 's';
        }
        else{
           move = 'h';
        }
      }
      else if(score == 14 || score == 15){
        if(currentHand.size() == 4){
          move = 's';
        }
        else{
           move = 'h';
        }
      }

      else if(score == 16){
        if(currentHand.size() == 4){
          move = 's';
        }
        else{
          move = 'h';
        }
      }
    }
    //Dealer's best hand without hitting is 18,
    //worse hand without hitting is 16
    else if(dealerCardScore == 7){
      //no chance of busting with a hand score of 10 or 11
      if(score == 10 || score == 11){
        move = 'h';
      }
      //Chance of busting on a 10, J, Q, K, 30% chance to bust
      else if(score == 12 || score == 13){
        //Bigger chance to get a card that will bust
        if(currentHand.size() == 5){
          move = 's';
        }
        else{
           move = 'h';
        }
      }
      else if(score == 14 || score == 15){
        if(currentHand.size() == 4){
          move = 's';
        }
        else{
           move = 'h';
        }
      }
      else if(score == 16){
        move = 's';
      }
    }
    //Dealer's best hand without hitting is 17,
    //worse hand without hitting is 16
    else if(dealerCardScore == 6){
      //no chance of busting with a hand score of 10 or 11
      if(score == 10 || score == 11){
        move = 'h';
      }
      //Chance of busting on a 10, J, Q, K, 30% chance to bust
      else if(score == 12 || score == 13 || score == 14){
        //Bigger chance to get a card that will bust
        if(currentHand.size() == 5){
          move = 's';
        }
        else{
           move = 'h';
        }
      }
      else if(score == 15 || score == 16){
        move = 's';
      }
    }
    //Dealer's hand cannot stand on two cards alone
    else if(dealerCardScore <= 5){
      if(score == 16){
        if(currentHand.size() == 5){
          move = 's';
        }
        else{
          move = 'h';
        }
      }
      else{
        move = 'h';
      }
    }
  }
  //Jim's hand is less than 10, no chance of busting
  else if(score < 10){
    move = 'h';
  }

  return move;
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