#ifndef SHIFT_H
#define SHIFT_H
#include "localization.h"
template<class Type> class Loc;

template <class Type>
class Shift
{
    // poni¿ej wszystko jest domyœlnie prywatne
    char longDir;
    char latitDir;


    Type convDir(Type arc, char dir) const
    {
        Type alpha;
        switch(dir)
        {
        case 'N':
        case 'E':
            alpha=arc;
            break;
        case 'S':
        case 'W':
            alpha=-arc;
        }
        return alpha;
    }
public:
    Type longArc;
    Type latitArc;
    Shift(Type arc1, char dir1, Type arc2, char dir2)
    {
        Type longArc=arc1;
        setLongDir(dir1);
        Type latitArc=arc2;
        setLatitDir(dir2);

    }

    Shift operator+(const Shift & s) const
    {
        Shift sum;

        if((sum.longArc=convDir(longArc,getLongDir())+convDir(s.longArc,s.getLongDir()))>0)
            sum.setLongDir('N');
        else
        {
            sum.setLongDir('S');
            sum.longArc*=(-1);
        }


        if((sum.latitArc=convDir(latitArc,getLatitDir())+convDir(s.latitArc,s.getLatitDir()))>0)
            sum.setLatitDir('E');
        else
        {
            sum.setLatitDir('W');
            sum.latitArc*=(-1);
        }

        return sum;


    }

    Shift operator-(const Shift & s) const
    {
        Shift diff;

        if(diff.longArc=convDir(longArc,getLongDir())-convDir(s.longArc,s.getLongDir())>0)
            diff.setLongDir('N');
        else
        {
            diff.setLongDir('S');
            diff.longArc*=(-1);
        }


        if((diff.latitArc=convDir(latitArc,latitDir)-convDir(s.latitArc,s.latitDir))>0)
            diff.setLatitDir('E');
        else
        {
            diff.setLongDir('w');
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

    char getLongDir()
    {
        return longDir;
    }

    char getLatitDir()
    {
        return latitDir;
    }

    void setLongDir(char ch)
    {
        if(ch=='N')
            longDir='N';
        else if(ch=='S')
            longDir='S';
        else longDir='N';

    }

    void setLatitDir(char ch)
    {
        if(ch=='E')
            longDir='E';
        else if(ch=='W')
            longDir='W';
        else longDir='E';
    }

};

#endif // SHIFT_H
