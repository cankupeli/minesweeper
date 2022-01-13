#ifndef BOARD_H
#define BOARD_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include <sstream>
#include "tile.h"
#include "tileImageDetermine.h"

 //! This class is the board game container which handles the boards creation, its components and it's interactions 
class board{
    public:
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
         * Default constructor
         */
        board();
        /**
         * Generates base container for board game with default unaltered tiles
         * @param mode Difficulty setting for board game
         */
        void generation(gameDifficulty mode);
        /**
         * Generates bombs and adjusts the value of surrounding tiles
         * @note The number of bombs generated is determined by the boards difficulty, more specifically the size of the container; see board::generation()
         */
        void generationValue();
        /**
         * Flags or unflags a tile
         * @param xpos x-position of tile
         * @param ypos y-position of tile
         */
        void flag(int xpos, int ypos);
        /**
         * Gets the status of the board game (ongoing, lost, won), see enum::gameStatus
         * @returns The status of the board game
         */
        gameStatus status();
        /**
         * Updates the status of the board game
         */
        void update();
        /**
         * Flips the tile to show the tiles true value
         * @param xpos x-position of the tile
         * @param ypos y-position of the tile
         */
        void setPositionsValue(int xpos, int ypos);
        /**
         * Prints the board to a screen
         * @param screen The screen the board will be printed to
         * @param xpos x-position of the tile
         * @param ypos y-position of the tile
         * @param imageLength Length of tile image, in pixels
         */
        void printing(sf::RenderWindow& screen, int xpos, int ypos, int imageLength);
        /**
         * Gets the size of the board as the amount of tiles per side
         * @returns The width/height of the board
         * @note The width and height will always be the same
         */
        int size();
        /**
         * Gets the amount of available flags
         * @returns amount of flag
         */
        std::string flag();
        /**
         * Gets the length of time the boards current session has been active
         * @return The time 
         * @note The time of the current session stops increasing at victory or defeat.
         */
        std::string time();
    private:
        int mineAmount();
        void print();
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