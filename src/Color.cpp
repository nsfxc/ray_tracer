#include "Color.h"

//"constructor"
Color color(const unsigned char r, const unsigned char g, const unsigned char b)
{
    return (Color)((r<<16) + (g<<8) + b);
}

//get R G B composants
unsigned char color_red(const Color c)
{
    return (unsigned char)(c>>16);
}
//faster but won't work if char greater than 8 bit...
//unsigned char color_green(const Color c)
//{
//    return (unsigned char)((c>>8));
//}
//unsigned char color_blue(const Color c)
//{
//    return (unsigned char)(c);
//}
//slower but sure
unsigned char color_green(const Color c)
{
    return (unsigned char)((c>>8)^((c>>16)<<8));
}
unsigned char color_blue(const Color c)
{
    return (unsigned char)(c^((c>>8)<<8));
}

