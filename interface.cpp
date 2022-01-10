#include "interface.h"

void hover(modeButton& currentButton, sf::Vector2i pos){
    if (currentButton.clickable(pos) && currentButton.status() == button::inactive){
        currentButton.setHover();
    }
    if (!currentButton.clickable(pos) && currentButton.status() == button::hovered){
        currentButton.setInactive();
    }
}
bool withinBoard (sf::Vector2i pos, int boardXpos, int boardYpos, int tileLength, int amountOfTiles){
    int boardLength = tileLength * amountOfTiles;
    if (pos.x > boardXpos && pos.y > boardYpos && pos.x < (boardXpos + boardLength) && pos.y < (boardYpos + boardLength)){
        return true;
    }
    return false;
}
interface::interface(int screenWidth, int screenHeight, int boardXpos, int boardYpos, int tileLength):screenWidth(screenWidth), screenHeight(screenHeight), boardXpos(boardXpos), boardYpos(boardYpos), tileLength(tileLength), app(sf::VideoMode(screenWidth, screenHeight), "Minesweeper"){
    backgroundT.loadFromFile("images/background.png");
    backgroundS.setTexture(backgroundT);
    navT.loadFromFile("images/nav.png");
    navS.setTexture(navT);
    font.loadFromFile("font/lato.ttf");

    title.creation(font, sf::Color::Black, 100, 100, 20, "MINESWEEPER");
    timerT.creation(font, sf::Color::White, 80, 1700, 20);
    flagsT.creation(font, sf::Color::White, 80, 950, 20);
    victory.creation(font, sf::Color(228, 179, 99), 130, 170, 900, "DEFUSED");
    detonated.creation(font, sf::Color(107,5,4), 100, 140, 900, "DETONATED");

    easyMode.creation(50, 300, 0, 900, 250, 450, 60, "EASY MODE", "images/active.png");
    mediumMode.creation(50, 500, 0, 900, 450, 650, 60, "MEDIUM MODE", "images/active.png");
    hardMode.creation(50, 700, 0, 900, 650, 850, 60, "HARD MODE", "images/active.png");
    quitMode.creation(400, 1250, 0, 900, 1200, 1400, 60, "QUIT", "images/active.png");
    easyMode.activation(minesweeperBoard, gameDifficulty::easy);
}
void interface::update(){
    while (app.isOpen()) 
    {
        int amountOfTiles = minesweeperBoard.size();
        sf::Vector2i pos = sf::Mouse::getPosition(app);
        int x = (pos.x-boardXpos) / tileLength;
        int y = (pos.y-boardYpos) / tileLength;
        sf::Event e;
        while (app.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                app.close();
            if (e.type == sf::Event::MouseButtonReleased){
                if (withinBoard(pos, boardXpos, boardYpos, tileLength, amountOfTiles)){
                    if (e.mouseButton.button == sf::Mouse::Left){ //if left click, that cell shows hidden cell
                        minesweeperBoard.setPositionsValue(x,y);
                    }
                    if (e.mouseButton.button == sf::Mouse::Right){ //if right click, that cell becomes flag 
                        minesweeperBoard.flag(x,y);
                    }
                }
                if(e.mouseButton.button == sf::Mouse::Left){
                    if (easyMode.clickable(pos)){
                        easyMode.activation(minesweeperBoard, gameDifficulty::easy);
                        mediumMode.deactivation();
                        hardMode.deactivation();
                    }
                    if (mediumMode.clickable(pos)){
                        mediumMode.activation(minesweeperBoard, gameDifficulty::medium);
                        easyMode.deactivation();
                        hardMode.deactivation();
                    }
                    if (hardMode.clickable(pos)){
                        hardMode.activation(minesweeperBoard, gameDifficulty::hard);
                        mediumMode.deactivation();
                        easyMode.deactivation();
                    }
                    if (quitMode.clickable(pos)){
                        app.close();
                    }
                }
            }
        }
        hover(easyMode, pos);
        hover(mediumMode, pos);
        hover(hardMode, pos);
        hover(quitMode, pos);
        flagsT.stringSetter(minesweeperBoard.flag());
        timerT.stringSetter("TIMER: " + minesweeperBoard.time() + "s");
        print();
    }
}
void interface::print(){
    app.clear();
    app.draw(backgroundS);                                  //WALLPAPER BACKGROUND
    app.draw(navS);                                         //NAVIGATION BACKGROUND
    title.printing(app);
    easyMode.printing(app);                                 //EASY MODE
    mediumMode.printing(app);                               //MEDIUM MODE  
    hardMode.printing(app);                                 //HARD MODE
    quitMode.printing(app);                                 //QUIT
    minesweeperBoard.printing(app, boardXpos, boardYpos, tileLength);  //BOARD
    flagsT.printing(app);
    timerT.printing(app);
    if (minesweeperBoard.statusChecker()==won){                        //VICTORY
        minesweeperBoard.statusSetter(won);
        victory.printing(app);
    }
    if (minesweeperBoard.statusChecker()==lost){                        //LOST
        detonated.printing(app);
    }
    app.display();
}
