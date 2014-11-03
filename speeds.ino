void forward(){
  spd_R = spd_dflt;
  spd_L = spd_dflt;
  
  writeSpeeds();
}

void halt(){
  spd_R = 0;
  spd_L = 0;
  
  writeSpeeds();
}

void offset1(){
    forward();
    delay(500);
    halt();
    delay(1000);
}

void offset2(){
    forward();
    delay(1500);
    halt();
    delay(500);
}
