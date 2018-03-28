
#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"     //Modül ile ilgili kütüphaneleri ekliyoruz

int mesaj[1];      //mesaj isminde bir dizi tanımlıyoruz
RF24 verici(9, 10);    //kütüphane tarafından kullanılacak pinleri tanımlıyoruz
const uint64_t kanal = 0xE8E8F0F0E1LL; //kanalı tanımlıyoruz

void setup(void)
{ 
  Serial.begin(9600);
  verici.begin();       //nrf yi başlatıyoruz
  verici.openWritingPipe(kanal);  //kanal id sı tanımlanıyor

    Serial.println("basla verici");
}


void loop(void)
{

    mesaj[0] = "abc";
    verici.write(mesaj, 1);   //mesaj değişkeni yollanıyor
    
  delay(3000);
  
}

