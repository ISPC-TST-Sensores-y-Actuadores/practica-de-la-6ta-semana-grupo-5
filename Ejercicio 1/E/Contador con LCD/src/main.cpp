#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2); 
int entrada=1 ,cont=0, estado=0;

void setup() {
  lcd.begin(16,2);                       //inicializar LCD
  pinMode(entrada,INPUT);
  lcd.print("Nro. de personas");
}

void loop() {
  estado = digitalRead(entrada);

  if (estado == LOW)
  {
    cont++;

    while (estado == LOW)                 //antirebote
    {
      estado = digitalRead(entrada);
    }

  }

  lcd.setCursor(7,1);                     //Coordenadas LCD (x,y)
  lcd.print(cont);

  if (cont > 20) {

    lcd.clear();
    lcd.print("Num. de Objetos");
    cont = 0;
  }
  
  
}