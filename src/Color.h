#ifndef COLOR_H
#define COLOR_H

//color = 0xRRGGBB
typedef unsigned long Color;

//constants
static const Color RED = 0xff0000;
static const Color GREEN = 0xff00;
static const Color BLUE = 0xff;
static const Color BLACK = 0x0;
static const Color WHITE = 0xffffff;

//get R G B composants
unsigned char color_red(const Color);
unsigned char color_green(const Color);
unsigned char color_blue(const Color);
#endif // COLOR_H
