#include <iostream>

// cout << (insertion operator)
// cin >> (extraction operator)

int main()
{
    std::string name; 
    int age; 

    std::cout << "What's your age? ";
    std::cin >> age; 

    std::cout << "What's your full name? ";
    // std::cin >> name; 
    // to get input with a <space> in it
    // std::getline(std::cin, name); 
    // however if we accept user input with "cin" followed by getline, while still in input buffer there is a '\n' char
    // But it does not register the new line, so it'll just accept the char in the newline buffer
    std::getline(std::cin >> std::ws, name);  // std::ws will eliminate any newline characters or white spaces before any user input 

    std::cout << "Hello " << name << '\n'; 
    std::cout << "You are " << age << " years old" << '\n'; 

    return 0;
}