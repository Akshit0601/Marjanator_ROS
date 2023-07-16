
# Marjanator

An ROS-enabled automated USV designed to automate the process of cleaning large lakes

## Capabilities
1. Automated cleaning using smart detection using detection model based on openCV and yoloV5(will be release soon)

2. Mapping - It can also be used for mapping 


## Requirements

1. Must have ROS(noetic) installed.
2. Packages :
[teleop_twist_keyboard](https://github.com/ros-teleop/teleop_twist_keyboard.git)
[rosserial](https://github.com/frankjoshua/rosserial_arduino_lib.git)
## Installation

Install dependencies using rosdep

```bash
 rosdep install --from-paths src --ignore-src -r -y

```
    
## Running
#### uploading arduino code in src/ros_marja.ino
### sourcing the workspace
```bash
source [workspace path]/devel/setup.sh
```
 ### Launching gazebo simulation 

 ```bash
 roslaunch mar_gaz_description gazebo.launch
 ```

 ### Launch Teleop_Twist_keyboard
```bash
rosrun teleop_twist_keyboard teleop_twist_keyboard.py cmd_vel:=mobile_base_controller/cmd_vel
```
### Launching Serial Node
```bash
rosrun rosserail_arduino serial_node.py __path:=/dev/cu.modem1101 
# [insert your own serial port here connected to your arduino]
```

### To Get a rough path traced by marjanator
```bash
rosrun mar_gaz_description remap.py 
rosrun turtlesim turtlesim_node
```
### To get IMU data
```bash
rostopic echo /imu
```
## 🔗 Links

[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/akshit-shishodia-631aab23a/)



