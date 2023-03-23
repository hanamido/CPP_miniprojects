/**
 * Program that is essentially a number guessing game with higher stakes.
 * The user deposits an initial amount to play the game, then they will guess
 * a number between 1-10 and enters the betting amount.
 * If they win, they will get 10 times the number of money betted.
 * If they lose, they will lose they will lose the betting amount. 
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>  // to seed the rng

using namespace std; 

void drawLine(int n, char symbol);  // draws the lines for the game

int main() 
{
    string playerName; 
    int amount;  // player's balance amount
    int bettingAmount;  // player's bet
    int guess;  //player's guess
    int correctNum;  // number to guess
    char choice;  // hold player's choice to continue or not

    /* PROMPT/GET user's name and deposit amount */
    // Get user's name and deposit amount
    cout << "What is your name? "; 

    /* EXPLAIN rules to the user */

    /* GENERATE the random number */

    /* OBTAIN user's guess and betting amount per round */

    /* INFORM user of their win or loss */

    /* CONTINUE game until user wants to stop */
}