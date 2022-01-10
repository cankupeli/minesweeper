#include "cell.h"

cell::cell(int valueHidden, int valueShown): valueHidden(valueHidden), valueShown(valueShown), checked(false){}
int cell::getHidden(){
    return valueHidden;
}
int cell::getShown(){
    return valueShown;
}
int cell::getChecked(){
    return checked;
}
bool cell::isFlag(){
    return valueShown == 11;
}
bool cell::isBomb(){
    return valueShown == 9;
}
void cell::setHidden(int value){
    valueHidden = value;
}
void cell::setShown(int value){
    valueShown = value;
}
void cell::setShown(){
    valueShown = valueHidden;
    checked = true;
}
void cell::increment(){
    valueHidden++;
}