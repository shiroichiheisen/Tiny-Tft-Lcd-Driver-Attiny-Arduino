# Tiny Driver St7735 for attiny's

Library tested with:

Attiny1616

## ☕ Using this library


To use this library, you need to download, install the library, and include the following file in your project:

```
#include "tiny_driver.h"
```

After that, declare the object:

```
tiny_driver DisplayA(int xSize, int ySize, int orientation, int xOffset, int yOffset, int cs, int dc, int textScale, int bgr)
```

xSize - Horizontal Size of the Display
ySize - Vertical Size of the Display
Orientation - Orientation of the Display
xOffset - Offset on the Horizontal plane of the Display
yOffset - Offset on the Vertical plane of the Display
CS - The pin where CS its connected
DC - The pin where DC its connected
textScale - The scale of the text on the display
BGR or RGB - The method of color of the display


In this library, you have:

[InitDisplay](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[DisplayOn](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[ClearDisplay ](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[MoveTo](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[PlotPoint](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[DrawTo](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[FillRect](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[PlotText](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[PlotInt](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[Color](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[ChangeTextScale](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[ChangeTextBackground](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[Show Text](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[Show Int](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[Show Image](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[Show Image Compressed](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

## InitDisplay()

Iniciates the Display, but remember that this only inicializes.

## DisplayOn()

Enable the display to begin showing images.

## ClearDisplay() 

Clears the display.

## MoveTo(int xposition, int yposition)

Moves the cursor to designed pixel on screen.

## PlotPoint(int xposition, int yposition)

Plot pixel on the designed x and y position.

## DrawTo(int xposition, int yposition)

To use this function, use first the MoveTo to change the cursor to start point and use this function to draw a line from the start point to designed x and y position.

## FillRect(int Widht, int Height);

Draw a Rectangle with designed widht and height.

## PlotText(const char Text)

Draw Text on display

## PlotInt(int Number)

Draw an Integer on display

## Color(int RGB565) or Color(int r, int g, int b)

Change the color, with this you can change the rectangle color, text and lines.

## ChangeTextScale(int Scale)

Change the size of the text that you will write on the display

## ChangeTextBackground(int BackgroundColor)

Change the background color of the text.

## ShowText(int xPosition, int yPosition, const char Text, int TextScale)

Show text with more userfriendly function, with the position and scale.

## ShowInt(int x, int y, int integer, int textScale)

Show Integer with more userfriendly function, with the position and scale.

## ShowImage(const unsigned int ImageHex, int xLocation, int yLocation, int xSize, int ySize)

Show converted RGB565 image, to convert just use the folowing link: http://www.rinkydinkelectronics.com/t_imageconverter565.php

After Converted, make and array of the hex from the image and send to this function

```
const unsigned int voltageIcon[] = { //The array HAVE! to be an unsigned int, because of the max color position! 65535
    0x0000,
    0x10A0,
    0x4282,
    0x6384,
    };

  ShowImage(voltageIcon, 10, 20, 32, 32);  
```

## ShowImageCompressed(const unsigned int ImageHex, int xLocation, int yLocation, int xSize, int ySize)

Show converted RGB565 image, to convert just use the folowing link: http://www.rinkydinkelectronics.com/t_imageconverter565.php  and compress it with the compressor i will be sending here, if you want before i post it here, just send me a dm, with the compressor i have sucessfuly turned and 5000 bytes image to only 2000 bytes, the eficiency of the compressor will be better if the image have large bytes of the same color sequencial, because the compressor use the color and the times this color appear on the line of pixels


```
const unsigned int voltageIcon[] = { //The array HAVE! to be an unsigned int, because of the max color position! 65535
    0x0000,   //color to send to each pixels
    18        //how many pixel the color will be sent on the x axys
    0x10A0,
    2
    0x4282,
    24
    0x6384,
    7
    };

  ShowImage(voltageIcon, 10, 20, 32, 32);  
```

Many more updates soon, because right now i will not use until the board arryves to make the final adjustments, if you have some betters ways to make this library more compact, just send a pull request!