# Package_Delivery_System


## Table of Content

- [Introduction](#Introduction)
- [User Guide](#User_Guide)
- [Product&Brand&Category_Segmentation](#Product&Brand&Category_Segmentation)
- [Sales](#Sales)


## Introduction
The purpose of this project is to build a simulation models that simulate a drone picking up a package from a designated location and delivery to the scheduled customer.
The simulation provides users with functionalities to modified the scheduled customer position, delivery package position in the campus, speed of the drone and so on.

## User Guide
This section provides guide to:
    1: How to obtain the code
    2: How to compile the code
    3: How to run the simulation

### How to obtain the code
    Create a new directory using mkdir:
    ```
    $ mkdir 3081_s21
    ```
    cd into the new directory:
    ```
    $ cd 3081_s21
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
    ```
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


## Drone Statistics

    This new feature collectes the data from the simulation and output into csv file.
    The data contains the loactioin for the drone, package and customer, the distance and
    duration time for the drone to pick up the package, the path type choosed by the drone
    and deliever to the customer. The csv files contained in the project folder. And we run code in
    the all_features_no_recharge_station.json

    \image html Statistic_Location.png
    \image latex Statistic_Location.png


    \image html Statistic_Duration.png
    \image latex Statistic_Duration.png


    In this update, we applied singleton pattern to implement the new feature. The most
    difficult part would be figure out how to create only one instance that can be used
    in the wohle namespace. It will be easier to understanding this patter by looking
    at the getInstance function in the StatisticsWriter class and understand the
    meaning of the syntax, static, in C++.
