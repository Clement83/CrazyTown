#include <SPI.h>
#include <Gamebuino.h>
Gamebuino gb;

#include <EEPROM.h>
#include <avr/pgmspace.h>
extern const byte font3x3[];
extern const byte font3x5[];
extern const byte font5x7[];

typedef struct {
  float x, y, v, vx, vy, angle;
  byte radius;
} Ufo;

Ufo player;

//destination du client
int xDest;
int yDest;
int numClient = -1;
unsigned int time = 0;
unsigned int score = 0;
boolean countingTime = false;

//global variables
int camera_x, camera_y;

void setup()
{
  gb.begin();
  gb.display.setFont(font5x7);
  initHighscore();
  drawTitleScreen();
  xDest = 100;
  yDest = 100;
}

void loop(){
  drawMenu();
}

void initGame(){
  gb.battery.show = false;
  initPlayer();
  initTime();
}

void play(){
  gb.display.setFont(font3x5);
  while(1){
    if(gb.update()){
      //pause the game if C is pressed
      if(gb.buttons.pressed(BTN_C)){
        gb.display.setFont(font5x7);
        return;
      }

      updatePlayer();
      updateTime();
      updateClient();
      drawWorld();
      drawMap();
      drawPlayer();
      DrawClient();
      drawHud();
    }
  }
}


