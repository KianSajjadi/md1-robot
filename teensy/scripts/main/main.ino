#include <Encoder.h>
#include <map.h>
#include <string.h>


double hall_resolution = 341.2;
Encoder motor_1_encoder(14, 15);
Encoder motor_2_encoder(16, 17);
Encoder motor_3_encoder(18, 19);
long motor_1_current_value  = -999;
long motor_2_current_value = -999;
long motor_3_current_value = -999;
long motor_1_new_value, motor_2_new_value, motor_3_new_value;

long read_motor_encoder(Encoder motor_encoder) {
  long motor_new_value;
  new_motor_value = motor_encoder.read();
  return motor_new_value;
}

double get_joint_angle(long motor_current_value) {
  double joint_angle;
  joint_angle = (360/hall_resolution) * motor_current_value;
  return joint_angle;
}

void process_encoder_data(long motor_current_value, long motor_new_value, string motor_name) {
  map<string, long> motor_name_value_pair;
  if (motor_new_value != motor_current_value) {
    motor_current_value = motor_new_value;
    joint_angle = get_joint_angle(motor_current_value);
    motor_name_value_pair[motor_name] = joint_angle;
  }

  Serial.print(motor_name_value_pair)
}


void setup() {
  Serial.begin(9600);
}

void loop() {
  motor_1_new_value = read_motor_encoder(motor_1_encoder);
  process_encoder_data(motor_1_current_value, motor_1_new_value, "motor_1");

  motor_2_new_value = read_motor_encoder(motor_2_encoder);
  process_encoder_data(motor_2_current_value, motor_2_new_value, "motor_2");

  motor_3_new_value = read_motor_encoder(motor_3_encoder);
  process_encoder_data(motor_3_current_value, motor_3_new_value, "motor_3");

}
