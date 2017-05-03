#ifndef LOCALIZATION_H
#define LOCALIZATION_H
#include "shift.h"
#include <cmath>

class<Type> Shift;

struct HistoryPosition
{
    Loc<Type> loc;
    Shift<Type> shift;
};


template <class Type> class Loc
{
    public:
        Loc(Type lg=0, Type lt=0, unsigned int historyLength=0);

        enum {N,S,E,W};

        Loc operator+(const Shift<Type> & s) const;
        Loc operator-(const Shift<Type> & s) const;
        Loc operator+=(const Shift<Type> & s) const;
        Loc operator -=(const Shift<Type> & s) const;
        Shift<Type> operator-(const Loc<Type> & l) const;


        bool ifequador();
        bool ifNpole();
        bool ifSpole();

        Type getLatit() const;
        Type getLong() const;

        Loc setLong (Type alpha,const Loc<Type>&l)const;
        Type setLatit(Type alpha)const;

        printHistory();
        Loc viewHistoryLoc(unsigned int);

    private:

        const unsigned int historyLength;
        unsigned int historyIndex;
        HistoryPosition* history[];

        Type longitude;
        Type latitude;

        Type convDir ( const Type alpha,  const char dir)const;

    template <class Type>
    Loc(Type lg, Type lt, const unsigned int historyLength)//dorobić przełożenia może funkcje
    {
        longitude=lg;
        latitude=lt;
        HistoryPosition* history= new HistoryPosition[historyLength];
        historyIndex=0;
    }

    template <class Type>
    ~Loc()
    {
        delete history;
    }

    template <class Type>
    Type getLatit() const
    {
        Type val=latitude;
        return val;
    }

    template <class Type>
    Type getLong() const
    {
        Type val=longitude;
        return val;
    }



    template <class Type>
     Loc operator+(const Shift & s) const
     {
        Loc sum;


        sum.latitude = setLatit(latitude+convDir(s.latitArc, s.latitDir));
        sum = setLong( longitude + convDir(s.longArc, s.longDir),sum);

        if(historyIndex<historyLength)
        {
            history[historyIndex].loc=sum;
            history[historyIndex].loc=&this;
            historyIndex++
        }


        return sum;
     }

    template <class Type>
     Loc operator-(const Shift & s) const
     {
        Loc diff;

        diff.latitude = setLatit( latitude - convDir(s.latitArc, s.latitDir));
        diff = setLong( longitude - convDir(s.longArc, s.longDir),diff);

        if(historyIndex<historyLength)
        {
            history[historyIndex].loc=sum;
            history[historyIndex].loc=&this;
            historyIndex++
        }

        return diff;
     }

    template <class Type>
     Shift operator-(const Loc & l) const
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
    Loc operator+=(const Shift & s) const
    {
        Loc sum;
        sum = sum + s;

        if(historyIndex<historyLength)
        {
            history[historyIndex].loc=sum;
            history[historyIndex].loc=&this;
            historyIndex++
        }

        return sum;
    }

    template <class Type>
    Loc operator-=(const Shift & s ) const
    {
        Loc diff;
        diff=diff - s;

        if(historyIndex<historyLength)
        {
            history[historyIndex].loc=sum;
            history[historyIndex].loc=&this;
            historyIndex++
        }

        return diff;
    }





    template <class Type>
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

    template <class Type>
    Type setLatit (Type arc) const
    {

        Type alpha=arc;
        alpha=alpha%360;
        alpha=fabs(alpha)<=180 ? alpha : alpha>0 ? 180-alpha: alpha-180;
        return alpha;
    }

    template <class Type>
    Loc setLong(Type arc, const Loc & l) const //zeraaa
    {
        Type alpha=arc%360;

        Loc st=l;


        st.longitude=fabs(alpha)<=90 ? alpha :fabs(alpha)<=180 ? alpha-2*(alpha%90) : fabs(alpha)<=270 ? -(alpha%180) : alpha<0? -360+alpha : 360-alpha;
        st.latitude = alpha>=90&&alpha<=270 ? (l.latitude<=0? 180+alpha: -180+alpha) : l.longitude;

        return st;
    }

    template <class Type>
    bool ifequador()
    {
        if (longitude==0)
            return true;
        else return false;
    }

    template <class Type>
    bool ifNpole()
    {
        if (longitude==90)
            return true;
        else return false;
    }

    template <class Type>
    bool ifSpole()
    {
        if (longitude==-90)
            return true;
        else return false;
    }

    template <class Type>
    printHistory()
    {
        for(unsigned int i=0;i < historyIndex; i++)
            std::cout << i+1 << history[i].shift.longArc <<history[i].shift.longDir << history[i].shift.latitArc << history[i].shift.latitDir<<"\n"<<std::endl;
    }

    template <class

    template <class Type>
    Loc viewHistoryLoc(unsigned int i)
    {

        return history[i+1].loc;
    }

};



#endif // LOCALIZATION_H
