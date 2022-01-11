#ifndef INTERFACE_H
#define INTERFACE_H
#include <time.h>
//#include <SFML/Audio.hpp>
#include "modeButton.h"
#include "board.h"
#include "text.h"

class interface{
    public:
        interface(int screenWidth, int screenHeight, int boardXpos, int boardYpos, int tileLength);
        /**
        * Updates the window by updating the current session time, flags used, tiles clicked and board status
        */
        void update();
        /**
        * Prints all components of the window
        */
        void print();
    private:
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