#include<nds.h>
#include "nsmb.h"

extern "C" {
	void nds_printf(u16 something[2], u16* screenPtr, const char* str, ...);
}

#define WHITE 0xD000
#define GREEN 0xE000
#define RED 0xF000

u8* ptr = (u8*)0x02000000;

int count = 0;
int pos = 4;

void debugScreenRamViewer()
{
	u16** topScreenPtr = (u16**) 0x020859EC;

	u16 something[2];
	something[0] = GREEN;
	something[1] = GREEN;

	int x=1;
	int y=1;
	myScanKeys();
	int keys = myKeysHeld();
	int keysDw = myKeysDown();
	
	u8* newptr = ptr;
	if(keysDw & KEY_UP) newptr+=1<<(pos*4);
	if(keysDw & KEY_DOWN) newptr-=1<<(pos*4);
	if(keysDw & KEY_LEFT) pos++;
	if(keysDw & KEY_RIGHT) pos--;
	if(pos > 7) pos = 7;
	if(pos < 0) pos = 0;
	
	nds_printf(something, *topScreenPtr + 33, "%08x - RAM VIEWER", ptr);
	nds_printf(something, *topScreenPtr + 65+7-pos, "^");
	
/*	if(ptr == newptr && !first)
		return;
*/
	ptr = newptr;	

	for(int i = 0; i < 16*20; i++)
	{
		if(something[0] == GREEN)
			something[0] = something[1] = WHITE;
		else
			something[0] = something[1] = GREEN;
			
		nds_printf(something, *topScreenPtr + i*2+4*32, "%02x", *newptr++);
	}
}
