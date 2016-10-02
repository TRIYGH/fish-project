//T. Robert Ward
//June 17, 2013

// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

//constants for the screen resolution
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int BACKGROUND_INDEX = 1;
const int FISH_INDEX[3] = {2, 3, 4};
const int XFISH_POS_MAX = 540;
const int YFISH_POS_MAX = 443;
float gx[3] = {1, 100, 300};
float gy[3] = {50, 200, 400};
int angle = 1;
int fishDirection[3] = {2, -4, 3};
int LorR = 0;

// Begin app, called once at the start
void app::Begin( void )
{

		//set the virtual resolution
	agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

	agk::CreateSprite(BACKGROUND_INDEX,"undersea.png");
	agk::CreateSprite(FISH_INDEX[0],"fish.png");

	agk::SetSpriteDepth(FISH_INDEX[0],1);
	agk::SetSpriteDepth(BACKGROUND_INDEX,500);

	agk::SetSpritePosition(FISH_INDEX[0],gx[0],gy[0]);

	agk::SetSpriteScale(FISH_INDEX[0],.333,.333);

	agk::SetSpriteAngle(FISH_INDEX[0],0);

	agk::SetSpriteFlip(FISH_INDEX[0],0,0);

	agk::CloneSprite(FISH_INDEX[1],FISH_INDEX[0]);
	agk::CloneSprite(FISH_INDEX[2],FISH_INDEX[0]);
	
	agk::SetSpriteDepth(FISH_INDEX[1],2);
	agk::SetSpriteDepth(FISH_INDEX[2],3);
	
	//agk::SetSpritePosition(3,20,20);
	
	//agk::SetSpritePosition(FISH1_INDEX, 200, 200);

	//agk::SetSyncRate(2,1);

	LorR = 1;

}

// Main loop, called every frame
void app::Loop ( void )
{
		agk::Sync();

		for(int fishnum = 0; fishnum < 3; fishnum++)
		{
			gx[fishnum] = gx[fishnum] + fishDirection[fishnum];

			if(gx[fishnum] >= XFISH_POS_MAX)
			{	
				fishDirection[fishnum] = -fishDirection[fishnum];
				agk::SetSpriteFlip(FISH_INDEX[fishnum],1,0);
			}
			if(gx[fishnum] < 0)
			{
				fishDirection[fishnum] = -fishDirection[fishnum];
				agk::SetSpriteFlip(FISH_INDEX[fishnum],0,0);
			}
			
			agk::SetSpritePosition(FISH_INDEX[fishnum],gx[fishnum],gy[fishnum]);
		}
		

		
}

// Called when the app ends
void app::End ( void )
{
}