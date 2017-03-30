#include "shift.h"



Shift::Shift(int arc1, char dir1,int arc2, char dir2)
{
   int longArc=arc1;
    char longDir=dir1;
    int latiArc=arc2;
    char latiDir=dir2;

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

    Loc Shift::operator+(const Loc & l) const
{
    Loc sum;

    sum = Loc::setLong( (this->getLong() + Loc::convDir(s.longArc, s.longDir)),sum);
    sum.latitude = Loc::setLatit(this->getLatit()+Loc::convDir(s.latitArc, s.latitDir), sum);

    return sum;
}

Shift Shift::operator-(const Shift & s) const;
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

Shift Shift::operator-=(const Shift & s) const
{
    Shift diff;

    diff=diff-s;

    return diff;
}

Shift Shift::operator+=(const Shift & s) const
{
    Shift sum;

    sum=sum+s;

    return sum;
}

int Shift::convDir(int arc, char dir) const
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







