#ifndef BOARD_H
#define BOARD_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include <sstream>
#include "cell.h"
#include "tileImageDetermine.h"
enum gameDifficulty{
    easy, medium, hard
};
enum gameStatus{
    ongoing, lost, won
};
class board{
    public:
        board();
        void generation(gameDifficulty mode);
        void generationValue();
        void print();
        void flag (int xpos, int ypos);
        gameStatus status();
        gameStatus statusChecker();
        void statusSetter(gameStatus);
        void setPositionsValue(int xpos, int ypos);
        int getPositionsValue(int xpos, int ypos);
        void printing(sf::RenderWindow& screen, int xpos, int ypos, int imageLength);
        int size();
        int mineAmount();
        std::string flag();
        std::string time();
        void musicStopper();
        void musicPlayer();
    private:
        int xyCells;
        int amountOfMines;
        int flagsLeft;
        std::string gameTime;
        gameStatus currentStatus;
        sf::Clock timer;
        sf::Music backgroundMusic;
        std::vector<std::vector<cell> > gameBoard;
};
#endif