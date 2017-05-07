CoolIm is the most RADICAL image viewer out there.
It is written in C++. It uses the ImageMagick library to handle files,
allowing it to support a huge number of formats, including FLIF and
JPEG-2000 (JP2).

## Dependencies
* Boost
* ImageMagick
* C++/Tk
* libb64

## Building

I will set up Autotools later, but for now run:
`g++ coolim.cpp -o coolim $(pkg-config cpptk Magick++ --cflags --libs) -lb64`

## TODO
* Zoom feature
* File name filters
* Browse directories as galleries
* Checkerboard pattern in transparent regions of an image
* Basic processing functionality? EXIF data, rotation, crop, conversion?
* Animated GIF support?
