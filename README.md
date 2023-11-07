# Tiny Driver ST7735

Welcome to the GitHub repository for the ST7735 Tiny Driver Library. This library has been thoroughly tested and is fully compatible with the 0, 1, and 2-Series ATTiny microcontrollers. It's also suitable for use with other ATTiny models and ATMega microcontrollers.

## 🚀 Getting Started with the ST7735 Tiny Driver

To integrate the ST7735 Tiny Driver into your project, follow these steps:

1. Download and install the library onto your system.

2. Include the library header in your project:

```cpp\n#include \"tiny_driver.h\"\n```

3. Create an instance of the `tiny_driver` class:

```cpp\ntiny_driver DisplayA(int xSize, int ySize, int orientation, int xOffset, int yOffset, int cs, int dc, int textScale, int bgr)\n```

- `xSize`: Display width in pixels\n- `ySize`: Display height in pixels\n- `Orientation`: Display orientation\n- `xOffset`: Horizontal offset on the screen\n- `yOffset`: Vertical offset on the screen\n- `CS`: Chip Select (CS) pin connection\n- `DC`: Data/Command (DC) pin connection\n- `textScale`: Text scaling factor on the screen\n- `BGR` or `RGB`: Color mode of the display

## 🛠️ Library Features

Below is a list of available functionalities in the library:

- InitDisplay()\n- DisplayOn()\n- ClearDisplay()\n- MoveTo()\n- PlotPoint()\n- DrawTo()\n- FillRect()\n- PlotText()\n- PlotInt()\n- Color()\n- ChangeTextScale()\n- ChangeTextBackground()\n- ShowText()\n- ShowInt()\n- ShowImage()\n- ShowImageCompressed()\n- ShowImageCompressedOne()

Detailed descriptions of each method can be found within the library's documentation and source code.

## 🧩 Library Functions Explained

### InitDisplay()\nInitializes the display. This must be called before any other display operations.

### DisplayOn()\nEnables the display to start showing images.

### ClearDisplay()\nClears the entire display.

### MoveTo(int xPosition, int yPosition)\nMoves the cursor to a specific pixel on the screen.

### PlotPoint(int xPosition, int yPosition)\nPlots a pixel at the specified `x` and `y` position.

### DrawTo(int xPosition, int yPosition)\nDraws a line from the current cursor position to the specified `x` and `y` position. Use `MoveTo` first to set the start point.

### FillRect(int Width, int Height)\nDraws a rectangle with the specified width and height.

### PlotText(const char* Text)\nDisplays text on the screen.

### PlotInt(int Number)\nDisplays an integer on the screen.

### Color(int RGB565)\nSets the current color using the RGB565 format or individual `r`, `g`, and `b` values.

### ChangeTextScale(int Scale)\nChanges the text scaling for display on the screen.

### ChangeTextBackground(int BackgroundColor)\nSets the background color for text.

### ShowText(int xPosition, int yPosition, const char* Text, int TextScale)\nDisplays text on the screen at the specified position and scale in a user-friendly manner.

### ShowInt(int x, int y, int number, int textScale)\nDisplays an integer on the screen at the specified position and scale in a user-friendly way.

### ShowImage(const unsigned int ImageHex[], int xLocation, int yLocation, int xSize, int ySize)\nDisplays an RGB565 image converted using the tool provided at: http://www.rinkydinkelectronics.com/t_imageconverter565.php

Example usage:

```cpp\nconst unsigned int voltageIcon[] = {\n    0x0000, // color value\n    0x10A0, // color value\n    // ... more colors\n};

DisplayA.ShowImage(voltageIcon, 10, 20, 32, 32);\n```

### ShowImageCompressed(const unsigned int ImageHex[], int xLocation, int yLocation, int xSize, int ySize)\nDisplays a compressed RGB565 image after conversion and compression.

### ShowImageCompressedOne(const unsigned int ImageHex[], int xLocation, int yLocation, int xSize, int ySize, int ColorCodeCompress)\nDisplays an image compressed with a single color.

## 📝 Final Notes

We're constantly updating and improving the library. If you have suggestions for enhancement or optimization or if you wish to contribute, feel free to submit a pull request!

Stay tuned for more updates and the final adjustments once the new boards arrive. Your feedback is always welcome!

---

If you have any queries or need support, don't hesitate to open an issue on the GitHub repository.
