#include <Encoder.h>
char rd = ' ';

//DECLARACION DE PINES
const int MTR_R1 = 4;  //Right motor direcction pin1
const int MTR_R2 = 5;  //Right motor direcction pin2
const int MTR_RS = 6;  //Right motor speed pin
const int MTR_L1 = 7;  //Left motor direcction pin1
const int MTR_L2 = 8;  //Left motor direcction pin2
const int MTR_LS = 9;  //Left motor speed pin
const int SLD  = 10;   //Digital left sensor
const int SFD  = 11;   //Digital front sensor
const int SRD  = 12;   //Digital right sensor
const int TE   = 13;   //Handshake end of work
const int NT   = 2;    //Handshake new work
const int CMD1 = 50;   //Comand to execute
const int CMD2 = 51;   //Comand to execute

//ENCODERS
Encoder encR(18,19),encL(20,21);     //Encoders to use
long encR_crn=0,encL_crn=0; //Current count
long encR_pst=0,encL_pst=0; //Past count
long encR_tru = 0 , encL_tru = 0;   //Real count
long goalL = 0, goalR = 0;
const int offset = 45;

//INTERPRETACION DE COMANDOS
int cmnd_crn = 0;          //Decimal representation of comands
int cmnd_pst = -1;
int spd_R=0,spd_L=0;    //Speed to write to the motors
const int spd_dflt=100; //Default speed
boolean ctrl=false;

//CONTROL DE ANGULO
double th_r=0;    //Decired theta
double th_pst=-1;
const float tlrnc = 0.08;
const float mppR = 0.28, mppL = 0.28;
const float diameter = 8.4192;
const float wmax = 30*PI;
const double bt=0.1;
double et=0;

//ACOPLAMIENTO DIGITAL DE SEÑALES ANALOGICAS
int asns[3];                     //Analog Sensor
const int thr[3]={990-200,983-225,979-400};  //Thresholding Points

void setup() {
  Serial.begin(115200);
  pinMode(MTR_R1,OUTPUT);
  pinMode(MTR_R2,OUTPUT);                          
  pinMode(MTR_RS,OUTPUT);
  pinMode(MTR_L1,OUTPUT);
  pinMode(MTR_L2,OUTPUT);
  pinMode(MTR_LS,OUTPUT);
  pinMode(SLD,OUTPUT);
  pinMode(SFD,OUTPUT);
  pinMode(SRD,OUTPUT);
  pinMode(TE, OUTPUT);
  pinMode(CMD1,INPUT);
  pinMode(CMD2,INPUT);
  attachInterrupt(0, readMode, CHANGE);
  
}

void loop(){

  sensorRead();
  sensorWrite();
  
  encoderRead();
  
  if( cmnd_crn != cmnd_pst){
    if( cmnd_crn == 0 ){
      forward();
    }
    if( cmnd_crn == 1 ){
      th_r = -90;
      halt();
      offset1();
      control();
      offset2();
      tareaEjecutada();
    }
    if( cmnd_crn == 2 ){
      th_r = 90;
      halt();
      offset1();
      control();
      offset2();
      tareaEjecutada();
    }
    if( cmnd_crn == 3 ){
      th_r = 180;
      halt();
      control();
      tareaEjecutada();
    }
    cmnd_pst = cmnd_crn;
  }

  writeSpeeds();
  
  monitorWrite();
  Serial.println();
}

