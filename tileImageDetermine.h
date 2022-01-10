#ifndef TILEIMAGEDETERMINE_H
#define TILEIMAGEDETERMINE_H

struct tileImageDetermine {
    std::string tileImage;
    int tileValue;
    bool finished = false;
    tileImageDetermine(int tileValue):tileValue(tileValue){}
    operator std::string(){
        return tileImage;
    }
    tileImageDetermine tile0() {
        if (!finished && tileValue == 0){
            tileImage = "images/tile0.png";
            finished = true;
        }
        return *this;
    }
    tileImageDetermine tile1() {
        if (!finished && tileValue == 1){
            tileImage = "images/tile1.png";
            finished = true;
        }
        return *this;
    }
    tileImageDetermine tile2() {
        if (!finished && tileValue == 2){
            tileImage = "images/tile2.png";
            finished = true;
        }
        return *this;
    }
    tileImageDetermine tile3() {
        if (!finished && tileValue == 3){
            tileImage = "images/tile3.png";
            finished = true;
        }
        return *this;
    }
    tileImageDetermine tile4() {
        if (!finished && tileValue == 4){
            tileImage = "images/tile4.png";
            finished = true;
        }
        return *this;
    }
    tileImageDetermine tile5() {
        if (!finished && tileValue == 5){
            tileImage = "images/tile5.png";
            finished = true;
        }
        return *this;
    }
    tileImageDetermine tile6() {
        if (!finished && tileValue == 6){
            tileImage = "images/tile6.png";
            finished = true;
        }
        return *this;
    }
    tileImageDetermine tile7() {
        if (!finished && tileValue == 7){
            tileImage = "images/tile7.png";
            finished = true;
        }
        return *this;
    }
    tileImageDetermine tile8() {
        if (!finished && tileValue == 8){
            tileImage = "images/tile8.png";
            finished = true;
        }
        return *this;
    }
    tileImageDetermine tile9() {
        if (!finished && tileValue == 9){
            tileImage = "images/tile9.png";
            finished = true;
        }
        return *this;
    }
    tileImageDetermine tile10() {
        if (!finished && tileValue == 10){
            tileImage = "images/tile10.png";
            finished = true;
        }
        return *this;
    }
    tileImageDetermine tile11() {
        if (!finished && tileValue == 11){
            tileImage = "images/tile11.png";
            finished = true;
        }
        return *this;
    }
};
#endif