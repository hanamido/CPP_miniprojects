#include <iostream>

int main()
{
    int day;
    std::cout << "Enter a day of the week to view the corresponding day (1-7): "; 
    std::cin >> day; 

    switch (day) {
        case 1: 
            std::cout << "It is Monday\n";
            break;
        case 2:
            std::cout << "It is Tuesday\n";
            break;
        case 3: 
            std::cout << "It is Wednesday\n"; 
            break;
        case 4:
            std::cout << "It is Thursday\n";
            break;
        case 5: 
            std::cout << "It is Friday\n";
            break;
        case 6: 
            std::cout << "It is Saturday\n";
            break;
        case 7:
            std::cout << "It is Sunday\n";
            break;
        default:
            std::cout << "Please only enter numbers (1-7)\n"; 
    }

    return 0; 
}