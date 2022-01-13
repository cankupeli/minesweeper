#ifndef TEXT_H
#define TEXT_H
#include <SFML/Graphics.hpp>


//! This class handles the creation and displaying of all text on the window.
class text{
    public:
        /**
         * Default constructor.
         */
        text();
        /**
         * Applies customazation to the text and sets the texts on screen position.
         * @param font The font to be applied on the text
         * @param color The color to be applied on the text
         * @param size The size to be applied on the text
         * @param xpos The x-position of the texts screen placement
         * @param ypos The y-position of the texts screen placement
         * @param textString The string to be set on the text
         * @attention If no string is given the string will be empty by default
         */
        void creation (sf::Font& font, sf::Color color, int size, int xpos, int ypos, std::string textString = "");
        /**
         * Sets the texts string 
         * @param stringSet the string to be set on text
         */
        void stringSetter(std::string stringSet);
        /**
         * Prints the text to a screen
         * @param screen The screen text will be printed to
         */
        void printing(sf::RenderWindow& screen);
    private:
        sf::Font font;
        sf::Text textShown;
};
#endif