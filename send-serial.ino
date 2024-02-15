// If the X and Y values of the joystick go over/under these limits, the mouse moves
#define R_THRESHOLD 800
#define L_THRESHOLD 400
#define D_THRESHOLD 800
#define U_THRESHOLD 400

#define VRX_PIN  A1 // Arduino pin connected to VRX pin
#define VRY_PIN  A0 // Arduino pin connected to VRY pin

int xValue = 0; // To store value of the X axis
int yValue = 0; // To store value of the Y axis

int bi = 0;
void setup() {

  //Put pins in input mode
  pinMode(VRX_PIN, INPUT);
  pinMode(VRY_PIN, INPUT);

  Serial.begin(9600);

}

void loop() {

  // read analog X and Y analog values
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);

  //Uniquely encodes the desired direction in an integer
  bi = 0;
  if (xValue < L_THRESHOLD) {
    bi = bi + 1;
  }
  if (xValue > R_THRESHOLD) {
    bi = bi+2;
  }
  if (yValue < U_THRESHOLD) {
    bi = bi+10;
  }
  if (yValue > D_THRESHOLD) {
    bi=bi+20;
  }

  //Writes the desired direction to Serial
  switch(bi) {
    case 1:
      Serial.println("LEFT");
      break;
    case 2:
      Serial.println("RIGHT");
      break;
    case 10:
      Serial.println("UP");
      break;
    case 20:
      Serial.println("DOWN");
      break;
    case 11:
      Serial.println("UPLEFT");
      break;
    case 12:
      Serial.println("UPRIGHT");
      break;
    case 21:
      Serial.println("DOWNLEFT");
      break;
    case 22:
      Serial.println("DOWNRIGHT");
      break;
  }

  //Delays so we don't write faster than python executes
  delay(100);
}