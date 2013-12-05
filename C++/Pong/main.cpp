#include <SDL/SDL.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cmath>
using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int  SCREEN_BPP = 32;
const int PADDLE_HEIGHT = 60;
const int PADDLE_WIDTH = 15;
const int BALL_DIAMETER = 18;

//SDL Surfaces for the background and screen.
SDL_Surface *screen = NULL;
SDL_Surface *background = NULL;
SDL_Event keyPress;

//The following function loads the image into a surface.
//This function is used for all image loading.
SDL_Surface *loadImage(string filename)
{
    SDL_Surface *loadedImage = NULL;
    SDL_Surface *optimizedImage = NULL;

    loadedImage = SDL_LoadBMP(filename.c_str());
    if (loadedImage != NULL)
    {
        optimizedImage = SDL_DisplayFormat(loadedImage); //Optimizing the image.
        SDL_FreeSurface(loadedImage);
    }
    if (optimizedImage != NULL)
    {
        //This section sets any white portions of an image to invisible.
        Uint32 colorkey = (SDL_MapRGB(optimizedImage->format, 0xFF, 0xFF, 0xFF));
        SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey);
    }
    return optimizedImage;
}

//This function applies the surface to the screen.
void applySurface(int x, int y, SDL_Surface *source, SDL_Surface *destination)
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    SDL_BlitSurface (source, NULL, destination, &offset);
}

//Paddle struct - contains methods for paddle movement and score adjusting.
//A better struct name would have been player.
struct paddle
{
    SDL_Surface *paddleImage;
    SDL_Surface *score;
    int intScore;
    SDL_Rect box;
    SDL_Rect scoreBox;

    void paddleUp ()
    {
        box.y -= 2;
        if (box.y < 0)
        {
            box.y = 0;
        }
    }

    void paddleDown()
    {
        box.y += 2;
        if ((box.y + box.h) > SCREEN_HEIGHT)
        {
            box.y = SCREEN_HEIGHT - box.h;
        }
    }

    void scoreAdjust()
    {
        switch (intScore)
        {
        case 1:
            score = loadImage("one.bmp");
            break;
        case 2:
            score = loadImage("two.bmp");
            break;
        }
    }

    paddle (int padY, int padX, int scoreX, int scoreY)
    {
        box.y = padY;
        box.x = padX;
        box.h = PADDLE_HEIGHT;
        box.w = PADDLE_WIDTH;
        scoreBox.x = scoreX;
        scoreBox.y = scoreY;
        intScore = 0;
        paddleImage = loadImage("paddle.bmp");
        score =  loadImage("black.bmp");
    }
};

//Ball struct - contains methods for ball movement.
//While playtesting the game I decided that the ball
//moving at a constant speed was boring - so now its random.
struct ball
{
    SDL_Rect box;
    //These booleans are used to find out what direction the ball is moving.
    //up and left are both true, down and right are both false.
    //upDown == true and leftRight == false would be up to the right.
    bool upDown, leftRight;
    bool start = true;
    SDL_Surface *image;
    int vertSpeed, horzSpeed;

    //The down and up functions both contain checks for collision with the
    //ceiling and the floor. My first optimization would be to move all of
    //that code to the collision function, or do away with the collision function
    //and move that code to these methods.
    void bUp ()
    {
        box.y -= vertSpeed;
        if (box.y < 10) //Checks for collision with ceiling.
        {
            bDown();
            upDown = false; //Sets direction of movement to down.
            vertSpeed = round(rand() % 2 + 1); //Sets new speed.
        }
    }

    void bDown ()
    {
        box.y += vertSpeed;
        if(box.y > SCREEN_HEIGHT - 12) //Checks for collision with floor.
        {
            bUp();
            upDown = true; //Sets direction of movement to up.
            vertSpeed = round(rand() % 2 + 1);
        }
    }

    void bLeft ()
    {
        box.x -= horzSpeed;
    }

    void bRight()
    {
        box.x += horzSpeed;
    }

    void moveBall()
    {
        if (start)
        {
            srand(time(NULL));
            upDown = floor(rand() % 2);
            leftRight = floor(rand() % 2);
            start = false;
        }
        if (upDown)
        {
            bUp();
        }
        else
        {
            bDown();
        }
        if (leftRight)
        {
            bLeft();
        }
        else
        {
            bRight();
        }
    }
    ball (int x, int y)
    {
        box.x = x;
        box.y= y;
        box.h = BALL_DIAMETER;
        box.w = BALL_DIAMETER;
        vertSpeed = 1;
        horzSpeed = 1;
        image = loadImage("Ball.bmp");
    }
};

//This function handles all of the input.
//If either of the
bool eventPoll(SDL_Event &kp, paddle &leftPad, paddle &rightPad)
{
    Uint8 *keystates = SDL_GetKeyState(NULL);
    if (SDL_PollEvent(&kp))
    {
        if (kp.type == SDL_QUIT)
        {
            return true;
        }
    }

    if (keystates[SDLK_w])
    {
        leftPad.paddleUp();
    }
    else if (keystates[SDLK_s])
    {
        leftPad.paddleDown();
    }

    if (keystates[SDLK_UP])
    {
        rightPad.paddleUp();
    }
    else if (keystates[SDLK_DOWN])
    {
        rightPad.paddleDown();
    }

    if (keystates[SDLK_ESCAPE])
    {
        return true;
    }
    return false;
}

void collision(paddle &left, paddle &right, ball &dot)
{
    int leftTop, leftBot, leftLeft, leftRight;
    int ballTop, ballBot, ballLeft, ballRight;
    int rightTop, rightBot, rightLeft, rightRight;

    leftTop = left.box.y;
    leftBot = left.box.y + left.box.h;
    leftLeft = left.box.x;
    leftRight = left.box.x + left.box.w;

    ballTop = dot.box.y;
    ballBot = dot.box.y + dot.box.h;
    ballLeft = dot.box.x;
    ballRight = dot.box.x + dot.box.w;

    rightTop = right.box.y;
    rightBot = right.box.y + right.box.h;
    rightLeft = right.box.x;
    rightRight = right.box.x + right.box.w;

    if (ballLeft < leftRight && ballLeft > leftLeft && ballTop < leftBot && ballBot > leftTop)
    {
        dot.leftRight = false;
        dot.horzSpeed = round(rand() % 2 + 1);
    }
    else if (ballRight > rightLeft && ballRight < rightRight && ballTop < rightBot && ballBot > rightTop)
    {
        dot.leftRight = true;
        dot.horzSpeed = round(rand() % 2 + 1);
    }
    if (ballLeft > 640)
    {
        left.intScore++;
        left.scoreAdjust();
    }
    if (ballLeft < 0)
    {
        right.intScore++;
        right.scoreAdjust();
    }
    if (ballLeft > 640 || ballLeft < 0)
    {
        dot.box.x = SCREEN_WIDTH / 2 - 6;
        dot.box.y = SCREEN_HEIGHT / 2 + 6;
        dot.start = true;
    }
}

int main (int argc, char* args[])
{
    if ( SDL_Init(SDL_INIT_EVERYTHING) == -1  )
        {
            return -1;
        }

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    if (screen==NULL)
    {
        return -2;
    }

    SDL_WM_SetCaption("Pong The Ultimate Game", NULL);
    background = loadImage("background.bmp");

    paddle leftPad (SCREEN_HEIGHT/2, 10, 20, 20);
    paddle rightPad(SCREEN_HEIGHT/2, SCREEN_WIDTH-30, 640-20-20, 30);
    ball bball(SCREEN_WIDTH/2 - 6, SCREEN_HEIGHT/2);

    while (true)
    {
        if (eventPoll(keyPress, leftPad, rightPad))
        {
            break;
        }
        bball.moveBall();
        collision(leftPad, rightPad, bball);
        applySurface(0, 0, background, screen);
        applySurface(leftPad.box.x, leftPad.box.y, leftPad.paddleImage, screen);
        applySurface(rightPad.box.x, rightPad.box.y, rightPad.paddleImage, screen);
        applySurface(leftPad.scoreBox.x, leftPad.scoreBox.y, leftPad.score, screen);
        applySurface(rightPad.scoreBox.x, rightPad.scoreBox.y, rightPad.score, screen);
        applySurface(bball.box.x, bball.box.y, bball.image, screen);

        SDL_Flip(screen);
        SDL_Delay(5);
    }

    SDL_FreeSurface(background);
    SDL_FreeSurface(rightPad.paddleImage);
    SDL_FreeSurface(leftPad.paddleImage);
    SDL_Quit();

    return 0;
}
