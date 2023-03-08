# blackjack
assignment given by chatGPT

Write a C++ program that simulates a game of Blackjack between the user and the computer. The rules of Blackjack are as follows:

-The goal of the game is to get as close to 21 points as possible without going over.  
-The game starts with the user and the computer each being dealt two cards. The user's cards are both face-up, while one of the computer's cards is face-down.  
-The user can choose to "hit" (draw another card) or "stand" (keep their current hand) until they either reach 21 points, or go over 21 points (which is called "busting").  
-Once the user stands, the computer reveals its face-down card and draws additional cards until its hand is worth 17 points or more.  
-If the user and/or the computer busts, the game is over and the other player wins.  
-If both the user and the computer have hands worth 21 points or less, the player with the higher hand value wins.  
-In the case of a tie, the game is a draw.  

To complete this assignment, you'll need to use a combination of conditional statements, loops, and functions to implement the game logic. You'll also need to use random number generation to simulate the shuffling and dealing of cards. Here are some additional details and requirements to keep in mind:

-The game should be text-based, and should output the state of the game at each step (e.g., the cards dealt, the current hand value, etc.). 
-The program should validate the user's input and make sure they only enter "hit" or "stand".  
-The program should implement the standard rules of Blackjack, including the special cases of "ace" cards (which can be worth either 1 or 11 points) and "blackjack" (an initial hand worth 21 points consisting of an ace and a ten-point card).  
-You can assume that the computer always follows a fixed strategy (e.g., always hitting until its hand is worth 17 points or more).  
