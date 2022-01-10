#include "interface.h"
//9x9 (10mines)
//16x26 (40mines)
//24x24 (99mines)
// 0 = open nothing
// 1 to 8 = numbers
// 9 = bomb
// 10 = untouched
// 11 = bombflag

int main()
{
    srand(time(0));
    interface game(2200,1400, 950, 150, 50);
    game.update();
    /*board steve;
    steve.generation(easy);
    steve.generationValue();
    steve.print();
    int screenWidth = 2200;
    int screenHeight = 1400;
    int boardXpos = 950;
    int boardYpos = 150;
    int tileLength = 50;

    sf::Font font;              
    font.loadFromFile("font/lato.ttf");
    sf::Music music;
    music.openFromFile("audio/bck.wav");
    music.play();

    sf::Clock timer;
    sf::RenderWindow app(sf::VideoMode(screenWidth, screenHeight), "Minesweeper");

    sf::Texture backgroundT;
    backgroundT.loadFromFile("images/background2.png");
    sf::Sprite backgroundS;
    backgroundS.setTexture(backgroundT);

    sf::Texture navT;
    navT.loadFromFile("images/nav2.png");
    sf::Sprite navS;
    navS.setTexture(navT);


    sf::Text title;             //TITLE
    title.setFont(font);
    title.setCharacterSize(100);
    title.setFillColor(sf::Color::Black);
    title.setStyle(sf::Text::Bold);
    title.setPosition(100,20);
    title.setString("MINESWEEPER");

    sf::Text timerT;            //TIMER
    timerT.setFont(font);
    timerT.setCharacterSize(80);
    timerT.setFillColor(sf::Color::White);
    timerT.setStyle(sf::Text::Bold);
    timerT.setPosition(1700,20);

    sf::Text flagsT;            //FLAGS
    flagsT.setFont(font);
    flagsT.setCharacterSize(80);
    flagsT.setFillColor(sf::Color::White);
    flagsT.setStyle(sf::Text::Bold);
    flagsT.setPosition(950,20);

    sf::Text victory;
    victory.setFont(font);
    victory.setCharacterSize(130);
    victory.setFillColor(sf::Color(228, 179, 99));
    victory.setStyle(sf::Text::Bold);
    victory.setPosition(200,900);
    victory.setString("DEFUSED");

    sf::Text detonated;
    detonated.setFont(font);
    detonated.setCharacterSize(100);
    detonated.setFillColor(sf::Color(107,5,4));
    detonated.setStyle(sf::Text::Bold);
    detonated.setPosition(150,900);
    detonated.setString("DETONATED");
    modeButton easyMode(50, 300, 0, 900, 250, 450, 60, "EASY MODE", "images/active.png");
    modeButton mediumMode(50, 500, 0, 900, 450, 650, 60, "MEDIUM MODE", "images/active.png");
    modeButton hardMode(50, 700, 0, 900, 650, 850, 60, "HARD MODE", "images/active.png");
    modeButton quitMode(400, 1250, 0, 900, 1200, 1400, 60, "QUIT", "images/active.png");
    easyMode.activation();
    while (app.isOpen()) 
    {
        int amountOfTiles = steve.size();
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
                    if (e.key.code == sf::Mouse::Left){ //if left click, that cell shows hidden cell
                        steve.setPositionsValue(x,y);
                    }
                    if (e.key.code == sf::Mouse::Right){ //if right click, that cell becomes flag 
                        steve.flag(x,y);
                    }
                }
                if(e.key.code == sf::Mouse::Left){
                    if (easyMode.clickable(pos)){
                        easyMode.activation();
                        mediumMode.deactivation();
                        hardMode.deactivation();
                        steve.generation(easy);
                        steve.generationValue();
                    }
                    if (mediumMode.clickable(pos)){
                        mediumMode.activation();
                        easyMode.deactivation();
                        hardMode.deactivation();
                        steve.generation(medium);
                        steve.generationValue();
                    }
                    if (hardMode.clickable(pos)){
                        hardMode.activation();
                        mediumMode.deactivation();
                        easyMode.deactivation();
                        steve.generation(hard);
                        steve.generationValue();
                    }
                    if (quitMode.clickable(pos)){
                        return 0;
                    }
                }
            }
        }
        hover(easyMode, pos);
        hover(mediumMode, pos);
        hover(hardMode, pos);
        hover(quitMode, pos);

        app.clear();

        app.draw(backgroundS);                                  //WALLPAPER BACKGROUND
        app.draw(navS);                                         //NAVIGATION BACKGROUND
        steve.printing(app, boardXpos, boardYpos, tileLength);  //BOARD
        app.draw(title);                                        //Title
        easyMode.printing(app);                                 //EASY MODE
        mediumMode.printing(app);                               //MEDIUM MODE  
        hardMode.printing(app);                                 //HARD MODE
        quitMode.printing(app);                                 //QUIT
        std::stringstream ss;                                   //FLAGS
        ss << steve.flag();
        flagsT.setString("FLAGS:" + ss.str());
        app.draw(flagsT);
        timerT.setString("TIMER: " + steve.time() + "s");       //TIMER
        app.draw(timerT);
        if (steve.statusChecker()==won){                        //VICTORY
            steve.statusSetter(won);
            app.draw(victory);
        }
        if (steve.statusChecker()==lost){                        //LOST
            app.draw(detonated);
        }
        app.display();
    }*/
}
/*
    title.setFont(font);
    title.setCharacterSize(100);
    title.setFillColor(sf::Color::Black);
    title.setStyle(sf::Text::Bold);
    title.setPosition(100,20);
    title.setString("MINESWEEPER");

    timerT.setFont(font);
    timerT.setCharacterSize(80);
    timerT.setFillColor(sf::Color::White);
    timerT.setStyle(sf::Text::Bold);
    timerT.setPosition(1700,20);

    flagsT.setFont(font);
    flagsT.setCharacterSize(80);
    flagsT.setFillColor(sf::Color::White);
    flagsT.setStyle(sf::Text::Bold);
    flagsT.setPosition(950,20);

    victory.setFont(font);
    victory.setCharacterSize(130);
    victory.setFillColor(sf::Color(228, 179, 99));
    victory.setStyle(sf::Text::Bold);
    victory.setPosition(200,900);
    victory.setString("DEFUSED");

    detonated.setFont(font);
    detonated.setCharacterSize(100);
    detonated.setFillColor(sf::Color(107,5,4));
    detonated.setStyle(sf::Text::Bold);
    detonated.setPosition(150,900);
    detonated.setString("DETONATED");*/

    //flagsT.setString(minesweeperBoard.flag());
    //timerT.setString("TIMER: " + minesweeperBoard.time() + "s");       //TIMER

    //app.draw(title);                                        //Title

    //app.draw(flagsT);                                       //FLAGS
    //app.draw(timerT);                                       //TIMER
    //app.draw(victory);
    //app.draw(detonated);