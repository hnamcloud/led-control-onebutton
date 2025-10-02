#include <Arduino.h>
#include <OneButton.h>

#define BUTTON_PIN 18  // chân nút nhấn
#define LED_PIN 23      // LED ngoài (chân GPIO2 trên ESP32)

OneButton button(BUTTON_PIN, true); // true = dùng INPUT_PULLUP

bool ledState = false;

void singleClick() {
  ledState = !ledState;
  digitalWrite(LED_PIN, ledState ? HIGH : LOW);
}

void setup() {
  pinMode(LED_PIN, OUTPUT);

  button.attachClick(singleClick);
}

void loop() {
  button.tick(); // phải gọi liên tục
}
