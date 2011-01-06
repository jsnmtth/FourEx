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
#include "fourex.hpp"
#include "include.hpp"
#include "main.hpp"



    int Program::main(const std::vector<CL_String> &args)
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
CL_ClanApplication app(&Program::main);
