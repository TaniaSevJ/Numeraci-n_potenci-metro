#include <OneWire.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_I2CDevice.h>

Adafruit_SSD1306 display(-1); // <-- Ningun pin reiniciara la pantalla
#define ONE_WIRE_BUS 4 // <-- Se establece el pin 4 como bus OneWire
OneWire oneWire(ONE_WIRE_BUS); // <-- Protocolo de comunicacion por 1 cable
char buffer_temps[128];

const int potenciometro =0; // el potenciometro esta conectado al pin A0
int numeracion;  //variable para la numeración 

void setup() {
// No se necesitan declaran los pines analogicos
//ya que se realiza automáticamente
Serial.begin(9600);
 delay(100);
  Serial.println("Iniciando pantalla OLED");
    // Iniciar pantalla OLED en la dirección 0x3C
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
#ifdef __DEBUG__
    Serial.println("No se encuentra la pantalla OLED");
#endif
    while (true);
  }
}
void loop() {
//Se limpia la pantalla después de inicializarse 
display.clearDisplay();
//los valores analogicos se usan entre 0 y 100
//asi que el valor del potenciometro lo dividos en 10
numeracion = analogRead (potenciometro) / 10;
//analogWrite recibe los valores analogicos del pin

if(numeracion <= 99){
  display.setTextColor(WHITE, BLACK); // <-- Pasa parametro de colores
  display.setTextSize(1); // <-- Tamaño de fuente 
  display.setCursor(0, 0); // <--Cordenadas para el cursor
  display.println("Numeracion = " + String(numeracion)); // <-- Mostrar mensaje en pantalla
  display.display(); // <-- Transferencia de lo que se mostrara
  //Se limpiará la pantalla cada vez que cambie la numeración
  display.clearDisplay();
  }
}
