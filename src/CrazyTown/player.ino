
const byte PetitTaxi[] PROGMEM = {16,8,0xFF,0xD0,0xC0,0x30,0xD6,0xB0,0x99,0xA0,0x99,0xA0,0xD6,0xB0,0xC0,0x30,0xFF,0xD0,};
const byte GrandTaxi[] PROGMEM = {24,9,0xFF,0xFF,0xA0,0xC0,0x0,0x60,0xCD,0xB5,0xE0,0x96,0xC,0x60,0x96,0x4C,0x40,0x96,0xC,0x60,0xCD,0xB5,0xE0,0xC0,0x0,0x60,0xFF,0xFF,0xA0,};
void initPlayer(){
  player.radius = 3;
  player.x = 20;
  player.y = 20;
  player.v = 0;
  player.vx = 0;
  player.vy = 0;
  player.angle = 0;
  numClient=-1;
}

void updatePlayer(){

  if(gb.buttons.repeat(BTN_RIGHT, 1)){
    player.angle += 0.31415/2;
  }
  if(gb.buttons.repeat(BTN_LEFT, 1)){
    player.angle -= 0.31415/2;
  }
  if(gb.buttons.repeat(BTN_A, 1)){
    player.v += 0.02;
  }
  if(gb.buttons.repeat(BTN_B, 1)){
    player.v *= 0.8;
    player.vx *= 0.8;
    player.vy *= 0.8;
  }

  byte currentTile = getTile(player.x/16, player.y/16);

  //friction
  switch(currentTile){
  case 0: //road
    player.v *= 0.95;
    player.vx *= 0.9;
    player.vy *= 0.9;
    break;
 /* case 5: //sand
    player.v *= 0.9;
    player.vx *= 0.8;
    player.vy *= 0.8;
    break;
  case 6: //ice
    player.v *= 0.7;
    player.vx *= 1;
    player.vy *= 1;
    break;
  default:
    player.v *= 0.95;
    player.vx *= 0.9;
    player.vy *= 0.9;
    break;*/
  }
/*
  //accelerator
  switch(currentTile){
  case 1: //right
    player.vx += 1;
    break;
  case 2: //down
    player.vy += 1;
    break;
  case 3: //left
    player.vx -= 1;
    break;
  case 4: //up
    player.vy -= 1;
    break;
  }*/

  //speed update
  player.vx += cos(player.angle)*player.v;
  player.vy += sin(player.angle)*player.v;

  //collisions
  player.x += player.vx;
  currentTile = getTile(player.x/16, player.y/16);
  if(currentTile == 1){
    player.x -= player.vx;

      player.vx *= -0.5;
      gb.sound.playTick();
    player.v *= 0.5;
  }

  player.y += player.vy;
  currentTile = getTile(player.x/16, player.y/16);
  if(currentTile == 1){
    player.y -= player.vy;
      player.vy *= -0.5;
      gb.sound.playTick();
    player.v *= 0.5;
  }
  
  distTotal += 8 * ((player.v<0)? -player.v : player.v)  ;
  if(numClient>-1)
  {
    //le compteur tourne !
    distClient += 8 * ((player.v<0)? -player.v : player.v ) ;
  }

  //target position of the camera for the cursor to be centered
  int camera_x_target = player.x + cos(player.angle)*player.v*64 - LCDWIDTH/2;
  int camera_y_target = player.y + sin(player.angle)*player.v*64- LCDHEIGHT/2;
  //apply the target coordinate to the current coordinates with some smoothing
  camera_x = (camera_x*3 + camera_x_target)/4;
  camera_y = (camera_y*3 + camera_y_target)/4;

}

void drawPlayer(){
  int x_screen = (int)player.x - camera_x;
  int y_screen = (int)player.y - camera_y;
  if(!(x_screen < -16 || x_screen > LCDWIDTH || y_screen < -16 || y_screen > LCDHEIGHT)){
   /*gb.display.fillCircle(x_screen, y_screen, player.radius);
    gb.display.setColor(WHITE);
    gb.display.drawLine(x_screen,y_screen,x_screen+cos(player.angle)*4, y_screen+sin(player.angle)*4);
    gb.display.setColor(BLACK);*/
    drawBitmapAngle(x_screen, y_screen, GrandTaxi,player.angle);
  }
}



