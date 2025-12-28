#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#define BLYNK_TEMPLATE_ID "TMPL6Zn1UGy3h"
#define BLYNK_TEMPLATE_NAME "Corona Discharge"
#define BLYNK_AUTH_TOKEN "H7_a4XL6-2tXWEBbohKIE3vVLQm0tctZ"
//#define BLYNK_TEMPLATE_ID "TMPL6ZELinKzm"
//#define BLYNK_TEMPLATE_NAME "Corona Discharge Monitoring"
//#define BLYNK_AUTH_TOKEN "6X2EcKR5g16ntmmXoumLyW9RYkgawUq6"
char ssid[] = "NAMA-WIFI";
char pass[] = "PASSWORD WIFI";

const int sensor = 34;
int dataawal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  // put your main code here, to run repeatedly:
  dataawal = analogRead(sensor);
  Serial.println(dataawal);
  Blynk.virtualWrite(V0, dataawal);
  Blynk.run();
  delay(100);
}
