//cards.cpp
//Author: Andy Gonzalrz
//Implementation of the classes defined in cards.h
#include "cards.h"
#include <iostream>
#include <string>
using namespace std;

//creates deep copy
Card Card::operator=(Card& card) {
    this->value = card.value;
    this->suit = card.suit;
    this->prev = card.prev;
    this->next = card.next;

    return *this;
}
bool Card::operator==(const Card& card)const {
    return ((this->value == card.value) && (this->suit == card.suit));
}

void Card::print() {
    cout << suit << " " << value << endl;
}

Card* CardList::SearchForCard(Card* card) {
    Card* searchCard = head;
    if(!searchCard) {return NULL;}
    while (searchCard) {
        if (*searchCard == *card) {
            return searchCard;
        }
        else {
            searchCard = searchCard->next;
        }
    }
    return NULL;
}

void CardList::Remove(Card* card) {
    Card* RemoveCard = SearchForCard(card);
    if (!RemoveCard) {return;}
    Card* nextcard = RemoveCard->next;
    Card* prevcard = RemoveCard->prev;
    if (nextcard) {
        nextcard->prev = prevcard;
    }
    if (prevcard) {
        prevcard->next = nextcard;
    }
    if (!prevcard) {
        head = nextcard;
        head->prev = nullptr;
    }
    if (!nextcard) {
        tail = prevcard;
        tail->next = nullptr;
    }
    if(RemoveCard) {
       delete RemoveCard; 
    }
}
   

void CardList::Append(Card card) {
    Card* newcard = new Card(card);
    if(!head){
        head = newcard;
        tail = newcard;
        head->prev = NULL;
        head->next = NULL;
    }
    else if(!head->next) {
        newcard->prev = head;
        newcard->next = nullptr;
        tail = newcard;
        head->next = newcard;
        head->prev = nullptr;
    }
    else {
        newcard->prev = tail;
        tail->next = newcard;
        tail = newcard;
        tail->next = nullptr;

    }
}

CardList::~CardList() {
    while(head) {
        Card* next = head->next;
        delete head;
        head = next;
    }
}


void CardList::PrintAll() const{
    Card* printcard = head;
    while(printcard) {
        if(printcard->prev) {
            cout << "Prevcard:"<< printcard->prev->suit << " " << printcard->prev->value << endl;
        }
        cout << "Currcard:" << printcard->suit << " " << printcard->value << endl;
        if (printcard->next) {
            printcard = printcard->next;
        }
        else {
            break;
        }
        if (printcard) {
            cout << "Nextcard:"<< printcard->suit << " " << printcard->value << endl << endl;
        }
        else {

        }
    }
}
void CardList::print() const {
    Card* printcard = head;
    while (printcard) {
        printcard->print();
        printcard = printcard->next;
    }
}


Card* GetNextCard(Card* card) {
    if(!card->next) {
        return NULL;
    }
    return card->next;
}

