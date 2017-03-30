#ifndef LOCALIZATION_H
#define LOCALIZATION_H
#include "shift.h"
class Shift;


class Loc
{
    public:
        Loc(int lg=0, int lt=0);

        Loc operator+(const Shift & s) const;
        Loc operator-(const Shift & s) const;
        Loc operator+=(const Shift & s) const;
        Loc operator -=(const Shift & s) const;
        Shift operator-(const Loc & l) const;


        bool ifequador();
        bool ifNpole();
        bool ifSpole();

        int getLatit() const;
        int getLong() const;

        Loc setLong (int alpha,const Loc&l)const;
        int setLatit(int alpha)const;

        virtual ~Loc();
    private:
        int longitude;
        int latitude;

        int convDir (int const alpha,  const char dir)const;


};

#endif // LOCALIZATION_H
