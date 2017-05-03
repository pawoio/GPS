#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <boost/mpl/list.hpp>

#include"shift.h"

typedef boost::mpl::list<int,long,unsigned int, float> test_types;

BOOST_AUTO_TEST_TEMPLATE(constructing_shift_components_are_defoult,Type, test_types)
{
Shift<Type> s;
BOOST_CHECK(longArc==0&&latitArc==0&&getLongDir()=='N'&&getLatitDir()=='E');
}

BOOST_AUTO_TEST_TEMPLATE(adding_two_shifts_eq_shift,Type, test_types)
{
Shift<Type> s=Shift(100,'S',-5);
Shift<Type> sh;
Shift<Type> eq;
eq=s+sh;
BOOST_CHECK(eq.latitArc==-5&&eq.longArc==100);
}
BOOST_AUTO_TEST_TEMPLATE(substracing_two_shifts_eq_shifts,Type, test_types)
{
Shift<Type> s=Shift(100,'N',-3);
Shift<Type> sh;
Shift<Type> eq;
eq=sh-s;
BOOST_CHECK(eq.longArc==100&&eq.getLongDir()=='S'&&eq.latitArc==3&&eq.getLatitDir()=='W');
}
BOOST_AUTO_TEST_TEMPLATE(adding_shift_to_location_eq_location,Type, test_types)
{
Loc<Type> l;
Shift<Type> s=Shift(10,'N',200,'E');
Loc<Type> eq;
eq=s+l;
BOOST_CHECK(eq.getLong()==10&&eq.getLatit()==160);
}

