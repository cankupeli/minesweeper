#include "tile.h"

tile::tile(int valueHidden, int valueShown): valueHidden(valueHidden), valueShown(valueShown), checked(false){}
int tile::getHidden(){
    return valueHidden;
}
int tile::getShown(){
    return valueShown;
}
int tile::getChecked(){
    return checked;
}
bool tile::isFlag(){
    return valueShown == 11;
}
bool tile::isBomb(){
    return valueShown == 9;
}
void tile::setHidden(int value){
    valueHidden = value;
}
void tile::setShown(int value){
    valueShown = value;
}
void tile::setShown(){
    valueShown = valueHidden;
    checked = true;
}
void tile::increment(){
    valueHidden++;
}