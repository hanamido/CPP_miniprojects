#include <iostream>

int main()
{
    std::string name; 

    std::cout << "Enter your name: ";
    std::getline(std::cin, name); 
    size_t name_len = name.length(); 

    // append() add another string to the string
    name.append("@gmail.com"); 
    // clear() clears out the string
    // at() get a specific char from the index of that string
    char firstLetter = name.at(0); 
    std::cout << "The first letter of your name is: " << firstLetter << '\n'; 

    // insert() inserts a character at an index
    // name.insert(0, "@");
    // std::cout << name; 
    
    // fine() returns position of the first matching character
    // std::cout << name.find('a'); 

    // erase() like splice in Python
    // name.erase(0, 3); 

    if (name.empty())
    {
        std::cout << "You didn't enter your name!\n"; 
    }
    else if (name_len > 12) 
    {
        std::cout << "Your name cannot be over 12 characters.\n"; 
    }
    else {
        std::cout << "Your username is now " << name << '\n'; 
    }

    return 0; 
}