/*Proyecto final, Arquitectura de Computadoras ACO941 G01T (Virtual)
Elaborado por:
Christian Gustavo Crespin Lozano CL060107
Carlos Francisco Villacorta Fernández VF161499
Mario Alejandro Orellana Andrade OA182314
Kevin Oswaldo Alvarez Rosales AR230041
Diego Benjamin Guerrero Zelaya GZ210369
Carlos Eduardo Hernández Alas HA221693
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Configuración LCD
LiquidCrystal_I2C lcd(0x20, 16, 2); 

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Sistema Domotica");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Loop principal
}
