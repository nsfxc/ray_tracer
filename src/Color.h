#ifndef COLOR_H
#define COLOR_H

//color = 0xRRGGBB
typedef unsigned long Color;

//constants
const Color RED = 0xff0000;
const Color GREEN = 0xff00;
const Color BLUE = 0xff;
const Color BLACK = 0x0;
const Color WHITE = 0xffffff;
const Color YELLOW = 0xffff00;

//"constructor"
Color color(unsigned char r, unsigned char g, unsigned char b);

//get R G B composants
unsigned char color_red(const Color);
unsigned char color_green(const Color);
unsigned char color_blue(const Color);
#endif // COLOR_H
