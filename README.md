# Tiny Driver St7735 for attiny's

# Readme still on update!!!!!!!!

Library tested with:

Attiny1616

## ☕ Using this library


To use this library, you need to download, install the library, and include the following file in your project:

```
#include <utils_various.h>
```

After that, declare the object with the following line:

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

[Init Display](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[Display On](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[Clear Display ](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[Move to](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[Plot Point](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[Draw to](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[Fill Rect](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[Plot Text](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[Plot Int](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[Color](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[Change Text Scale](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[Change Text Background](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[Show Text](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[Show Int](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)

[Display Image](https://github.com/shiroichiheisen/Tiny-Driver-ST7735#function)



To use the image display, just use the folowing piece of code:


```
void DisplayImage(int xLocation, int yLocation, int xSize, int ySize)
{
  int hexNum = 0;
  for (int y = yLocation + ySize; y > yLocation; y--)
  {
    for (int x = xLocation; x < xLocation + xSize; x++)
    {
      int a = <changeToimageBytes>[hexNum];
      displaya.Color(a);
      displaya.PlotPoint(x, y);
      hexNum++;
    }
  }
}
```

to convert the image to code just use the site: http://www.rinkydinkelectronics.com/t_imageconverter565.php