!!! wajib pakai library MFRC552 dari repository ini ya !!!

untuk komponennya bisa dibeli di link berikut
- esp32 Type C : https://tokopedia.link/rclreN0TjPb
- servo MG90 : https://tokopedia.link/yVygo12TjPb
- RFID Reader : https://tokopedia.link/JaNH3D7TjPb
- Powerbank : https://tokopedia.link/1YNdUaaUjPb
- baterai 18650 : https://tokopedia.link/lDjKvEcUjPb

link 3D Print Coin Dispenser : https://www.thingiverse.com/thing:6441683/files

## Tabel Koneksi Pin Proyek

| **RFID MFRC522**   | **Pin ESP32** | **Fungsi**                                 | **Keterangan**                                     |
|--------------------|---------------|--------------------------------------------|----------------------------------------------------|
|  **SS (SDA)**      | Pin 5         | Slave Select (SPI)                         | Mengatur pemilihan perangkat slave untuk komunikasi SPI. |
|  **RST (RESET)**   | Pin 22        | Reset                                      | Mengatur ulang modul RFID.                         |
|  **MISO**          | Pin 19        | Master In Slave Out                        | Membaca data dari RFID ke ESP32 (SPI).            |
|  **MOSI**          | Pin 23        | Master Out Slave In                        | Mengirim data dari ESP32 ke RFID (SPI).           |
|  **SCK**           | Pin 18        | Serial Clock                               | Mengatur sinkronisasi clock pada komunikasi SPI.  |
|  **VCC**           | 3.3V          | Power                                      | Diberi daya sebesar 3.3V.                         |
|  **GND**           | GND           | Ground                                     | Terhubung ke ground ESP32.                        |

| **Servo Motor**    | **Pin ESP32** | **Fungsi**                                 | **Keterangan**                                    |
|--------------------|---------------|--------------------------------------------|----------------------------------------------------|
|  **Signal (PWM)**  | Pin 13        | Kontrol sudut servo                        | Sinyal PWM untuk mengontrol posisi servo.         |
|  **VCC**           | 5V            | Power                                      | Diberi daya sebesar 5V.                           |
|  **GND**           | GND           | Ground                                     | Terhubung ke ground ESP32.                        |
