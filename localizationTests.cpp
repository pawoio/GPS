#include <boost/test/unit_test.hpp>

#include "localization.h"




BOOST_AUTO_TEST_CASE(auto_constructed_Loc_latitude_is_zero)
{
    Loc l;
    BOOST_CHECK_EQUAL(l.getLatit(), 0);
}

BOOST_AUTO_TEST_CASE(auto_constructed_Loc_longitude_is_zero)
{
    Loc l;
    BOOST_CHECK_EQUAL(l.getLong(), 0);
}

BOOST_AUTO_TEST_CASE(loc_plus_shift_equals_loc)
{
    Loc l;
    Loc k;
    Shift s=Shift(15,'N',15, 'W');
    l=k+s;
    BOOST_CHECK(l.getLatit()==15&&l.getLong()==-15);
}
BOOST_AUTO_TEST_CASE(in_loc_Longitude_over_90_equals_other_side)
{
Loc l;
Shift s=Shift(100,'N',10);
l=l+s;
BOOST_CHECK(l.getLatit()==80&&l.getLong()==-10);
}

BOOST_AUTO_TEST_CASE(if_localization_minus_shift_equals_loc)
{
Loc l;
Shift s=Shift(190,'N',50,'W');
l=l-s;
BOOST_CHECK(l.getLong()==-10&&l.getLatit()==-130);
}

BOOST_AUTO_TEST_CASE(while_substrucing_Loc_schift_is_produced)
{Loc l=Loc(10);
Loc k=Loc(15);
Shift s;
s=l-k;
BOOST_CHECK(s.longArc==5&&s.longDir=='S');
}

BOOST_AUTO_TEST_CASE(while_longitude_eq_0_is_on_equador)
{
Loc l;
BOOST_CHECK(l.ifequador());
}

BOOST_AUTO_TEST_CASE(while_longitude_eq_90_is_on_Npole)
{
Loc l=Loc(90);
BOOST_CHECK(l.ifNpole());
}

BOOST_AUTO_TEST_CASE(while_longitude_eq_minus_90_is_on_Npole)
{
Loc l=Loc(-90);
BOOST_CHECK(l.ifSpole());
}



