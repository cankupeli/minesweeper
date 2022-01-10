#include "text.h"

text::text(){};
void text::creation (sf::Font font, sf::Color color, int size, int xpos, int ypos, std::string textString){
    this->font = font;
    textShown.setFont(this->font);
    textShown.setStyle(sf::Text::Bold);
    textShown.setFillColor(color);
    textShown.setPosition(xpos, ypos);
    textShown.setCharacterSize(size);
    textShown.setString(textString);
}
void text::stringSetter(std::string stringSet){
    textShown.setString(stringSet);
}
void text::printing(sf::RenderWindow& screen){
    screen.draw(textShown);
}