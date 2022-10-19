// Arduino_simultaneous_button_push.ino 

// Using Analogue Input to return values from resitors conected to more tnan one switch. Values returned by resistor voltage divider type simple circuit

// Buttons, switches may be pressed at the same time i.e. Simultaneous Button push, or separtly

// Buttons presseed Analogue Input

// I am using a CNC Shield 3 on a Arduino  Uno.

// CNC Shield 3.3 Volts, even 5 V pins supply only 3.3 Volts
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
int Analogue_input_pin = A0;  // A0 Analogue pin of the Arduino is connected with the Abort pin of the CNC shield.

int Analogue_value_returned = 0;

bool button_pressed_state;

void setup() {
  Serial.begin(115200);  // Standard is 9600 Serial Monitor display

  pinMode(Analogue_input_pin, INPUT);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {
  // Read the value from the sensor:  values returned by resistor voltage devider.  Using resistors to return different values between one each button and both buttons presses range for Analogue reading. Strictly, its range is from 0 to 1023.

  button_pressed_state = false;  // Reset button pressed state pin

  // Ref: https://jumbleat.com/en/2016/08/17/reduce_fluctuations/
  Analogue_value_returned = analogRead(Analogue_input_pin);

  if (Analogue_value_returned > 480 && Analogue_value_returned < 540) {
    Serial.println("    BOTH buttons Pressed");
    button_pressed_state = true;
  }

  if (Analogue_value_returned > 320 && Analogue_value_returned < 360) {
    Serial.println("    Left button Pressed");
    button_pressed_state = true;
  }

  if (Analogue_value_returned > 640 && Analogue_value_returned < 720) {
    Serial.println("   Right button Pressed");
    button_pressed_state = true;
  }

  if (!button_pressed_state) {

    Serial.println("No button Pressed");
  }

  Serial.println();
  Serial.println();

  delay(500);
}