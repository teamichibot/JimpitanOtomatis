#include <SPI.h>
#include <MFRC522.h>
#include <ESP32Servo.h>

// Pin konfigurasi RFID
#define SS_PIN 5
#define RST_PIN 22
MFRC522 rfid(SS_PIN, RST_PIN);

// Konfigurasi Servo
static const int servoPin = 13;
Servo servo1;

// ID kartu RFID yang diizinkan
String allowedCard = "4 8 27 3A 1E 78 80"; // Ganti dengan UID kartu Anda (dapatkan dari Serial Monitor)

// Fungsi setup
void setup() {
  Serial.begin(115200);

  // Inisialisasi RFID
  SPI.begin();
  rfid.PCD_Init();
  Serial.println("RFID siap!");

  // Inisialisasi Servo
  servo1.attach(servoPin);
  servo1.write(0); // Posisi awal servo
  Serial.println("Servo siap!");
}

// Fungsi loop
void loop() {
  // Periksa apakah kartu terdeteksi
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    delay(50); // Tunggu sejenak sebelum mencoba lagi
    return;
  }

  // Dapatkan UID kartu yang dibaca
  String cardUID = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    cardUID += String(rfid.uid.uidByte[i], HEX);
    if (i < rfid.uid.size - 1) cardUID += " ";
  }
  cardUID.toUpperCase(); // Ubah ke huruf kapital untuk konsistensi

  Serial.print("Kartu terdeteksi dengan UID: ");
  Serial.println(cardUID);

  // Cek apakah kartu diizinkan
  if (cardUID == allowedCard) {
    Serial.println("Akses diizinkan!");
    moveServo();
  } else {
    Serial.println("Akses ditolak!");
  }

  // Berhenti membaca kartu saat ini
  rfid.PICC_HaltA();
  delay(1000); // Hindari pembacaan berulang terlalu cepat
}

// Fungsi untuk menggerakkan servo
void moveServo() {
  Serial.println("Menggerakkan servo...");
  servo1.write(0);    // Posisi awal
  delay(500);
  servo1.write(170);  // Gerakkan ke 150 derajat
  delay(500);
  servo1.write(0);    // Kembali ke posisi awal
  delay(500);
}
