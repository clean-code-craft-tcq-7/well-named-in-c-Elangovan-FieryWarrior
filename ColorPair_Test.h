#ifndef COLORPAIR_TEST_H
#define COLORPAIR_TEST_H

#include "colorpair.h"

void testNumberToPair(int pairNumber,
    enum MajorColor expectedMajor,
    enum MinorColor expectedMinor);

void testPairToNumber(
    enum MajorColor major,
    enum MinorColor minor,
    int expectedPairNumber);

#endif // COLORPAIR_TEST_H