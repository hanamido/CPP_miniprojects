#include <iostream>

int main()
{
    // int grade = 75;
    // (grade >= 60) ? std::cout << "You pass!\n" : std::cout << "You fail!\n"; 

    // int number = 9;
    // number % 2 ? std::cout << "ODD\n" : std::cout << "EVEN\n"; 

    std::string hungerStatus; 

    std::cout << "Are you hungry? (\"Yes\" or \"No\")\n";
    std::cin >> hungerStatus; 
    
    // hungry ? std::cout << "You are hungry\n" : std::cout << "You are full\n"; 
    std::cout << (hungerStatus == "Yes" ? "You are hungry\n" : "You are full\n"); 

    return 0; 
}