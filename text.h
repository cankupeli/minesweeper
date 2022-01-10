#ifndef TEXT_H
#define TEXT_H
#include <SFML/Graphics.hpp>
class text{
    public:
        text();
        void creation (sf::Font font, sf::Color color, int size, int xpos, int ypos, std::string textString = "");
        void stringSetter(std::string stringSet);
        void printing(sf::RenderWindow& screen);
    private:
        sf::Font font;
        sf::Text textShown;
};
#endif