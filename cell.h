#ifndef CELL_H
#define CELL_H
/**
 * Representation of each tile on the gameboard.
 */
class cell{
    public:
        cell(){};
        /**
        * Constructor for cell
        * @param valueHidden The type of tile.
        * @param valueShown The type of visible tile.
        */
        cell(int valueHidden, int valueShown);
        //cell(const cell &rhs);
        int getHidden();
        int getShown();
        int getChecked();
        bool isFlag();
        bool isBomb();
        void setHidden(int value);
        void setShown(int value);
        void setShown();
        void increment();
    private:
        int valueHidden;
        int valueShown;
        bool checked;
};
#endif