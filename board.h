#ifndef BOARD_H
#define BOARD_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include <sstream>
#include "tile.h"
#include "tileImageDetermine.h"
/**
 * Enum for the difficulty setting of the board
 */
enum gameDifficulty{
    easy, medium, hard
};
/**
 * Enum for the status of the board
 */
enum gameStatus{
    ongoing, lost, won
};
/**
 * This class is the board game container which handles the boards creation, its components and it's interactions 
 */
class board{
    public:
        /**
         * Default constructor
         */
        board();
        /**
         * Generates base container for board game with default unaltered tiles
         * @param mode difficulty setting for board game
         */
        void generation(gameDifficulty mode);
        /**
         * Generates bombs and corrosponding values surround said bomb for the containers tiles
         * @note The amoune of bombs generate is decided by the size of the container, see board::generation()
         */
        void generationValue();
        /**
         * Prints the hidden values of the board game to the terminal 
         */
        void print();
        /**
         * Flags or unflags a tile
         * @param xpos x-position of tile
         * @param ypos y-position of tile
         */
        void flag (int xpos, int ypos);
        /**
         * Gets the status of the board game
         * @returns status of the board game
         */
        gameStatus status();
        /**
         * Updates the status of the board game
         */
        void statusChecker();
        /**
         * Sets the shown valuation of the tile to equal that of it's hidden counter-part
         * @param xpos x-position of the tile
         * @param ypos y-position of the tile
         */
        void setPositionsValue(int xpos, int ypos);
        /**
         * Gets the shown valuation of a tile
         * @param xpos x-position of the tile
         * @param ypos y-position of the tile
         * @return The shown valuation of the tile
         */
        int getPositionsValue(int xpos, int ypos);
        /**
         * Prints the board to a screen
         * @param screen The screen the board will be printed to
         * @param xpos x-position of the tile
         * @param ypos y-position of the tile
         * @param imageLength length of tile image, in pixels
         */
        void printing(sf::RenderWindow& screen, int xpos, int ypos, int imageLength);
        /**
         * Gets the size of the board as amount of tiles per side
         * @return xyCells
         */
        int size();
        /**
         * Gets the total number of bombs on the board
         * @return amountOfMines
         */
        int mineAmount();
        /**
         * Gets the amount of available flags
         * @return flagsLeft as a string
         */
        std::string flag();
        /**
         * Gets the amount of time the board has been active
         * @return timer 
         */
        std::string time();
    private:
        void musicPlayer(sf::Music& music);
        void musicStopper(sf::Music& music);
        int xyCells;
        int amountOfMines;
        int flagsLeft;
        std::string gameTime;
        gameStatus currentStatus;
        sf::Clock timer;
        sf::Music backgroundMusic, victoryMusic, defeatMusic;
        std::vector<std::vector<tile> > gameBoard;
};
#endif