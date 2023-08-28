#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Seed the random number generator with the current time
   srand(time(0));

    // Generate a random number between 1 and 100
    int secretNumber = std::rand() % 100 + 1;

    int guess;
    bool hasGuessedCorrectly = false;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100. Try to guess it." << endl;

    while (!hasGuessedCorrectly) {
        cout << "Enter your guess: ";
        cin >> guess;
        if (guess < secretNumber) {
           cout << "Too low!" << endl;
        } else if (guess > secretNumber) {
            cout << "Too high!" << endl;
        } else {
            hasGuessedCorrectly = true;
            std::cout << "Congratulations! You guessed the number " <<endl;
        }
    }

    return 0;
}
