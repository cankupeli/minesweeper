#include "board.h"
#include <algorithm>
board::board():currentStatus(ongoing){
    backgroundMusic.openFromFile("audio/bck.wav");
    victoryMusic.openFromFile("audio/leagueVictory.wav");
    defeatMusic.openFromFile("audio/victory3.wav");
}
void board::generation(gameDifficulty mode){
    musicStopper(victoryMusic);
    musicStopper(defeatMusic);
    musicPlayer(backgroundMusic);
    if (mode == easy){
        xyCells = 9;
        amountOfMines = 10;
    }
    if (mode == medium){
        xyCells = 16;
        amountOfMines = 40;
    }
    if (mode == hard){
        xyCells = 24;
        amountOfMines = 99;
    }
    gameBoard.clear();
    flagsLeft = amountOfMines;
    timer.restart();
    currentStatus = ongoing;
    gameBoard.resize(xyCells);
    auto tileGenerator = [this]() {
        tile temp(0, 10);
        return temp;
    };
    auto rowGenerator = [this, tileGenerator]() {
        std::vector<tile> column(xyCells);
        std::generate(column.begin(), column.end(), tileGenerator);
        return column;
    };
    std::generate(gameBoard.begin(), gameBoard.end(), rowGenerator);
    /*for (int i = 0; i < xyCells; i++){
        std::vector<tile> column;
        for (int i = 0; i < xyCells; i++){
            tile temp(0, 10);
            column.push_back(temp);
        }
        gameBoard.push_back(column);
    }*/
}
void board::generationValue(){
    for (int i = 0; i < amountOfMines; i++){
        int xpos = rand() % xyCells;
        int ypos = rand() % xyCells;
        while (gameBoard[xpos][ypos].getHidden() == 9){
            xpos = rand() % xyCells;
            ypos = rand() % xyCells;
        }
        gameBoard[xpos][ypos].setHidden(9);
        if (xpos+1 <= xyCells-1)
            if (gameBoard[xpos+1][ypos].getHidden() != 9)
                gameBoard[xpos+1][ypos].increment();
        if (xpos+1 <= xyCells-1 && ypos+1 <= xyCells-1)
            if (gameBoard[xpos+1][ypos+1].getHidden() != 9)
                gameBoard[xpos+1][ypos+1].increment();
        if (ypos+1 <= xyCells-1)
            if (gameBoard[xpos][ypos+1].getHidden() != 9)
                gameBoard[xpos][ypos+1].increment();
        if (xpos-1 >= 0)
            if (gameBoard[xpos-1][ypos].getHidden() != 9)
                gameBoard[xpos-1][ypos].increment();
        if (xpos-1 >= 0 && ypos-1 >= 0)
            if (gameBoard[xpos-1][ypos-1].getHidden() != 9)
                gameBoard[xpos-1][ypos-1].increment();
        if (ypos-1 >= 0)
            if (gameBoard[xpos][ypos-1].getHidden() != 9)
                gameBoard[xpos][ypos-1].increment();
        if (xpos+1 <= xyCells-1 && ypos-1 >= 0)
            if (gameBoard[xpos+1][ypos-1].getHidden() != 9)
                gameBoard[xpos+1][ypos-1].increment();
        if (xpos-1 >= 0 && ypos+1 <= xyCells-1)
            if (gameBoard[xpos-1][ypos+1].getHidden() != 9)
                gameBoard[xpos-1][ypos+1].increment();
    }
    print();
}
void board::print(){
    std::cout << "------------------------------------------------" <<std::endl;
    for (int i = 0; i < xyCells; i++){
        for (int j = 0; j < xyCells; j++){
            std::cout << gameBoard[j][i].getHidden() << " ";
        }
        std::cout << "\n";
    }
    std::cout << "------------------------------------------------" <<std::endl;
}
void board::flag (int xpos, int ypos){
    if (gameBoard[xpos][ypos].getShown() == 10 && flagsLeft > 0){
        gameBoard[xpos][ypos].setShown(11);
        flagsLeft--;
    }
    else if (gameBoard[xpos][ypos].isFlag()){
        gameBoard[xpos][ypos].setShown(10);
        flagsLeft++;
    }
}
board::gameStatus board::status(){
    return currentStatus;
}
int board::mineAmount(){
    return amountOfMines;
}
void board::update(){
    int unflippedTiles = 0;
    bool lost = false;
    auto checkGameStatus = [&unflippedTiles, &lost](tile &c) {
        if (c.getShown() == 10 || c.getShown() == 11)
            unflippedTiles++;
        if (c.getShown() == 9)
            lost = true;
    };
    for (auto e: gameBoard)
        std::for_each(e.begin(), e.end(), checkGameStatus);
    if (unflippedTiles == mineAmount()){
        musicStopper(backgroundMusic);
        musicPlayer(victoryMusic);
        currentStatus = gameStatus::won;
    }
    else if (lost){
        musicStopper(backgroundMusic);
        musicPlayer(defeatMusic);
        currentStatus = gameStatus::lost;
    }
}

void board::setPositionsValue(int xpos, int ypos){
    if (!gameBoard[xpos][ypos].isFlag())
        gameBoard[xpos][ypos].setShown();
    if (gameBoard[xpos][ypos].getHidden() == 0){
        if (xpos > 0 && !gameBoard[xpos-1][ypos].getChecked())
            setPositionsValue(xpos-1, ypos);
        if (ypos > 0 && !gameBoard[xpos][ypos-1].getChecked())
            setPositionsValue(xpos, ypos-1);
        if (xpos > 0 && ypos > 0 && !gameBoard[xpos-1][ypos-1].getChecked())
            setPositionsValue(xpos-1, ypos-1);
        if (xpos+1 < xyCells && !gameBoard[xpos+1][ypos].getChecked())
            setPositionsValue(xpos+1, ypos);
        if (ypos+1 < xyCells && !gameBoard[xpos][ypos+1].getChecked())
            setPositionsValue(xpos, ypos+1);
        if (xpos+1 < xyCells && ypos+1 < xyCells && !gameBoard[xpos+1][ypos+1].getChecked())
            setPositionsValue(xpos+1, ypos+1);
        if (xpos > 0 && ypos+1 < xyCells && !gameBoard[xpos-1][ypos+1].getChecked())
            setPositionsValue(xpos-1, ypos+1);
        if (ypos > 0 && xpos+1 < xyCells && !gameBoard[xpos+1][ypos-1].getChecked())
            setPositionsValue(xpos+1, ypos-1);
    }
    return;
}
void board::printing(sf::RenderWindow& screen, int xpos, int ypos, int imageLength){
    int x = xpos;
    int y = xpos;
    sf::Texture cellT;
    cellT.loadFromFile("images/tile0.png");
    sf::Sprite cellS;
    cellS.setTexture(cellT);
    for (int i = 0; i < xyCells; i++){
        x = xpos + imageLength * i;
        for (int j = 0; j < xyCells; j++){
            y = ypos + imageLength * j;
            cellS.setPosition(x,y);
            if (currentStatus == lost){
                tileImageDetermine tile(gameBoard[i][j].getHidden());
                cellT.loadFromFile(tile.tile0().tile1().tile2().tile3().tile4().tile5().tile6().tile7().tile8().tile9().tile10().tile11());
            }
            else{
                tileImageDetermine tile(gameBoard[i][j].getShown());
                cellT.loadFromFile(tile.tile0().tile1().tile2().tile3().tile4().tile5().tile6().tile7().tile8().tile9().tile10().tile11());
            }
            screen.draw(cellS);
        }
    }
}
int board::size(){
    return xyCells;
}
std::string board::flag(){
    std::stringstream ss;
    ss << flagsLeft;
    return "FLAGS:" + ss.str();
}
std::string board::time(){
    if (status() == ongoing){
        int timeLeftSeconds = timer.getElapsedTime().asSeconds();
        std::stringstream ssTimer;
        ssTimer << timeLeftSeconds;
        gameTime = ssTimer.str();
    }
    return gameTime;
}
void board::musicStopper(sf::Music& music){
    music.stop();
}
void board::musicPlayer(sf::Music& music){
    music.play();
}