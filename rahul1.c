//Program


int leds[] = {2, 3, 4, 5, 6};   // LED pins
int numLeds = 5;                // Number of LEDs
int delayTime = 200;            // Speed of blinking (ms)

void setup() {
    // Set all LED pins as output
    for (int i = 0; i < numLeds; i++) {
        pinMode(leds[i], OUTPUT);
    }
}

void loop() {
    // Forward direction (left to right)
    for (int i = 0; i < numLeds; i++) {
        digitalWrite(leds[i], HIGH);
        delay(delayTime);
        digitalWrite(leds[i], LOW);
    }

    // Reverse direction (right to left)
    for (int i = numLeds - 2; i > 0; i--) {
        digitalWrite(leds[i], HIGH);
        delay(delayTime);
        digitalWrite(leds[i], LOW);
    }
}
