#ifndef SHIFT_H
#define SHIFT_H
#include "localization.h"
class Loc<Type>;
template <class Type>
class Shift
{
    public:

        Shift(Type arc1=0, char dir1='N',Type arc2=0, char dir2='E');


        Shift operator+(const Shift & s) const;
        Shift operator-(const Shift & s) const;
        Shift operator-=(const Shift & s) const;
        Shift operator+=(const Shift & s) const;

        Type longArc;
        Type latitArc;

        char getLongDir();
        char getLatitDir();
        void setLatitDir();
        void setLongDir();


    private:
        Type convDir(Type arc, char dir) const;
        char longDir;
        char latitDir;


template <class Type>
Shift(Type arc1, char dir1,Type arc2, char dir2)
{
   Type longArc=arc1;
     setLongDir(dir1);
    Type latitArc=arc2;
    setLatitDir(dir2);

}

template <class Type>
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

template <class Type>
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

template <class Type>
Shift operator-=(const Shift & s) const
{
    Shift diff;

    diff=diff-s;

    return diff;
}

template <class Type>
Shift operator+=(const Shift & s) const
{
    Shift sum;

    sum=sum+s;

    return sum;
}

template <class Type>
Type convDir(Type arc, char dir) const
{
    Type alpha;
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

template <class Type>
char getLongDir()
{
    return longDir;
}

template <class Type>
char getLatitDir()
{
    return latitDir;
}

template <class Type>
void setLongDir(char ch)
{
    if(ch=='N')
        longDir='N';
    else if(ch=='S')
        longDir='S';
    else longDir='N';

}

template <class Type>
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
