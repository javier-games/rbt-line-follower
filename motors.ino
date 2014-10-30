void writeSpeeds(){
  if( spd_R >= 0 ){
    digitalWrite(MTR_R1,HIGH);        
    digitalWrite(MTR_R2,LOW);
  }
  if( spd_R < 0 ){
    spd_R = -spd_R;
    digitalWrite(MTR_R1,LOW);
    digitalWrite(MTR_R2,HIGH);
  }
  if( spd_L >= 0 ){
    digitalWrite(MTR_L1,HIGH);
    digitalWrite(MTR_L2,LOW);
  }   
  if( spd_L < 0 ){
    spd_R = -spd_R;
    digitalWrite(MTR_L1,LOW);
    digitalWrite(MTR_L2,HIGH);
  }
  
  analogWrite(MTR_RS,spd_R);
  analogWrite(MTR_LS,spd_L);
}
