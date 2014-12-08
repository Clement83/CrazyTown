

void drawHud(){
  
    gb.display.setColor(WHITE);
    gb.display.fillCircle(4, 43, 4);
    gb.display.setColor(BLACK);
    gb.display.drawCircle(4, 43, 4);
  // int dist =sqrt( pow(x-camXCenter,2) + pow(y-camYCenter,2));
  if(numClient>-1)
  {
    int AC = 4;
    int DB = xDest - player.x;
    int AD = yDest - player.y ;
    float AB = sqrt( pow( DB,2) + pow(AD,2));
    float EC = (AC/AB) * DB;
    float AE = (AC/AB) * AD;
    gb.display.drawLine(4,43,4+EC,43+AE);
  }
    //gb.display.cursorX = 15;
    //gb.display.cursorY = 0;
    gb.display.setColor(BLACK, WHITE);
    gb.display.setFont(font3x3);
    displayInt(timeleft,0,0,5);
    displayInt(time,60,0,5);
    displayInt(score,69,45,4);
  if(numClient>-1)
  {
    gb.display.setColor(BLACK);
    gb.display.fillRoundRect(27, 0, 20, 7, 3);
    gb.display.setColor(INVERT);
  }
  else 
  {
    gb.display.setColor(WHITE);
    gb.display.fillRoundRect(27, 0, 20, 7, 3);
    gb.display.setColor(BLACK);
    gb.display.drawRoundRect(27, 0, 20, 7, 3);
  }
    displayText("TAXI",30,2);

    gb.display.setFont(font3x5);
    gb.display.setColor(BLACK);
}
