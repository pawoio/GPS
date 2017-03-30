#include "localization.h"
#include <cmath>



Loc::Loc(int lg, int lt)//dorobić przełożenia może funkcje
{
    longitude=lg;
    latitude=lt;
}

Loc::~Loc()
{
    //dtor
}

int Loc::getLatit()
{
    int val=latitude;
    return val;
}

int Loc::getLong()
{
    int val=longitude;
    return val;
}



 Loc Loc::operator+(const Shift & s) const
 {
    Loc sum;


    sum.latitude = setLatit(latitude+convDir(s.latitArc, s.latitDir));
    sum = setLong( longitude + convDir(s.longArc, s.longDir),sum);
    return sum;
 }

 Loc Loc::operator-(const Shift & s) const
 {
    Loc diff;

    diff.latitude = setLatit( latitude - convDir(s.latitArc, s.latitDir));
    diff = setLong( longitude - convDir(s.longArc, s.longDir),diff);

    return diff;
 }

 Shift Loc::operator-(const Loc & l) const
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

Loc Loc::operator+=(const Shift & s) const
{
    Loc sum;
    sum = sum + s;
    return sum;
}

Loc Loc::operator-=(const Shift & s ) const
{
    Loc diff;
    diff=diff - s;
    return diff;
}





int Loc::convDir(const int alpha, const char dir) const
{
    int arc;
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

int Loc::setLatit (int arc) const
{

    int alpha=arc;
    alpha=alpha%360;
    alpha=fabs(alpha)<=180 ? alpha : alpha>0 ? 180-alpha: alpha-180;
    return alpha;
}
Loc Loc::setLong(int arc,Loc & l) const //zeraaa
{
    int alpha=arc%360;

    Loc st=l;


    st.longitude=fabs(alpha)<=90 ? alpha :fabs(alpha)<=180 ? alpha-2*(alpha%90) : fabs(alpha)<=270 ? -(alpha%180) : alpha<0? -360+alpha : 360-alpha;
    st.latitude = alpha>=90&&alpha<=270 ? (l.latitude<=0? 180+alpha: -180+alpha) : l.longitude;

    return st;
}

        bool Loc::ifequador()
        {
            if (longitude==0)
                return true;
            else return false;
        }
        bool Loc::ifNpole()
        {
            if (longitude==90)
                return true;
            else return false;
        }
        bool Loc::ifSpole()
        {
            if (longitude==-90)
                return true;
            else return false;
        }
