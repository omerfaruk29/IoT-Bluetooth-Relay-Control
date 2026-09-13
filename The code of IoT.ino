/*
 * Proje: Bluetooth / Ses Kontrollü 220V Lamba Otomasyonu
 * Yazar: [Ömer Faruk YIĞCI]
 * Açıklama: Arduino UNO, HC-05/06 Bluetooth modülü ve 5V Röle kartı 
 *           kullanılarak 220V şebeke yükünün güvenli kontrolü.
 */

#include <SoftwareSerial.h>

// Pin Tanımlamaları
const int BT_RX = 2;       // Arduino Pin 2 -> Bluetooth TX
const int BT_TX = 3;       // Arduino Pin 3 -> Bluetooth RX
const int RELAY_PIN = 7;   // Arduino Pin 7 -> Röle IN

// SoftwareSerial Nesnesi
SoftwareSerial BTSerial(BT_RX, BT_TX);

// Değişkenler
char incomingCommand;

void setup() {
  // Seri Haberleşme Başlatma
  Serial.begin(9600);    // Bilgisayar Seri Port İzleyici
  BTSerial.begin(9600);  // Bluetooth Modülü İletişimi

  // Röle Pin Konfigürasyonu
  pinMode(RELAY_PIN, OUTPUT);
  
  // Güvenlik Başlangıç Durumu (Active-LOW Röleler İçin)
  // Güç verildiğinde rölenin anlık tetiklenmesini önler.
  digitalWrite(RELAY_PIN, HIGH); 
  
  Serial.println("SYSTEM: IoT Röle Kontrol Sistemi Hazir.");
}

void loop() {
  // Bluetooth Üzerinden Veri Geldi mi?
  if (BTSerial.available() > 0) {
    incomingCommand = BTSerial.read();
    
    switch (incomingCommand) {
      case '1':
        digitalWrite(RELAY_PIN, LOW); // Röle aktif (Lamba AÇIK)
        BTSerial.println("STATE: LAMP_ON");
        Serial.println("LOG: Lamba Acildi.");
        break;
        
      case '0':
        digitalWrite(RELAY_PIN, HIGH); // Röle pasif (Lamba KAPALI)
        BTSerial.println("STATE: LAMP_OFF");
        Serial.println("LOG: Lamba Kapatildi.");
        break;

      default:
        // Tanımsız komut durumu
        break;
    }
  }
}