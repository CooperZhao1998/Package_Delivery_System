# Package_Delivery_System


## Table of Content

- [Introduction](#Introduction)
- [Compiltion Guide](#Compiltion_Guide)
- [Features Describtion](#Features_Describtion)


## Introduction
The goal of this software project is to produce a package delivery system in which the simulation can be controlled via external configuration (without code change) and be visualized on a web browser. The simulation of this package delivery system is using three.js to create a 3D model of the University of Minnesota campus.
In package delivery system, the robot/drone can detect the package, pick it up and deliver it to the designed customer in different speed and using different roue. 
It provides users with functionalities to modified the scheduled customer position, delivery package position in the campus, speed of the drone and so on.



## Compiltion_Guide


### Pre-requisites
  * [Git](https://git-scm.com/)

### Docker Pre-requisites
  * Windows 10 Home
    * Install [wsl2 and Ubuntu](https://www.youtube.com/watch?v=ilKQHAFeQR0&list=RDCMUCzLbHrU7U3cUDNQWWAqjceA&start_radio=1&t=7)
  * Install [Docker Desktop](https://hub.docker.com/?overlay=onboarding) from [Docker Hub](https://hub.docker.com/)
  * Linux
    * Use [docker group instead of sudo](https://www.digitalocean.com/community/tutorials/how-to-install-and-use-docker-on-ubuntu-18-04)



### How to compile the code
1. Use git clone to clone the remote repository, username and password will be required to gain full access to the repository:

    ```bash
    git clone https://github.com/CooperZhao1998/Package_Delivery_System.git
    ```
    
2. Navigate to base repo directory:

    ```bash
    cd Package_Delivery_System
    ```

3. Build docker image

    ```bash
    bin/build-env.sh
    ```

4. Run docker image

    ```bash
    bin/run-env.sh
    ```

5. After successfully setup and ran the docker server, now you are inside the docker image. 
Next, build the project web server

    ```bash
    cd project
    make
    ```
    
6. Run web server (inside docker image)

    ```bash
    bin/run.sh
    ```

7. To run the web server on specific scene(eg., all_features_no_recharge_station.json)
    
    ```bash
    bin/run.sh scenes/<name_of_scene_file>
    ```
8. Open up browser and browse to 

    ```bash
    http://127.0.0.1:8081/
    ```



## Features_Describtion

### Statistics feature 
Drone Statistics feature collectes the data from the simulation and output into csv file. The data contains the loactioin for the drone/robot, package and customer, the distance and duration time for the drone/robot to pick up the package, the path type choosed by the drone and deliever to the customer. The csv files contained in the project folder. This project was applied singleton pattern to implement this feature. 

### Reporting features
The drones/robots were implemented reporting features in observer pattern to report when a package is scheduled, delivered, or enroute to all of the observers.
In addition, it also could report when the drones/robots are moving or idle. If the battery of either the robot or the drone is depleted the package will be dropped, rescheduled for delivery, and the robot or drone will be idle. The purpose of implement observer patterns in this project is to notify users when the state of the drone/robot/package has changed.

### Route planning features
The project was implement with a route planning features for drone. The drone will be choosing a route using one of three routes: shortest path algorithm, beeline, or parabolic based upon differing sets of criteria, 
And, the design of route planning in this project was implemented in strategy pattern.

### Google Test and Doxygen
This project was implemented with Unit Testing with Google Test, and Doxygen which could generate web pages to show the structure of this project.
