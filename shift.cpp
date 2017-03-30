#include "shift.h"

using namespace shiftProg;

Shift::Shift()
{
    longArc=0;
    latitArc=0;
    longDir='N';
    latitDir='E';
}
Shift::Shift(int arc1, char dir1='N',int arc2=0, char dir2='E')
{
    longArc=arc1;
    longDir=dir1;
    latiArc=arc2;
    latiDir=dir2;

}

Shift::~Shift()
{
    //dtor
}

Shift Shift::operator+(const Shift & s) const
{
    Shift sum;

   if((sum.longArc=convDir(longArc,longDir)+convDir(s.longArc,s.longDir))>0)
        sum.longDir='N';
    else
    {
        sum.longDir='S';
        sum.longArc*=(-1);
    }


    if((sum.latitArc=convDir(latitArc,latitDir)+convDir(s.latitArc,s.latitDir))>0)
        sum.latitDir='E';
    else
    {
        sum.latitDir='W';
        sum.latitArc*=(-1);
    }

    return sum;


}

    Loc operator+(const Loc & l) const
{
    Loc sum;

    sum.longitude = Loc::setLong( longitude + Loc::convDir(s.longArc, s.longDir));
    sum = Loc::setLatit(latitude+Loc::convDir(s.latitArc, s.latitDir), sum);

    return sum;
}

Shift operator-(const Shift & s) const;
{
    Shift diff;

    if((diff.longArc=convDir(longArc,longDir)-convDir(s.longArc,s.longDir))>0)
        diff.longDir='N';
    else
    {
        diff.longDir='S';
        diff.longArc*=(-1);
    }


    if((diff.latitArc=convDir(latitArc,latitDir)-convDir(s.latitArc,s.latitDir))>0)
        diff.latitDir='E';
    else
    {
        diff.latitDir='W';
        diff.latitArc*=(-1);
    }

    return diff;
}

Shift operator-=(const Shift & s) const
{
    Shift diff;

    diff=diff-s;

    return diff;
}

Shift operator+=(const Shift & s) const
{
    Shift sum;

    sum=sum+s;

    return sum;
}

int Shift::convDir(int arc, char dir)
{
    int alpha;
    switch(dir)
    {
        case 'N':
        case 'E':alpha=arc;
                break;
        case 'S':
        case 'W':alpha=-arc;
    }
    return alpha;
}







