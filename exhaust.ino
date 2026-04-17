#define BLYNK_TEMPLATE_ID "TMPL302pkdFWB"
#define BLYNK_TEMPLATE_NAME "exhaust automation"
#define BLYNK_AUTH_TOKEN "-hBNodaG6oULt49Zm5YujRxyys29LUmR"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

// ----- Pins -----
#define DHTPIN D3
#define DHTTYPE DHT11
#define MQ135_PIN A0
#define FAN_EN D5
#define FAN_IN1 D1
#define FAN_IN2 D2

// ----- Sensor Objects -----
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

// ----- Thresholds -----
float tempThreshold = 27.0;
int smokeThreshold = 350;

// ----- Wi-Fi Credentials -----
char ssid[] = "Appi";
char pass[] = "Appi@2005";

// ----- State Flags -----
bool fanState = false;
bool tempAlertSent = false;
bool smokeAlertSent = false;

void readSensors() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int smoke = analogRead(MQ135_PIN);

  // Handle sensor read errors
  if (isnan(temp) || isnan(hum)) {
    Serial.println("DHT sensor error!");
    return;
  }

  // Send data to Blynk dashboard
  Blynk.virtualWrite(V1, temp);   // Temperature
  Blynk.virtualWrite(V2, hum);    // Humidity
  Blynk.virtualWrite(V3, smoke);  // Smoke level

  Serial.print("Temp: "); Serial.print(temp); Serial.print(" °C");
  Serial.print(" | Humidity: "); Serial.print(hum); Serial.print(" %");
  Serial.print(" | Smoke: "); Serial.println(smoke);

  // ---- FAN CONTROL ----
  if (temp >= tempThreshold || smoke >= smokeThreshold) {
    if (!fanState) {
      fanState = true;
      digitalWrite(FAN_EN, HIGH);
      digitalWrite(FAN_IN1, HIGH);
      digitalWrite(FAN_IN2, LOW);
      Blynk.virtualWrite(V4, 1);
      Serial.println("Fan: ON");
    }
  } else {
    if (fanState) {
      fanState = false;
      digitalWrite(FAN_EN, LOW);
      digitalWrite(FAN_IN1, LOW);
      digitalWrite(FAN_IN2, LOW);
      Blynk.virtualWrite(V4, 0);
      Serial.println("Fan: OFF");
    }
  }

  // ---- NOTIFICATION LOGIC ----
  if (temp >= tempThreshold && !tempAlertSent) {
    Blynk.logEvent("temp_alarm", "High temperature detected in kitchen!");
    tempAlertSent = true;
    Serial.println("ALERT: Temperature high! Notification sent.");
  }
  if (temp < tempThreshold - 1 && tempAlertSent) {
    tempAlertSent = false; // reset flag when temperature normalizes
  }

  if (smoke >= smokeThreshold && !smokeAlertSent) {
    Blynk.logEvent("Smoke_Alarm", "High smoke level detected in kitchen!");
    smokeAlertSent = true;
    Serial.println("ALERT: Smoke level high! Notification sent.");
  }
  if (smoke < smokeThreshold - 20 && smokeAlertSent) {
    smokeAlertSent = false; // reset flag when smoke clears
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(FAN_EN, OUTPUT);
  pinMode(FAN_IN1, OUTPUT);
  pinMode(FAN_IN2, OUTPUT);

  digitalWrite(FAN_EN, LOW);
  digitalWrite(FAN_IN1, LOW);
  digitalWrite(FAN_IN2, LOW);

  dht.begin();

  // Connect to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.println("Connecting to WiFi and Blynk...");

  // Sensor reading every 1.5 seconds
  timer.setInterval(1500L, readSensors);
}

void loop() {
  Blynk.run();
  timer.run();
}