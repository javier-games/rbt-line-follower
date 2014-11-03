void monitorWrite(){
  if(Serial.available()){
    char rd2 = Serial.read();
    if(rd2 == 'a')
      tareaEjecutada();
    }
  }

void readMode(){
    digitalWrite(TE,LOW);
    cmnd_crn = digitalRead( CMD1 )*1+digitalRead( CMD2 )*2;
}

void tareaEjecutada(){
  digitalWrite(TE,HIGH);
  delay(5);
  digitalWrite(TE,LOW);
}
