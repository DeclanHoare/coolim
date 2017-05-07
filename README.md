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

Run

```
autoreconf -i
./configure
make
```

to build the program. You can also run `make install` as root to install
it system-wide.

## TODO
* Zoom feature
* File name filters
* Browse directories as galleries
* Checkerboard pattern in transparent regions of an image
* Basic processing functionality? EXIF data, rotation, crop, conversion?
* Animated GIF support?
