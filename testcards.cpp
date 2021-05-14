// This file should contain unit tests for all the 
// public interfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
  runAll();
  return 0;
}

void runAll(){
  test_append();
  test_equal();
  test_card();
  //test_constructor();
  //test_destructor();
  test_remove();
  test_search();
}

void test_append(){
  START_TEST("test_append");
  test_append_empty_list();
  //test_append_single_element_list();
  END_TEST("test_append");

}

void test_remove(){
  START_TEST("test_remove");
  test_remove_card();
  END_TEST("test_remove");

}
void test_search() {
  START_TEST("test_search");
  test_search_card();
  test_search_null();
  END_TEST("test_search");
}

void test_equal(){
  START_TEST("test_equal");
  test_equal_empty_list();
  //test_equal_single_element_list();
  END_TEST("test_equal");

}

void test_card(){
  START_TEST("test_card");
  test_card_operator_double_equal();
  END_TEST("test_card");
}


void test_append_empty_list(){
    CardList cards1;
    Card card('h', '4');
    cards1.Append(card);
    if (*cards1.GetTopCard() == card) {
      cout << "PASSED\n";
    }
    else {
      cout << "FAILED test_append_empty_list()\n";
    }
}

void test_append_single_element_list(){
  CardList list1;
  Card card('h', '6');
  Card card2('c', '4');
  list1.Append(card);
  list1.Append(card2);
  if (list1.GetTopCard()) {
    cout << "PASSED\n";
  }
  else {
    cout << "FAILED test_append_single_element_list\n";
  }
}
void test_equal_empty_list(){
  string testname = "case 0: [], []";
  CardList l1, l2;
  assertEquals(l1.GetTopCard(),l2.GetTopCard(), "assertEquals()");
}

void test_card_operator_double_equal(){
  Card* card1 = new Card('h', '6');
  Card* card2 = new Card('h', '6');
  bool equals = false;
  if (*card1==*card2){
    equals = true;
    cout << "PASSED" << endl;
  }
  if (!equals) {
    cout << "FAILED" << endl;
  }
  delete card1;
  delete card2;
}

void test_remove_card() {
  CardList cards1;
  Card card1('h', '4'), card2('d', '7'), card3('c', '3');
  cards1.Append(card1);
  cards1.Append(card2);
  cards1.Append(card3);
  Card* cardRemoved = new Card;
  *cardRemoved =  card2;
  cards1.Remove(cardRemoved);
  if (cards1.SearchForCard(cardRemoved) == NULL) {
    cout << "PASSED" << endl;
  }
  else {
    cout << "FAILED" << endl;
  }
  delete cardRemoved;
}
void test_search_card() {
  CardList cards1;
  Card card1('h', '4'), card2('d', '7'), card3('c', '3');
  cards1.Append(card1);
  cards1.Append(card2);
  cards1.Append(card3);
  Card* searchcard= new Card;
  *searchcard =  card2;
  if(cards1.SearchForCard(searchcard)) {
    cout << "PASSED" << endl;
  }
  else {
    cout << "FAILED" << endl;
  }
  delete searchcard;
  
}
void test_search_null() {
  CardList cards1;
  Card card1('h', '4'), card2('d', '7'), card3('c', '3');
  cards1.Append(card1);
  cards1.Append(card2);
  cards1.Append(card3);
  Card* searchcard= new Card('c', 'q');
  if(!cards1.SearchForCard(searchcard)) {
    cout << "PASSED" << endl;
  }
  else {
    cout << "FAILED" << endl;
  }
  delete searchcard;

}



