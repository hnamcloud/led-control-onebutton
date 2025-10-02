#include <Arduino.h>
#include <OneButton.h>

#define BUTTON_PIN 18
#define LED_PIN    23

OneButton button(BUTTON_PIN, true);  // true = dùng INPUT_PULLUP
bool ledState = false;
bool blinkMode = false;

void handleClick() {
  // Single click: ON/OFF LED
  blinkMode = false;
  ledState = !ledState;
  digitalWrite(LED_PIN, ledState ? HIGH : LOW);
}

void handleDoubleClick() {
  // Double click: bật/tắt chế độ nhấp nháy
  blinkMode = !blinkMode;
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  button.attachClick(handleClick);
  button.attachDoubleClick(handleDoubleClick);
}

void loop() {
  button.tick();

  if (blinkMode) {
    digitalWrite(LED_PIN, HIGH);
    delay(300);
    digitalWrite(LED_PIN, LOW);
    delay(300);
  }
}
