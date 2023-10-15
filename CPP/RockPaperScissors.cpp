#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int playerChoice;
    int computerChoice;
    int playerScore = 0;
    int computerScore = 0;

    cout << "Let's play Rock, Paper, Scissors! We will play 10 rounds." << endl;

    for (int round = 1; round <= 10; round++) {
        cout << "Round " << round << endl;
        cout << "1. Rock\n2. Paper\n3. Scissors" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> playerChoice;

        // Ensure the player's choice is valid (1, 2, or 3)
        if (playerChoice < 1 || playerChoice > 3) {
            cout << "Invalid choice. Please choose 1, 2, or 3." << endl;
            return 1;
        }

        // Generate a random choice for the computer (1 for Rock, 2 for Paper, 3 for Scissors)
        computerChoice = rand() % 3 + 1;

        // Display the computer's choice
        cout << "Computer chose: ";
        switch (computerChoice) {
            case 1:
                cout << "Rock" << endl;
                break;
            case 2:
                cout << "Paper" << endl;
                break;
            case 3:
                cout << "Scissors" << endl;
                break;
        }

        // Determine the winner of this round
        if (playerChoice == computerChoice) {
            cout << "It's a tie!" << endl;
        } else if ((playerChoice == 1 && computerChoice == 3) ||
                   (playerChoice == 2 && computerChoice == 1) ||
                   (playerChoice == 3 && computerChoice == 2)) {
            cout << "You win this round!" << endl;
            playerScore++;
        } else {
            cout << "Computer wins this round!" << endl;
            computerScore++;
        }
    }

    cout << "Game over! Here's the final score:" << endl;
    cout << "Your Score: " << playerScore << endl;
    cout << "Computer's Score: " << computerScore << endl;

    if (playerScore > computerScore) {
        cout << "You win the game!" << endl;
    } else if (playerScore < computerScore) {
        cout << "Computer wins the game!" << endl;
    } else {
        cout << "It's a tie game!" << endl;
    }

    return 0;
}
