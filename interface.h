#ifndef INTERFACE_H
#define INTERFACE_H
#include <time.h>
#include "modeButton.h"
#include "board.h"
#include "text.h"
/**
 * This class acts as a wrapper class for the program
 */
class interface{
    public:
        /**
         * Creates the screen and all its components 
         * @param screenWidth The width of the screen in pixels
         * @param screenHeight The height of the screen in pixels
         * @param boardXpos The x-position of the top left corner of the board, in pixels
         * @param boardYpos The y-position of the top left corner of the board, in pixels
         * @param tileLength The length of each tile, in pixels
         */
        interface(int screenWidth, int screenHeight, int boardXpos, int boardYpos, int tileLength);
    private:
        void update();
        void print();
        sf::RenderWindow app;
        board minesweeperBoard;
        int screenWidth, screenHeight, boardXpos, boardYpos, tileLength;
        sf::Font font;
        sf::Texture backgroundT, navT;
        sf::Sprite backgroundS, navS;
        text title, timerT, flagsT, victory, detonated;
        modeButton easyMode, mediumMode, hardMode, quitMode;
};
void hover(modeButton& currentButton, sf::Vector2i pos);
bool withinBoard (sf::Vector2i pos, int boardXpos, int boardYpos, int tileLength, int amountOfTiles);
#endif