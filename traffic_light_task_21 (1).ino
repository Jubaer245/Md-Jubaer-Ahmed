// --- Pin Definitions ---
const int carGreen = 2;
const int carYellow = 3;
const int carRed = 4;
const int pedGreen = 5;
const int pedRed = 6;
const int buttonPin = 7;
// --- Variables ---
bool buttonPressed = false;
void setup() {
pinMode(carGreen, OUTPUT);
pinMode(carYellow, OUTPUT);
pinMode(carRed, OUTPUT);
pinMode(pedGreen, OUTPUT);
pinMode(pedRed, OUTPUT);
pinMode(buttonPin, INPUT_PULLUP);
// Start with Car Green, Pedestrian Red
digitalWrite(carGreen, HIGH);
digitalWrite(carYellow, LOW);
digitalWrite(carRed, LOW);
digitalWrite(pedGreen, LOW);
digitalWrite(pedRed, HIGH);
}
void loop() {
// --- CAR GREEN PHASE ---
digitalWrite(carGreen, HIGH);
digitalWrite(carYellow, LOW);
digitalWrite(carRed, LOW);
digitalWrite(pedGreen, LOW);
digitalWrite(pedRed, HIGH);
// Wait 10 seconds or until button is pressed
for (int i = 0; i < 1000; i++) {
if (digitalRead(buttonPin) == LOW) {
buttonPressed = true;
}
delay(10); // 10 seconds
}
// --- CAR YELLOW PHASE ---
digitalWrite(carGreen, LOW);
digitalWrite(carYellow, HIGH);
digitalWrite(carRed, LOW);
digitalWrite(pedGreen, LOW);
digitalWrite(pedRed, HIGH);
delay(5000); // 5 seconds
// --- PEDESTRIAN GREEN PHASE ---
if (buttonPressed) {
digitalWrite(carGreen, LOW);
digitalWrite(carYellow, LOW);
digitalWrite(carRed, HIGH);
digitalWrite(pedGreen, HIGH);
digitalWrite(pedRed, LOW);
delay(7000); // 7 seconds pedestrian green
buttonPressed = false;
}
// --- BACK TO CAR GREEN ---
digitalWrite(carGreen, HIGH);
digitalWrite(carYellow, LOW);
digitalWrite(carRed, LOW);
digitalWrite(pedGreen, LOW);
digitalWrite(pedRed, HIGH);
}