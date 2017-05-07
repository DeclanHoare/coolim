# Copyright 2017 Declan Hoare
# This file is part of CoolIm.
#
# CoolIm is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# CoolIm is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with CoolIm.  If not, see <http://www.gnu.org/licenses/>.

ACLOCAL_AMFLAGS = -I m4

bin_PROGRAMS = coolim
coolim_SOURCES = coolim.cpp
coolim_CXXFLAGS = @CPPTK_CFLAGS@ @MAGICK_CFLAGS@
coolim_LDFLAGS = @CPPTK_LIBS@ @MAGICK_LIBS@ -lb64
