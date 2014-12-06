#define DIST_RECUP_DEPOS 10
#define NB_CLIENT 4
//x1,y1
int Clients[NB_CLIENT*2];
const byte Client1[] PROGMEM = {8,8,0x0,0x77,0x55,0x14,0x3E,0x2A,0x3E,0x3E,};

void updateClient()
{
  //MAJ des clients
  for(int i =0;i<NB_CLIENT;i++)
  {
    if(numClient==i) 
      continue;//Client an taxi on l'affiche pas
    
    int x = Clients[i*2];
    int y = Clients[i*2 + 1];
    int camXCenter = player.x; // camera_x + LCDHEIGHT/2;
    int camYCenter = player.y; //camera_y + LCDWIDTH/2;
    int dist =sqrt( pow(x-camXCenter,2) + pow(y-camYCenter,2));
    
    if(dist>150)
    {
      do
      {
        Clients[i*2]  = camXCenter + random(-LCDWIDTH*2,LCDWIDTH*2);
        Clients[i*2 + 1] = camYCenter  + random(-LCDHEIGHT*2,LCDHEIGHT*2);
     /* Serial.print(x);Serial.print(" <= x cli, y=> ");Serial.print(y);Serial.print(" | ");
      Serial.print(camera_x);Serial.print(" <= x cam, y=> ");Serial.print(camera_y);Serial.print(" | ");*/
        byte spriteID = getTile(Clients[i*2]/16,Clients[i*2 + 1]/16);
        if(spriteID == 0)
        {
          //Serial.print(player.x);Serial.print(" <= x , y=> ");Serial.print(player.y);Serial.print(" | ");
          //Serial.print("new client : [x,y] ["); Serial.print( Clients[i*2]);Serial.print(",");Serial.print(Clients[i*2 + 1]);Serial.println("]");

          break;
        }
        
      }while(true);
    }
    else if(dist<DIST_RECUP_DEPOS &&  sqrt(pow(player.v,2))<1 && numClient==-1)
    {
      //On monte dans le taxi
      numClient = i;
      countingTime = true;
      //xDest
      //yDest
      
      do
      {
          xDest  = random (100,2000);
          yDest = random (100,2000);
        byte spriteID = getTile(xDest/16,yDest/16);
        if(spriteID == 0)
        {
          //Serial.print(xDest);Serial.print(" <= x , y=> ");Serial.print(yDest);Serial.print(" | ");
          break;
        }
        
      }while(true);
    }
    if(numClient>-1)
    {
      int DB = xDest - player.x;
      int AD = yDest - player.y ;
      float AB = sqrt( pow( DB,2) + pow(AD,2));
      if(AB<DIST_RECUP_DEPOS)
      {
        score++;
        numClient = -1;
        initTime();
      }
    }
  }
}

void DrawClient()
{
  for(int i =0;i<NB_CLIENT;i++)
  {
    if(numClient==i) 
      continue;//Client an taxi on l'affiche pas
      
    int x = Clients[i*2];
    int y = Clients[i*2 + 1];
    int x_screen = x - camera_x;
    int y_screen = y - camera_y;
    if(!(x_screen < -16 || x_screen > LCDWIDTH || y_screen < -16 || y_screen > LCDHEIGHT)){
      //gb.display.fillCircle(x_screen, y_screen, 2);
      
       gb.display.drawBitmap(x_screen, y_screen, Client1);
   }
  }
  
  int x_screen = xDest - camera_x;
    int y_screen = yDest - camera_y;
    if(!(x_screen < -16 || x_screen > LCDWIDTH || y_screen < -16 || y_screen > LCDHEIGHT)){
//      gb.display.fillCircle(x_screen, y_screen, 2);
      gb.display.drawCircle(x_screen, y_screen, 4);
      gb.display.drawCircle(x_screen, y_screen, 1);
    }
  
  
}
