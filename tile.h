#ifndef TILE_H
#define TILE_H
//! This class is the representation of a double sided tile.
class tile{
    public:
        /**
        * Default constructor
        */
        tile(){};
        /**
        * Parameterised constructor
        * @param valueHidden Tile's value.
        * @param valueShown Tile's displayed value.
        */
        tile(int valueHidden, int valueShown);
        /**
        * Retrieves the value of the tile.
        * @returns The tiles value
        */
        int getHidden();
        /**
        * Retrieves the displayed value of the tile.
        * @return The tiles displayed value
        */
        int getShown();
        /**
        * Retrieves the status of the tile; if it has been checked or not.
        * @returns True if tile has been checked.
        */
        int getChecked();
        /**
        * Checks if the tile's displayed value is equivalent to that of a flag.
        * @return true if the displayed value is a flag
        */
        bool isFlag();
        /**
        * Checks if the tile's displayed value is equivalent to that of a bomb.
        * @return true if displayed value is a bomb
        */
        bool isBomb();
        /**
        * Sets the tiles value.
        * @param value Value to be set.
        */
        void setHidden(int value);
        /**
        * Sets the tiles displayed value.
        * @param value Value to be set.
        */
        void setShown(int value);
        /**
        * Sets displayed value to tiles value and sets its status to being checked
        */
        void setShown();
        /**
        * Increments the valuation of the tile's hidden value by 1; 
        */
        void increment();
    private:
        int valueHidden;
        int valueShown;
        bool checked;
};
#endif