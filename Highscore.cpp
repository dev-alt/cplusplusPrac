#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iterator>
#include <algorithm>
using namespace std;


enum Difficulty{
    EASY,
    Medium,
    Hard,
    Ultra_Hard,
};

void StartGame(Difficulty level){
    switch(level){
        case Difficulty::EASY:
            std::cout << "Starting an easy Game.\n";
            break;
        case Difficulty::Medium:
            std::cout << "Starting game on medium level.\n";
            break;
        case Difficulty::Hard:
            std::cout << "Starting game on Hard.\n";
            break;
        case Difficulty::Ultra_Hard:
            std::cout << "you have chosen Ultra Hard,\n";
            break;
        default:
            std::cout<<"Invalid Choice.\n";
            break;
    }
}

struct Player{
    std::string name;
    int score;
};
bool comparePlayers(const Player& a, const Player& b){
    return a.score > b.score;
}

class HighscoreSystem{
private:
    std::vector<Player> highscores;
public:
    void addScore(const std::string& playerName, int playerScore){
        Player newPlayer(playerName, playerScore);
        highscores.push_back(newPlayer);
        std::sort(highscores.begin(), highscores.end(), comparePlayers);

    }
    void displayTopScores(int topN){
        std::cout << "Top " << topN << " Highscores\n";
        for(int i = 0; i < std::min(topN, static_cast<int>(highscores.size())); ++i){
            std::cout << i + 1 << ". " << highscores[i].name << " - " << highscores[i].score << "\n";
        }
    }
};

int main(){
    HighscoreSystem highscoreSystem;
    Difficulty selectedLevel = Difficulty::Medium;
    StartGame(selectedLevel);

    // Example: Adding scores
    highscoreSystem.addScore("Player1", 1500);
    highscoreSystem.addScore("Player2", 1200);
    highscoreSystem.addScore("Player3", 1800);
    highscoreSystem.addScore("Player4", 1600);

    // Example: Displaying top 3 scores
    highscoreSystem.displayTopScores(3);

};
