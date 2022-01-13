#ifndef TILE_H
#define TILE_H
/**
 * Representation of a double sided tile.
 */
class tile{
    public:
        /**
        * Default constructor
        */
        tile(){};
        /**
        * Parameterised constructor
        * @param valueHidden Tile's hidden (true) valuation and type.
        * @param valueShown Tile's visible valuation and type.
        */
        tile(int valueHidden, int valueShown);
        /**
        * Retrieves the hidden (true) value of the tile.
        * @return member: valueHidden
        */
        int getHidden();
        /**
        * Retrieves the visible value of the tile.
        * @return member: valueShown
        */
        int getShown();
        /**
        * Retrieves the status of the tile; if it has been checked or not.
        * @return member: checked
        */
        int getChecked();
        /**
        * Checks if the tile's shown value is equivalent to that of a flag.
        * @return true if valueShown is equivalent to 11
        */
        bool isFlag();
        /**
        * Checks if the tile's shown value is equivalent to that of a bomb.
        * @return true if valueShown is equivalent to 9
        */
        bool isBomb();
        /**
        * Sets the value of tile's hidden valuation.
        * @param value Value to be set.
        */
        void setHidden(int value);
        /**
        * Sets the value of tile's shown valuation.
        * @param value Value to be set.
        */
        void setShown(int value);
        /**
        * Sets the value of tile's shown valuation to equal that of the tile's hidden valuation and set the tile's status to being checked.
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