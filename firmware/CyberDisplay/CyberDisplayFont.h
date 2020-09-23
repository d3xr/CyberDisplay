/**
** The original 3x5 font is licensed under the 3-clause BSD license:
**
** Copyright 1999 Brian J. Swetland
** Copyright 1999 Vassilii Khachaturov
** Portions (of vt100.c/vt100.h) copyright Dan Marks
**
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions
** are met:
** 1. Redistributions of source code must retain the above copyright
**    notice, this list of conditions, and the following disclaimer.
** 2. Redistributions in binary form must reproduce the above copyright
**    notice, this list of conditions, and the following disclaimer in the
**    documentation and/or other materials provided with the distribution.
** 3. The name of the authors may not be used to endorse or promote products
**    derived from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
** IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
** IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
** NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
** THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
** Modifications to Tom Thumb for improved readability are from Robey Pointer,
** see:
** http://robey.lag.net/2010/01/23/tiny-monospace-font.html
**
** The original author does not have any objection to relicensing of Robey
** Pointer's modifications (in this file) in a more permissive license.  See
** the discussion at the above blog, and also here:
** http://opengameart.org/forumtopic/how-to-submit-art-using-the-3-clause-bsd-license
**
** Feb 21, 2016: Conversion from Linux BDF --> Adafruit GFX font,
** with the help of this Python script:
** https://gist.github.com/skelliam/322d421f028545f16f6d
** William Skellenger (williamj@skellenger.net)
** Twitter: @skelliam
**
** September 16, 2020: Font optimized for 5*5 RGB matrix to display glucose 
** unints and glucose trend in blood via parsing NightScout site.
** More at: https://github.com/d3xr/CyberDisplay
*/ 

const uint8_t CyberDisplayFontBitmaps[] PROGMEM = {
  0x00, 0x80, 0x80, 0x80, 0x00, 0x80, 0xA0, 0xA0, 0xA0, 0xE0, 0xA0, 0xE0, 
  0xA0, 0x60, 0xC0, 0x60, 0xC0, 0x40, 0x80, 0x20, 0x40, 0x80, 0x20, 0xC0, 
  0xC0, 0xE0, 0xA0, 0x60, 0x80, 0x80, 0x40, 0x80, 0x80, 0x80, 0x40, 0x80, 
  0x40, 0x40, 0x40, 0x80, 0xA0, 0x40, 0xA0, 0x40, 0xE0, 0x40, 0x40, 0x80, 
  0xE0, 0x80, 0x78, 0x18, 0x28, 0x48, 0x80, 0xE0, 0xA0, 0xA0, 0xA0, 0xE0, 
  0x80, 0x80, 0x80, 0x80, 0x80, 0xE0, 0x20, 0x40, 0x80, 0xE0, 0xE0, 0x20, 
  0x40, 0x20, 0xE0, 0xA0, 0xA0, 0xE0, 0x20, 0x20, 0xE0, 0x80, 0xE0, 0x20, 
  0xE0, 0xE0, 0x80, 0xE0, 0xA0, 0xE0, 0xE0, 0x20, 0x40, 0x80, 0x80, 0xE0, 
  0xA0, 0xE0, 0xA0, 0xE0, 0xE0, 0xA0, 0xE0, 0x20, 0xE0, 0x80, 0x00, 0x80, 
  0x40, 0x00, 0x40, 0x80, 0x20, 0x20, 0xA8, 0x70, 0x20, 0xE0, 0x00, 0xE0, 
  0x20, 0x70, 0xA8, 0x20, 0x20, 0xE0, 0x20, 0x40, 0x00, 0x40, 0x40, 0xA0, 
  0xE0, 0x80, 0x60, 0x40, 0xA0, 0xE0, 0xA0, 0xA0, 0xC0, 0xA0, 0xC0, 0xA0, 
  0xC0, 0x60, 0x80, 0x80, 0x80, 0x60, 0xC0, 0xA0, 0xA0, 0xA0, 0xC0, 0xE0, 
  0x80, 0xE0, 0x80, 0xE0, 0xE0, 0x80, 0xE0, 0x80, 0x80, 0x60, 0x80, 0xE0, 
  0xA0, 0x60, 0xA0, 0xA0, 0xE0, 0xA0, 0xA0, 0xE0, 0x40, 0x40, 0x40, 0xE0, 
  0x20, 0x20, 0x20, 0xA0, 0x40, 0xA0, 0xA0, 0xC0, 0xA0, 0xA0, 0x80, 0x80, 
  0x80, 0x80, 0xE0, 0xA0, 0xE0, 0xE0, 0xA0, 0xA0, 0xA0, 0xE0, 0xE0, 0xE0, 
  0xA0, 0x40, 0xA0, 0xA0, 0xA0, 0x40, 0xC0, 0xA0, 0xC0, 0x80, 0x80, 0x40, 
  0xA0, 0xA0, 0xE0, 0x60, 0xC0, 0xA0, 0xE0, 0xC0, 0xA0, 0x60, 0x80, 0x40, 
  0x20, 0xC0, 0xE0, 0x40, 0x40, 0x40, 0x40, 0xA0, 0xA0, 0xA0, 0xA0, 0x60, 
  0xA0, 0xA0, 0xA0, 0x40, 0x40, 0xA0, 0xA0, 0xE0, 0xE0, 0xA0, 0xA0, 0xA0, 
  0x40, 0xA0, 0xA0, 0xA0, 0xA0, 0x40, 0x40, 0x40, 0xE0, 0x20, 0x40, 0x80, 
  0xE0, 0xE0, 0x80, 0x80, 0x80, 0xE0, 0x80, 0x48, 0x28, 0x18, 0x78, 0xE0, 
  0x20, 0x20, 0x20, 0xE0, 0x40, 0xA0, 0xE0, 0x80, 0x40, 0xC0, 0x60, 0xA0, 
  0xE0, 0x80, 0xC0, 0xA0, 0xA0, 0xC0, 0x60, 0x80, 0x80, 0x60, 0x20, 0x60, 
  0xA0, 0xA0, 0x60, 0x60, 0xA0, 0xC0, 0x60, 0x20, 0x40, 0xE0, 0x40, 0x40, 
  0x60, 0xA0, 0xE0, 0x20, 0x40, 0x80, 0xC0, 0xA0, 0xA0, 0xA0, 0x80, 0x00, 
  0x80, 0x80, 0x80, 0x20, 0x00, 0x20, 0x20, 0xA0, 0x40, 0x80, 0xA0, 0xC0, 
  0xC0, 0xA0, 0xC0, 0x40, 0x40, 0x40, 0xE0, 0x50, 0xA8, 0xA8, 0xA8, 0xC0, 
  0xA0, 0xA0, 0xA0, 0x40, 0xA0, 0xA0, 0x40, 0xC0, 0xA0, 0xA0, 0xC0, 0x80, 
  0x60, 0xA0, 0xA0, 0x60, 0x20, 0x60, 0x80, 0x80, 0x80, 0x60, 0xC0, 0x60, 
  0xC0, 0x40, 0xE0, 0x40, 0x40, 0x60, 0xA0, 0xA0, 0xA0, 0x60, 0xA0, 0xA0, 
  0xE0, 0x40, 0xA8, 0xA8, 0xF8, 0xA8, 0x90, 0x60, 0x60, 0x90, 0xA0, 0xA0, 
  0x60, 0x20, 0xC0, 0xE0, 0x60, 0xC0, 0xE0, 0x20, 0x20, 0xF8, 0x70, 0x20, 
  0x20, 0x10, 0xF8, 0x10, 0x20, 0x20, 0x70, 0xF8, 0x20, 0x20, 0x60, 0xC0 
};

const GFXglyph CyberDisplayFontGlyphs[] PROGMEM = {
  {     0,   8,   1,   2,    0,   -5 }   // ' '
 ,{     1,   8,   5,   2,    0,   -5 }   // '!'
 ,{     6,   8,   2,   4,    0,   -5 }   // '"'
 ,{     8,   8,   5,   4,    0,   -5 }   // '#'
 ,{    13,   8,   5,   4,    0,   -5 }   // '$'
 ,{    18,   8,   5,   4,    0,   -5 }   // '%'
 ,{    23,   8,   5,   4,    0,   -5 }   // '&'
 ,{    28,   8,   2,   2,    0,   -5 }   // '''
 ,{    30,   8,   5,   3,    0,   -5 }   // '('
 ,{    35,   8,   5,   3,    0,   -5 }   // ')'
 ,{    40,   8,   3,   4,    0,   -5 }   // '*'
 ,{    43,   8,   3,   4,    0,   -4 }   // '+'
 ,{    46,   8,   2,   3,    0,   -2 }   // ','
 ,{    48,   8,   1,   4,    0,   -3 }   // '-'
 ,{    49,   8,   1,   2,    0,   -1 }   // '.'
 ,{    50,   8,   5,   5,    0,   -5 }   // '/'
 ,{    55,   8,   5,   4,    0,   -5 }   // '0'
 ,{    60,   8,   5,   2,    0,   -5 }   // '1'
 ,{    65,   8,   5,   4,    0,   -5 }   // '2'
 ,{    70,   8,   5,   4,    0,   -5 }   // '3'
 ,{    75,   8,   5,   4,    0,   -5 }   // '4'
 ,{    80,   8,   5,   4,    0,   -5 }   // '5'
 ,{    85,   8,   5,   4,    0,   -5 }   // '6'
 ,{    90,   8,   5,   4,    0,   -5 }   // '7'
 ,{    95,   8,   5,   4,    0,   -5 }   // '8'
 ,{   100,   8,   5,   4,    0,   -5 }   // '9'
 ,{   105,   8,   3,   2,    0,   -4 }   // ':'
 ,{   108,   8,   4,   3,    0,   -4 }   // ';'
 ,{   112,   8,   5,   5,    0,   -5 }   // '<'
 ,{   117,   8,   3,   4,    0,   -4 }   // '='
 ,{   120,   8,   5,   5,    0,   -5 }   // '>'
 ,{   125,   8,   5,   4,    1,   -5 }   // '?'
 ,{   130,   8,   5,   4,    0,   -5 }   // '@'
 ,{   135,   8,   5,   4,    0,   -5 }   // 'A'
 ,{   140,   8,   5,   4,    0,   -5 }   // 'B'
 ,{   145,   8,   5,   4,    0,   -5 }   // 'C'
 ,{   150,   8,   5,   4,    0,   -5 }   // 'D'
 ,{   155,   8,   5,   4,    0,   -5 }   // 'E'
 ,{   160,   8,   5,   4,    0,   -5 }   // 'F'
 ,{   165,   8,   5,   4,    0,   -5 }   // 'G'
 ,{   170,   8,   5,   4,    0,   -5 }   // 'H'
 ,{   175,   8,   5,   4,    0,   -5 }   // 'I'
 ,{   180,   8,   5,   4,    0,   -5 }   // 'J'
 ,{   185,   8,   5,   4,    0,   -5 }   // 'K'
 ,{   190,   8,   5,   4,    0,   -5 }   // 'L'
 ,{   195,   8,   5,   4,    0,   -5 }   // 'M'
 ,{   200,   8,   5,   4,    0,   -5 }   // 'N'
 ,{   205,   8,   5,   4,    0,   -5 }   // 'O'
 ,{   210,   8,   5,   4,    0,   -5 }   // 'P'
 ,{   215,   8,   5,   4,    0,   -5 }   // 'Q'
 ,{   220,   8,   5,   4,    0,   -5 }   // 'R'
 ,{   225,   8,   5,   4,    0,   -5 }   // 'S'
 ,{   230,   8,   5,   4,    0,   -5 }   // 'T'
 ,{   235,   8,   5,   4,    0,   -5 }   // 'U'
 ,{   240,   8,   5,   4,    0,   -5 }   // 'V'
 ,{   245,   8,   5,   4,    0,   -5 }   // 'W'
 ,{   250,   8,   5,   4,    0,   -5 }   // 'X'
 ,{   255,   8,   5,   4,    0,   -5 }   // 'Y'
 ,{   260,   8,   5,   4,    0,   -5 }   // 'Z'
 ,{   265,   8,   5,   4,    0,   -5 }   // '['
 ,{   270,   8,   5,   5,    0,   -5 }   // '\'
 ,{   275,   8,   5,   4,    0,   -5 }   // ']'
 ,{   280,   8,   2,   4,    0,   -5 }   // '^'
 ,{   282,   8,   1,   4,    0,   -1 }   // '_'
 ,{   283,   8,   2,   3,    0,   -5 }   // '`'
 ,{   285,   8,   4,   4,    0,   -4 }   // 'a'
 ,{   289,   8,   5,   4,    0,   -5 }   // 'b'
 ,{   294,   8,   4,   4,    0,   -4 }   // 'c'
 ,{   298,   8,   5,   4,    0,   -5 }   // 'd'
 ,{   303,   8,   4,   4,    0,   -4 }   // 'e'
 ,{   307,   8,   5,   4,    0,   -5 }   // 'f'
 ,{   312,   8,   5,   4,    0,   -4 }   // 'g'
 ,{   317,   8,   5,   4,    0,   -5 }   // 'h'
 ,{   322,   8,   5,   2,    0,   -5 }   // 'i'
 ,{   327,   8,   6,   4,    0,   -5 }   // 'j'
 ,{   333,   8,   5,   4,    0,   -5 }   // 'k'
 ,{   338,   8,   5,   4,    0,   -5 }   // 'l'
 ,{   343,   8,   4,   5,    0,   -4 }   // 'm'
 ,{   347,   8,   4,   4,    0,   -4 }   // 'n'
 ,{   351,   8,   4,   4,    0,   -4 }   // 'o'
 ,{   355,   8,   5,   4,    0,   -4 }   // 'p'
 ,{   360,   8,   5,   4,    0,   -4 }   // 'q'
 ,{   365,   8,   4,   4,    0,   -4 }   // 'r'
 ,{   369,   8,   4,   4,    0,   -4 }   // 's'
 ,{   373,   8,   5,   4,    0,   -5 }   // 't'
 ,{   378,   8,   4,   4,    0,   -4 }   // 'u'
 ,{   382,   8,   4,   4,    0,   -4 }   // 'v'
 ,{   386,   8,   4,   5,    0,   -4 }   // 'w'
 ,{   390,   8,   4,   4,    0,   -4 }   // 'x'
 ,{   394,   8,   5,   4,    0,   -4 }   // 'y'
 ,{   399,   8,   4,   4,    0,   -4 }   // 'z'
 ,{   403,   8,   5,   5,    0,   -5 }   // '{'
 ,{   408,   8,   5,   5,    0,   -5 }   // '|'
 ,{   413,   8,   5,   5,    0,   -5 }   // '}'
 ,{   418,   8,   2,   4,    0,   -5 }   // '~'
};

const GFXfont CyberDisplayFont PROGMEM = {(uint8_t *)CyberDisplayFontBitmaps,      
                                  (GFXglyph *)CyberDisplayFontGlyphs, 0x20, 0x7e,       6};
