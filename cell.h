#ifndef CELL_H
#define CELL_H
class cell{
    public:
        cell(int valueHidden, int valueShown);
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