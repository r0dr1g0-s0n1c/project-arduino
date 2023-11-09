// este codigo clona o rfid de forma a o onde mostra na tela lcd o id clonado para isso e preciso montar o laboratorio usando arduino e a placa de rfid. lembrando fins didadico.
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//DEFININDO OS PINOS RFID
#define RST_PIN         9       
#define SS_PIN          10

//CRINADO A INSTANCIA RFID
MFRC522 mfrc522(SS_PIN, RST_PIN);


//CRIANDO INSTANCIA LCD
LiquidCrystal_I2C lcd(0x3F,20,4);
//DEFININDO PINOS LCD
#define endereço 0x3F
#define colunas  16
#define linhas   2

void setup() {
  //RFID
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  //LCD
  lcd.init();                      
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Veja o ID:");
  
  
}

void loop() {

  //RFID
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Mostra UID na serial
 
  Serial.print("Card UID:");
  String conteudo= "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  char name = Serial.println();
  conteudo.toUpperCase();
  
  if (name == name){
    lcd.setCursor(0,1);
    lcd.print(conteudo.substring(1));
    delay(3000);
  }
  

}

