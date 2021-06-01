import time
from adafruit_motorkit import MotorKit
import serial

kit = MotorKit()
motor_1 = kit.motor1
motor_2 = kit.motor2
motor_3 = kit.motor3

#Serial comms to teensy
def get_current_joint_angle(motor):
  ser = serial.Serial(port='/dev/ttyACM0')
  return current_joint_angle
#Serial comms to teensy
def drop_ball_in_servo(servo):
  ser = serial.Serial(port='/dev/ttyACM0')

def go_to_joint_angle(motor, goal_angle, tolerance):
  current_joint_angle = get_current_joint_angle(motor)
  angle_to_move = goal_angle - current_joint_angle #this can be negative, meaning the motor must move in the opposite direction, this should also act as a very primitive control system to keep the arm in one position and will cause alot of transience
  while abs(angle_to_move) > tolerance: #the smaller the tolerance, the closer the motor arm will get to the position it should be at
    #motor will start at throttle of 100% and decelerate depending on how close it is to the goal angle
    if (angle_to_move > 0):
      motor.throttle = 1 - (current_joint_angle/goal_angle)
    if (angle_to_move < 0):
      motor.throttle = -1 * (1 - (current_joint_angle/goal_angle))
    #update arm angle
    current_joint_angle = get_current_joint_angle(motor)
    #update the amount the motor has to move the arm
    angle_to_move = goal_angle - current_joint_angle

def stop_motor(motor)
  motor.throttle = 0

def emergency_stop()
  motor_1.throttle = 0
  motor_2.throttle = 0
  motor_3.throttle = 0

if __name__ == "__main__":
  #set this to an angle, expressed in degrees, so that we get this close to where the robot arm should be. This should help eliminate transience in the motion
  tolerance = 5

  #step one, get to first silo
  arm_1_goal_angle = 
  arm_2_goal_angle = 
  arm_3_goal_angle =
  #step two, get to second silo
  arm_1_goal_angle = 
  arm_2_goal_angle = 
  arm_3_goal_angle = 
  #step three, get to third silo, this may include fourth silo too
  arm_1_goal_angle = 
  arm_2_goal_angle = 
  arm_3_goal_angle = 
  #step four, get to fourth silo
  arm_1_goal_angle = 
  arm_2_goal_angle = 
  arm_3_goal_angle = 