#ifndef TILEIMAGEDETERMINE_H
#define TILEIMAGEDETERMINE_H
//! This structure is used to determine which image to assign to a tile
struct tileImageDetermine {
    std::string tileImage;
    int tileValue;
    bool finished = false;
    /**
     * Parameterized constructor 
     * @param tileValue The hidden value of the tile
     */
    tileImageDetermine(int tileValue):tileValue(tileValue){}
    /**
     * Conversion operator used to return the object as a string representing the file to the tiles corrosponding image
     * @returns local path to image file
     */
    operator std::string(){
        return tileImage;
    }
    /**
     * If image is undetermined and has a hidden value of zero, the image will be determined
     * @returns object 
     */
    tileImageDetermine tile0() {
        if (!finished && tileValue == 0){
            tileImage = "images/tile0.png";
            finished = true;
        }
        return *this;
    }
    /**
     * If image is undetermined and has a hidden value of one, the image will be determined
     * @returns object 
     */
    tileImageDetermine tile1() {
        if (!finished && tileValue == 1){
            tileImage = "images/tile1.png";
            finished = true;
        }
        return *this;
    }
    /**
     * If image is undetermined and has a hidden value of two, the image will be determined
     * @returns object 
     */
    tileImageDetermine tile2() {
        if (!finished && tileValue == 2){
            tileImage = "images/tile2.png";
            finished = true;
        }
        return *this;
    }
    /**
     * If image is undetermined and has a hidden value of three, the image will be determined
     * @returns object 
     */
    tileImageDetermine tile3() {
        if (!finished && tileValue == 3){
            tileImage = "images/tile3.png";
            finished = true;
        }
        return *this;
    }
    /**
     * If image is undetermined and has a hidden value of four, the image will be determined
     * @returns object 
     */
    tileImageDetermine tile4() {
        if (!finished && tileValue == 4){
            tileImage = "images/tile4.png";
            finished = true;
        }
        return *this;
    }
    /**
     * If image is undetermined and has a hidden value of five, the image will be determined
     * @returns object 
     */
    tileImageDetermine tile5() {
        if (!finished && tileValue == 5){
            tileImage = "images/tile5.png";
            finished = true;
        }
        return *this;
    }
    /**
     * If image is undetermined and has a hidden value of six, the image will be determined
     * @returns object 
     */
    tileImageDetermine tile6() {
        if (!finished && tileValue == 6){
            tileImage = "images/tile6.png";
            finished = true;
        }
        return *this;
    }
    /**
     * If image is undetermined and has a hidden value of seven, the image will be determined
     * @returns object 
     */
    tileImageDetermine tile7() {
        if (!finished && tileValue == 7){
            tileImage = "images/tile7.png";
            finished = true;
        }
        return *this;
    }
    /**
     * If image is undetermined and has a hidden value of eight, the image will be determined
     * @returns object 
     */
    tileImageDetermine tile8() {
        if (!finished && tileValue == 8){
            tileImage = "images/tile8.png";
            finished = true;
        }
        return *this;
    }
    /**
     * If image is undetermined and has a hidden value of nine, the image will be determined
     * @returns object 
     */
    tileImageDetermine tile9() {
        if (!finished && tileValue == 9){
            tileImage = "images/tile9.png";
            finished = true;
        }
        return *this;
    }
    /**
     * If image is undetermined and has a hidden value of ten, the image will be determined
     * @returns object 
     */
    tileImageDetermine tile10() {
        if (!finished && tileValue == 10){
            tileImage = "images/tile10.png";
            finished = true;
        }
        return *this;
    }
    /**
     * If image is undetermined and has a hidden value of one, the image will be determined
     * @returns object 
     */
    tileImageDetermine tile11() {
        if (!finished && tileValue == 11){
            tileImage = "images/tile11.png";
            finished = true;
        }
        return *this;
    }
};
#endif