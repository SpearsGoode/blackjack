/*
blackjack.cpp
Spears Goode
3/3/23
*/

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

  //=========
 //Structs
//=========
struct card {
    string suit;
    int rank;
    int val[2];
    card(int r, string s) {
        suit = s;
        rank = r;
        if (r > 1 && r <= 10) {
            val[0] = r;
            val[1] = r;
        } 
        else if (r == 1) {
            val[0] = r;
            val[1] = 11;
        } else {
            val[0] = 10;
            val[1] = 10;
        }
    }
    void print_card() {
        switch (rank) {
        case 1:
            cout << "Ace ";
            break;
        case 2:
            cout << "Two ";
            break;
        case 3:
            cout << "Three ";
            break;
        case 4:
            cout << "Four ";
            break;
        case 5:
            cout << "Five ";
            break;
        case 6:
            cout << "Six ";
            break;
        case 7:
            cout << "Seven ";
            break;
        case 8:
            cout << "Eight ";
            break;
        case 9:
            cout << "Nine ";
            break;
        case 10:
            cout << "Ten ";
            break;
        case 11:
            cout << "Jack ";
            break;
        case 12:
            cout << "Queen ";
            break;
        case 13:
            cout << "King ";
            break;
        default:
            break;
        }
        cout << "of " << suit << " " << endl;
    }
};

struct hand {
    vector<card> cards;
    int val[2];
    int num_ace;
    hand() {
        val[0] = 0;
        val[1] = 0;
        num_ace = 0;
    }
    void add_card(card c) {
        cards.push_back(c);
        if (c.rank == 1){    
            if (num_ace == 0) {
                val[0]++;
                val[1] += 11;
                num_ace++;
            } else {
                val[0]++;
                val[1]++;
                num_ace++;
            }
        } else {
            val[0] += c.val[0];
            val[1] += c.val[1];
        }
    }
};

  //==================
 // Blackjack Class
//==================
class blackjack {
    vector<card> deck;
    hand dealer_hand;
    hand player_hand;
    void shuffle_deck() {
        random_device rd;
        default_random_engine rng(rd());
        shuffle(deck.begin(), deck.end(), rng);
    }
public:
    string winner;
    blackjack() {
        winner = "none";
        for (int i = 1; i <= 13; i++){
            deck.push_back(card(i, "Hearts"));
            deck.push_back(card(i, "Diamonds"));
            deck.push_back(card(i, "Spades"));
            deck.push_back(card(i, "Clubs"));
        }
        shuffle_deck();
    }
    
        // Prints the deck (testing)
    void print_deck() {
        cout << endl << "Deck:" << endl;
        for (int i = 0; i < deck.size(); i++)
            deck[i].print_card();
    }
    
        // Prints player hand
    void print_player_hand() {
        cout << endl << " Player Hand:" << endl;
        for (int i = 0; i < player_hand.cards.size(); i++)
            player_hand.cards[i].print_card();
        cout << " Value: " << player_hand.val[0];
        if (player_hand.num_ace > 0 && player_hand.val[1] <= 21)
            cout << " or " << player_hand.val[1];
        cout << endl;
    }

        // Prints dealer hand with one in the hole
    void print_dealer_hand() {
        cout << endl << " Dealer Hand:" << endl;
        for (int i = 0; i < dealer_hand.cards.size(); i++) {
            if (i == 1) continue;
            dealer_hand.cards[i].print_card();
        }
        cout << "and one in the hole" << endl;
    }
        // Prints dealer hand with both cards face up
    void print_full_dealer_hand() {

        cout << endl << " Dealer Hand:" << endl;
        for (int i = 0; i < dealer_hand.cards.size(); i++)
            dealer_hand.cards[i].print_card();
        cout << " Value: " << dealer_hand.val[0];
        if (dealer_hand.num_ace > 0 && dealer_hand.val[1] <= 21)
            cout << " or " << dealer_hand.val[1];
        cout << endl;
    }

        // Deals two cards to each player
    void deal() {
        for (int i = 0; i < 2; i++) {
            player_hit();
            dealer_hit();
        }
    }
    
        // Asks player to hit or stand until Bust, Blackjack, or stand
    void player_turn() {
        string choice;
        while (winner == "none") {
            cout << endl << "Do you want to hit or stand? (enter 'hit' or 'stand'): ";
            cin >> choice;
            cout << endl;
            if (choice == "stand") break;
            else if (choice == "hit") {
                player_hit();
                print_player_hand();    
            }
            else cout << "please enter a valid input." << endl;
        }
    }

        // Logic for dealer turn (hits until hard 17, Blackjack, or Bust)
    void dealer_turn() {
        print_full_dealer_hand();
        while (dealer_hand.val[0] < 17 && winner == "none") {
            cout << endl << "dealer hit" << endl;
            dealer_hit();
            print_full_dealer_hand();
        }
    }

        // Add a card from the deck to the player's hand
    void player_hit() {
        player_hand.add_card(deck[deck.size()-1]);
        deck.pop_back();
        if (player_hand.val[0] > 21) bust("player");
        if (player_hand.val[0] == 21 
        || player_hand.val[1] == 21) 
            twenty_one("player");
    }

        // Add a card from the deck to the dealer's hand
    void dealer_hit() {
        dealer_hand.add_card(deck[deck.size()-1]);
        deck.pop_back();
        if (dealer_hand.val[0] > 21) bust("dealer");
        if (dealer_hand.val[0] == 21 || dealer_hand.val[1] == 21) 
            twenty_one("dealer");
    }
        // Set winner to player that did not Bust
    void bust(string l) {
        cout << " Bust!" << endl;
        if (l == "player") winner = "dealer";
        if (l == "dealer") winner = "player";
    }

        // Set winner to the player that get Blackjack
    void twenty_one(string w) {
        cout << " Blackjack!" << endl;
        winner = w;
    }

        // Score the game if no one Busts of gets Blackjack
    void score() {
        cout << endl;
        if (winner == "player")
            cout << " You Win!" << endl;
        else if (winner == "dealer")
            cout << " House Wins!" << endl;
        else {
            int player_score = 0;
            int dealer_score = 0;
            if (player_hand.val[1] > 21)
                player_score = player_hand.val[0];
            else player_score = player_hand.val[1];
            if (dealer_hand.val[1] > 21)
                dealer_score = dealer_hand.val[0];
            else dealer_score = dealer_hand.val[1];
            if (player_score > dealer_score)
                cout << " You Win!" << endl;
            else if (player_score < dealer_score)
                cout << " House Wins!" << endl;
            else cout << " Draw!" << endl;
        }
        
    }
};


int main()
{
    blackjack BJ;
    BJ.deal();
    BJ.print_player_hand();
    BJ.print_dealer_hand();
    BJ.player_turn();
    BJ.dealer_turn();
    BJ.score();
    return 0;
}
