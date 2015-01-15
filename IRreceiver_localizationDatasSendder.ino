/***********************************************************************
Project : PPE (ECE Paris)
Part : IR receiver, localisation datas sender
Authors : DERUE Florian, ROBERT David

Description  :
- gets the values of all receivers
- get the heigh
- find the 3 receivers matching with the 3 transmitters
- returns by wifi :
  - the id of the 3 matching receivers
  - the heigh
***********************************************************************/



//        HEADERS
/***********************************************************************/
#include <IRremote.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "config.h"

//        DECLARATIONS
/***********************************************************************/
// Mux output
IRrecv mux_out1(MUX_OUT1);
IRrecv mux_out2(MUX_OUT2);
IRrecv mux_out3(MUX_OUT3);
IRrecv mux_out4(MUX_OUT4);

//Mux input
unsigned int mux_inValue;
boolean mux_in[3];

//IR receivers values
decode_results IR_result; //decoding entity
byte IRreceiver[32];

//H sensor value
byte heigh;

//Data to send
byte dataToSend[4];
    // byte0 : id of receiver matching with transmitter1
    // byte1 : id of receiver matching with transmitter2
    // byte2 : id of receiver matching with transmitter3
    // byte3 : heigh
               
//Wifi sender
RF24 wifiSender(WIFI_INPUT,WIFI_OUTPUT);

//        SETUP
/***********************************************************************/
void setup()
{
  //Serial.begin(9600);
  mux_out1.enableIRIn(); // Start the receiver1
  mux_out2.enableIRIn(); // Start the receiver2
  mux_out3.enableIRIn(); // Start the receiver3
  mux_out4.enableIRIn(); // Start the receiver4
  
  pinMode(MUX_OUT1, INPUT);
  pinMode(MUX_OUT2, INPUT);
  pinMode(MUX_OUT3, INPUT);
  pinMode(MUX_OUT4, INPUT);
  
  pinMode(MUX_IN0, OUTPUT);
  pinMode(MUX_IN1, OUTPUT);
  pinMode(MUX_IN2, OUTPUT);
  
  pinMode(HEIGH_SENSOR, INPUT);
  
  pinMode(COMMUTLASER, OUTPUT);
  
}

//        LOOP
/***********************************************************************/
void loop()
{
  getIRreceiver();
  getHeigh();
  getMatchingIRreceiver();
  sendDatas();
}
