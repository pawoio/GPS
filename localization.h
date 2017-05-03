#ifndef LOCALIZATION_H
#define LOCALIZATION_H
#include "shift.h"
#include <cmath>
#include <iostream>

template<class Type> class Shift;
template <class Type> class Loc;

template<class Type>
struct HistoryPosition
{
    Loc<Type> loc;
    Shift<Type> shift;
};


template <class Type> class Loc
{
    public:


        enum {N,S,E,W};



    private:

        const unsigned int historyLength;
        unsigned int historyIndex;
        HistoryPosition<Type>* history;

        Type longitude;
        Type latitude;

public:
    Loc(Type lg = 0, Type lt = 0, const unsigned int historyLength = 0)//dorobić przełożenia może funkcje
    {
        longitude = lg;
        latitude = lt;
        history = new HistoryPosition<Type>[historyLength];
        historyIndex=0;
    }

    ~Loc()
    {
        delete history;
    }

    Type getLatit() const
    {
        Type val=latitude;
        return val;
    }

    Type getLong() const
    {
        Type val=longitude;
        return val;
    }

     Loc operator+(const Shift<Type> & s)
     {
        Loc sum;


        sum.latitude = setLatit(latitude+convDir(s.latitArc, s.latitDir));
        sum = setLong( longitude + convDir(s.longArc, s.longDir),sum);

        if(historyIndex < historyLength)
        {
            history[historyIndex].loc = sum;
            history[historyIndex].loc = &this;
            historyIndex++;
        }


        return sum;
     }

     Loc operator-(const Shift<Type> & s)
     {
        Loc diff;

        diff.latitude = setLatit( latitude - convDir(s.latitArc, s.latitDir));
        diff = setLong( longitude - convDir(s.longArc, s.longDir),diff);

        if(historyIndex<historyLength)
        {
            history[historyIndex].loc = diff;
            history[historyIndex].loc = &this;
            historyIndex++;
        }

        return diff;
     }

     Shift<Type> operator-(const Loc & l) const
     {
        Shift<Type> diff;
        diff.latitArc = fabs(l.latitude - latitude);
        diff.longArc = fabs(l.longitude - longitude);

        if((l.latitude-latitude)>0)
            diff.latitDir='E';
        else diff.latitDir='W';

        if((l.longitude-longitude)>0)
            diff.longDir='N';
        else diff.longDir='S';

        return diff;
     }

    Loc operator+=(const Shift<Type> & s)
    {
        Loc sum;
        sum = sum + s;

        if(historyIndex<historyLength)
        {
            history[historyIndex].loc = sum;
            history[historyIndex].loc = &this;
            historyIndex++;
        }

        return sum;
    }

    Loc operator-=(const Shift<Type> & s )
    {
        Loc diff;
        diff=diff - s;

        if(historyIndex<historyLength)
        {
            history[historyIndex].loc = diff;
            history[historyIndex].loc = &this;
            historyIndex++;
        }

        return diff;
    }





    Type convDir(const Type alpha, const char dir) const
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

    Type setLatit (Type arc) const
    {

        Type alpha=arc;
        alpha=alpha%360;
        alpha=fabs(alpha)<=180 ? alpha : alpha>0 ? 180-alpha: alpha-180;
        return alpha;
    }

    Loc setLong(Type arc, const Loc & l) const //zeraaa
    {
        Type alpha=arc%360;

        Loc st=l;


        st.longitude=fabs(alpha)<=90 ? alpha :fabs(alpha)<=180 ? alpha-2*(alpha%90) : fabs(alpha)<=270 ? -(alpha%180) : alpha<0? -360+alpha : 360-alpha;
        st.latitude = alpha>=90&&alpha<=270 ? (l.latitude<=0? 180+alpha: -180+alpha) : l.longitude;

        return st;
    }

    bool ifequador()
    {
        if (longitude==0)
            return true;
        else return false;
    }

    bool ifNpole()
    {
        if (longitude==90)
            return true;
        else return false;
    }

    bool ifSpole()
    {
        if (longitude==-90)
            return true;
        else return false;
    }

    void printHistory()
    {
        for(unsigned int i=0;i < historyIndex; i++)
            std::cout << i+1 << history[i].shift.longArc <<history[i].shift.longDir << history[i].shift.latitArc << history[i].shift.latitDir<<"\n"<<std::endl;
    }

    Loc viewHistoryLoc(unsigned int i)
    {

        return history[i+1].loc;
    }

};



#endif // LOCALIZATION_H
