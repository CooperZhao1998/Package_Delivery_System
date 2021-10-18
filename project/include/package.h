/**
 *@file package.h
 */
#ifndef PACKAGE_H_
#define PACKAGE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity_base.h"
#include <chrono>
#include <iostream>

using namespace std::chrono;
using namespace std;
namespace csci3081{
/*******************************************************************************
* Class Definitions
******************************************************************************/
/**
* @brief package class,
* store information of packages and interaction with other classes,
* this class is a derived class of EntityBase
*/
    class Package: public csci3081::EntityBase{
        public:
            /**
             * package constructor that constructs a package class with given properties
             * @param pos position of the new package
             * @param direction direction of the new package
             * @param obj picojson file that contains all the information of the simulation
             */
            Package(std::vector<float> pos, std::vector<float> direction, const picojson::object& obj);
            ~Package();

            /**
             * return the id of the package
             * @return id
             */
            int GetId() const;

            /**
             * set the name of the package
             * @param value string of the new name
             */
            void SetName(std::string value);

            /**
             * return the name of the package
             * @return name
             */
            const std::string& GetName();

            /**
             * return the position of the package
             * @return position
             */
            const std::vector<float>& GetPosition() const;

            /**
             * return the direction of the package
             * @return direction
             */
            const std::vector<float>& GetDirection() const;

            /**
             * return the radius of the package
             * @return radius
             */
            float GetRadius() const;

            /**
             * reutrn the version of the package
             * @return version
             */
            int GetVersion() const;

            /**
             * return the state of the package, used for compilation
             * @return isDynamic
             */
            bool IsDynamic() const;

            /**
             * set the position of the package
             * @param dronePos new position to set, usually the position of the drone which carries the package or the customer who received it
             */
            void SetPosition(float x, float y, float z);

            /**
             * setter for isDynamic of package which indicates if the package is moving
             * @param state new state as a boolean to set for isDynamic
             */
            void SetisDynamic(bool state);

            void packageStartTime()
            {
              _start=high_resolution_clock::now();
            }

            double GetDurationTime()
            {
              return (duration_cast<microseconds>(high_resolution_clock::now() - _start).count()*0.000001);
            }
            double GetTimeFromPickToDel(double time)
            {
              return (time-_time_duration);
            }
            void SetTime(double time)
            {
              _time_duration=time;
            }

        private:
            double _time_duration;
            int id;
            std::string name;
            std::vector<float> position;
            std::vector<float> direction;
            float radius;
            int version;
            bool isDynamic;
            time_point<high_resolution_clock>_start;


    };


}

#endif
