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

AC_INIT([coolim], [1.0], [https://github.com/RogueAI42/coolim/issues], [coolim], [https://github.com/RogueAI42/coolim])
AC_CONFIG_SRCDIR([coolim.cpp])
AC_CONFIG_MACRO_DIRS([m4])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([1.11 -Wall foreign subdir-objects])
AC_CONFIG_FILES([Makefile])
AC_PROG_CXX
AM_PROG_AR
PKG_CHECK_MODULES([CPPTK], [cpptk])
PKG_CHECK_MODULES([MAGICK], [Magick++])
AC_CHECK_LIB([b64], [base64_encode_block])
LT_INIT
AC_OUTPUT
