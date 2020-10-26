#include "esp_camera.h"
#include <WiFi.h>
#define CAMERA_MODEL_ESP_EYE

#include "camera_pins.h"

const char* ssid = "esp-eye-9d25";
const char* password = "";

void startCameraServer();

void setup() {
  // put your setup code here, to run once:
#if defined(CAMERA_MODEL_ESP_EYE)
  pinMode(13, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
#endif

 // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }

 WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");


}

void loop() {
  // put your main code here, to run repeatedly:

}
