#ifndef SHIFT_H
#define SHIFT_H
#include "localization.h"
class Loc;

class Shift
{
    public:
        int longArc;
        char longDir;
        int latitArc;
        char latitDir;

        Shift ();
        Shift(int arc1, char dir1='N',int arc2=0, char dir2='E');


        Shift operator+(const Shift & s) const;
        Loc operator+(const Loc & l) const;
        Shift operator-(const Shift & s) const;
        Shift operator-=(const Shift & s) const;
        Shift operator+=(const Shift & s) const;


        virtual ~Shift();

    private:
        int convDir(int arc, char dir);

};

#endif // SHIFT_H
