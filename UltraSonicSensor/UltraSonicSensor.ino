// Prototype Tempat Otomatis Berbasis Arduino
// Sensor Ultrasonic HC-SR04 dan Servo
// Dibuat ole : M.Nofgi Y.P.U.
// www.nofgipiston.wordpress.com
// Tokopedia/Bukalapak : Nofgi Piston Shop
// Mohon dipelajari program yang diberikan agar mendapat ilmu yg bermanfaat :)


// menambahkan lubrary Servo
#include <Servo.h>

// inialisasi variabel untuk servo
Servo servo1;

// inialisasi pin ultrasonic
const int pinTRIGGER = 13;
const int pinECHO = 7;

// inialisasi variabel pembacaan sensor ultrasonic
// gunakan "float" untuk angka dengan koma
// atau gunakan "int" untuk angka tanpa koma
float durasi, jarak;


// ======================= program pengaturan awal ====================== //
void setup()
{
  // inialisasi baud rate serial monitor
  Serial.begin(9600);
  // inialisasi pin servo
  servo1.attach(8);
  // menulis derajat awal servo (menutup)
  servo1.write(0);
  // inialisasi stauts I/O pin
  pinMode(pinTRIGGER, OUTPUT);
  pinMode(pinECHO, INPUT);
  delay(1000);
}


// ============================== program utama ============================= //
void loop()
{
  //pembacaan sesnor ulrasonic
  //Mengaktifak pin Trigger selama 10mikrodetik
  //Lalu dia non aktif
  digitalWrite(pinTRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTRIGGER, LOW);

  //Mengaktifkan pin Echo yang menerima pantulan gelombang ultrasonik
  //pulseIn = Lama durasi pin Echo menerima pantulan gelombang
  //Menghitung rumus jarak(Lama durasi dibagi dua)
  durasi = pulseIn(pinECHO, HIGH);
  jarak = ((durasi * 0.034) / 2);

  // menulis data pembacaan ultrasonic pada serial monitor
  // jadi kita tahu jarak obejak yang terbaca
  
  Serial.print("Jarak: ");
  Serial.println(jarak);


  // program buka tutup servo otomatis
  // jika jarak objek terbaca <= 7 cm
  // ubah dan sesuaikan jarak objek saat buka di sini, satuan cm
  if (jarak <= 7)
  {
    // servo membuka, mnuju derajat 90
    // ubah dan asesuaikan derajat buka di sini
    servo1.write(90);

    // delay membuka servo
    // di sini disetting 3 detik membukanya
    // ubah durasi buka di sini
    delay(3000);

    // servo menutup kembali, menuju derajat 0
    // ubah dan sesuaikan derajat tutup di sini
    servo1.write(0);
}

  // jika jarak objek terbaca lebih dari pernyataan di atas
  else
  {
  // servo menutup, menuju derajat 0
  // ubah dan sesuaikan derajat tutup di sini
  servo1.write(0);
  }
  // delay program
  delay(100);

}