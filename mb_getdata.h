#include <ModbusMaster.h>

ModbusMaster node;
uint8_t MAX485_RE_NEG;
uint8_t MAX485_DE;

void preTransmission() {
  digitalWrite(MAX485_RE_NEG, 1);
  digitalWrite(MAX485_DE, 1);
}

void postTransmission() {
  digitalWrite(MAX485_RE_NEG, 0);
  digitalWrite(MAX485_DE, 0);
}

void modbus_init(byte RE, byte DE, byte Rx, byte Tx) {
  MAX485_RE_NEG = RE;
  MAX485_DE = DE;
  Serial1.begin(9600, SERIAL_8N1, Rx, Tx);
  pinMode(MAX485_RE_NEG, OUTPUT);
  pinMode(MAX485_DE, OUTPUT);
  digitalWrite(MAX485_RE_NEG, 0);
  digitalWrite(MAX485_DE, 0);
  node.begin(1, Serial1);
  node.preTransmission(preTransmission);
  node.postTransmission(postTransmission);
}

float modbus_read(int addr, int sm) {
  int result = node.readHoldingRegisters(addr, sm);
  int data[10];
  float flt=0;
  if (result == node.ku8MBSuccess) {
    for (int j = 0; j < 2; j++) {
      data[j] = node.getResponseBuffer(j);
    }
    unsigned long temp = (unsigned long)data[0] + (unsigned long)data[1] * 65536;
    flt = *((float*)&temp);
    Serial.println("response: " + String(flt));
    delay(100);
  }
  else {
    Serial.print("Failed, Response Code: ");
    Serial.print(result, HEX);
    Serial.println(" ");
    delay(100);
  }
  return flt;
}