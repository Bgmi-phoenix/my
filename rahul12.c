#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String buffer = "";
const unsigned int MAX_BUFFER = 200;

void setup() {
  Serial.begin(9600);
  Serial.println(F("=== Keypad Keystroke Recorder ==="));
  Serial.println(F("Press keys on keypad."));
  Serial.println(F("Special keys:"));
  Serial.println(F("  # ? Show recorded keys"));
  Serial.println(F("  * ? Clear recorded keys"));
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    unsigned long ts = millis();

    Serial.print("Key pressed: ");
    Serial.print(key);
    Serial.print(" - Time (ms): ");
    Serial.println(ts);

    if (buffer.length() < MAX_BUFFER) {
      buffer += key;
    }

    if (key == '#') {
      Serial.print("Recorded sequence: ");
      Serial.println(buffer);
    } else if (key == '*') {
      buffer = "";
      Serial.println(F("Buffer cleared!"));
    }
  }
}
