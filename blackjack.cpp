/*
blackjack.cpp
Spears Goode
3/3/23
*/

#include <iostream>
using namespace std;

  //=========
 //Structs
//=========
struct card {
    card(int r, char s) {
        suit = s;
        rank = r;
        if (r > 1 && r < 11) {
            val[0] = r;
            val[1] = 0;
        } 
        else if (r == 1) {
            val[0] = r;
            val[1] = 11;
        } else {
            val[0] = 10;
            val[1] = 0;
        }
    }
    char suit;
    int rank;
    int val[2];
};

struct deck {
    card* cards;
};

struct hand {
    card* cards;
    int value;
};

  //==================
 // Blackjack Class
//==================
class blackjack {
    deck deck;
    hand dealer_hand;
    hand player_hand;
public:
    blackjack();

};


int main()
{
    
    return 0;
}
