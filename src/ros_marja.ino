#include <ros.h>

#include <geometry_msgs/Twist.h>

#include <ros.h>
 
#define ENA 3
#define IN1 5
#define IN2 4
#define ENB 9
#define IN3 10
#define IN4 11
//#define auto_l 6
//#define auto_r 7

int speed1 = 0;
int speed2 = 0;

int dir1 = 1;
int dir2 = 1;

ros :: NodeHandle nh;
float linear_vel = 0;
float ang_vel = 0;
void cmd_vel_callback(const geometry_msgs::Twist& cmd_vel_msg){
   linear_vel = cmd_vel_msg.linear.x;
   ang_vel = cmd_vel_msg.angular.z; 
}
void mControl1(int mspeed,int mdir){
  if(mdir ==0){
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    
  }
  else{
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
  }
  analogWrite(ENA,mspeed); 
}
void mControl2(int mspeed,int mdir){
  if(mdir ==0){
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    
  }
  else{
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
  }
  analogWrite(ENB,mspeed);  
}

ros::Subscriber<geometry_msgs::Twist> cmd_vel_sub("/mobile_base_controller/cmd_vel", cmd_vel_callback);

void setup() {
  nh.initNode();
  nh.subscribe(cmd_vel_sub);
  pinMode(ENA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENB,OUTPUT);
  
  
 
}

void loop() {
  // put your main code here, to run repeatedly:
  nh.spinOnce();
  if(linear_vel > 0 && ang_vel > 0 ){
    int vel = linear_vel * 50;
    mControl1(vel,1);
    mControl2(vel,0);
    
  }
  else if(linear_vel > 0 && ang_vel == 0){
    int vel = linear_vel * 50;
    mControl1(vel,1);
    mControl2(vel,1);
  }
   else if(linear_vel > 0 && ang_vel < 0){
    int vel = linear_vel * 50;
    mControl1(vel,0);
     mControl2(vel,1);
  }
   else if(linear_vel == 0 && ang_vel < 0){
    int vel = ang_vel * 50;
    mControl1(vel,1);
    mControl2(vel,1);
  }
   else if(linear_vel == 0 && ang_vel == 0){
    int vel = 0;
    mControl1(vel,0);
    mControl2(vel,1);
  }
   else if(linear_vel < 0 && ang_vel < 0) {
    int vel = linear_vel * 50;
    mControl1(vel,0);
    mControl2(vel,0);
  }
   else if(linear_vel < 0 && ang_vel == 0){
    int vel = linear_vel * 50;
    mControl1(vel,0);
    mControl2(vel,0);
  }
   else if(linear_vel == 0 && ang_vel > 0){
    int vel = ang_vel * 50;
    mControl1(vel,0);
    mControl2(vel,0);
  }
  
  
  
  
  
  
  

}
