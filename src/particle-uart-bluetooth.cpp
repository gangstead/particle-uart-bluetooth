/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/gangstead/code/particle-uart-bluetooth/src/particle-uart-bluetooth.ino"
#include "Serial4/Serial4.h"

void setup();
void loop();
void serialEvent();
void serialEvent4();
#line 3 "/Users/gangstead/code/particle-uart-bluetooth/src/particle-uart-bluetooth.ino"
const int SEND_BUF_SIZE = 100;
char sendBuf[SEND_BUF_SIZE];
size_t sendBufOffset = 0;

SYSTEM_MODE(MANUAL);
void setup() {
  Cellular.off();
  Serial.begin(9600); //usb serial
  waitFor(Serial.isConnected, 10000);
  Serial4.begin(9600);
  delay(2000);
  Serial.println("starting up");
}

void loop() {
}

void serialEvent() {
  while (Serial.available() > 0) {
    int byte = Serial.read();
    Serial.write(byte);
    if ((char)byte == '\r') {
      sendBuf[sendBufOffset] = 0;
      Serial.printlnf("\nCommand Sent (%s)\n", sendBuf);
      Serial4.println(sendBuf);
      // for(int i = 0; i < SEND_BUF_SIZE; i++) sendBuf[i] = 0;
      sendBufOffset = 0;
    } else {
      // Serial.write(byte);
      sendBuf[sendBufOffset++] = byte;
    }
    if (sendBufOffset > SEND_BUF_SIZE) {
      Serial.println("Command too long.  Starting over");
      sendBufOffset = 0;
    }
  };
}
void serialEvent4() {
  while (Serial4.available() > 0) {
    Serial.write(Serial4.read());
  };
}