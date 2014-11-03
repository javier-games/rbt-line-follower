void sensorRead(){
  asns[0] = analogRead(A1);
  asns[1] = analogRead(A2);
  asns[2] = analogRead(A3);
}

void sensorWrite(){
  for( int i=0 ; i<3 ; i++ ){
    if( asns[i] >= thr[i] ){
      digitalWrite(10+i,HIGH);
    }
    else{
      digitalWrite(10+i,LOW);
    }
  }
}
