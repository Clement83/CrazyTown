

void initTime(){
  time = 0;
  countingTime = false;
}

void updateTime(){
  /*if(getTile(player.x/16, player.y/16) == 7){
    if(!countingTime){
      countingTime = true;
      time = 0;
    }
    else{
      if(time > 20){
        gb.display.setFont(font5x7);
        saveHighscore(time);
        gb.display.setFont(font3x5);
        initTime();
        initPlayer();
      }
    }
  }*/
  if(countingTime){
    time++;
  }
}



