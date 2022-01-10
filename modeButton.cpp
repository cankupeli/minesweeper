#include "modeButton.h"


void modeButton::creation(int xpos, int ypos, int xmin, int xmax, int ymin, int ymax, int size, std::string text, std::string activeImage){
    this->xmin = xmin;
    this->xmax = xmax;
    this->ymin = ymin;
    this->ymax = ymax;
    this->activity = inactive;
    font.loadFromFile("font/lato.ttf");
    buttonText.setFont(font);
    buttonText.setCharacterSize(size);
    buttonText.setFillColor(sf::Color::Black);
    buttonText.setStyle(sf::Text::Bold);
    buttonText.setPosition(xpos,ypos);
    buttonText.setString(text);

    activeT.loadFromFile(activeImage);
    activeS.setTexture(activeT);
    activeS.setPosition(xmin, ymin);
}
bool modeButton::clickable(sf::Vector2i pos){
    if (pos.x > xmin && pos.y > ymin && pos.x <= xmax && pos.y <= ymax)
        return true;
    else
        return false;
}
void modeButton::activation(board& board, gameDifficulty difficulty){
    activity = active;
    buttonText.setFillColor(sf::Color::White);
    board.generation(difficulty);
    board.generationValue();
}
button modeButton::status(){
    return activity;
}
void modeButton::setHover(){
    activity = hovered;
}
void modeButton::setInactive(){
    activity = inactive;
}
void modeButton::deactivation(){
    activity = inactive;
    buttonText.setFillColor(sf::Color::Black);
}
void modeButton::printing (sf::RenderWindow& screen){
    if (activity == hovered){
        activeT.loadFromFile("images/hovered.png");
        screen.draw(activeS);
    }
    if (activity == active){
        activeT.loadFromFile("images/active.png");
        screen.draw(activeS);
    }
    screen.draw(buttonText);
}