void control(){
  enc_reset();
  do{
    
    encoderRead();
    
    double th_crn = (mppR*encR_tru-mppL*encL_tru)/diameter;
    et = (th_r*PI/180)-th_crn;
    spd_L = -wmax*(-1+2/(1+exp(-et/bt))); //se obtiene la velocidad del motor Izquierdo
    spd_R =  wmax*(-1+2/(1+exp(-et/bt))); //se obtiene la velocidad del motor Derecho
    
    writeSpeeds();   
  
  }while( abs(et) >= tlrnc );
  
  halt();
  
}
  
  
