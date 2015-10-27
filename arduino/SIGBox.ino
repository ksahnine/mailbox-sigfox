/* 
 * Author: Kadda SAHNINE
 * 
 * Description : This sketch will turn your plain old mailbox into 
 *               a SIGFOX connected device.
 * 
 * The circuit:
 *   - 1 AKERU EVB (ARDUINO UNO + SIGFOX transceiver TD1208)
 *   - 1 Tilt sensor
 *
 * Tilt Sensor module to Arduino UNO
 *   - VCC to 5V 
 *   - GND to GND
 *   - S (Signal) to D2
 */
  
/*** Librairies ***/
#include <IsTime.h>
#include <LowPower.h>
#include <SoftwareSerial.h>

/*** Configure the serial pins used by the SIGFOX tranceiver ***/
#define RX_PIN 5
#define TX_PIN 4
SoftwareSerial sigfox(RX_PIN,TX_PIN);

/*** Parameters ***/
#define TILT_PIN 2  // Tilt sensor output pin (D2)
const static int interval = 30000; // 30 seconds interval

long unsigned previous_millis;

void setup() {
  Serial.begin(9600);
  sigfox.begin(9600);
  Serial.println("Ready!");
  attachInterrupt(TILT_PIN - 2, tiltStateChange, CHANGE);
}

void loop() {
  while (sigfox.available()){
    Serial.print(sigfox.read());
  }   
}

void tiltStateChange(void) {
  if (IsTime(previous_millis, interval)) {
    previous_millis = millis();

    // Power up !
    LowPower.powerSave(SLEEP_500MS, ADC_OFF, BOD_OFF, TIMER2_OFF);

    int tilt = digitalRead(TILT_PIN); // worthless

    // Send the notification through SIGFOX network
    sigfox.write("AT$SF=\n");
    
    // Power down state with ADC and BOD module disabled
    LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);

    Serial.println("Notification sent. Time to sleep now");
  }
}
