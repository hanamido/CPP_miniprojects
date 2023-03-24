/**
 * Program that is a casino number guessing game.
 * The user deposits an initial amount to play the game, then they will guess
 * a number between 1-10 and enters the betting amount.
 * If they win, they will get 10 times the number of money betted.
 * If they lose, they will lose the betting amount. 
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>  // to seed the rng

using namespace std; 

// Function declarations
void drawLine(int n, char symbol);  // draws separators for various parts
void explainRules();
bool validateAmount(int currAmount, char compare, int checkAmount); 
bool validateNumerical(string input);
bool validateDeposit(string deposit);
bool validateBettingAmount(string bettingAmount, int deposit);
bool validateGuess(string guess);

int main() 
{
    string playerName; 
    string depositStr;  // player's deposit (in str)
    int deposit;  // player's deposit (after checking)
    string bettingAmountStr;  // player's bet (in str)
    int bettingAmount;  // player's betting amount (after validation)
    int balance = deposit;  // player's remaining balance
    int totalWon;  // total won per round
    string guessStr;  // player's guess (in str)
    int guess;  //player's guess (after validation)
    int correctNum;  // number to guess
    char choice;  // hold player's choice to continue or not
    char choiceFromNegative;  // player's choice to continue from a negative balance

    /* Initialize game title */
    drawLine(50, '*'); 
    cout << "\nCASINO GAME: NUMBER GUESSING GAME\n";
    drawLine(50, '*');  

    /* PROMPT/GET user's name and deposit amount */
    // Get user's name and deposit amount
    cout << "\nEnter your full name: "; 
    getline(cin, playerName); 
    cout << "Hello, " << playerName << "!\n"; 

    /* EXPLAIN rules to the user */
    explainRules(); 

    /* GENERATE the random number */
    srand(time(NULL)); 
    correctNum = 1 + (rand() % 10); 

    /* OBTAIN player's initial deposit amount and bet amount */
promptDeposit: 
    cout << "\nEnter your initial deposit amount: $";
    cin >> depositStr;
    deposit = stoi(depositStr); 
    cout << "deposit amount " << deposit << '\n';
    // if deposit amount is numerical 
    bool validateDepositResult = validateDeposit(depositStr); 
    if (validateDeposit(depositStr) == false)
    {
        goto promptDeposit;
    }
    deposit = stoi(depositStr); 

    // Loop while player still has money
    while (balance > 0)
    {
    promptBettingAmount: 
        cout << "\nEnter your betting amount: $";
        cin >> bettingAmountStr;  

        // Validate that betting amount is numerical, greater than 0, and less than deposit
        bool validateBetResult = validateBettingAmount(bettingAmountStr, deposit); 
        if (validateBetResult == false)
        {
            goto promptBettingAmount; 
        }
        bettingAmount = stoi(bettingAmountStr); 
    
    promptGuess:
        cout << "Enter your guess: "; 
        cin >> guessStr; 
        bool validateGuessResult = validateGuess(guessStr); 
        if (validateGuessResult == false)
        {
            goto promptGuess; 
        }
        guess = stoi(guessStr); 

        /* INFORM user of their win or loss */
        if (guess < correctNum || guess > correctNum) {
            deposit -= bettingAmount; 
            cout << "Sorry, you lost $" << bettingAmount << '\n'; 
            cout << "Your new balance: $" << deposit << "\n\n"; 
        } else {  // if player gets the correct amount
            totalWon = bettingAmount * 10; 
            deposit += totalWon; 
            cout << "Congratulations! You won $" << totalWon << '\n'; 
            // if deposit is now negative, exit right away
            if (validateAmount(deposit, '<', 0)) {
                goto exit;
            }
            cout << "Your new balance: $" << deposit << "\n\n";  
            // Regenerate the number if the guess was correct
            srand(time(NULL)); 
            correctNum = 1 + (rand() % 10); 
        }

        if (validateAmount(deposit, '=', 0) == true)  // if the player has no more money left
        {
        promptReplay:
            cout << "Sorry, you have no more money left.\nWould you like to enter more money to play again? (Enter 'y' or 'Y' for yes, 'n' or 'N' for no): ";
            cin >> choice; 
            if (choice == 'y' || choice == 'Y') {
                goto promptDeposit; 
            }
            else if (choice == 'n' || choice == 'N') {
                goto exit; 
            }
            else {
                cout << "Please only enter 'y', 'Y', 'n', or 'N'.\n"; 
                goto promptReplay; 
            }
        }

        /* CONTINUE game until user wants to stop */
    confirmChoice:
        cout << "Would you like to continue? (Enter 'y' or 'Y' to continue, 'n' or 'N' to quit.) ";
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            continue; 
        }
        else if (choice == 'N' || choice == 'n') goto exit; 
        else {  // invalid choice, reprompt user
            cout << "\nPlease only enter one of the following: 'y', 'Y', 'n', or 'N'.\n";
            goto confirmChoice;
        }
    }
    exit: 
        cout << "Thanks for playing!\n";
        cout << "Your Final Balance: $" << deposit << '\n'; 
    return 0; 
}

// Function to draw a certain amount of a symbol to separate various parts of the app
void drawLine(int n, char symbol)
{
    int i;
    for (i = 0; i <= n; i++) {
        cout << symbol; 
    }
}

// Function to explain the rules to the player
void explainRules() 
{
    string depositRule = "1. Enter an initial deposit amount to start the game.\n"; 
    string guessRule = "2. Choose a number from 1 to 10 and enter your bet.\n";
    string winRule = "3. If you win you will get 10 times the amount.\n"; 
    string loseRule = "4. If you lose you will lose your your betting amount.\n";
    string continueRule = "5. When prompted, press 'Y' to continue and 'N' to quit the game.\n"; 

    cout << "\n"; 
    drawLine(50, '-'); 
    cout << "\nRULES OF THE GAME\n"; 
    drawLine(50, '-');
    cout << '\n';
    cout << '\t' << depositRule;
    cout << '\t' << guessRule;
    cout << '\t' << winRule;
    cout << '\t' << loseRule;
    cout << '\t' << continueRule; 
}

// Function to check if an amount is within limits
bool validateAmount(int currAmount, char compare, int checkAmount)
{
    bool validateFlag = false; 
    switch (compare)
    {
        case '>':
            if (currAmount > checkAmount) {
                validateFlag = true; 
            } 
            break; 
        case '=':
            if (currAmount == checkAmount) {
                validateFlag = true;
            }
            break; 
        case '<':
            if (currAmount < checkAmount) {
                validateFlag = true; 
            }
            break;
    }
    return validateFlag; 
}

// Validate that input is numerical
bool validateNumerical(string input)
{
    int i;
    int inputLen = input.length(); 
    for (i = 0; i < inputLen; i++) 
    {
        if (isdigit(input[i]) == false) return false; 
    }
    return true; 
}

/**
 * Function to validate player's deposit.
 * Parameters: 
 *      input: the input being validated
*/
bool validateDeposit(string deposit) 
{
    // if deposit entered is not a number
    if (validateNumerical(deposit) == false) {
        cout << "Please only enter a number for the deposit.\n";
        return false; 
    } else {  // check if deposit entered is greater than 0
        int newDeposit = stoi(deposit);
        if (validateAmount(newDeposit, '>', 0) == false) {
            cout << "Please only enter a deposit amount greater than 0.\n"; 
            return false; 
        } 
        return true; 
    }
}

/**
 * Function to validate player's betting amount. 
*/
bool validateBettingAmount(string bettingAmount, int deposit)
{
    // if bettingAmount entered is not a number
    if (validateNumerical(bettingAmount) == false) {
        cout << "Please only enter a number for the bet.\n";
        return false; 
    } else {  // check if bettingAmount entered is within bounds 
        int newBettingAmount = stoi(bettingAmount);
        if (validateAmount(newBettingAmount, '>', 0) == false) {
            cout << "Please only enter a bet greater than 0.\n"; 
            return false; 
        } 
        // check if bettingAmount is less than deposit
        else if (validateAmount(newBettingAmount, '<', deposit) == false) {
            if (validateAmount(newBettingAmount, '=', deposit)) return true; 
            cout << "Please enter a betting amount less than or equal to the balance $" << deposit << '\n'; 
            return false; 
        }
        return true; 
    }
}

/**
 * Function to validate player's guess. 
*/
bool validateGuess(string guess)
{
    // if guess entered is not a number
    if (validateNumerical(guess) == false) {
        cout << "Please only enter a number for the guess.\n";
        return false; 
    } else {  // check if guess is within bounds
        int newGuess = stoi(guess);
        if (validateAmount(newGuess, '>', 0) == false || validateAmount(newGuess, '<', 10) == false) {
            // if guess is equal to 10, it's a valid guess
            if (validateAmount(newGuess, '=', 10) == true) return true; 
            cout << "Please only enter a guess between 1 and 10.\n"; 
            return false; 
        } 
        return true; 
    }
}