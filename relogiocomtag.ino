//Inclusao das bibliotecas
#include "RTClib.h"             // Biblioteca para RTC
#include <Wire.h>               //Biblioteca utilizada gerenciar a comunicação entre dispositicos através do protocolo I2C
#include <LiquidCrystal_I2C.h>  //Biblioteca controlar display 16x2 através do I2C

LiquidCrystal_I2C lcd(0x27, 16, 2);  //Cria o objeto lcd passando como parâmetros o endereço, o nº de colunas e o nº de linhas

//As linhas de codigo a seguir devem ser comentadas, ou descomentadas, de acordo com o modelo de RTC utilizado (DS1307 ou DS3132)
RTC_DS1307 rtc;  //Objeto rtc da classe DS1307
//RTC_DS3231 rtc; //Objeto rtc da classe DS3132

void setup() {
  //-- RTC
  rtc.begin();                                     // Inicia o módulo RTC
  rtc.adjust(DateTime(F(_DATE), F(TIME_)));  // Ajuste Automático de hora e data, executa apenas uma vez dps comenta
  //rtc.adjust(DateTime(2019, 11, 29, 10, 23, 00));   // Ajuste Manual (Ano, Mês, Dia, Hora, Min, Seg)

  //-- Display
  lcd.init();       //Inicializa a comunicação com o display já conectado
  lcd.clear();      //Limpa a tela do display
  lcd.backlight();  //Aciona a luz de fundo do display
}

void loop() {
  DateTime now = rtc.now();

  //Mostrar a hora

  lcd.setCursor(1, 0);            // Posiciona o cursor na primeira linha
  lcd.print("Hora: ");            // Imprime o texto "Hora: "
  lcd.print(rtc.now().hour());    // Imprime a Hora
  lcd.print(":");                 // Imprime o texto entre aspas
  lcd.print(rtc.now().minute());  // Imprime o Minuto
  lcd.print(":");    //Inclusao das bibliotecas
#include "RTClib.h"             // Biblioteca para RTC
#include <Wire.h>               //Biblioteca utilizada gerenciar a comunicação entre dispositicos através do protocolo I2C
#include <LiquidCrystal_I2C.h>  //Biblioteca controlar display 16x2 através do I2C

LiquidCrystal_I2C lcd(0x27, 16, 2);  //Cria o objeto lcd passando como parâmetros o endereço, o nº de colunas e o nº de linhas

//As linhas de codigo a seguir devem ser comentadas, ou descomentadas, de acordo com o modelo de RTC utilizado (DS1307 ou DS3132)
RTC_DS1307 rtc;  //Objeto rtc da classe DS1307
//RTC_DS3231 rtc; //Objeto rtc da classe DS3132

void setup() {
  //-- RTC
  rtc.begin();                                     // Inicia o módulo RTC
  rtc.adjust(DateTime(F(_DATE), F(TIME_)));  // Ajuste Automático de hora e data, executa apenas uma vez dps comenta
  //rtc.adjust(DateTime(2019, 11, 29, 10, 23, 00));   // Ajuste Manual (Ano, Mês, Dia, Hora, Min, Seg)

  //-- Display
  lcd.init();       //Inicializa a comunicação com o display já conectado
  lcd.clear();      //Limpa a tela do display
  lcd.backlight();  //Aciona a luz de fundo do display
}

void loop() {
  DateTime now = rtc.now();

  //Mostrar a hora

  lcd.setCursor(1, 0);            // Posiciona o cursor na primeira linha
  lcd.print("Hora: ");            // Imprime o texto "Hora: "
  lcd.print(rtc.now().hour());    // Imprime a Hora
  lcd.print(":");                 // Imprime o texto entre aspas
  lcd.print(rtc.now().minute());  // Imprime o Minuto
  lcd.print(":");                 // Imprime o texto entre aspas
  lcd.print(rtc.now().second());  // Imprime o Segundo


  //Mostrar a data
  lcd.setCursor(0, 1);           // Posiciona o cursor na segunda linha
  lcd.print("Data: ");           // Imprime o texto entre aspas
  lcd.print(rtc.now().day());    // Imprime o Dia
  lcd.print("/");                // Imprime o texto entre aspas
  lcd.print(rtc.now().month());  // Imprime o Mês
  lcd.print("/");                // Imprime o texto entre aspas
  lcd.print(rtc.now().year());   // Imprime o Ano

  delay(1000);  // Aguarda 1 segundo
  lcd.clear();  //Limpa tela

  /*Caso queira utilizar alarme

  // No comando (now.dayOfTheWeek() == 1) Varia de 0 a 6 onde 0 é domingo e 6 sabado
  if ((now.hour() == 19) && (now.minute() == 39) && (now.dayOfTheWeek() == 1)  ) { 
    lcd.setes tbm
    lcd.clear();//Limpa tela
  }*/
}             // Imprime o texto entre aspas
  lcd.print(rtc.now().second());  // Imprime o Segundo


  //Mostrar a data
  lcd.setCursor(0, 1);           // Posiciona o cursor na segunda linha
  lcd.print("Data: ");           // Imprime o texto entre aspas
  lcd.print(rtc.now().day());    // Imprime o Dia
  lcd.print("/");                
  lcd.print(rtc.now().month());  
  lcd.print("/");                
  lcd.print(rtc.now().year());  

  delay(1000);  
  lcd.clear();  
}