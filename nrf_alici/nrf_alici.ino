
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"           //Modül ile ilgili kütüphaneleri ekliyoruz

int mesaj[1];
RF24 alici(9, 10);
const uint64_t kanal = 0xE8E8F0F0E1LL;
int led = 2;

void setup(void) {
  Serial.begin(9600);

  alici.begin();
  alici.openReadingPipe(1, kanal);
  alici.startListening();
  pinMode(led, OUTPUT);
  
  Serial.println("basla alici");
}

void loop(void) {
  if (alici.available())
  Serial.println("ok");
  {
    bool done = false;
    while (!done)
    {
      done = alici.read(mesaj, 1);
      Serial.println(mesaj[0]);

      if (mesaj[0] == 123)
      {
        delay(10);
        digitalWrite(led, HIGH);
        Serial.println("h");
      }
      else {
        digitalWrite(led, LOW);
        Serial.println("l");
      }
      delay(10);
    }
  }
}

