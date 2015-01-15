void getIRreceiver()
{
  unsigned long max_time;;
  
  for(int i=0; i<8; i++)
  {
    //        INCREMENT MUX
    /***********************************************************************/
    mux_inValue=i;
    
    // Get mux input
    switch(mux_inValue) //Binaire réfléchi ?
    {
      case 0 : mux_in[2]=0 ; mux_in[1]=0 ; mux_in[0]=0 ; break;
      case 1 : mux_in[2]=0 ; mux_in[1]=0 ; mux_in[0]=1 ; break;
      case 2 : mux_in[2]=0 ; mux_in[1]=1 ; mux_in[0]=0 ; break;
      case 3 : mux_in[2]=0 ; mux_in[1]=1 ; mux_in[0]=1 ; break;
      case 4 : mux_in[2]=1 ; mux_in[1]=0 ; mux_in[0]=0 ; break;
      case 5 : mux_in[2]=1 ; mux_in[1]=0 ; mux_in[0]=1 ; break;
      case 6 : mux_in[2]=1 ; mux_in[1]=1 ; mux_in[0]=0 ; break;
      case 7 : mux_in[2]=1 ; mux_in[1]=1 ; mux_in[0]=1 ; break;
    }
    
    // Update mux
    digitalWrite(MUX_IN0,mux_in[0]);
    digitalWrite(MUX_IN1,mux_in[1]);
    digitalWrite(MUX_IN2,mux_in[2]);
    

    //        GET MUX OUTPUT
    /***********************************************************************/
    //MUXS1
    // Receive new value
    mux_out1.resume();
    max_time = millis() + TIMEOUT;
    // Wait for decode or timeout
    while (!mux_out1.decode(&IR_result))
    {
      if (millis() > max_time)
        Serial.println("Timeout receiving data");
    }
    // Update IR_receiver value
    IRreceiver[i]=IR_result.value;
    
    //MUXS2
    // Receive new value
    mux_out2.resume();
    max_time = millis() + TIMEOUT;
    // Wait for decode or timeout
    while (!mux_out2.decode(&IR_result))
    {
      if (millis() > max_time)
        Serial.println("Timeout receiving data");
    }
    // Update IR_receiver value
    IRreceiver[i+8]=IR_result.value;

    //MUXS3
    // Receive new value
    mux_out3.resume();
    max_time = millis() + TIMEOUT;
    // Wait for decode or timeout
    while (!mux_out3.decode(&IR_result))
    {
      if (millis() > max_time)
        Serial.println("Timeout receiving data");
    }
    // Update IR_receiver value
    IRreceiver[i+16]=IR_result.value;

    //MUXS4
    // Receive new value
    mux_out4.resume();
    max_time = millis() + TIMEOUT;
    // Wait for decode or timeout
    while (!mux_out4.decode(&IR_result))
    {
      if (millis() > max_time)
        Serial.println("Timeout receiving data");
    }
    // Update IR_receiver value
    IRreceiver[i+24]=IR_result.value;

  }
}
