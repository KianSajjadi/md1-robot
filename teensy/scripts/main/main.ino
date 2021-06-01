#include <Encoder.h>


double hall_resolution = 341.2;
Encoder motor_1_encoder(9, 10);
Encoder motor_2_encoder();
Encoder motor_3_encoder();

long positionLeft  = -999;
long positionRight = -999;

void setup() {
  Serial.begin(9600);

}

void loop() {
	long test;
	double motor_angle;
  test = motor_1_encoder.read();
	if (test != positionLeft) {
		motor_angle = (360/hall_resolution)*test;z
		Serial.print("Left = ");
		Serial.print(motor_angle);
		Serial.print("degrees");
		Serial.println();
		positionLeft = test;
	}

	if (Serial.available()) {
		Serial.read();
		Serial.println("reset");
		motor_1_encoder.write(0);
	}

}
