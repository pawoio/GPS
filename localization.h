#ifndef LOCALIZATION_H
#define LOCALIZATION_H


class localization
{
    public:
        localization();
        virtual ~localization();
    private:
        enum {N,S,W,E};
        int longitude;
        int lengthitude;

};

#endif // LOCALIZATION_H
