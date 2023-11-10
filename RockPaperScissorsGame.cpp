#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// Stubs
char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer);

int main(){
    char player;
    char computer;
    player = getUserChoice();
    cout << "Your choice: ";
    showChoice(player);
    computer = getComputerChoice();
    cout << "Computers choice: ";
    showChoice(computer);

    chooseWinner(player, computer);


return 0;
};

//Functions
char getUserChoice(){
    char player;
    cout << "Rock-Paper-Scissors Game!\n";
    do{
        cout << "*************************\n";
        cout << "*************************\n";
        cout << "'r' for rock\n";
        cout << "'p' for paper\n";
        cout << "'s' for scissors\n";
        cin >> player;
    }while(player != 'r' && player != 'p' && player != 's');


    return player;
}
char getComputerChoice(){
    srand(time(0));
    int num = rand() % 3 + 1;

    switch(num){
        case 1: return 'r';
        case 2: return 'p';
        case 3: return 's';
    }
    return 0;
}
void showChoice(char choice){
    switch(choice){
        case 'r': cout << "Rock\n";
            break;
        case 'p': cout << "Paper\n";
            break;
        case 's': cout << "Scissors\n";
            break;
        default: cout << "Invalid choice";
            break;
    }
}
void chooseWinner(char player, char computer){

    switch (player) {
        case 'r': if(computer == 'r'){
            cout << "It's a tie";
        }
        else if (computer == 'p'){
            cout << "You lose";
        }
        else{
            cout << "You win!";
        }
        break;

    }
    switch (player) {
        case 'p': if(computer == 'p'){
                cout << "It's a tie";

            }
            else if (computer == 's'){
                cout << "You lose";
            }
            else{
                cout << "You win!";
            }
            break;

    }
    switch (player) {
        case 's': if(computer == 's'){
                cout << "It's a tie";
            }
            else if (computer == 'p'){
                cout << "You win!";
            }
            else{
                cout << "you lose!";
            }
            break;

    }
}
