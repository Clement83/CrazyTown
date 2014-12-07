#include <SPI.h>
#include <Gamebuino.h>
Gamebuino gb;

#include <EEPROM.h>
#include <avr/pgmspace.h>
extern const byte font3x3[];
extern const byte font3x5[];
extern const byte font5x7[];

void displayText(String s, byte x, byte y, byte t);
void displayText(String s, byte x, byte y);
void displayInt(long l, byte Tx, byte Ty, byte fig);
void displayInt(long l, byte fig);
void initTime(int tempMax);

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
unsigned int timeleft = 0;
unsigned int score = 0;
unsigned long distTotal = 0;
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

void initGame(int tempMax){
  gb.battery.show = false;
  initPlayer();
  distTotal = 0;
  initTime(tempMax);
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
      
      if(timeleft == 0)
      {
        GameOverScreen();
        break;
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


//101 starship function
void displayText(String s, byte x, byte y, byte t){
  gb.display.cursorX = x;
  gb.display.cursorY = y;  
  gb.display.fontSize = t;
  gb.display.print(s);
}
void displayText(String s, byte x, byte y){
  displayText(s,x,y,1);
}
void displayInt(long l, byte Tx, byte Ty, byte fig){
  gb.display.fontSize = 1;
  String sl = String(l);
  while(sl.length() < fig){
    sl = "0" + sl;  
  }
  gb.display.cursorX = Tx;
  gb.display.cursorY = Ty;  
  gb.display.print(sl);
}

void displayInt(long l, byte fig){
  gb.display.fontSize = 1;
  String sl = String(l);
  while(sl.length() < fig){
    sl = "0" + sl;  
  } 
  gb.display.print(sl);
}
