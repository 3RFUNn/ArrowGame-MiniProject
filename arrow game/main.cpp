#include "SBDL.h"
#include <time.h>
#include <cstdlib>
#include <iostream>
using namespace SBDL;
using namespace std;
bool hasIntersectionRotated(SDL_Rect ,SDL_Rect ,bool ,double );
int angle = 45;
int wallwidth;
int wallY;
int emtiaz=0;
int sorat=2;
int x=0;
int time_bazi=0;
bool akse_seda=true;
bool akse_bi_seda=false;
bool gemBarkhord= false;
Music* queen;
Sound* Gem;
Sound* SpecialGem;
Texture settings;
Texture gem;
char state='m';
Texture scoreText;
Texture joone_ezafi;
Font* font;
bool gemintersection = false;
bool Arrow=false;
bool seda=true;
Texture seda_on;
Texture seda_off;
Texture arrow;
Texture arrow2;
Texture dot;
Texture background;
Texture walls;
Texture gem_addi;
Texture startText;
Texture exitText;
Texture  menutext;
Texture restart;
Texture Continue;
Texture YES;
Texture NO;
Texture Pause;
SDL_Rect leftwall[100];
SDL_Rect rightwall[100];
SDL_Rect arrowrect={220,450,25,25};
SDL_Rect backgroundrect={0,0,500,500};
SDL_Rect gemrect={245,-30,25,25};
SDL_Rect boxscore={0,50,500,50};
SDL_Rect gemkhafan={245,-1060,25,25};
SDL_Rect pauserect={460,0,40,40};
SDL_Rect menu_rect={200,0,100,100};
SDL_Rect start_rect = {100,200 ,100 ,100 };
SDL_Rect exit_rect = {200,390,100,100};
SDL_Rect restart_rect = {200,200,90,100};
SDL_Rect mainMenu_rect = {200,400,100,100};
SDL_Rect continue_rect = {200,50,100,100};
SDL_Rect restart2_rect = {200,220,90,100};
SDL_Rect dot1 = {125,300 ,50 ,50 };
SDL_Rect no1={150,150,100,100};
SDL_Rect yes1={300,150,100,100};
SDL_Rect settingsrect={300,200,100,100};
SDL_Rect dot2={325,300,50,50};
SDL_Rect Seda={25,25,50,50};
void loadkolli(){
    Pause=loadTexture("D:/assets/pause.png");
   arrow= SBDL::loadTexture("D:/assets/arrow.png");
   background=SBDL:: loadTexture("D:/assets/img/ground_1.png");
   walls=loadTexture("D:/assets/img/wall_1.png");
   gem_addi=loadTexture("D:/assets/gem.png");
   queen=loadMusic("D:/assets/sounds/chilled_v1.mp3");
   font =loadFont("D:/assets/GoboldThinLight.otf",30);
   gem=loadTexture("D:/assets/img/gem.png");
   Gem=loadSound("D:/assets/sounds/click.wav");
   SpecialGem=loadSound("D:/assets/sounds/gem.mp3");
   settings=loadTexture("D:/assets/settings.png");
   arrow2=loadTexture("D:/assets/img/dragon.png");
   startText = loadTexture("D:/assets/play.png");
    exitText = loadTexture("D:/assets/exit.png");
    menutext=loadTexture("D:/assets/menu.png");
    restart=loadTexture("D:/assets/restart.png");
    Continue=loadTexture("D:/assets/continue.png");
    YES=loadTexture("D:/assets/yes.png");
    NO=loadTexture("D:/assets/no.png");
    dot=loadTexture("D:/assets/dot.png");
    seda_on=loadTexture("D:/assets/sound-on.png");
    seda_off=loadTexture("D:/assets/sound-off.png");


}
void fontnevis(){
    drawRectangle(boxscore,230,230,250,200);
    scoreText=createFontTexture(font,to_string(emtiaz),0,0,0);
    showTexture(scoreText,230,55);

}
void buildwalls(){
    srand(time(NULL));
    wallY=-5000;
    for (auto & i : rightwall) {
        wallwidth=rand()%220;
        i={-200,wallY,wallwidth,500};
        wallY+=60;
    }
    wallY=-5000;
    for (auto & j : leftwall) {
        wallwidth=rand()%220;
        j={690-wallwidth,wallY,wallwidth,550};
        wallY+=60;
    }
}
void showwall(){
    for (auto & i : rightwall) {
        showTexture(walls,-45,i);
        i.y+=sorat;
     if(i.y==500){
         i.y=-500;
     }
}
    for (auto & j : leftwall) {
        showTexture(walls,45,j);
        j.y+=sorat;
        if (j.y==500){
            j.y=-500;
        }
    }
}
void showarrow() {
if(Arrow) {
    showTexture(arrow, angle, arrowrect);
    arrowrect.x += 2;
    if (arrowrect.y > 350) {
        arrowrect.y -= 1;
    }
    if (keyHeld(SDL_SCANCODE_SPACE)) {
        arrowrect.x -= 4;
        if (angle >= -45)
            angle -= 5;


    } else if (angle <= 45)
        angle += 5;
}
else {
    showTexture(arrow2, angle, arrowrect);
    arrowrect.x += 2;
    if (arrowrect.y > 350) {
        arrowrect.y -= 1;
    }
    if (keyHeld(SDL_SCANCODE_SPACE)) {
        arrowrect.x -= 4;
        if (angle >= -45)
            angle -= 5;


    } else if (angle <= 45)
        angle += 5;
}
}
void showbackground(){
    showTexture(background,backgroundrect);
}
void showpause(){
    if(mouseInRect(pauserect) && Mouse.clicked())
        state='p';
    if(keyPressed(SDL_SCANCODE_P)){
        state='p';
    }
}
void showgem(){
    if(emtiaz%10==1 || emtiaz%10==4 || emtiaz%10==7)
        gemrect.x=170;
    if(emtiaz%10==2 || emtiaz%10==5 || emtiaz%10==8)
        gemrect.x=290;
    if(emtiaz%10==0 || emtiaz%10==3 || emtiaz%10==6 || emtiaz%10==9)
        gemrect.x=230;

    if(!gemBarkhord)
        showTexture(gem_addi,gemrect);
         gemrect.y+=sorat;
     if(hasIntersectionRect(arrowrect,gemrect)){
         if(!gemBarkhord) {
             playSound(Gem, 1);
             emtiaz++;
         }
         gemBarkhord=true;
     }
     if(gemrect.y==500){
         gemrect.y=-30;
         gemBarkhord=false;
     }


}

void showcoolgem(){
    if(emtiaz%10==5 || emtiaz%10==2 || emtiaz%10==8) {
        if (gemkhafan.y < -1)
            gemkhafan.x = 160;
    }
    if(emtiaz%10==0 || emtiaz%10==3 || emtiaz%10==6 || emtiaz%10==9) {
        if (gemkhafan.y < -1)
            gemkhafan.x = 280;
    }
    if(emtiaz%10 ==1 || emtiaz%10==4 || emtiaz%10==7) {
        if (gemkhafan.y < -1)
            gemkhafan.x = 220;
    }
    if(!gemintersection)
        showTexture(gem, gemkhafan);
        gemkhafan.y+=sorat;

        if(hasIntersectionRect(arrowrect,gemkhafan)){
            if(!gemintersection) {
                playSound(SpecialGem, 1);
                emtiaz += 10;
            }
            gemintersection=true;
        }
        if(gemkhafan.y==500) {
            gemkhafan.y = -500;
            gemintersection = false;
        }
}
void shurubazi(){
    showpause();
    showbackground();
    showarrow();
    showgem();
    showcoolgem();
    showwall();
    fontnevis();
    showTexture(Pause,pauserect);








    for (int i = 0; i <100 ; ++i) {
        if(hasIntersectionRotated(rightwall[i],arrowrect , true,angle)) {
            if(emtiaz>=25)
            state='j';
            else
            state='l';

        }
        if(hasIntersectionRotated(leftwall[i],arrowrect, false,angle)) {
            if(emtiaz>=25)
                state='j';
            else
            state='l';
        }
    }
}
void bakht()
{
showTexture(restart,restart2_rect);
showTexture(menutext,mainMenu_rect);

    if(SBDL::mouseInRect(restart_rect) && SBDL::Mouse.clicked()){
        arrowrect.x=220;
        gemrect.y=-30;
        gemkhafan.y=-1060;
        emtiaz=0;
        buildwalls();
        showwall();
        state='g';
    }

    if(SBDL::mouseInRect(mainMenu_rect) && SBDL::Mouse.clicked())
    state = 'm';

}
void joon(){
    if(emtiaz>=25){
        joone_ezafi=createFontTexture(font,"become alive? ",0,0,0);
        showTexture(joone_ezafi,0,20);
        showTexture(NO,no1);
        showTexture(YES,yes1);
        if(mouseInRect(no1) && Mouse.clicked()) {
            state='l';
        }
        if(mouseInRect(yes1) && Mouse.clicked()){
            arrowrect.x=220;
            gemrect.y=-30;
            gemkhafan.y=-1060;
            emtiaz-=25;
            buildwalls();
            showwall();
            state='g';
        }
    }
}
void main_menu(){
    if(x%2==0) {
        showTexture(seda_on, Seda);
    }
    if(x%2==1){
        showTexture(seda_off,Seda);
    }
    if(mouseInRect(Seda) && Mouse.clicked()){
        if(x%2==1){
            time_bazi=0;
        }
       x++;
    }

    showTexture(menutext,menu_rect);
    SBDL::showTexture(startText, start_rect);
    SBDL::showTexture(exitText, exit_rect);
    showTexture(settings,settingsrect);
    if(SBDL::mouseInRect(start_rect) && SBDL::Mouse.clicked()) {
        arrowrect.x=220;
        gemrect.y=-30;
        gemkhafan.y=-1060;
        emtiaz=0;
        buildwalls();
        showwall();
        state = 'g';
    }
    if(mouseInRect(settingsrect) && Mouse.clicked()){
        state='s';
    }
    if(SBDL::mouseInRect(exit_rect) && SBDL::Mouse.clicked())
        exit(0);
}
void pause(){

    SBDL::showTexture(Continue,continue_rect);
    SBDL::showTexture(restart,restart2_rect);
    SBDL::showTexture(menutext,mainMenu_rect);

    if(SBDL::mouseInRect(continue_rect) && SBDL::Mouse.clicked())
        state = 'g';
    if(SBDL::mouseInRect(restart_rect) && SBDL::Mouse.clicked()) {
        arrowrect.x=220;
        gemrect.y=-30;
        gemkhafan.y=-1060;
        emtiaz=0;
        showwall();
        state='g';
    }
    if(SBDL::mouseInRect(mainMenu_rect) && SBDL::Mouse.clicked())
        state = 'm';
}
void settings2(){
    showTexture(arrow,start_rect);
    showTexture(arrow2,settingsrect);
    showTexture(menutext,mainMenu_rect);
    if(mouseInRect(start_rect) && Mouse.clicked()) {
        Arrow = true;
        showTexture(dot,dot1);
        playSound(Gem,1);
    }
    if(mouseInRect(settingsrect) && Mouse.clicked()) {
        Arrow = false;
        showTexture(dot, dot2);
        playSound(Gem,1);
    }
    if(mouseInRect(mainMenu_rect) && Mouse.clicked())
        state='m';


}




int main(int argc, char *argv[])
{
    srand(time(NULL));
    const int window_width = 500;
    const int window_height = 500;
    SBDL::InitEngine("SBDL Test", window_width, window_height);
    const int FPS = 60; //frame per second
    const int delay = 1000/FPS ; //delay we need at each frame
        loadkolli();
        buildwalls();



    while (SBDL::isRunning()) {
        int startTime = SBDL::getTime();
        SBDL::updateEvents();
        SBDL::clearRenderScreen();
        if(x%2==0) {
            time_bazi++;
            for (int i = 0; i <1 ; ++i) {
                if(time_bazi>1){
                    break;
                }



                playMusic(queen, -1);

            }
        }
        else
            stopMusic();
        //Game logic code
        switch (state) {
            case 'g': shurubazi();break;
            case 'p' : pause(); break;
            case 'l' : bakht(); break;
            case 'm' : main_menu(); break;
            case 'j' : joon();break;
            case 's' : settings2();break;
         }

        SBDL::updateRenderScreen();


        int elapsedTime = SBDL::getTime() - startTime;
        if (elapsedTime < delay)
            SBDL::delay(delay - emtiaz/20);

    }
}