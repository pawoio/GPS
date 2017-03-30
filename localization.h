#ifndef LOCALIZATION_H
#define LOCALIZATION_H
#include "shift.h"

namespace Localization;

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


        bool ifequador();
        bool ifNpole();
        bool ifSpole();

        virtual ~loc();
    private:
        int longitude;
        int latitude;

        int convDir (int const alpha,  const char dir);
        int setLong (int alpha);
        Loc setLatit(int alpha, Loc & l);

};

#endif // LOCALIZATION_H
