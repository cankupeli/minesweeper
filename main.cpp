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
}