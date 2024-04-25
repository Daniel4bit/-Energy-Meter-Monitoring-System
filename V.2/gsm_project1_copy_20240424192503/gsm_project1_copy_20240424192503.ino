


String num1;//danielraj
String num2;//Customer
String num3;//customer
String num4;//customer2



#include "mb_getdata.h"
#include "push_data_int.h"
#include "values.h"

#include <EEPROM.h>

#include <ArduinoJson.h>
String number ="http://13.233.93.242/projects/energy/api/get-messaging-mobile-numbers.php?mid=101";
String data="http://13.233.93.242/projects/energy/api/get-max.php?mid=101";
JsonDocument doc;

int a, b, c;
const int X = 40001;

#define MAX485_DE 5
#define MAX485_RE_NEG 4
#define RX_PIN 16
#define TX_PIN 17

bool st = false;

void setup() {
  modbus_init(MAX485_RE_NEG, MAX485_DE, RX_PIN, TX_PIN);
  Serial.begin(9600);
  gprs_init(12, 13);
  String num_data = get_num();  
  deserializeJson(doc, num_data);
  long long int temp;

  temp =doc["data"][0];
  num1 = "+91" + String(temp);

  temp =doc["data"][1];
  num2 = "+91" + String(temp);

  temp =doc["data"][2];
  num3 = "+91" + String(temp);

  temp =doc["data"][3];
  num4 = "+91" + String(temp);

  Serial.println(num1);
  Serial.println(num2);
  Serial.println(num3);
  Serial.println(num4);

  }

void loop() {

  String fgh = get_data();
  

  Serial.println();
  Serial.println(fgh);
  if (fgh != "{}") {
    deserializeJson(doc, fgh);
    a = doc["data"][0];
    b = doc["data"][1];
    c = doc["data"][2];
  }
  Serial.println(a);
  Serial.println(b);
  Serial.println(c);

  // get modbus values
  wattstot = modbus_read((40101 - X), 2);
  wattsrphase = modbus_read((40103 - X), 2);
  wattsyphase = modbus_read((40105 - X), 2);
  wattsbphase = modbus_read((40107 - X), 2);
  PFAverage = modbus_read((40117 - X), 2);
  pfrphase = modbus_read((40119 - X), 2);
  pfyphase = modbus_read((40121 - X), 2);
  pfbphase = modbus_read((40123 - X), 2);
  vatotal = modbus_read((40125 - X), 2);
  varphase = modbus_read((40127 - X), 2);
  vayphase = modbus_read((40129 - X), 2);
  vabphase = modbus_read((40131 - X), 2);
  VLLAverage = modbus_read((40133 - X), 2);
  vryphase = modbus_read((40135 - X), 2);
  vybphase = modbus_read((40137 - X), 2);
  vbrphase = modbus_read((40139 - X), 2);
  VLNAverage = modbus_read((40141 - X), 2);
  vrphase = modbus_read((40143 - X), 2);
  vyphase = modbus_read((40145 - X), 2);
  vbphase = modbus_read((40147 - X), 2);
  currenttotal = modbus_read((40149 - X), 2);
  currentrphase = modbus_read((40151 - X), 2);
  currentyphase = modbus_read((40153 - X), 2);
  currentbphase = modbus_read((40155 - X), 2);
  Frequency = modbus_read((40157 - X), 2);
  wh = modbus_read((40159 - X), 2);
  vah = modbus_read((40161 - X), 2);
  loadhours = modbus_read((40217 - X), 2);

  String str_values =
    String(wattstot) + "," + String(wattsrphase) + "," + String(wattsyphase) + "," + String(wattsbphase) + "," + String(PFAverage) + "," + String(pfrphase) + "," + String(pfyphase) + "," + String(pfbphase) + "," + String(vatotal) + "," + String(varphase) + "," + String(vayphase) + "," + String(vabphase) + "," + String(VLLAverage) + "," + String(vryphase) + "," + String(vybphase) + "," + String(vbrphase) + "," + String(VLNAverage) + "," + String(vrphase) + "," + String(vyphase) + "," + String(vbphase) + "," + String(currenttotal) + "," + String(currentrphase) + "," + String(currentyphase) + "," + String(currentbphase) + "," + String(Frequency) + "," + String(wh) + "," + String(vah) + "," + String(loadhours);

  Serial.print(str_values);
  
  put(str_values);

  Serial.println("VLL :" + String(VLLAverage));
  if (VLNAverage > 0) {
    if (!st) {
      message(num1, "power: ON");
      delay(1000);
      message(num2, "power: ON");
      delay(1000);
      message(num3, "power: ON");
      delay(1000);
      message(num4, "power: ON");
      delay(1000);
      st = true;
    }
  } else {
    if (st) {
      message(num1, "power: OFF");
      delay(1000);
      message(num2, "power: OFF");
      delay(1000);
      message(num3, "power: OFF");
      delay(1000);
      message(num4, "power: OFF");
      delay(1000);
      st = false;
    }
  }

  if (VLLAverage < b && VLLAverage > 0) {
    //less volt
    message(num1, "voltage drop:volt = " + String(VLLAverage) + "V");
    delay(1000);
    message(num2, "voltage drop:volt = " + String(VLLAverage) + "V");
    delay(1000);
    message(num3, "voltage drop:volt = " + String(VLLAverage) + "V");
    delay(1000);
    message(num4, "voltage drop:volt = " + String(VLLAverage) + "V");
    delay(1000);
  }

  if (VLLAverage > a) {
    //more volt
    message(num1, "High voltage \n volt = " + String(VLLAverage) + "V");
    delay(1000);
    message(num2, "High voltage \n volt = " + String(VLLAverage) + "V");
    delay(1000);
    message(num3, "High voltage \n volt = " + String(VLLAverage) + "V");
    delay(1000);
    message(num4, "High voltage \n volt = " + String(VLLAverage) + "V");
    delay(1000);
  }

  if (currenttotal > c) {
    //more current
    message(num1, "The device have delivered high current \n current = " + String(currenttotal) + "A");
    delay(1000);
    message(num2, "The device have delivered high current \n current = " + String(currenttotal) + "A");
    delay(1000);
    message(num3, "The device have delivered high current \n current = " + String(currenttotal) + "A");
    delay(1000);
    message(num4, "The device have delivered high current \n current = " + String(currenttotal) + "A");
    delay(1000);
  }
}