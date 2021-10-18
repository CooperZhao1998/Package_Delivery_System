/**
 *@file drone.h
 */
#ifndef DRONE_H_
#define DRONE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity_base.h"
#include "battery.h"
#include "package.h"
#include "customer.h"

namespace csci3081 {
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief drone class store information of drones,
 * this class store information of drones also partial information of its responsible classes such as package class and customer class,
 * this class is a derived class of EntityBase
 */
class Drone : public csci3081::EntityBase{
  // TODO: Add documentation to these functions
  public:
    /**
     * constructor that construct drone with given properties
     * @param pos position of the new drone
     * @param direction direction of the new drone
     * @param obj picojson file contains all the information of the simulation
     *
     */
    Drone(std::vector<float> pos, std::vector<float> direction, const picojson::object& obj);
    /**
     * destructor
     */
    ~Drone();

    /**
     * return the ID of the drone
     * @return id
     */
    int GetId() const;
    /**
     * return the name of the drone
     * @return name
     */
    const std::string& GetName();
    // void SetName(std::string& newName);
    /**
     * return the position of the position of the drone
     * @return position
     */
    const std::vector<float>& GetPosition() const;
    /**
     * return the direction of the drone
     * @return direction
     */
    const std::vector<float>& GetDirection() const;
    /**
     * return the radius of the drone
     * @return radius
     */
    float GetRadius() const;
    /**
     * return the version of the drone
     * @return version
     */
    int GetVersion() const;
    /**
     * return the speed of the drone
     */
    float GetSpeed() const;
    /**
     * return if the drone is moving as a boolean
     * @return isDynamic
     */
    bool IsDynamic() const;
    /**
     * set the moving state of the drone which is a boolean
     * @param b new state as a boolean
     */
    void SetDynamic(bool b);
    /**
     * set the name of the drone
     * @param
     */
    void SetName(std::string value);
    void Update(float dt, std::vector<std::vector<std::vector<float>>>& path);
    /**
     * set the speed of the drone
     * @param s new speed
     */
    void SetSpeed(float s);
    /**
     * set the scheduled package to pick up
     * @param pack a pointer to the package
     */
    void SetPackage(Package* pack);
    /**
     * set the scheduled customer to deliver to
     * @param cust a pointer to the customer
     */
    void SetCustomer(Customer* cust);
    /**
     * return a boolean indicates if the drone has already loaded a package
     * @return loaded
     */
    bool GetLoaded();
    /**
     * set the boolean "loaded" when the drone has loaded or dropped a package
     * @param l loaded boolean
     */
    void SetLoaded(bool l);


    /**
     * set the boolean "loaded" when the drone has loaded or dropped a package
     * @param l loaded boolean
     */
    void SetPath(std::vector<std::vector<float>> path1, std::vector<std::vector<float>> path2);

    /**
     * get the path
     * @param loaded return the specific path refer to drone's status
     * @return current path
     */
    std::vector<std::vector<std::vector<float>>>& GetPath(bool loaded);

    /**
     * set the battery capacty
     * @param capacity capacity to set
     */
    void SetBattery(float capacity);

    /**
     * remaining charge getter
     * @return return a float indicating the current remaining charge in battery
     */
    float GetRemainingCharge();

    /**
     * set the path
     * @param path string indicating which path to set
     */
    void SetPath(std::string path);


    /**
     * return the pointer to the designated package
     * @return package
     */
    Package* GetPackage();

    /**
     * Get package at index in the vector
     * @param index integer indicating the index
     * @return Package* pointing to the wanted package
     */
    Package* GetPackageAt(int index);

    /**
     * Package getter
     * @return return all the scheduled packages of this drone, as a package vector
     */
    std::vector<Package*> GetPackages();
    /**
     * return the pointer the the designated customer
     * @return customer
     */
    Customer* GetCustomer();

    /**
     * customer getter
     * @return Customer pointer points to the last customer scheduled in the vector
     */
    Customer* GetCustomerTail();

    /**
     * return HasAPackage indicating if the drone has a package at the moment
     * @return boolean, HasAPackage
     */
    bool HasAPackage();

    /**
     * Set HasPackage
     * @param state new state to set for HasAPackage
     */
    void SetHasPackage(bool state);

    /**
     * return atCustomer, indicating if the drone is at the position of customer
     * @return atCustomer
     */
    bool IsAtCustomer()
    {
      return atcustomer;
    }

    /**
     * set atCustomer
     * @param state new state to set for atCustomer
     */
    void SetAtCustomer(bool state)
    {
      atcustomer=state;
    }

    /**
     * package getter
     * @return tempPackage, return the temp package, used to track the delivered package which is removed from the scheduled package list
     *
     */
    Package* GetTempPac()
    {
      return tempPackage;
    }

    /**
     * reschedule setter
     * @param state new state to set for reschedule status
     */
    void SetReschedule(bool state)
    {
      PackageReScheduled=state;
    }

    /**
     * return boolean indicating if the package has been rescheduled
     * @return boolean, PackageReScheduled
     */
    bool GetReschedule()
    {
      return PackageReScheduled;
    }



  //TODO for lab10: What member variables are needed?
  // should they be private or public?
  private:
    Battery* battery = new Battery();
    int id;
    std::string name;
    std::vector<float> position;
    std::vector<float> direction;
    float radius;
    int version;
    float speed;
    bool isDynamic;
    std::vector<Package*> package;
    std::vector<Customer*> customer;
    bool loaded;
    std::vector<std::vector<std::vector<float>>> dppath;
    std::vector<std::vector<std::vector<float>>> pcpath;
    bool HasPackageD;
    bool atcustomer=false;
    Package* tempPackage;
    bool PackageReScheduled=false;
    std::string path;


};

}

#endif
