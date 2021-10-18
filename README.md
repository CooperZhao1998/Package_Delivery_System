# Package_Delivery_System

/*! \mainpage CSCI 3081 Delivery Simulation project
*



## Table of Content

- [Data](#Data)
- [User_Segmentation](#User_Segmentation)
- [Product&Brand&Category_Segmentation](#Product&Brand&Category_Segmentation)
- [Sales](#Sales)


## Introduction
The purpose of this project is a simulation models that simulate a amazon drone picking up a package from a designated location and delivery to the scheduled customer.
The simulation provides users with functionalities to modified the scheduled customer position, delivery package position in the campus, speed of the drone and so on.

## User Guide and Introduction
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

    ## How to compile the code
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

    ## How to run the code
    in the project directory, run the docker file
    ```
    $ bin/run.sh scenes/all_features_no_recharge_station.json
    ```
    The server is successfully started, open browser and type in the server address
    ```
    127.0.0.1:8081
    ```

    we pick to complete the Drone statistic, the csv files will generated in the project/ folder once the delivery simulation complete.


*\section functionality Drone Statistics

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


*\section teamwork1 Iteration 3 Team Documentation


    ## Implement StatisticsWriter Class

    Leader: Yuancan Zhang(zhan5684)

    Date:
    April 25th

    Who you worked with:
    Tian Liu(liu00839), Zhenyu Yang(yang6067), Cooper Zhao(zhao0888)

    What you needed help with:
    Chooes fuunctionality


    Date:
    April 26th & 27th

    Who you worked with:
    Tian Liu(liu00839), Zhenyu Yang(yang6067), Cooper Zhao(zhao0888)

    What you needed help with:
    Implement methods for the StatisticsWriter class.



    ## Add GoogleTest

    Leader: Tian Liu(liu00839)

    Date:
    April 28th

    Who you worked with:
    Zhenyu Yang(yang6067), Yuancan Zhang(zhan5684),  Cooper Zhao(zhao0888)

    What you needed help with:
    Writing the google test for the StatisticsWriter class.



    ## Writing Doxygen mainpage

    Leader: Zhenyu Yang(yang6067)

    Date:
    March 29th

    Who you worked with:
    Tian Liu(liu00839), Yuancan Zhang(zhan5684),  Cooper Zhao(zhao0888)

    What you needed help with:
    Figure out the advantages of Singleton pattern and update the mainpage file.



    ## Class Description

    Leader: Cooper Zhao(zhao0888)

    April 29th

    Who you worked with:
    Zhenyu Yang(yang6067), Yuancan Zhang(zhan5684),  Tian Liu(liu00839)

    What you needed help with:
    Write the class description and check out if there any bugs in the code.



*\section teamwork2 Iteration 2 Team Documentation

    ## Priority Level 1-groupwork

    Leader: Yuancan Zhang(zhan5684)
    Date:
    March 30th

    Who you worked with:
    Tian Liu(liu00839), Zhenyu Yang(yang6067), Cooper Zhao(zhao0888)

    What you needed help with:
    Implement methods for the Robot class.


    Date:
    March 31st

    Who you worked with:
    Tian Liu(liu00839), Zhenyu Yang(yang6067), Cooper Zhao(zhao0888)

    What you needed help with:
    Writing Google test for the Robot Class.


    ## Prority Level 2-groupwork

    Leader: Zhenyu Yang(yang6067)

    Date:
    March 30th

    Who you worked with:
    Tian Liu(liu00839), Yuancan Zhang(zhan5684),  Cooper Zhao(zhao0888)

    What you needed help with:
    Figure out the logic for the observer pattern and implementing multiple drones/robots in this project


    Date:
    March 31st

    Who you worked with:
    Tian Liu(liu00839), Yuancan Zhang(zhan5684), Cooper Zhao(zhao0888)

    What you needed help with:
    Implement the observer pattern of package part, and deliever multiple packages.


    Date:
    April 1st

    Who you worked with:
    Tian Liu(liu00839), Yuancan Zhang(zhan5684), Cooper Zhao(zhao0888)

    What you needed help with:
    Finish the oberver pattern and run on the drone_and_robot_many_deliveries.json


    ## Prority Level 3-groupwork

    Date:
    April 16th

    Who you worked with:
    Tian Liu(liu00839), Yuancan Zhang(zhan5684),  Zhenyu Yang(yang6067)

    What you needed help with:
    Figuring out the logic for implememt the strategy patern.


    Date:
    April 17th

    Who you worked with:
    Tian Liu(liu00839), Yuancan Zhang(zhan5684),  Zhenyu Yang(yang6067)

    What you needed help with:
    Figuring out how to implement the Parabolic route.


    Date:
    April 19th

    Who you worked with:
    Tian Liu(liu00839), Yuancan Zhang(zhan5684),  Zhenyu Yang(yang6067)

    What you needed help with:
    Writing the google test for the Smart, Beeline and Parabolic route.


    ## Prority Level 4-groupwork

    Leader: Tian Liu(liu00839)

    Date:
    April 16th

    Who you worked with:
    Zhenyu Yang(yang6067), Yuancan Zhang(zhan5684),  Cooper Zhao(zhao0888)

    What you needed help with:
    Writing the class for the battery.


    Leader: Tian Liu(liu00839)

    April 18th

    Who you worked with:
    Zhenyu Yang(yang6067), Yuancan Zhang(zhan5684),  Cooper Zhao(zhao0888)

    What you needed help with:
    Figuring out the logic for allocating the new drone/robot to pick up the dropped package.


    April 19th

    Who you worked with:
    Zhenyu Yang(yang6067), Yuancan Zhang(zhan5684),  Cooper Zhao(zhao0888)

    What you needed help with:
    Finishing up the observe pattern of the iteration 2.



*\section discussion Discussion about Factories
        The factory pattern of this project implements the composite factory pattern that provides a flexible
        structure for user, allows creation and addition of new factory class into the project without modifying the main function
        and maintain the structure of the code. We currently have three different factory in the composite factory list, user can add
        more customized factory into the list if needed in the future.

        There are also other alternative approach to the factory pattern to construct the project, such can be
        abstract factory pattern and concrete factory pattern.

        \image html CompositePattern.png
        \image latex CompositePattern.png
        1) concrete factory:
            this pattern uses ifs to connect and create entity classes in a single big factory, which means modification is inevitable
            when adding a new factory into the project, such modification can be adding more if statements to include the new factory methods.
            pros: this pattern is less complicated to organize and write compared to composite factory which has each derived factory written in a
            separate header file, this pattern is more efficient when the system is consistent that there is little change to the entity/factory classes.
            cons: this pattern is much more complicated to modify compare to composite factory pattern if there are newly added factory class
            to the system.

        \image html AbstractFactory.png
        \image latex AbstractFactory.png
        2) abstract factory:
            this pattern allows a more flexible structure of the code.
            pros: it allows user to test the project and change the design of the project with ease, the methods and structure in this pattern is
            relatively loose compare to other pattern.
            cons: because its loosely structured, the code is less readable and hard to understand its functionality because it is abstract.

        \image html ConcreteFactory.png
        \image latex ConcreteFactory.png
        3) composit factory:
            this pattern requires a more intense connection between factories and organized arrangement between factory header files.
            pros: it is more closely connected and structured, the composite factory is separated from the implementation of the classes,
            which makes the addition of new factory easier and less modification is needed for the other part of the project.
            cons: its hard to organize and more complicated to write and inherit which requires polymorphism in its implementation.

*\section   obsever Observer Pattern Design Discussion
        The purpose of implement observer patterns in this project is to notify us when the state of the drone/robot/package has changed.
        Since we want only to be notified when the state changes, we only need to add the code to the place that shows the state changed.
        When state changes, we first create a picojson-object to store the state information of the drone/robot/package,
        then we call the AddStringToJsonObject function to add the state information to the object and call the ConvertPicojsonObjectToValue
        function to convert the object to value type and then call the Onevent function to notify, we used a for loop to ensure we could notify
        all observers.

        \image html observer.png
        \image latex observer.png
*\section   route Discussion of designing and implementing new routes
        The design of route planning in this project implemented the strategy pattern, there are one interface and three subclasses that designed to
        achieved the route planning using different strategy (ex. Beeline, parabolic). The interface includes a constructor, a GetRoute virtual function that requires
        two parameter one for starting position of the path and one for destination position. Those three subclasses inherits the interface, besides each class having
        a constructor, all three classes have a GetRoute function that override the virtual function in interface which implements the corresponding pathing
        strategy (ex. class beeline implements beeline pathing in GetRoute). Class Smart which implements the smart strategy is the only class that has a private
        variable which is a IGraph class variable, it is used to directly implement the GetPath() path planning from the source code given by IGraph class which is also the smart
        strategy.
        The GetRoute function for beeline and parabolic used mathematical computations to determine the path of drone/robot from starting point to destination, the parabolic
        path calculation provides some challenges, the computation of a perfect parabolic path between two points is harder than beeline which basically hard coding, Lab 14's material for
        computing the parabolic path is extremely helpful when we code Parabolic's GetRoute() function
*\section  singleton Singleton Pattern Design Discussion
        \image html singleton.png
        \image latex singleton.png
        The pattern we used to utilize the Drone Statistics is the singleton pattern, the advantages of using singleton pattern are: singleton can be implemented, it has static Initialization
        so there is only one instance could be called by other function, the dependencies are hidden, only provides a single point, easier to maintain.
        we used the static method at first, but we aware that compare to singleton class, a static class can still have instances but a singleton class can prevents it, also, a static class cannot
        be initialized with a parameter, but singleton class can be.
        Compare to factory pattern, a factory pattern will create and return new instance, in our problem, we need to gather the distance and time information, so we want a static instance so we could
        track how long it have been.
*\section feature Description of Feature
        The feature we implemented is Drone Statistics, we can collect different types of data of the Drone when running the simulation, we can get the name of the scheduled package, the distance from the Drone to the package, the distance from the package to the customer and the total distance, as well as the time cost of delivering the package.
        By comparing different path strategies we can analyze which strategy is more efficient.



*/
