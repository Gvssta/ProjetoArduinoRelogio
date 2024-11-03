#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>

// Definições para RFID
#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);

// Definições para RTC
RTC_DS3231 rtc;

// Definições para LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // Ajuste o endereço se necessário

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  
  // Inicializa o RTC
  if (!rtc.begin()) {
    Serial.println("RTC não encontrado!");
    while (1);
  }

  // Inicializa o LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Aproxime o TAG");
}

void loop() {
  if (rfid.PICC_IsNewCardPresent()) {
    if (rfid.PICC_ReadCardSerial()) {
      Serial.print("UID: ");
      String uid = "";
      for (byte i = 0; i < rfid.uid.size; i++) {
        uid += String(rfid.uid.uidByte[i], HEX);
        Serial.print(rfid.uid.uidByte[i], HEX);
        Serial.print(" ");
      }
      Serial.println();
      
      uid.toLowerCase(); // Transforma o UID para minúsculas

      // Lê a data e hora do RTC
      DateTime now = rtc.now();
      String date = String(now.day()) + "/" + String(now.month()) + "/" + String(now.year());
      String time = String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second());

      // Verifica se o UID é o esperado
      if (uid == "44cb86a7") { // Certifique-se de remover espaços
        // Envia os dados válidos para o Python
        Serial.println("VALID," + uid + "," + date + "," + time);
        
        // Exibe no LCD
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Dados Validos");
        lcd.setCursor(0, 1);
        lcd.print("UID: " + uid);
        lcd.setCursor(0, 2);
        lcd.print("Data: " + date);
        lcd.setCursor(0, 3);
        lcd.print("Hora: " + time);
      } else {
        // Exibe mensagem de dados inválidos no LCD
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Dados Invalidos");
        lcd.setCursor(0, 1);
        lcd.print("UID Invalida");
      }

      delay(2000); // Delay para leitura do LCD
      rfid.PICC_HaltA(); // Para o cartão
    }
  }
}