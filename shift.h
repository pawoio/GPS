#ifndef SHIFT_H
#define SHIFT_H
#include "localization.h"
class Loc;

class Shift
{
    public:

        Shift(int arc1=0, char dir1='N',int arc2=0, char dir2='E');


        Shift operator+(const Shift & s) const;
        Shift operator-(const Shift & s) const;
        Shift operator-=(const Shift & s) const;
        Shift operator+=(const Shift & s) const;

        double longArc;
        char longDir;
        double latitArc;
        char latitDir;


    private:
        int convDir(int arc, char dir) const;


};

#endif // SHIFT_H
