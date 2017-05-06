// Copyright 2017 Declan Hoare
// This file is part of CoolIm.
//
// CoolIm is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// CoolIm is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with CoolIm.  If not, see <http://www.gnu.org/licenses/>.

#include <string>
#include <sstream>

#include <boost/interprocess/streams/bufferstream.hpp>

#include <cpptk.h>
#include <Magick++.h>

#define BUFFERSIZE 16777216
#include <b64/encode.h>

using namespace Tk;

Magick::Image orig;
bool loaded = false;

void updateLabel(void)
{
	if (loaded)
	{
		Magick::Image conv(orig);
		
		// Scale the image for the display area.
		// FIXME: doesn't work for some images larger than the display
		// area - there is probably a really dumb mistake somewhere here
		int iw = conv.columns();
		int ih = conv.rows();
		int cw = winfo(width, ".label");
		int ch = winfo(height, ".label");
		double imscale = 1.0;
		if ((iw - cw) > (ih - ch))
			imscale = (double) cw / iw;
		else
			imscale = (double) ch / ih;
		iw *= imscale;
		ih *= imscale;
		Magick::Geometry resize(iw, ih);
		conv.scale(resize);
		".photo" << configure() -width(iw) -height(ih);
		
		// Convert to PNG and transfer into the Tcl environment using
		// Base64. There is probably a much faster way to do this, FIXME
		Magick::Blob imdata;
		conv.magick("PNG");
		conv.write(&imdata);
		base64::encoder enc;
		boost::interprocess::bufferstream instr((char*) imdata.data(), imdata.length());
		std::stringstream outstr;
		enc.encode(instr, outstr);
		Tk::eval("set outstr \"" + outstr.str() + "\"");
		Tk::eval(".photo configure -data $outstr");
		".label" << configure() -image(".photo"); 
	}
}

void openImage(void)
{
	// TODO: add filename filters
	std::string filename = tk_getOpenFile();
	if (!filename.empty())
	{
		orig.read(filename);
		loaded = true;
		updateLabel();
	}
}

int main(int argc, char** argv)
{
	Tk::init(argv[0]);
	Magick::InitializeMagick(argv[0]);
	
	wm(title, ".", "CoolIm");
	bind(".", "<Configure>", updateLabel);
	frame(".mbar") -borderwidth(1) -relief(raised);
	pack(".mbar") -fill(x);
	
	menubutton(".mbar.file") -text("File") -submenu(".mbar.file.m");
	pack(".mbar.file") -side(left);
	
	menu(".mbar.file.m");
	".mbar.file.m" << add(command) -menulabel("Open") -command(openImage);
	".mbar.file.m" << add(command) -menulabel("Exit") -command(std::string("exit"));
	
	images(create, photo, ".photo");
	
	label(".label");
	pack(".label") -fill(both) -expand(true);
	
	if (argc > 1)
	{
		orig.read(argv[1]);
		loaded = true;
	}
	
	Tk::runEventLoop();
	return 0;
}
