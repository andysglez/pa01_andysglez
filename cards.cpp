//cards.cpp
//Author: Andy Gonzalrz
//Implementation of the classes defined in cards.h
#include "cards.h"
#include <iostream>
#include <string>
using namespace std;

//creates shallow copy
Card Card::operator=(Card card) {
    this->value = card.value;
    this->suit = card.suit;
    return *this;
}
void Card::print() {
    cout << suit << " " << value << endl;
}
bool Card::operator==(const Card& card)const {
    return ((this->value == card.value) && (this->suit == card.suit));
}
bool Card::operator==(const Card* card)const {
    return ((this->value == card->value) && (this->suit == card->suit));
} 
bool CardList::CompareLists(CardList cards1, CardList cards2) {
    Card* head = cards1.GetTopCard();
    bool Same = false;
    while(head){
        if (cards2.SearchForCard(head)) {
            Same = true;
            return Same;
        }
        head = head->next;
    }
    return Same;
}
Card* CardList::SearchForCard(Card* card) {
    Card* searchCard = head;
    while (searchCard) {
        if ((searchCard->suit == card->suit) && (searchCard->value == card->value)) {
            return searchCard;
        }
        else {searchCard = searchCard->next;}
    }
    return NULL;
}

void CardList::Remove(Card* card) {
    if (!card) {return;}
    Card* nextcard = card->next;
    Card* prevcard = card->prev;
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
    delete card;

}
   

void CardList::Append(Card card) {
    Card* newcard = new Card(card);
    if(!head){
        head = newcard;
        tail = newcard;
        head->prev = nullptr;
        head->next = nullptr;
        tail->next = nullptr;
        tail->prev = nullptr;
    }
    if(!head->next) {
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

//deletes original Card List and updates it with new Card List cards
/*CardList CardList::operator=(CardList* CardList) {
    while(this->head) {
        this->head = this->head->next;
        delete this->head->prev;
    }
    this->head = new Card;
    if (!CardList->head) {
        return *this;
    }
    else {
        this->head = CardList->head;
    }
    Card* newCard = new Card;
    newCard->next = nullptr;
    newCard->prev = head;
    head->next = newCard;
    Card* tempCard = CardList->head->next;
    while(tempCard) {
        newCard = tempCard; //uses overloaded operator
        tempCard = tempCard->next;
        newCard = newCard->next;
        newCard->next = nullptr;
    }
    tail = newCard; //tail equals to the last newCard
    return *this;
}*/

void CardList::Print() const{
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


Card* GetNextCard(Card* card) {
    if(!card->next) {
        return NULL;
    }
    return card->next;
}

