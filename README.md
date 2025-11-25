# Sistema Domótica - Arduino

## Descripción del Proyecto

Sistema de domótica desarrollado con Arduino para la materia **Arquitectura de Computadoras ACO941 G01T (Virtual)**. Este proyecto implementa un sistema automatizado de control ambiental con monitoreo de temperatura, humedad, luz y seguridad mediante sensor de movimiento.

## Autores

- Christian Gustavo Crespin Lozano (CL060107)
- Carlos Francisco Villacorta Fernández (VF161499)
- Mario Alejandro Orellana Andrade (OA182314)
- Kevin Oswaldo Alvarez Rosales (AR230041)
- Diego Benjamin Guerrero Zelaya (GZ210369)
- Carlos Eduardo Hernández Alas (HA221693)

## Características Principales

### 🌡️ Control de Temperatura
- Monitoreo continuo de temperatura ambiente
- Activación automática de ventilación cuando la temperatura supera los 26°C
- Sensor: TMP36 o similar (pin analógico A0)

### 💡 Control de Iluminación
- Detección de niveles de luz ambiente
- Activación automática de iluminación cuando la luz es insuficiente (< 500)
- Sensor: LDR (pin analógico A2)

### 💧 Sistema de Riego Automático
- Monitoreo de humedad del suelo
- Activación automática del riego cuando la humedad es baja (< 400)
- Sensor: Sensor de humedad de suelo (pin analógico A1)

### 🚨 Sistema de Alarma
- Activación/desactivación mediante botón
- Detección de movimiento con sensor PIR
- Alerta sonora con buzzer cuando se detecta movimiento
- Indicador LED de estado de alarma

### 📺 Display LCD
- Pantalla LCD I2C 16x2
- Muestra temperatura actual
- Estado de la alarma (ON/OFF)
- Nivel de luz con indicador de activación
- Nivel de humedad

## Componentes de Hardware

### Sensores (Entradas)
- **PIN_TEMP (A0)**: Sensor de temperatura TMP36
- **PIN_HUMEDAD (A1)**: Sensor de humedad de suelo
- **PIN_LUZ (A2)**: Sensor LDR (fotoresistor)
- **PIN_PIR (D2)**: Sensor de movimiento PIR
- **PIN_BOTON_ALARMA (D12)**: Botón para activar/desactivar alarma

### Actuadores (Salidas)
- **RELAY_VENTILACION (D4)**: Relé para control de ventilador
- **RELAY_ILUMINACION (D5)**: Relé para control de iluminación
- **RELAY_RIEGO (D6)**: Relé para sistema de riego
- **PIN_LED_ALARMA (D7)**: LED indicador de alarma activa
- **PIN_BUZZER (D8)**: Buzzer para alerta sonora

### Display
- **LCD I2C (0x20)**: Pantalla LCD 16x2 con módulo I2C

## Umbrales Configurables

```cpp
const float LIMITE_TEMP = 26.0;      // Temperatura límite en °C
const int UMBRAL_LUZ = 500;          // Nivel mínimo de luz
const int UMBRAL_HUMEDAD = 400;      // Nivel mínimo de humedad
```

## Librerías Requeridas

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
```

### Instalación de Librerías
1. Abrir Arduino IDE
2. Ir a **Sketch > Include Library > Manage Libraries**
3. Buscar e instalar:
   - `LiquidCrystal I2C` por Frank de Brabander

## Diagrama de Conexiones

### Conexiones I2C (LCD)
- SDA → A4 (Arduino Uno)
- SCL → A5 (Arduino Uno)

### Sensores Analógicos
- TMP36 → A0
- Sensor Humedad → A1
- LDR → A2

### Sensores Digitales
- PIR → D2
- Botón Alarma → D12 (con INPUT_PULLUP)

### Relés y Actuadores
- Ventilación → D4
- Iluminación → D5
- Riego → D6
- LED Alarma → D7
- Buzzer → D8

## Funcionamiento

### Inicialización
Al encender el sistema, el LCD muestra:
1. "Sistema Domotica" (500ms)
2. "ACO941 G01T (V)" (500ms)
3. Pantalla principal con datos en tiempo real

### Loop Principal
El sistema ejecuta continuamente:
1. **Gestión de alarma**: Verifica estado del botón y sensor PIR
2. **Lectura de sensores**: Lee temperatura, luz y humedad
3. **Control de actuadores**: Activa/desactiva relés según umbrales
4. **Actualización LCD**: Refresca pantalla cada 500ms

### Pantalla LCD
```
T:25C Alr:OFF
Luz:450* H:380
```
- **T**: Temperatura en °C
- **Alr**: Estado de alarma (ON/OFF)
- **Luz**: Nivel de luz (* indica iluminación activa)
- **H**: Nivel de humedad

## Funciones Principales

### `gestionarAlarma()`
Controla el sistema de alarma:
- Detecta pulsación del botón (con debounce)
- Alterna estado de alarma
- Activa LED indicador
- Genera tono de alerta si detecta movimiento

### `actualizarLCD()`
Actualiza la información en pantalla:
- Muestra temperatura, luz y humedad
- Indica estado de alarma
- Marca con asterisco (*) cuando la iluminación está activa

## Instalación y Uso

1. **Clonar el repositorio**
   ```bash
   git clone [URL_DEL_REPOSITORIO]
   ```

2. **Abrir en Arduino IDE**
   - Abrir el archivo `Sistema_Domotica.ino`

3. **Configurar placa**
   - Seleccionar placa Arduino (Uno, Mega, etc.)
   - Seleccionar puerto COM correcto

4. **Cargar el código**
   - Verificar y compilar
   - Subir a la placa Arduino

5. **Verificar conexiones**
   - Revisar que todos los componentes estén conectados correctamente
   - Verificar dirección I2C del LCD (por defecto 0x20)

## Solución de Problemas

### LCD no muestra nada
- Verificar conexiones I2C (SDA/SCL)
- Ajustar contraste del LCD
- Probar con dirección I2C alternativa (0x27)

### Sensores no responden
- Verificar alimentación (5V y GND)
- Comprobar conexiones en pines correctos
- Revisar valores en Monitor Serial

### Relés no activan
- Verificar alimentación de módulo de relés
- Comprobar lógica de activación (HIGH/LOW)
- Revisar umbrales configurados
