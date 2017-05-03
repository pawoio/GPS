#ifndef LOCALIZATION_H
#define LOCALIZATION_H
#include "shift.h"
#include <cmath>

class Shift;


template <class Type> class Loc
{
    public:
        Loc(Type lg=0, Type lt=0);

        enum {N,S,E,W};

        Loc operator+(const Shift & s) const;
        Loc operator-(const Shift & s) const;
        Loc operator+=(const Shift & s) const;
        Loc operator -=(const Shift & s) const;
        Shift operator-(const Loc<Type> & l) const;


        bool ifequador();
        bool ifNpole();
        bool ifSpole();

        Type getLatit() const;
        Type getLong() const;

        Loc setLong (Type alpha,const Loc<Type>&l)const;
        Type setLatit(Type alpha)const;

    private:
        Type longitude;
        Type latitude;

        Type convDir (Type const alpha,  const char dir)const;


};

template <class Type>
Loc<Type>::Loc(Type lg, Type lt)//dorobić przełożenia może funkcje
{
    longitude=lg;
    latitude=lt;
}

template <class Type>
Loc<Type>::~Loc()
{
    //dtor
}

template <class Type>
Type Loc<Type>::getLatit() const
{
    Type val=latitude;
    return val;
}

template <class Type>
Type Loc<Type>::getLong() const
{
    Type val=longitude;
    return val;
}



template <class Type>
 Loc<Type> Loc<Type>::operator+(const Shift & s) const
 {
    Loc<Type> sum;


    sum.latitude = setLatit(latitude+convDir(s.latitArc, s.latitDir));
    sum = setLong( longitude + convDir(s.longArc, s.longDir),sum);
    return sum;
 }

template <class Type>
 Loc Loc<Type>::operator-(const Shift & s) const
 {
    Loc diff;

    diff.latitude = setLatit( latitude - convDir(s.latitArc, s.latitDir));
    diff = setLong( longitude - convDir(s.longArc, s.longDir),diff);

    return diff;
 }

template <class Type>
 Shift Loc<Type>::operator-(const Loc & l) const
 {
    Shift diff;
    diff.latitArc=fabs(l.latitude-latitude);
    diff.longArc=fabs(l.longitude-longitude);

    if((l.latitude-latitude)>0)
        diff.latitDir='E';
    else diff.latitDir='W';

    if((l.longitude-longitude)>0)
        diff.longDir='N';
    else diff.longDir='S';

    return diff;
 }

template <class Type>
Loc Loc<Type>::operator+=(const Shift & s) const
{
    Loc sum;
    sum = sum + s;
    return sum;
}

template <class Type>
Loc Loc<Type>::operator-=(const Shift & s ) const
{
    Loc diff;
    diff=diff - s;
    return diff;
}





template <class Type>
int Loc<Type>::convDir(const Type alpha, const char dir) const
{
    Type arc;
    switch(dir)
    {
        case 'N':arc=alpha;
                break;
        case 'S':arc=(-alpha);
                break;
        case 'E':arc=alpha;
                break;
        case 'W':arc=(-alpha);
    }
    return arc;
}

template <class Type>
int Loc<Type>::setLatit (Type arc) const
{

    Type alpha=arc;
    alpha=alpha%360;
    alpha=fabs(alpha)<=180 ? alpha : alpha>0 ? 180-alpha: alpha-180;
    return alpha;
}

template <class Type>
Loc Loc<Type>::setLong(Type arc, const Loc & l) const //zeraaa
{
    Type alpha=arc%360;

    Loc st=l;


    st.longitude=fabs(alpha)<=90 ? alpha :fabs(alpha)<=180 ? alpha-2*(alpha%90) : fabs(alpha)<=270 ? -(alpha%180) : alpha<0? -360+alpha : 360-alpha;
    st.latitude = alpha>=90&&alpha<=270 ? (l.latitude<=0? 180+alpha: -180+alpha) : l.longitude;

    return st;
}

template <class Type>
bool Loc<Type>::ifequador()
{
    if (longitude==0)
        return true;
    else return false;
}

template <class Type>
bool Loc<Type>::ifNpole()
{
    if (longitude==90)
        return true;
    else return false;
}

template <class Type>
bool Loc<Type>::ifSpole()
{
    if (longitude==-90)
        return true;
    else return false;
}


#endif // LOCALIZATION_H
