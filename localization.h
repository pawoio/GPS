#ifndef LOCALIZATION_H
#define LOCALIZATION_H
#include "shift.h"



class Loc
{
    public:
        Loc();
        Loc(int lg, int lt=0);

        Loc operator+(const Shift & s) const;
        Loc operator-(const Shift & s) const;
        Loc operator+=(const Shift & s) const;
        Loc operator -=(const Shift & s) const;
        Shift operator-(const Loc & l) const;


        friend bool ifequador();
       friend  bool ifNpole();
        friend bool ifSpole();

        virtual ~loc();
    private:
        int longitude;
        int latitude;

        int convDir (int const alpha,  const char dir)const;
        Loc setLong (int alpha,Loc&l)const;
        int setLatit(int alpha)const;

}

#endif // LOCALIZATION_H
