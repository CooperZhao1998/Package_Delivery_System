# Package_Delivery_System


## Table of Content

- [Introduction](#Introduction)
- [User Guide](#User_Guide)
- [Features Describtion](#Features_Describtion)


## Introduction
The goal of this software project is to produce a package delivery system in which the simulation can be controlled via external configuration (without code change) and be visualized on a web browser. The simulation of this package delivery system is using three.js to create a 3D model of the University of Minnesota campus.
In package delivery system, the robot/drone can detect the package, pick it up and deliver it to the designed customer in different speed and using different roue. 
It provides users with functionalities to modified the scheduled customer position, delivery package position in the campus, speed of the drone and so on.



## User Guide
This section provides guide to:
- How to obtain the code
- How to compile the code
- How to run the simulation

### How to obtain the code
Create a new directory using mkdir:

    $ mkdir Package_Delivery_System
    
    ```
cd into the new directory:

    $ cd Package_Delivery_System
    ```
Use git clone to clone the remote repository, username and password will be required to gain full access to the repository:
    ```
    $ git clone https://github.umn.edu/umn-csci-3081-s21/repo-zhan5684.git
    ```

### How to compile the code
Navigate to base repo directory:
    ```
    $ cd repo-zhan5684
    ```
Run docker, you need to configured dockers before using this command, and dos2unix can be used to convert file to readable format for docker.

    $ bin/build-env.sh
    

    $ bin/run-env.sh
    ```
After successfully setup and ran the docker server, cd into the project folder
    ```
    $ cd project
    ```
Use make
    ```
    $ make
    ```

### How to run the code
in the project directory, run the docker file
    ```
    $ bin/run.sh scenes/all_features_no_recharge_station.json
    ```
The server is successfully started, open browser and type in the server address
    ```
    127.0.0.1:8081
    ```

we pick to complete the Drone statistic, the csv files will generated in the project/ folder once the delivery simulation complete.


## Features Describtion

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
