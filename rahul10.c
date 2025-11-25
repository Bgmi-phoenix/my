//Program

/*  
   UART String Transmission Example
   Board: Arduino Uno
   TX -> Pin 1
   RX -> Pin 0
*/

void setup() {
    // Initialize UART at 9600 baud
    Serial.begin(9600);

    // Wait for Serial Monitor to open (optional, for debugging)
    while (!Serial) {
        ; // Wait
    }

    // Send an initial string
    Serial.println("UART Communication Started!");
}

void loop() {
    // Transmit a string every 2 seconds
    Serial.println("Hello, UART! This is Arduino Uno transmitting.");
    delay(2000);
}


/*  
   UART Receiver
   Arduino Uno #2
   TX -> Pin 1
   RX -> Pin 0
*/

void setup() {
    Serial.begin(9600);  // UART at 9600 baud
}

void loop() {
    if (Serial.available() > 0) {   // Check if data is available
        String received = Serial.readStringUntil('\n');  // Read until newline
        Serial.print("Received: ");
        Serial.println(received);   // Display on Serial Monitor
    }
}
