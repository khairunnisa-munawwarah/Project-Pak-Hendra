#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Konfigurasi WiFi
char auth[] = "PQQkQvSr8RilCzfqZQax0eAftj3ZkaIZ";
char ssid[] = "WIFI";
char pass[] = "12345678";

// Konfigurasi pin relay dan sensor suara
const int relay = D7;
const int Sensor = D6;

int x = 0;
int y = 0;

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(relay, OUTPUT);
  pinMode(Sensor, INPUT);

  // Mematikan relay dan mengirim status awal ke Blynk
  digitalWrite(relay, HIGH);
  Blynk.virtualWrite(V1, "Lampu Mati");
}

void loop() {
  Blynk.run();
  x = digitalRead(Sensor);
  y = digitalRead(relay);

  // Menghidupkan atau mematikan relay berdasarkan nilai sensor suara
  if (y == LOW && x == LOW) {
    digitalWrite(relay, HIGH);
    Blynk.virtualWrite(V1, "Lampu Hidup");
  }
  if (y == HIGH && x == LOW) {
    digitalWrite(relay, LOW);
    Blynk.virtualWrite(V1, "Lampu Mati");
  }
}
