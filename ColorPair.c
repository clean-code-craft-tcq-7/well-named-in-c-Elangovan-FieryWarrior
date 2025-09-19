#include <stdio.h>
#include <assert.h>
#include "ColorPair.h"

const char* MajorColorNames[] = {
    "White", "Red", "Black", "Yellow", "Violet"
};

const int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

const char* MinorColorNames[] = {
    "Blue", "Orange", "Green", "Brown", "Slate"
};

const int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    sprintf(buffer, "%s %s",
        MajorColorNames[colorPair->majorColor],
        MinorColorNames[colorPair->minorColor]);
}

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = 
        (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor =
        (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors +
            colorPair->minorColor + 1;
}

void PrintReferenceManual()
{
    printf("Reference Manual\n");
    printf("-----------------------------\n");
    printf("| Pair No | Major  | Minor  |\n");
    printf("-----------------------------\n");
    char colorPairStr[32];
    for (int i = 1; i <= numberOfMajorColors * numberOfMinorColors; i++)
    {
        ColorPair colorDetails = GetColorFromPairNumber(i);
        ColorPairToString(&colorDetails, colorPairStr);
        printf("| %7d | %6s | %6s |\n", 
            i, 
            MajorColorNames[colorDetails.majorColor], 
            MinorColorNames[colorDetails.minorColor]);
    }
    printf("-----------------------------\n");
}

int main()
{
    PrintReferenceManual();
    return 0;
}