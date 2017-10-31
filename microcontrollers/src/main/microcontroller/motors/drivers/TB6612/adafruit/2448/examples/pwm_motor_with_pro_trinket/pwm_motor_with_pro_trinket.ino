
// Setup the motor pins numbers.
#define MOTOR_A_INPUT_1 4
#define MOTOR_A_INPUT_2 8

// Set the modes for the motor pins.
void setup()
{
    Serial.begin(9600);

    pinMode(MOTOR_A_INPUT_1, OUTPUT);
    pinMode(MOTOR_A_INPUT_2, OUTPUT);
}


void loop()
{
    Serial.println("top of the loop");

    digitalWrite(MOTOR_A_INPUT_1, HIGH);
    digitalWrite(MOTOR_A_INPUT_2, LOW);
    delay(1000);
    
    digitalWrite(MOTOR_A_INPUT_1, LOW);
    digitalWrite(MOTOR_A_INPUT_2, LOW);
    delay(1000);
    
    digitalWrite(MOTOR_A_INPUT_1, LOW);
    digitalWrite(MOTOR_A_INPUT_2, HIGH);
    delay(1000);
}