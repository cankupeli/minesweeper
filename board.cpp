#include "board.h"

board::board():currentStatus(ongoing){
    backgroundMusic.openFromFile("audio/bck.wav");
}
void board::generation(gameDifficulty mode){
    backgroundMusic.play();
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
    for (int i = 0; i < xyCells; i++){
        std::vector<cell> column;
        for (int i = 0; i < xyCells; i++){
            cell temp(0, 10);
            column.push_back(temp);
        }
        gameBoard.push_back(column);
    }
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
gameStatus board::status(){
    return currentStatus;
}
int board::mineAmount(){
    return amountOfMines;
}
gameStatus board::statusChecker(){
    int bombs = 0;
    bool lost = false;
    for (auto e: gameBoard){
        for (auto i: e){
            if (i.getShown() == 10 || i.getShown() == 11){
                bombs++;
            }
            if (i.getShown() == 9)
                lost = true;
        }
    }
    if (bombs == mineAmount()){
        musicStopper();
        return gameStatus::won;
    }
    if (lost)
        return gameStatus::lost;
    return gameStatus::ongoing;
}
void board::statusSetter(gameStatus current){
    currentStatus = current;
}
void board::setPositionsValue(int xpos, int ypos){
    if (!gameBoard[xpos][ypos].isFlag()){
        gameBoard[xpos][ypos].setShown();
        if (gameBoard[xpos][ypos].isBomb()){
            currentStatus = lost;
            musicStopper();
        }
    }
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
int board::getPositionsValue(int xpos, int ypos){
    return gameBoard[xpos][ypos].getShown();
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
    std::stringstream ss;                                   //FLAGS
    ss << flagsLeft;
    return "FLAGS:" + ss.str();
}
//if the game is not won or lost, update the clock. print the last updated clock
std::string board::time(){
    if (status() == ongoing){
    int timeLeftSeconds = timer.getElapsedTime().asSeconds();
    std::stringstream ssTimer;
    ssTimer << timeLeftSeconds;
    gameTime = ssTimer.str();
    }
    return gameTime;
}
void board::musicStopper(){
    backgroundMusic.stop();
}
void board::musicPlayer(){
    backgroundMusic.play();
}