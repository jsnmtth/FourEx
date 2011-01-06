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
#include "include.h"
#include "fourex.h"
#include "gamemenu.h"



    void fourEx::run()
    {
        windowsize[0]=1024;
        windowsize[1]=680;
        quit = false;
        ingame=false;

        CL_DisplayWindow window("Sunset", windowsize[0], windowsize[1]);
        CL_Slot slot_quit = window.sig_window_close().connect(this, &fourEx::on_window_close);
        CL_GraphicContext gc = window.get_gc();
        CL_InputDevice keyboard = window.get_ic().get_keyboard();
        gamemenu gameMenu();

        while (!quit)
        {

            CL_InputEvent inputevent;


            if (keyboard.get_keycode(CL_KEY_ESCAPE) == true)
            {
                if (menu==true)
                {
                    menu=false;
                    pause=true;
                }
                else
                {
                    menu=true;
                    pause=false;
                }
                CL_System::pause(100);

            }

            if(keyboard.get_keycode(CL_KEY_CONTROL) && keyboard.get_keycode(CL_KEY_N)) {
             ingame=true;
            }

            if(keyboard.get_keycode(CL_KEY_Q)) {
             if(ingame==true) {
                 ingame=areyousure(gc,"You Want to Quit?");
                 }
             else quit=true;
            }


            if (menu==true) {

                updateFrames(gc);
                drawmenu(gc);
            } else {
                updateFrames(gc);
            }

            window.flip();
            CL_KeepAlive::process();

            CL_System::sleep(10);
        }
    }

    void fourEx::clearscreen(CL_GraphicContext &gc)
    {
        CL_Draw::fill(gc, 0,0,windowsize[0],windowsize[1],CL_Colorf("black"));

    }
    bool fourEx::areyousure(CL_GraphicContext &gc,std::string message)
    {
        bool answer=false;
        bool yesorno=false;
        CL_Draw::fill(gc, .33*windowsize[0],.40*windowsize[1],1-.33*windowsize[0],1-.40*windowsize[1],CL_Colorf("red"));
        drawtext(gc,message,.43*windowsize[0],.50*windowsize[2]);
        //window.flip();

        while(!answer) {
          if (keyboard.get_keycode(CL_KEY_Y) == true){
                answer=true;
                yesorno=true;
            } else if (keyboard.get_keycode(CL_KEY_N)==true) {
                answer=true;
            }

        }
        return yesorno;

    }

    void fourEx::openingscreen(CL_GraphicContext &gc)
    {

        CL_Draw::fill(gc, 0,0,windowsize[0],windowsize[1],CL_Colorf("black"));
        std::string filename="assets/openingscreen.png";
        //std::string currentpath=directory.getpath();

        CL_Texture introscreen(gc, filename);
        if (introscreen.is_null())
        {
            drawtext(gc,"Image is Null!",100,100);
        }
        else
        {
            gc.set_texture(0, introscreen);
            CL_Draw::texture(gc, CL_Rectf(0,0,windowsize[0],windowsize[1]), CL_Colorf(0.5f, 0.5f, 0.5f, 1.0f));
        }



    }

    void fourEx::drawtext(CL_GraphicContext &gc,std::string text,int posx, int posy,int fontheight,std::string fontname)
    {
        CL_FontDescription system_font_desc;
        system_font_desc.set_typeface_name(fontname);
        system_font_desc.set_height(fontheight);
        CL_Font_System system_font(gc, system_font_desc);

        system_font.draw_text(gc, posx, posy, text);
    }
    void fourEx::drawmenu(CL_GraphicContext &gc)
    {
        CL_Draw::fill(gc,CL_Rectf(.25*windowsize[0],.05*windowsize[1],.75*windowsize[0],.95*windowsize[1]),CL_Colorf(0.1f,0.1f,1.0f,1.0f));
        drawtext(gc,"Menu", .35*windowsize[0],.35*windowsize[1]);
    }

    void fourEx::updateFrames(CL_GraphicContext &gc)
    {
        if (ingame==true) {
            clearscreen(gc);
            std::string screentitle = "Screen Resolution: ";
            screentitle+= CL_StringHelp::int_to_text(windowsize[0]);
            screentitle+= " x ";
            screentitle+= CL_StringHelp::int_to_text(windowsize[1]);
            drawtext(gc,screentitle, 30, 100);
            //Draw Some Fonts
        } else {
            openingscreen(gc);
        }






        // Draw some text using the fonts
        //*/
    }

    void fourEx::on_window_close()
    {
        quit = true;
    }
