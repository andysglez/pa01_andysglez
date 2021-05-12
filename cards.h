//cards.h
//Andy Gonzalez
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H
#endif
#include <string>
using namespace std;
// Use this file to define all your classes and public functions
// You should design your program with OOP prinicples using classes
// An example of class design would be having Card, CardList and Player as Classes.
// Card represent Node in your LinkedList which has some data in it
// CardList can be your LinkedList Class which has operations such as append, remove etc
// Player class represents your game player
// Think about the public functions that should be part of each class. (All public function need to be tested in unit testing)
// One of the important functions is search / find which is essential for players to find cars in their opponent's "hand"
// Make sure you overload the desired operators
// This is not the fixed design. We are not expecting exactly 3 classes. You can do with less or more.
// Important thing to consider is abstraction.


struct Card {
    Card() {suit = 'h'; value = '6';};
    Card(char Suit, char val) {suit = Suit; value = val;};
    Card operator=(Card card);
    bool operator==(const Card& card) const;
    bool operator==(const Card* card) const;
    char suit;
    char value;
    Card* next;
    Card* prev;
    void print();
};

class CardList {
    public:
        void Append(Card card);
        void Remove(Card* card);
        void Print() const;
        ~CardList();
        Card* SearchForCard(Card* card);
        CardList() {head = nullptr; tail = nullptr;};
        void SearchRemove(Card* card);
        Card* GetNextCard(Card* card);
        Card* GetTopCard() {return head;};
        bool CompareLists(CardList cards1, CardList cards2);
        //Card* getFirstCard() {return head;};
        //CardList operator<<(const CardList cardlist);
    private:
        
        Card* head;
        Card* tail;
        
};

struct Player {
    Player() {name = "NoName";};
    Player(string Name) {name = Name;};
    string name;
    CardList* cards;
};
