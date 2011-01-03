#include <ClanLib/core.h>
#include <ClanLib/display.h>
#include <ClanLib/gl.h>
#include <ClanLib/application.h>



int windowsize[2] = {1024,768};

class fourEx
{
private:
    bool quit;
    bool menu;
    bool pause;
    bool ingame;
public:
    void run()
    {
        quit = false;
        ingame=false;
        CL_DisplayWindow window("Sunset", windowsize[0], windowsize[1]);

        CL_Slot slot_quit = window.sig_window_close().connect(this, &fourEx::on_window_close);

        CL_GraphicContext gc = window.get_gc();
        CL_InputDevice keyboard = window.get_ic().get_keyboard();

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
            }
            if(keyboard.get_keycode(CL_KEY_CONTROL) && keyboard.get_keycode(CL_KEY_N)) {
             ingame=true;
            }
            if(keyboard.get_keycode(CL_KEY_Q)) {
             if(ingame==true)ingame=false;
             else quit=true;
            }


            if (menu==true) {

                updateFrames(gc);
                drawmenu(gc);
            } else {
                updateFrames(gc);
            }
            drawtext(gc,CL_StringHelp::int_to_text(inputevent.type),60,30);
            drawtext(gc,"test",60,20);
            window.flip();
            CL_KeepAlive::process();

            CL_System::sleep(10);
        }
    }

    void clearscreen(CL_GraphicContext &gc)
    {
        CL_Draw::fill(gc, 0,0,windowsize[0],windowsize[1],CL_Colorf("black"));

    }

    void openingscreen(CL_GraphicContext &gc)
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

    void drawtext(CL_GraphicContext &gc, std::string text,int posx=0, int posy=0,int fontheight=40,std::string fontname="tahoma")
    {
        CL_FontDescription system_font_desc;
        system_font_desc.set_typeface_name(fontname);
        system_font_desc.set_height(fontheight);
        CL_Font_System system_font(gc, system_font_desc);

        system_font.draw_text(gc, posx, posy, text);
    }
    void drawmenu(CL_GraphicContext &gc)
    {

        drawtext(gc, "Menu", 30, 100);
    }

    void updateFrames(CL_GraphicContext &gc)
    {
        if (ingame==true) {
            clearscreen(gc);
            std::string screentitle = "Screen Resolution: ";
            screentitle+= CL_StringHelp::int_to_text(windowsize[0]);
            screentitle+= " x ";
            screentitle+= CL_StringHelp::int_to_text(windowsize[1]);
            drawtext(gc, screentitle, 30, 100);
            //Draw Some Fonts
        } else {
            openingscreen(gc);
        }






        // Draw some text using the fonts
        //*/
    }

    void on_window_close()
    {
        quit = true;
    }
};

class Program
{
public:
    static int main(const std::vector<CL_String> &args)
    {
        CL_SetupCore setup_core;
        CL_SetupDisplay setup_display;
        CL_SetupGL setup_gl;

        try
        {
            fourEx game;
            game.run();
        }
        catch (CL_Exception &exception)
        {
            // Create a console window for text-output if not available
            CL_ConsoleWindow console("Console", 80, 160);
            CL_Console::write_line("Error: " + exception.get_message_and_stack_trace());

            console.display_close_message();

            return -1;
        }
        return 0;
    }

};
CL_ClanApplication app(&Program::main);
