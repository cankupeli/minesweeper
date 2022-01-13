#ifndef TEXT_H
#define TEXT_H
#include <SFML/Graphics.hpp>

/**
 * This class handles the creation and displaying of all text on the window.
 */
class text{
    public:
        /**
         * Default constructor.
         */
        text();
        /**
         * Applys customazation to the text and sets the texts on screen position.
         * @param font the font to be applied on the text
         * @param color the color to be applied on the text
         * @param size the size to be applied on the text
         * @param xpos the x-position of the texts screen placement
         * @param ypos the y-position of the texts screen placement
         * @param textString the string to be set on the text
         * @attention If no string is given the string will be empty by default
         */
        void creation (sf::Font font, sf::Color color, int size, int xpos, int ypos, std::string textString = "");
        /**
         * Sets the texts string 
         * @param stringSet the string to be set on text
         */
        void stringSetter(std::string stringSet);
        /**
         * prints the text to a screen
         * @param screen the screen text will be printed to
         */
        void printing(sf::RenderWindow& screen);
    private:
        sf::Font font;
        sf::Text textShown;
};
#endif