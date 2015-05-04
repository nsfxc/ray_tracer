#include "Color.h"

//get R G B composants
unsigned char color_red(const Color c)
{
    return (unsigned char)(c/0x10000);
}
unsigned char color_green(const Color c)
{
    return (unsigned char)(c/0x100%0x100);
}
unsigned char color_blue(const Color c)
{
    return (unsigned char)(c%0x100);
}
