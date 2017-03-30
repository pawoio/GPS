#include <boost/test/unit_test.hpp>

#include "localization.h"

using namespace Localization;


BOOST_AUTO_TEST_CASE(auto_constructed_Loc_latitude_is_zero)
{
    Loc l;
    BOOST_CHECK_EQUAL(l.latitude, 0)
}

BOOST_AUTO_TEST_CASE(auto_constructed_Loc_longitude_is_zero)
{
    Loc l;
    BOOST_CHECK_EQUAL(l.longitude, 0)
}

BOOST_AUTO_TEST_CASE(loc_plus_shift_equals_loc)
{
    Loc l;
    Loc k;
    Shift(15,'N',15, 'W') s;
    l=k+s
    BOOST_CHECK(l.latitude==15&&l.longitude==-15)
}
BOOST_AUTO_TEST_CASE(in_loc_Longitude_over_90_equals_other_side)
{
Loc l;
Shift(100,'N',10) s;
l=l+s
BOOST_CHECK(l.latitude==80&&l.longitude==-10)
}

BOOST_AUTO_TEST_CASE(if_localization_minus_shift_equals_loc)
{
Loc l;
Shift(190,'N',50,'W') s;
l=l-s;
BOOST_CHECK(l.longitude==-10&&l.latitude==-130)
}

BOOST_AUTO_TEST_CASE(while_substrucing_Loc_schift_is_produced)
{Loc(10) l;
Loc(15) k;
Shift s;
s=l-k;
BOOST_CHECK(s.longArc==5&&s.longDir=='S')
}

BOOST_AUTO_TEST_CASE(while_longitude_eq_0_is_on_equador)
{
Loc l;
BOOST_CHECK(ifequador(l))
}

BOOST_AUTO_TEST_CASE(while_longitude_eq_90_is_on_Npole)
{
Loc(90) l;
BOOST_CHECK(ifNpole(l))
}

BOOST_AUTO_TEST_CASE(while_longitude_eq_minus_90_is_on_Npole)
{
Loc(-90) l;
BOOST_CHECK(ifSpole(l))
}

BOOST_AUTO_TEST_CASE()
{
BOOST_CHECK()
}
BOOST_AUTO_TEST_CASE()
{
BOOST_CHECK()
}

