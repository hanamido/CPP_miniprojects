#include <iostream>

// can have different versions of the same-named variables as long as they are in a different namespace
namespace first {
    int x = 1; 
}
namespace second 
{
    int x = 2; 
}

int main()
{
    // then don't need to put "first::x"
    // but would still need to put "second::x" if we want the x from the namespace "second"
    using namespace first; 
    int x = 0;

    // to get the version of x in the namespace "first"
    // :: is the scope resolution operator
    std::cout << first::x; 

    return 0; 
}