/**
 *@file robot.h
 */
#ifndef ROBOT_H_
#define ROBOT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity_base.h"
#include "battery.h"
#include "package.h"
#include "customer.h"



namespace csci3081{
/*******************************************************************************
* Class Definitions
******************************************************************************/
/**
* @brief robot class
* this class defined the robot entity
*/
    class Robot : public csci3081::EntityBase{
        public:

        /**
         * constructor of Robot
         * @param pos vector indicating the initial position of the robot
         * @param direction vector indicating the direction of the robot
         * @param obj object contains the picojson details of the new robot
         *
         */
        Robot(std::vector<float> pos, std::vector<float> direction, const picojson::object& obj);
       ~Robot();

        /**
         * name getter
         * @return name of the robot as a string
         */
        const std::string& GetName();

        /**
         * ID getter
         * @return ID of the robot as a int
         */
        int GetId() const;

        /**
         * Position getter
         * @return position of the robot as a vector
         */
        const std::vector<float>& GetPosition() const;

        /**
         * Direction getter
         * @return direction of the robot as a vector
         */
        const std::vector<float>& GetDirection() const;

        /**
         * radius getter
         * @return radius of robot as a float
         */
        float GetRadius() const;

        /**
         * version getter
         * @return version of robot as a int
         */
        int GetVersion() const;

        /**
         * speed getter
         * @return speed of robot as a float
         */
        float GetSpeed() const;

        /**
         * isDynamic getter
         * @return return the moving state of robot as a boolean
         */
        bool IsDynamic() const;

        /**
         * isDynamic setter
         * @param b new moving state to set
         */
        void SetDynamic(bool b);

        /**
         * name setter
         * @param value new name to set for robot
         */
        void SetName(std::string value);

        /**
         * update function to update the state of robot every time being executed
         * @param dt time intervel
         * @param path a set of path scheduled for robot to move
         *
         */
        void Update(float dt, std::vector<std::vector<std::vector<float>>>& path);

        /**
         * speed setter
         * @param s new speed to set for robot
         */
        void SetSpeed(float s);

        /**
         * package setter
         * @param pack set the package of robot, add it to the list of scheduled packages stored in robot
         */
        void SetPackage(Package* pack);

        /**
         * customer setter
         * @param cust set the customer of robot, add it to the list of scheduled customers stored in robot
         */
        void SetCustomer(Customer* cust);

        /**
         * loaded getter
         * @return boolean indicate if the robot is loaded with packages which means its carrying a package at the moment
         */
        bool GetLoaded();

        /**
         * loaded setter
         * @param l new state for loaded
         */
        void SetLoaded(bool l);

        /**
         * path setter
         * @param path1 robot to package path
         * @param path2 when picked up package, path from package to customer
         *
         */
        void SetPath(std::vector<std::vector<float>> path1, std::vector<std::vector<float>> path2);

        /**
         * path getter
         * @param loaded boolean indicates if the robot is carrying a package
         * @return the current moving path of robot
         */
        std::vector<std::vector<std::vector<float>>>& GetPath(bool loaded);

        /**
         *  batter capacity setter
         * @param capacity float indicate the capacity of the battery
         */
        void SetBattery(float capacity);

        /**
         * remaining charge getter
         * @return return the remaining charge in the battery of robot
         */
        float GetRemainingCharge();

        /**
         * path setter
         * @param path new name of path
         */
        void SetPath(std::string path);

        /**
         * package getter 1
         * @return current package the robot is heading to pick up or carrying
         */
        Package* GetPackage();

        /**
         * package getter 2
         * @return list of packages the robot is scheduled with
         */
        std::vector<Package*> GetPackages();

        /**
         * customer getter 1
         * @return current customer the robot is heading to
         */
        Customer* GetCustomer();

        /**
         * customer getter 2
         * @return the last customer in the list of customers which the robot is scheduled with
         */
        Customer* GetCustomerTail();

        /**
         * HasAPackage getter
         * @return boolean indicating if the robot is carrying a package, defined specifically for observer
         */
        bool HasAPackage();

        /**
         * HasAPackage setter
         * @param state new state for HasAPackage
         */
        void SetHasPackage(bool state);

            /**
             * AtCustomer getter
             * @return atcustomer which indicates if the robot is at the customer's position
             */
            bool IsAtCustomer()
            {
            return atcustomer;
            }

            /**
             * AtCustomer setter
             * @param state new state for atcustomer
             *
             */
            void SetAtCustomer(bool state)
            {
            atcustomer=state;
            }

            /**
             * tempPackage getter
             * @return tempPackage which stores the package delivered or deleted from the list of packages stored in robot
             */
            Package* GetTempPac()
            {
            return tempPackage;
            }
            /**
             * PackageReScheduled Setter
             *@param PackageReScheduled which stores the state of the package been scheduled or not
             */
            void SetReschedule(bool state)
            {
              PackageReScheduled=state;
            }
            /**
             * PackageReScheduled Getter
             *@return PackageReScheduled which stores the state of the package been scheduled or not
             */
            bool GetReschedule()
            {
              return PackageReScheduled;
            }

    private:
        Battery* battery = new Battery();
        std::string name;
        int id;
        std::vector<float> position;
        std::vector<float> direction;
        float radius;
        int version;
        float speed;
        bool isDynamic;
        std::vector<Package*> package;
        std::vector<Customer*> customer;
        bool loaded;
        std::vector<std::vector<std::vector<float>>> rppath;
        std::vector<std::vector<std::vector<float>>> pcpath;
        bool HasPackageR;
        bool atcustomer=0;
        Package* tempPackage;
        bool PackageReScheduled=false;

        std::string path;
    };
}

#endif
