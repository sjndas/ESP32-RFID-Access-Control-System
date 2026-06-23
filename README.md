# ESP32-RFID-Access-Control-System
An RFID-based access control system using ESP32 and RC522 RFID reader. Authorized users are granted access through a relay-controlled door lock and automatically relocks after 5 seconds. while unauthorized users are denied. Status messages are displayed on a 16×2 LCD.

## Components Used

* ESP32
* RC522 RFID Reader
* 16×2 LCD
* Relay Module

## Features

* RFID-based authentication
* Access Granted/Denied indication
* Relay-controlled door lock
* LCD status display
* Automatic relocking after 5 seconds

## Software Used

* Arduino IDE
* MFRC522 Library
* LiquidCrystal Library

* ## Connection Diagrams

### RC522 to ESP32
![RC522 Connection](RC522_ESP32_connection.png)

### LCD to ESP32
![LCD Connection](lcd_ESP32_connection.png)

### Relay to ESP32
![Relay Connection](relay_ESP32_connection.png)

## Working Demonstration

### Scan New Card
![Scan New Card](scan_new_card.jpg)

### Getting UID Number
![Getting UID](getting_UID_number.jpg)

### Card Scanning
![Card Scanning](card_scanning.jpg)

### Access Granted
![Access Granted](access_granted.jpg)

### Access Denied
![Access Denied](access_denied.jpg)

## Author

Sajindas M

