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
  while(!CompareLists(cards1, cards2)) {
    Card* head = cards1.GetTopCard();
    while(head) {
      Card* card = NULL;
      if(cards2.SearchForCard(head)){
        card = cards2.SearchForCard(head);
      }
      if(card) {
        cout << "A picked matching card:" << card->suit << " " << card->value << endl;
        cards1.Remove(head);
        cards2.Remove(card);
        break;
      }
      head = head->next; 
    }
    head = cards2.GetTopCard();
    while(head) {
      Card* card = NULL;
      if(cards1.SearchForCard(head)){
        card = cards1.SearchForCard(head);
      }
      if(card) {
        cout << "B picked matching card:" << card->suit << " " << card->value << endl;
        cards1.Remove(head);
        cards2.Remove(card);
        break;
      }
      head = head->next;
    }
  }

  /*cout << "cards1:" << endl;
  cards1.Print();
  
  cout << "cards2:" << endl;
  cards2.Print();*/
  
  


  return 0;
}
