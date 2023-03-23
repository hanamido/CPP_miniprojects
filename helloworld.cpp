#include <iostream>

int main() 
{
    // standard character out to print
    std::cout << "I like pizza!" << std::endl;  // std::endl adds an extra line
    // but std::endl will flush the buffer
    // could just add \n instead in stdout
    std::cout << "It's really good!" << '\n'; 
    int x = 5;
    int y = 6;

    std::cout << x << '\n';
    std::cout << y << '\n'; 

    // string (objects that represent sequence of text)
    std::string name = "Hanami"; 
    std::string food = "sushi";
    std::string age = "21"; 
    std::cout << "Hello " << name << '\n';
    std::cout << "You are " << age << " years old" << '\n';  

    return 0; 
}