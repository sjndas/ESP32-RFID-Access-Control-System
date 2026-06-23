#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
#define SS_PIN 5
#define RST_PIN 22
#define RELAY_PIN 27

MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal lcd(13, 12, 14, 26, 25, 33);

byte authorizedUID[] = {0xB1, 0x7C, 0xF3, 0x06};

void setup()
{ SPI.begin();
  rfid.PCD_Init();
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Scan Your Card");}

void loop()
{if (!rfid.PICC_IsNewCardPresent())
 return;
if (!rfid.PICC_ReadCardSerial())
 return;
bool accessGranted = true;

for (byte i = 0; i < 4; i++)
{if (rfid.uid.uidByte[i] != authorizedUID[i])
 {accessGranted = false;
 break;}}

if (accessGranted)
{lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Access Granted");
digitalWrite(RELAY_PIN, HIGH);
lcd.setCursor(0, 1);
lcd.print("Opening..");
delay(5000);
digitalWrite(RELAY_PIN, LOW);
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Scan Your Card");}
  
else
{lcd.clear();
lcd.setCursor(0,0);
lcd.print("Access Denied");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Scan Your Card");}

while (rfid.PICC_IsNewCardPresent())
{delay(50);}

rfid.PICC_HaltA();
rfid.PCD_StopCrypto1();
}
