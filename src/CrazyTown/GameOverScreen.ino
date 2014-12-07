
void GameOverScreen()
{
  while(true)
  {
    if(gb.update()){
      gb.display.setFont(font5x7);
      gb.display.println("Game Over");
      gb.display.setFont(font3x5);
      gb.display.print("Clients:");
      displayInt(score,4);gb.display.println("");
      gb.display.print("Dist:");
      displayInt(distTotal,6);
      
      if(haveNewHightScore())
      {
        gb.display.cursorX = 20+random(0,2);
        gb.display.cursorY = 30+random(0,2);
        gb.display.println(F("New records!"));
      }
      
      if(gb.buttons.pressed(BTN_A) || gb.buttons.pressed(BTN_B) || gb.buttons.pressed(BTN_C)){
        gb.sound.playOK();
        break;
      }
    }
  }
  
  saveHighscore(score);
  
}
