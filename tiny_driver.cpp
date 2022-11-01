
#include <Arduino.h>
#include "tiny_driver.h"

#include <SPI.h>

int
    displayYHeight,
    displayYOffset,
    displayXHeight,
    displayXOffset,
    displayOrientation,
    displayCs,
    displayDc,
    displayTextScale,
    displayBgr_or_Rgb,

    xpos, ypos,
    fore = 0xFFFF,
    back = 0;

int const
    CASET = 0x2A,
    RASET = 0x2B,
    RAMWR = 0x2C;

#define uchar unsigned char
#define uint unsigned int

const uint8_t CharMap[96][6] PROGMEM = {
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x5F, 0x00, 0x00, 0x00},
    {0x00, 0x07, 0x00, 0x07, 0x00, 0x00},
    {0x14, 0x7F, 0x14, 0x7F, 0x14, 0x00},
    {0x24, 0x2A, 0x7F, 0x2A, 0x12, 0x00},
    {0x23, 0x13, 0x08, 0x64, 0x62, 0x00},
    {0x36, 0x49, 0x56, 0x20, 0x50, 0x00},
    {0x00, 0x08, 0x07, 0x03, 0x00, 0x00},
    {0x00, 0x1C, 0x22, 0x41, 0x00, 0x00},
    {0x00, 0x41, 0x22, 0x1C, 0x00, 0x00},
    {0x2A, 0x1C, 0x7F, 0x1C, 0x2A, 0x00},
    {0x08, 0x08, 0x3E, 0x08, 0x08, 0x00},
    {0x00, 0x80, 0x70, 0x30, 0x00, 0x00},
    {0x08, 0x08, 0x08, 0x08, 0x08, 0x00},
    {0x00, 0x00, 0x60, 0x60, 0x00, 0x00},
    {0x20, 0x10, 0x08, 0x04, 0x02, 0x00},
    {0x3E, 0x51, 0x49, 0x45, 0x3E, 0x00},
    {0x00, 0x42, 0x7F, 0x40, 0x00, 0x00},
    {0x72, 0x49, 0x49, 0x49, 0x46, 0x00},
    {0x21, 0x41, 0x49, 0x4D, 0x33, 0x00},
    {0x18, 0x14, 0x12, 0x7F, 0x10, 0x00},
    {0x27, 0x45, 0x45, 0x45, 0x39, 0x00},
    {0x3C, 0x4A, 0x49, 0x49, 0x31, 0x00},
    {0x41, 0x21, 0x11, 0x09, 0x07, 0x00},
    {0x36, 0x49, 0x49, 0x49, 0x36, 0x00},
    {0x46, 0x49, 0x49, 0x29, 0x1E, 0x00},
    {0x00, 0x00, 0x14, 0x00, 0x00, 0x00},
    {0x00, 0x40, 0x34, 0x00, 0x00, 0x00},
    {0x00, 0x08, 0x14, 0x22, 0x41, 0x00},
    {0x14, 0x14, 0x14, 0x14, 0x14, 0x00},
    {0x00, 0x41, 0x22, 0x14, 0x08, 0x00},
    {0x02, 0x01, 0x59, 0x09, 0x06, 0x00},
    {0x3E, 0x41, 0x5D, 0x59, 0x4E, 0x00},
    {0x7C, 0x12, 0x11, 0x12, 0x7C, 0x00},
    {0x7F, 0x49, 0x49, 0x49, 0x36, 0x00},
    {0x3E, 0x41, 0x41, 0x41, 0x22, 0x00},
    {0x7F, 0x41, 0x41, 0x41, 0x3E, 0x00},
    {0x7F, 0x49, 0x49, 0x49, 0x41, 0x00},
    {0x7F, 0x09, 0x09, 0x09, 0x01, 0x00},
    {0x3E, 0x41, 0x41, 0x51, 0x73, 0x00},
    {0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00},
    {0x00, 0x41, 0x7F, 0x41, 0x00, 0x00},
    {0x20, 0x40, 0x41, 0x3F, 0x01, 0x00},
    {0x7F, 0x08, 0x14, 0x22, 0x41, 0x00},
    {0x7F, 0x40, 0x40, 0x40, 0x40, 0x00},
    {0x7F, 0x02, 0x1C, 0x02, 0x7F, 0x00},
    {0x7F, 0x04, 0x08, 0x10, 0x7F, 0x00},
    {0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00},
    {0x7F, 0x09, 0x09, 0x09, 0x06, 0x00},
    {0x3E, 0x41, 0x51, 0x21, 0x5E, 0x00},
    {0x7F, 0x09, 0x19, 0x29, 0x46, 0x00},
    {0x26, 0x49, 0x49, 0x49, 0x32, 0x00},
    {0x03, 0x01, 0x7F, 0x01, 0x03, 0x00},
    {0x3F, 0x40, 0x40, 0x40, 0x3F, 0x00},
    {0x1F, 0x20, 0x40, 0x20, 0x1F, 0x00},
    {0x3F, 0x40, 0x38, 0x40, 0x3F, 0x00},
    {0x63, 0x14, 0x08, 0x14, 0x63, 0x00},
    {0x03, 0x04, 0x78, 0x04, 0x03, 0x00},
    {0x61, 0x59, 0x49, 0x4D, 0x43, 0x00},
    {0x00, 0x7F, 0x41, 0x41, 0x41, 0x00},
    {0x02, 0x04, 0x08, 0x10, 0x20, 0x00},
    {0x00, 0x41, 0x41, 0x41, 0x7F, 0x00},
    {0x04, 0x02, 0x01, 0x02, 0x04, 0x00},
    {0x40, 0x40, 0x40, 0x40, 0x40, 0x00},
    {0x00, 0x03, 0x07, 0x08, 0x00, 0x00},
    {0x20, 0x54, 0x54, 0x78, 0x40, 0x00},
    {0x7F, 0x28, 0x44, 0x44, 0x38, 0x00},
    {0x38, 0x44, 0x44, 0x44, 0x28, 0x00},
    {0x38, 0x44, 0x44, 0x28, 0x7F, 0x00},
    {0x38, 0x54, 0x54, 0x54, 0x18, 0x00},
    {0x00, 0x08, 0x7E, 0x09, 0x02, 0x00},
    {0x18, 0xA4, 0xA4, 0x9C, 0x78, 0x00},
    {0x7F, 0x08, 0x04, 0x04, 0x78, 0x00},
    {0x00, 0x44, 0x7D, 0x40, 0x00, 0x00},
    {0x20, 0x40, 0x40, 0x3D, 0x00, 0x00},
    {0x7F, 0x10, 0x28, 0x44, 0x00, 0x00},
    {0x00, 0x41, 0x7F, 0x40, 0x00, 0x00},
    {0x7C, 0x04, 0x78, 0x04, 0x78, 0x00},
    {0x7C, 0x08, 0x04, 0x04, 0x78, 0x00},
    {0x38, 0x44, 0x44, 0x44, 0x38, 0x00},
    {0xFC, 0x18, 0x24, 0x24, 0x18, 0x00},
    {0x18, 0x24, 0x24, 0x18, 0xFC, 0x00},
    {0x7C, 0x08, 0x04, 0x04, 0x08, 0x00},
    {0x48, 0x54, 0x54, 0x54, 0x24, 0x00},
    {0x04, 0x04, 0x3F, 0x44, 0x24, 0x00},
    {0x3C, 0x40, 0x40, 0x20, 0x7C, 0x00},
    {0x1C, 0x20, 0x40, 0x20, 0x1C, 0x00},
    {0x3C, 0x40, 0x30, 0x40, 0x3C, 0x00},
    {0x44, 0x28, 0x10, 0x28, 0x44, 0x00},
    {0x4C, 0x90, 0x90, 0x90, 0x7C, 0x00},
    {0x44, 0x64, 0x54, 0x4C, 0x44, 0x00},
    {0x00, 0x08, 0x36, 0x41, 0x00, 0x00},
    {0x00, 0x00, 0x77, 0x00, 0x00, 0x00},
    {0x00, 0x41, 0x36, 0x08, 0x00, 0x00},
    {0x00, 0x06, 0x09, 0x06, 0x00, 0x00},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00}};

tiny_driver::tiny_driver(int xSize, int ySize, int orientation, int xOffset, int yOffset, int cs, int dc, int textScale, int bgr)
{
    displayCs = cs;
    displayDc = dc;
    displayOrientation = orientation;
    displayTextScale = textScale;
    displayXHeight = xSize;
    displayYHeight = ySize;
    displayXOffset = xOffset;
    displayYOffset = yOffset;
    displayBgr_or_Rgb = bgr;
}

void tiny_driver::ChangeTextScale(int scale)
{
    displayTextScale = scale;
}

void Data(uint8_t d)
{
    digitalWrite(displayCs, LOW);
    SPI.transfer(d);
    digitalWrite(displayCs, HIGH);
}

void Command(uint8_t c)
{
    digitalWrite(displayDc, LOW);
    Data(c);
    digitalWrite(displayDc, HIGH);
}

void Command2(uint8_t c, uint16_t d1, uint16_t d2)
{
    digitalWrite(displayDc, LOW);
    Data(c);
    digitalWrite(displayDc, HIGH);
    Data(d1 >> 8);
    Data(d1);
    Data(d2 >> 8);
    Data(d2);
}

void SPI_WriteData(uchar Data)
{
    SPI.transfer(Data);
}

void Lcd_WriteIndex(uchar Data)
{
    digitalWrite(displayCs, LOW);
    digitalWrite(displayDc, LOW);
    SPI_WriteData(Data);
    digitalWrite(displayCs, HIGH);
}

void Lcd_WriteData(uchar Data)
{
    digitalWrite(displayCs, LOW);
    digitalWrite(displayDc, HIGH);
    SPI_WriteData(Data);
    digitalWrite(displayCs, HIGH);
}

void tiny_driver::InitDisplay()
{
    pinMode(displayDc, OUTPUT);
    pinMode(displayCs, OUTPUT);
    digitalWrite(displayCs, HIGH);
    digitalWrite(displayDc, HIGH); // Data
    SPI.begin();
    Command(0x01); // Software reset
    Lcd_WriteIndex(0xfe);
    Lcd_WriteIndex(0xfe);
    Lcd_WriteIndex(0xfe);
    Lcd_WriteIndex(0xef);
    Lcd_WriteIndex(0xb3);
    Lcd_WriteData(0x03);
    Lcd_WriteIndex(0x36);
    Lcd_WriteData(0xd8);
    Lcd_WriteIndex(0x3a);
    Lcd_WriteData(0x05);
    Lcd_WriteIndex(0xb6);
    Lcd_WriteData(0x11);
    Lcd_WriteIndex(0xac);
    Lcd_WriteData(0x0b);
    Lcd_WriteIndex(0xb4);
    Lcd_WriteData(0x21);
    Lcd_WriteIndex(0xb1);
    Lcd_WriteData(0xc0);
    Lcd_WriteIndex(0xe6);
    Lcd_WriteData(0x50);
    Lcd_WriteData(0x43);
    Lcd_WriteIndex(0xe7);
    Lcd_WriteData(0x56);
    Lcd_WriteData(0x43);
    Lcd_WriteIndex(0xF0);
    Lcd_WriteData(0x1f);
    Lcd_WriteData(0x41);
    Lcd_WriteData(0x1B);
    Lcd_WriteData(0x55);
    Lcd_WriteData(0x36);
    Lcd_WriteData(0x3d);
    Lcd_WriteData(0x3e);
    Lcd_WriteData(0x0);
    Lcd_WriteData(0x16);
    Lcd_WriteData(0x08);
    Lcd_WriteData(0x09);
    Lcd_WriteData(0x15);
    Lcd_WriteData(0x14);
    Lcd_WriteData(0xf);
    Lcd_WriteIndex(0xF1);
    Lcd_WriteData(0x1f);
    Lcd_WriteData(0x41);
    Lcd_WriteData(0x1B);
    Lcd_WriteData(0x55);
    Lcd_WriteData(0x36);
    Lcd_WriteData(0x3d);
    Lcd_WriteData(0x3e);
    Lcd_WriteData(0x0);
    Lcd_WriteData(0x16);
    Lcd_WriteData(0x08);
    Lcd_WriteData(0x09);
    Lcd_WriteData(0x15);
    Lcd_WriteData(0x14);
    Lcd_WriteData(0xf);
    Lcd_WriteIndex(0xfe);
    Lcd_WriteIndex(0xff);
    Lcd_WriteIndex(0x35);
    Lcd_WriteData(0x00);
    Lcd_WriteIndex(0x44);
    Lcd_WriteData(0x00);
    Lcd_WriteIndex(0x11);
    delay(120);
    Lcd_WriteIndex(0x29);
    Lcd_WriteIndex(0x2A); // Set Column Address
    Lcd_WriteData(0x00);
    Lcd_WriteData(0x18);
    Lcd_WriteData(0x00);
    Lcd_WriteData(0x67);
    Lcd_WriteIndex(0x2B); // Set Page Address
    Lcd_WriteData(0x00);
    Lcd_WriteData(0x00);
    Lcd_WriteData(0x00);
    Lcd_WriteData(0x9f);
    Lcd_WriteIndex(0x2c);
    Command(0x36);
    Data(displayOrientation << 5 | displayBgr_or_Rgb << 3); // Set orientation and rgb/bgr
}

void tiny_driver::DisplayOn()
{
    Command(0x29); // Display on
    delay(150);
}

void tiny_driver::ClearDisplay()
{
    Command2(CASET, displayYOffset, displayYOffset + displayYHeight - 1);
    Command2(RASET, displayXOffset, displayXOffset + displayXHeight - 1);
    Command(0x3A);
    Data(0x03); // 12-bit colour
    Command(RAMWR);
    for (int i = 0; i < displayXHeight / 2; i++)
    {
        for (int j = 0; j < displayYHeight * 3; j++)
        {
            Data(0);
        }
    }
    Command(0x3A);
    Data(0x05); // Back to 16-bit colour
}

void tiny_driver::Color(int r, int g, int b)
{
    if (displayBgr_or_Rgb)
        fore = (r & 0xf8) << 8 | (g & 0xfc) << 3 | b >> 3;
    else
        fore = (b & 0xf8) << 8 | (g & 0xfc) << 3 | r >> 3;
}

void tiny_driver::Color(int rgb)
{
    fore = rgb;
}

// Move current plot position to x,y
void tiny_driver::MoveTo(int x, int y)
{
    xpos = x;
    ypos = y;
}

// Plot point at x,y
void tiny_driver::PlotPoint(int x, int y)
{
    Command2(CASET, displayYOffset + y, displayYOffset + y);
    Command2(RASET, displayXOffset + x, displayXOffset + x);
    Command(RAMWR);
    Data(fore >> 8);
    Data(fore & 0xff);
}

// Draw a line to x,y
void tiny_driver::DrawTo(int x, int y)
{
    int sx, sy, e2, err;
    int dx = abs(x - xpos);
    int dy = abs(y - ypos);
    if (xpos < x)
        sx = 1;
    else
        sx = -1;
    if (ypos < y)
        sy = 1;
    else
        sy = -1;
    err = dx - dy;
    for (;;)
    {
        PlotPoint(xpos, ypos);
        if (xpos == x && ypos == y)
            return;
        e2 = err << 1;
        if (e2 > -dy)
        {
            err = err - dy;
            xpos = xpos + sx;
        }
        if (e2 < dx)
        {
            err = err + dx;
            ypos = ypos + sy;
        }
    }
}

void tiny_driver::FillRect(int w, int h)
{
    Command2(CASET, ypos + displayYOffset, ypos + displayYOffset + h - 1);
    Command2(RASET, xpos + displayXOffset, xpos + displayXOffset + w - 1);
    Command(RAMWR);
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            Data(fore >> 8);
            Data(fore & 0xff);
        }
    }
}

// Plot an ASCII character with bottom left corner at x,y
void PlotChar(char c)
{
    int colour;
    Command2(CASET, displayYOffset + ypos, displayYOffset + ypos + 8 * displayTextScale - 1);
    Command2(RASET, displayXOffset + xpos, displayXOffset + xpos + 6 * displayTextScale - 1);
    Command(RAMWR);
    for (int xx = 0; xx < 6; xx++)
    {
        int bits = pgm_read_byte(&CharMap[c - 32][xx]);
        for (int xr = 0; xr < displayTextScale; xr++)
        {
            for (int yy = 0; yy < 8; yy++)
            {
                if (bits >> (7 - yy) & 1)
                    colour = fore;
                else
                    colour = back;
                for (int yr = 0; yr < displayTextScale; yr++)
                {
                    Data(colour >> 8);
                    Data(colour & 0xFF);
                }
            }
        }
    }
    xpos = xpos + 6 * displayTextScale;
}

// Plot text starting at the current plot position
void tiny_driver::PlotText(PGM_P p)
{
    while (1)
    {
        char c = pgm_read_byte(p++);
        if (c == 0)
            return;
        PlotChar(c);
    }
}

void tiny_driver::PlotInt(int n)
{
    bool lead = false;
    for (int d = 10000; d > 0; d = d / 10)
    {
        char j = (n / d) % 10;
        if (j != 0 || lead || d == 1)
        {
            PlotChar(j + '0');
            lead = true;
        }
    }
}

void tiny_driver::ShowText(int x, int y, const char *text, int textScale)
{
    MoveTo(x, y);
    ChangeTextScale(textScale);
    PlotText(text);
}

void tiny_driver::ShowInt(int x, int y, int integer, int textScale)
{
    MoveTo(x, y);
    ChangeTextScale(textScale);
    PlotInt(integer);
}

void tiny_driver::ChangeTextBackground(int backColor)
{
    back = backColor;
}

void tiny_driver::ShowImage(const unsigned int *image, int xLocation, int yLocation, int xSize, int ySize)
{
    int hexNum = 0;
    for (int y = yLocation + ySize; y > yLocation; y--)
    {
        for (int x = xLocation; x < xLocation + xSize; x++)
        {
            int a = image[hexNum];
            Color(a);
            PlotPoint(x, y);
            hexNum++;
        }
    }
}

void tiny_driver::ShowImageCompressed(const unsigned int *image, int xLocation, int yLocation, int xSize, int ySize)
{
    unsigned short int
        xposition = xLocation,
        yposition = yLocation + (ySize - 1),
        hexNum = 0;

    while (1)
    {
        Color(image[hexNum]);
        for (unsigned int i = image[hexNum + 1]; i > 0; i--)
        {
            PlotPoint(xposition, yposition);
            xposition++;
            if (xposition > (xLocation + (xSize - 1)))
            {
                yposition--;
                xposition = xLocation;
            }
            if (yposition == yLocation)
                break;
        }
        hexNum += 2;
        if (yposition == yLocation)
            break;
    }
}

void tiny_driver::ShowImageCompressedOne(const unsigned int *image, int xLocation, int yLocation, int xSize, int ySize, int ColorCodeCompress)
{
    unsigned short int
        xposition = xLocation,
        yposition = yLocation + (ySize - 1),
        hexNum = 0;

    while (1)
    {
        if (image[hexNum] == ColorCodeCompress)
        {
            Color(image[hexNum]);
            for (unsigned int i = image[hexNum + 1]; i > 0; i--)
            {
                PlotPoint(xposition, yposition);
                xposition++;
                if (xposition > (xLocation + (xSize - 1)))
                {
                    yposition--;
                    xposition = xLocation;
                }
                if (yposition == yLocation)
                    break;
            }
            hexNum += 2;
            if (yposition == yLocation)
                break;
        }
        else
        {
            Color(image[hexNum]);
            int a = image[hexNum];
            Color(a);
            PlotPoint(xposition, yposition);
            hexNum++;
            xposition++;
            if (xposition > (xLocation + (xSize - 1)))
            {
                yposition--;
                xposition = xLocation;
            }
            if (yposition == yLocation)
                break;
        }
    }
}