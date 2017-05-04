#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <boost/mpl/list.hpp>

#include "localization.h"


typedef boost::mpl::list<int,long,unsigned int, float> test_types;


BOOST_AUTO_TEST_CASE_TEMPLATE(auto_constructed_Loc_latitude_is_zero, Type, test_types)
{
    Loc<Type> l;
    BOOST_CHECK_EQUAL(l.getLatit(), 0);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(auto_constructed_Loc_longitude_is_zero,Type, test_types)
{
    Loc<Type> l;
    BOOST_CHECK_EQUAL(l.getLong(), 0);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(loc_plus_shift_equals_loc,Type, test_types)
{
    Loc<Type> l;
    Loc<Type> k;
    Shift<Type> s=Shift<Type>(15,'N',15, 'W');
    l=k+s;
    BOOST_CHECK(l.getLatit()==15&&l.getLong()==-15);
}
BOOST_AUTO_TEST_CASE_TEMPLATE(in_loc_Longitude_over_90_equals_other_side,Type, test_types)
{
Loc<Type> l;
Shift<Type> s=Shift<Type>(100,'N',10);
l=l+s;
BOOST_CHECK(l.getLatit()==80&&l.getLong()==-10);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(if_localization_minus_shift_equals_loc,Type, test_types)
{
Loc<Type> l;
Shift<Type> s=Shift<Type>(190,'N',50,'W');
l=l-s;
BOOST_CHECK(l.getLong()==-10&&l.getLatit()==-130);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(while_substrucing_Loc_schift_is_produced,Type, test_types)
{Loc<Type> l=Loc<Type>(10);
Loc<Type> k=Loc<Type>(15);
Shift<Type> s;
s=l-k;
BOOST_CHECK(s.longArc==5&&s.getLongDir()=='S');
}

BOOST_AUTO_TEST_CASE_TEMPLATE(while_longitude_eq_0_is_on_equador,Type, test_types)
{
Loc<Type> l;
BOOST_CHECK(l.ifequador());
}

BOOST_AUTO_TEST_CASE_TEMPLATE(while_longitude_eq_90_is_on_Npole,Type, test_types)
{
Loc<Type> l=Loc<Type>(90);
BOOST_CHECK(l.ifNpole());
}

BOOST_AUTO_TEST_CASE_TEMPLATE(while_longitude_eq_minus_90_is_on_Npole,Type, test_types)
{
Loc<Type> l=Loc<Type>(-90);
BOOST_CHECK(l.ifSpole());
}
BOOST_AUTO_TEST_CASE(history_of_second_element_equols_third_change_in_loc)
{
    Loc<int> l(15,15,6);
    Loc<int> lo(5,5,6);
    Shift<int> s(5,'N',5,'W');
    l+=s;
    l+=s;
    l+=s;


}

