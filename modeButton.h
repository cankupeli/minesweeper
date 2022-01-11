#ifndef MODEBUTTON_H
#define MODEBUTTON_H
//#include <SFML/Graphics.hpp>
#include "board.h"
enum button{
    active, inactive, hovered
};
class modeButton{
    public:
        modeButton(){};
        void creation(int xpos, int ypos, int xmin, int xmax, int ymin, int ymax, int size, std::string text, std::string activeImage);
        bool clickable(sf::Vector2i pos);
        void activation(board& board, gameDifficulty difficulty);
        button status();
        void setHover();
        void setInactive();
        void deactivation();
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