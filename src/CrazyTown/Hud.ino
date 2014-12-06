

void drawHud(){
  
    gb.display.setColor(WHITE);
    gb.display.fillCircle(4, 4, 4);
    gb.display.setColor(BLACK);
    gb.display.drawCircle(4, 4, 4);
  // int dist =sqrt( pow(x-camXCenter,2) + pow(y-camYCenter,2));
  if(numClient>-1)
  {
    int AC = 4;
    int DB = xDest - player.x;
    int AD = yDest - player.y ;
    float AB = sqrt( pow( DB,2) + pow(AD,2));
    float EC = (AC/AB) * DB;
    float AE = (AC/AB) * AD;
    gb.display.drawLine(4,4,4+EC,4+AE);
    gb.display.cursorX = 15;
    gb.display.cursorY = 0;
    gb.display.setColor(BLACK, WHITE);
    gb.display.setFont(font3x3);
    gb.display.print("D:");
    gb.display.print((int)AB);
    gb.display.print(" T:");
    gb.display.print(time);
    gb.display.print(" S:");
    gb.display.print(score);
    gb.display.setFont(font3x5);
    gb.display.setColor(BLACK);
  }

}
