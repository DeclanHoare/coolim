CoolIm is the most RADICAL image viewer out there.
It is written in C++ and uses the ImageMagick library to handle files,
allowing it to support a huge number of formats, including FLIF and
JPEG-2000 (JP2).
It is still in early stages and so it's unfortunately a bit slow. But
in the future it will be a lot faster and have more abilities.

## Dependencies
* Boost
* ImageMagick
* C++/Tk
* libb64

## Building

I will set up Autotools later, but for now run:
`g++ coolim.cpp -o coolim $(pkg-config cpptk Magick++ --cflags --libs) -lb64`

## TODO
* Transferring the image data to Tcl is a bit too slow.
* Toggle for linear/nearest?
* Adding a zoom feature would be nice.
* File name filters
* Browse directories as galleries
* Checkerboard pattern in transparent regions of an image
* Basic processing functionality? EXIF data, rotation, crop, conversion?
* Animated GIF support
