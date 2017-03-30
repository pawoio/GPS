#include <boost/test/unit_test.hpp>

#include"shift.h"

BOOST_AUTO_TEST_CASE(constructing_shift_components_are_defoult)
{
Shift s;
BOOST_CHECK(longArc==0&&latitArc==0&&longDir='N'&&latitDir='E')
}

BOOST_AUTO_TEST_CASE(adding_two_shifts_eq_shift)
{
Shift(100,'S',-5) s;
Shift sh;
Shift eq;
eq=s+sh;
BOOST_CHECK(eq.latitArc==-5&&eq.longArc==100)
}
BOOST_AUTO_TEST_CASE(substracing_two_shifts_eq_shifts)
{
Shift(100,'N',-3) s;
Shift sh;
Shift eq;
eq=sh-s;
BOOST_CHECK(eq.longArc==100&&eq.longDir=='S'&&eq.latitArc==3&&eq.latitDir=='W')
}
BOOST_AUTO_TEST_CASE(adding_shift_to_location_eq_location)
{
Loc l;
Shift(10,'N',200,'E') s;
Loc eq;
eq=s+l
BOOST_CHECK(eq.longitude==10&&eq.latitude==160)
}

