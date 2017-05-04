# -Wall == all warnings enabled
CPPFLAGS = --std=c++11 -DBOOST_TEST_DYN_LINK
LINKFLAGS = --std=c++11 -lboost_unit_test_framework

lib_SOURCES = \
	localization.h \
	shift.h
lib_OBJECTS=$(lib_SOURCES:.cpp=.o)

tests_SOURCES = \
	localizationTests.cpp \
	shiftTests.cpp

tests_OBJECTS=$(tests_SOURCES:.cpp=.o)

tests_EXECUTABLE = tests_bin

all: tests

%.o : %.c
	$(CXX) -c $(CPPFLAGS) $< -o $@

$(tests_EXECUTABLE): $(tests_OBJECTS) $(lib_OBJECTS)
	$(CXX) -o $@ $(tests_OBJECTS) $(lib_OBJECTS) $(LINKFLAGS)

tests: $(tests_EXECUTABLE)
	./$(tests_EXECUTABLE)

.PHONY: clean tests

clean:
	- rm *.o
	- rm tests_bin