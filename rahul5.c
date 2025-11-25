//Program

// Define the pin where the LDR is connected
const int ldrPin = A0;

// Define the pin where the LED is connected
const int ledPin = 9;

void setup() {
    // Initialize serial communication
    Serial.begin(9600);

    // Set the LED pin as an output
    pinMode(ledPin, OUTPUT);
}

void loop() {
    // Read the analog value from the LDR
    int ldrValue = analogRead(ldrPin);

    // Print the analog value to the Serial Monitor
    Serial.print("LDR Value: ");
    Serial.println(ldrValue);

    // Check if it's dark (adjust threshold as needed)
    if (ldrValue > 200) {
        // If it's dark, turn on the LED
        digitalWrite(ledPin, HIGH);
    } else {
        // If it's not dark, turn off the LED
        digitalWrite(ledPin, LOW);
    }

    // Wait for a short delay before taking the next reading
    delay(1000);
}
