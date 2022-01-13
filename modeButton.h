#ifndef MODEBUTTON_H
#define MODEBUTTON_H
#include "board.h"


//! This class is for the buttons used to change the mode of the game
class modeButton{
    public:
        /**
         * Enums for the status of a button
         */
        enum button{
            active, inactive, hovered
        };
        /**
         * Default constructor
         */
        modeButton(){};
        /**
         * Applies the customization and positioning of the button
         * @param xpos x-position of the button
         * @param ypos y-position of the button
         * @param xmin Minimum x-boundry for buttons clickability
         * @param xmax Maximum x-boundry for buttons clickability
         * @param ymin Minimum y-boundry for buttons clickability
         * @param ymax Maximum y-boundry for buttons clickability
         * @param size The size to be applied on the text
         * @param text The string to be applied on the text
         * @param activeImage The image to be shown when button has an active state
         */
        void creation(int xpos, int ypos, int xmin, int xmax, int ymin, int ymax, int size, std::string text, std::string activeImage);
        /**
         * Checks if the button is in a clickable state
         * @param pos The position of the cursor
         * @returns True if button is clickable
         */
        bool clickable(sf::Vector2i pos);
        /**
         * Handles the activation of a click
         * @param board The board game to be regenerated
         * @param difficulty The difficulty for the board to be generated with
         */
        void activation(board& board, board::gameDifficulty difficulty);
        /**
         * Gets the status of the button (active, inactive and hovered)
         * @returns Button's status 
         */
        button status();
        /**
         * Sets the status of the button to hover
         */
        void setHover();
        /**
         * Sets the status of the button to inactive
         */
        void setInactive();
        /**
         * Sets the status of the button to in inactive from an active state
         */
        void deactivation();
        /**
         * Prints the button to a screen
         * @param screen The screen the button will be printed to
         */
        void printing (sf::RenderWindow& screen);
    private:
        int xmin;
        int xmax;
        int ymin;
        int ymax;
        button activity;
        sf::Font font;
        sf::Text buttonText;
        sf::Texture activeT;
        sf::Sprite activeS;
};
#endif