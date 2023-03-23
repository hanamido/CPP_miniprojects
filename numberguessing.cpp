#include <iostream>

int main() 
{
    int num;
    int guess;
    // tries need to be initialized to 0
    int tries = 0; 

    // seed the rng
    srand(time(NULL)); 
    num = (rand() % 100) + 1;

    std::cout << "******** NUMBER GUESSING GAME ********\n";

    do {
        // Prompt user to enter a guess
        std::cout << "Enter a guess between (1-100): ";
        std::cin >> guess;
        tries++; 
        std::cout << "Try # " << tries << '\n';

        // Check guess number
        if (guess > num)
        {
            std::cout << "Too high!\n";
        }
        else if (guess < num)
        {
            std::cout << "Too low!\n"; 
        }
        else {
            std::cout << "CORRECT! # of tries: " << tries << '\n';
        } 
    } while (guess != num); 

    std::cout << "****************************\n";

    return 0;
}