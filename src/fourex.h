/*
FourEx - FourEx is a 4X Strategy Game Using a Simple 2D implementation
Copyright (C) 2011  Jason Ramsey <jramsey@openkettle.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#include "include.h"


class fourEx
{
private:
    bool quit;
    bool menu;
    bool pause;
    bool ingame;

    CL_DisplayWindow window;
    CL_GraphicContext gc;
    CL_InputDevice keyboard;
public:


    void run();

    void clearscreen(CL_GraphicContext &gc);

    void openingscreen(CL_GraphicContext &gc);

    void drawtext(CL_GraphicContext &gc,std::string text,
                  int posx=0,
                  int posy=0,
                  int fontheight=40,
                  std::string fontname="tahoma"
                 );

    void drawmenu(CL_GraphicContext &gc);

    bool areyousure(CL_GraphicContext &gc,std::string message="Are you Sure? Y/N");

    void updateFrames(CL_GraphicContext &gc);

    void on_window_close();
public:
    int windowsize[2];
};
