# Tiny Driver St7735

Library works 100% with 0, 1 and 2-Series attinys (already tested on them), on other attinys and atmegas will work too

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


# In this library, you have:

[InitDisplay](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#InitDisplay)

[DisplayOn](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#DisplayOn)

[ClearDisplay ](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#ClearDisplay)

[MoveTo](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#MoveToint-xposition-int-yposition)

[PlotPoint](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#PlotPointint-xposition-int-yposition)

[DrawTo](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#DrawToint-xposition-int-yposition)

[FillRect](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#FillRectint-Widht-int-Height)

[PlotText](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#PlotTextconst-char-Text)

[PlotInt](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#PlotIntint-Number)

[Color](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#Colorint-RGB565-or-Colorint-r-int-g-int-b)

[ChangeTextScale](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#ChangeTextScaleint-Scale)

[ChangeTextBackground](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#ChangeTextBackgroundint-BackgroundColor)

[Show Text](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#ShowTextint-xPosition-int-yPosition-const-char-Text-int-TextScale)

[Show Int](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#ShowIntint-x-int-y-int-integer-int-textScale)

[Show Image](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#ShowImageconst-unsigned-int-ImageHex-int-xLocation-int-yLocation-int-xSize-int-ySize)

[Show Image Compressed](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#ShowImageCompressedconst-unsigned-int-ImageHex-int-xLocation-int-yLocation-int-xSize-int-ySize)

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

## FillRect(int Widht, int Height)

Draw a Rectangle with designed widht and height.

## PlotText(const char Text)

Draw Text on display.

## PlotInt(int Number)

Draw an Integer on display.

## Color(int RGB565) or Color(int r, int g, int b)

Change the color, with this you can change the rectangle color, text and lines.

## ChangeTextScale(int Scale)

Change the size of the text that you will write on the display.

## ChangeTextBackground(int BackgroundColor)

Change the background color of the text.

## ShowText(int xPosition, int yPosition, const char Text, int TextScale)

Show text with more userfriendly function, with the position and scale.

## ShowInt(int x, int y, int integer, int textScale)

Show Integer with more userfriendly function, with the position and scale.

## ShowImage(const unsigned int ImageHex, int xLocation, int yLocation, int xSize, int ySize)

Show converted RGB565 image, to convert just use the folowing link: http://www.rinkydinkelectronics.com/t_imageconverter565.php

After Converted, make and array of the hex from the image and send to this function:

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

Show converted RGB565 image, to convert just use the folowing link: http://www.rinkydinkelectronics.com/t_imageconverter565.php  and compress it with the compressor: https://shiroichiheisen.github.io/Tiny-Driver-ST7735/, with the compressor i have sucessfuly turned an 5000 bytes image to only 2000 bytes, the eficiency of the compressor will be better if the image have large bytes of the same color sequencial, because the compressor use the color and the times this color appear on the line of pixels.

To use the compressor just paste the image code on the first input, to compress all colors, click on the button "Covert All Data!", I recomend to use the 1 color only compress, because you will have a better eficiency of the compression, just insert the color that repeats the most, on my images I have most 0x0000 color repeating, and click on the button "Convert only the color code!", on the input bellow will be the compressed code and below him will be some text showing how much compression you get.


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

Many more updates soon, because right now i will not use until the board aryves to make the final adjustments, if you have some betters ways to make this library more compact, just send a pull request!.