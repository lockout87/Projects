#include <SDL/SDL.h>
#include <cmath>
#include <ctime>
#include <string>
#include <cassert>
#define NDEBUG
using namespace std;

const int SCREEN_WIDTH = 680;
const int SCREEN_HEIGHT = 440;
const int SCREEN_BPP = 32;
const string BACKGROUND_IMAGE = "background.bmp";
const int WORM_BLOCK = 8;
const string WORM_IMAGE = "worm.bmp";

SDL_Surface *screen = NULL;
SDL_Surface *background = NULL;

SDL_Event *keypress;

SDL_Surface *loadImage(string fileName)
{
    SDL_Surface *loadedImage = NULL;
    SDL_Surface *optimizedImage = NULL;


    loadedImage = SDL_LoadBMP(fileName.c_str());
    if (loadedImage != NULL)
    {
        optimizedImage = SDL_DisplayFormat(loadedImage);
        if (optimizedImage != NULL)
        {
            Uint32 colorKey = SDL_MapRGB(optimizedImage->format, 0xFF, 0xFF, 0xFF);
            SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorKey);
            SDL_FreeSurface(loadedImage);
        }
    }
    return optimizedImage;
}

void applySurface(int x, int y, SDL_Surface *source, SDL_Surface *destination)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;

    SDL_BlitSurface(source, NULL, destination, &offset);
}

struct worm
{
    SDL_Rect box;
    SDL_Surface *wIMG;
    bool leftRight, upDown;
    int lastMove;

    void wormMover()
    {
        Uint8 *keystate = SDL_GetKeyState(NULL);
        if (keystate[ SDLK_w])
        {
            box.y -= 4;
            lastMove = 1;
            upDown = true;
            leftRight = false;
        }
        if (keystate[ SDLK_s])
        {
            box.y += 4;
            lastMove = 2;
            upDown = true;
            leftRight = false;
        }
        if (keystate[ SDLK_a])
        {
            box.x -= 1;
            lastMove = 3;
            upDown = false;
            leftRight = true;
        }
        if (keystate [SDLK_d])
        {
            box.x +=4;
            lastMove = 4;
            upDown = false;
            leftRight = true;
        }
/*        else
        {
            switch (lastMove)
            {
            case 1:
                {
                    box.y -= 1;
                    break;
                }
            case 2:
                {
                    box.y += 1;
                    break;
                }
            case 3:
                {
                    box.x -= 1;
                    break;
                }
            case 4:
                {
                    box.x += 1;
                    break;
                }
            default: ;
            }
        }*/

    }

    worm(int x, int y)
    {
        box.x = x;
        box.y = y;
        box.h = x + WORM_BLOCK;
        box.w = y + WORM_BLOCK;
        leftRight = false;
        upDown = true;
        lastMove = 1;

        wIMG = loadImage(WORM_IMAGE);
    }

};

int main ( int argc, char** argv )
{
    if (SDL_Init(SDL_INIT_EVERYTHING))
    {
        return -1;
    }

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    if (screen == NULL)
    {
        return -1;
    }

    SDL_WM_SetCaption("Worms, Supa Coo' Game", NULL);

    background = loadImage(BACKGROUND_IMAGE);
    worm head(50, 50);
    while (true)
    {
        head.wormMover();
        applySurface(0, 0, background, screen);
        applySurface(head.box.x, head.box.y, head.wIMG, screen);
         if (SDL_Flip(screen) == -1)
        {
            return -1;
        }
        SDL_Delay(20);
    }





    return 0;
}
