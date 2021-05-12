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
}

void test_append(){
  START_TEST("test_append");
  test_append_empty_list();
  test_append_single_element_list();
  END_TEST("test_append");

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
  //test_equal_single_element_list();
  END_TEST("test_card");
}


void test_append_empty_list(){
    CardList list1;
    Card card('h', '6');
    list1.Append(card);
    if (list1.GetTopCard()) {
      cout << "test_append_empty_list() PASSED";
    }
    else {
      cout << "test_append_empty_list() FAILED";
    }
}

void test_append_single_element_list(){ 
  CardList list1;
  Card card('h', '6');
  Card card2('c', '4');
  list1.Append(card);
  list1.Append(card2);
  if (*list1.GetTopCard() == card) {
    cout << "test_append_single_element_list() PASSED";
  }
  else {
    cout << "test_append_single_element_list() FAILED";
  }
}
void test_equal_empty_list(){ 
  string testname = "case 0: [], []";
  CardList l1, l2;
  //assertEquals(l1.GetTopCard(),l2.GetTopCard(), "assertEquals()");
}

void test_card_operator_double_equal(){
  Card* card1 = new Card('h', '6');
  Card* card2 = new Card('h', '6');
  bool equals = false;
  if (card1==card2){
    equals = true;
  }
  if (!equals) {
    cout << "test_card_operator_double_equal() FAILED" << endl;
  }
  delete card1;
  delete card2;
}




