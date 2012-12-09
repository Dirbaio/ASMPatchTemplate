#include<nds.h>

//This runs right at the start of the game.
void hook_0200089c()
{
	//The value at 0x023FFC20 tells the game what to boot.
	//The reason for this is that the rom reboots itself when entering/exiting minigames.
	
	//0x000000: Nintendo logo and main menu
	//0x000100: Main menu
	//0x010101: Minigames
	//0x020100: Main menu, Minigames selected. Like when returning from minigames.
	
	(*(vu32*)0x023FFC20) = 0x100;
}

