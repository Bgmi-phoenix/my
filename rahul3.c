#define TRIG 9
#define ECHO 10
#define BUZZER 5
#define LED 6

long duration;
int distance;
const int distanceThreshold = 50; // cm

void setup() {
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    pinMode(BUZZER, OUTPUT);
    pinMode(LED, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    // --- Measure Distance ---
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

    duration = pulseIn(ECHO, HIGH);
    distance = duration * 0.034 / 2;  // cm

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // --- Intrusion Logic ---
    if (distance > 0 && distance <= distanceThreshold) {
        Serial.println("⚠ ALERT! Intruder Detected!");
        digitalWrite(BUZZER, HIGH);
        digitalWrite(LED, HIGH);
    } else {
        digitalWrite(BUZZER, LOW);
        digitalWrite(LED, LOW);
    }

    delay(200);
}
