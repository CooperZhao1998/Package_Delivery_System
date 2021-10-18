/**
 *@file droneFactory.h
 */
#ifndef DRONE_FACTORY_H_
#define DRONE_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "drone.h"
#include "json_helper.h"

namespace csci3081{
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
* @brief drone factory,
* a factory class used to create drone classes,
* this class is a derived class of IEntityFactory
*/
    class DroneFactory : public IEntityFactory{
        public:
            /**
             * drone factory which will create a drone from the information read from the picojson file
             * @param val picojson::object&
             * @return drone pointer
             */
            Drone* CreateEntity(const picojson::object& val);

            /**
             * constructor
             */
            DroneFactory();


        private:


    };
}

#endif
