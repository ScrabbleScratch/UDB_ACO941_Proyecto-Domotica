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

// Pines Entradas
const int PIN_TEMP = A0;
const int PIN_HUMEDAD = A1;
const int PIN_LUZ = A2;
const int PIN_PIR = 2;
const int PIN_BOTON_ALARMA = 12; 

// Actuadores (Salidas a los Relés)
const int RELAY_VENTILACION = 4;
const int RELAY_ILUMINACION = 5;
const int RELAY_RIEGO = 6;
const int PIN_LED_ALARMA = 7;
const int PIN_BUZZER = 8;

// Umbrales
const float LIMITE_TEMP = 26.0;
const int UMBRAL_LUZ = 500;
const int UMBRAL_HUMEDAD = 400;

// Variables
bool sistemaAlarmaActivo = false;
bool estadoBotonAnterior = HIGH;
unsigned long tiempoUltimaLectura = 0;

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Sistema Domotica");
  delay(500);
  lcd.clear();
  lcd.print("ACO941 G01T (V)");
  delay(500);
  lcd.clear();

  pinMode(PIN_PIR, INPUT);
  pinMode(PIN_BOTON_ALARMA, INPUT_PULLUP);

  pinMode(RELAY_VENTILACION, OUTPUT);
  pinMode(RELAY_ILUMINACION, OUTPUT);
  pinMode(RELAY_RIEGO, OUTPUT);
  pinMode(PIN_LED_ALARMA, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);
}

void loop() {
  // Lecturas
  int lecturaTemp = analogRead(PIN_TEMP);
  int lecturaLuz = analogRead(PIN_LUZ);
  int lecturaHumedad = analogRead(PIN_HUMEDAD);

  // Conversión Temp
  float voltaje = lecturaTemp * 5.0 / 1024.0;
  float temperaturaC = (voltaje - 0.5) * 100.0;

  // --- CONTROL DE ACTUADORES ---

  // 1. Ventilación
  if (temperaturaC >= LIMITE_TEMP) digitalWrite(RELAY_VENTILACION, HIGH);
  else digitalWrite(RELAY_VENTILACION, LOW);

  // 2. Iluminación
  if (lecturaLuz < UMBRAL_LUZ) digitalWrite(RELAY_ILUMINACION, HIGH);
  else digitalWrite(RELAY_ILUMINACION, LOW);

  // 3. Riego
  if (lecturaHumedad < UMBRAL_HUMEDAD) digitalWrite(RELAY_RIEGO, HIGH);
  else digitalWrite(RELAY_RIEGO, LOW);
}
