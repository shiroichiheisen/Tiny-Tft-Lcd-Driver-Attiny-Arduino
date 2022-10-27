# Tiny Driver St7735 for attiny's

Library tested with:

Attiny1616

## ☕ Using this library

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

on the future readme will be updated