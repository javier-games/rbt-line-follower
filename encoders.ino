void enc_reset(){
  encR_pst = encR_crn;
  encL_pst = encL_crn;
}

void encoderRead(){
  encR_crn=encR.read();
  encL_crn=encL.read();
  encR_tru = encR_crn-encR_pst;
  encL_tru = encL_crn-encL_pst;
}
