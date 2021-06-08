#include <Encoder.h>

double hall_resolution = 341.2;
Encoder motor_1_encoder(14, 15);
Encoder motor_2_encoder(16, 17);
Encoder motor_3_encoder(18, 19);
long motor_1_current_value  = -999;
long motor_2_current_value = -999;
long motor_3_current_value = -999;
long motor_1_new_value, motor_2_new_value, motor_3_new_value;
double joint_angle;

long read_motor_encoder(Encoder motor_encoder) {
  long motor_new_value;
  motor_new_value = motor_encoder.read();
  return motor_new_value;
}

double get_joint_angle(long motor_current_value) {
  joint_angle = ((360 / (hall_resolution * 2)) * motor_current_value) / 4;
  return joint_angle;
}

void process_encoder_data(long motor_current_value, long motor_new_value, int motor_id) {
  if (motor_new_value != motor_current_value) {
    motor_current_value = motor_new_value;
    joint_angle = get_joint_angle(motor_current_value);
    Serial.print(motor_id);
    Serial.print(",");
    Serial.println(joint_angle);
    delay(50);
  }
}


void setup() {
  Serial.begin(57600);
}

void loop() {
  motor_1_new_value = read_motor_encoder(motor_1_encoder);
  process_encoder_data(motor_1_current_value, motor_1_new_value, 1);

  motor_2_new_value = read_motor_encoder(motor_2_encoder);
  process_encoder_data(motor_2_current_value, motor_2_new_value, 2);

  motor_3_new_value = read_motor_encoder(motor_3_encoder);
  process_encoder_data(motor_3_current_value, motor_3_new_value, 3);

}
