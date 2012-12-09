ASM Patch project template
==========================

By Dirbaio
http://nsmbhd.net/

===========================

See for more details:
http://nsmbhd.net/thread/1025-asm-hacking-project-template/
http://nsmbhd.net/thread/1281-how-asm-hacks-are-setup/

===========================

Stuff works similar to NDS homebrew projects.
Code goes in source/
Data goes in data/

Place a NSMB USA ROM in this folder (Other regions will NOT work)
Use a recent version of NSMB Editor to compile and insert the code into the ROM.

Included features:

nonintendo.cpp - Makes the game skip the Nintendo boot screen (for faster testing!)
debugscreen.s - Makes the debug screen show without entering the key combination
ramviewer.cpp - Adds a RAM viewer function to the debug screen!
keys.cpp - Adds functions for reading keys. (The ones from libnds DO NOT work)
print.s - Stuff for printing to no$gba debugger / desmume console.
nsmb.h - Defines several useful functions from the game. Not complete at all, I've just added stuff as I needed it.

Enjoy!
