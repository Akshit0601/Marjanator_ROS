cmake_minimum_required(VERSION 2.8.3)
project(mar_gaz_description)

find_package(catkin REQUIRED)

catkin_package()

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
catkin_install_python(PROGRAMS
   src/cmd_vel_sub.py
   src/remap.py
   src/return.py
   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
