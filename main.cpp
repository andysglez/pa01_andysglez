#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"
using namespace std;

int main(int argv, char** argc){
  if(argv != 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail()){
    cout << "Could not open file " << argc[1];
    return 1;
  }

  if (cardFile2.fail()){
    cout << "Could not open file " << argc[2];
    return 1;
  }

 

  // Create two objects of the class you defined 
  // to contain two sets of cards in two input files
 CardList cards1;
 CardList cards2; 

  // Read each file and store cards
  while (getline (cardFile1, line) && (line.length() > 0)){
    Card card(line[0], line[2]);
    cards1.Append(card);
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
    Card card(line[0], line[2]);
    cards2.Append(card);
  }

  cardFile2.close();

  /*cout << "cards1:" << endl;
  cards1.Print();
  
  cout << "cards2:" << endl;
  cards2.Print();*/

  // Start the game
  Card* tempcard = cards1.GetTopCard();
  Card* tempcard2 = cards2.GetTopCard();
  while(tempcard || tempcard2) {
    while (tempcard) { //Alice's turn
      Card* SameCard = cards2.SearchForCard(tempcard);
      if (SameCard) {
        cout << "Alice picked matching card: ";
        tempcard->print();
        cards1.Remove(tempcard);
        cards2.Remove(SameCard);
        break;
      }
      tempcard = tempcard->next;
    }
    while (tempcard2) { //Bob's turn;
      Card* SameCard = cards1.SearchForCard(tempcard2);
      if (SameCard) {
        cout << "Bob picked matching card: ";
        tempcard2->print();
        cards2.Remove(tempcard2);
        cards1.Remove(SameCard);
        break;
      }
      tempcard2 = tempcard2->next;
    }
    if (!tempcard || !tempcard2) { //if either player reaches the end of their deck
      cout << endl;
      cout << "Alice's cards:" << endl;
      cards1.print();
      cout << "Bobs's cards:" << endl;
      cards2.print();
      break;
    }
    tempcard = cards1.GetTopCard();
    tempcard2 = cards2.GetTopCard();
  }
  

  return 0;
}
