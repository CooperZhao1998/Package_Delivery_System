
/**
 *@file robotFactory.h
 */
#ifndef ROBOTFACTORY_H_
#define ROBOTFACTORY_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "robot.h"
#include "json_helper.h"

namespace csci3081{
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
* @brief robot factory,
* a factory class used to create robot classes,
* this class is a derived class of IEntityFactory
*/
    class RobotFactory : public IEntityFactory{
        public:
            /**
             * robot factory which will create a robot from the information read from the picojson file
             * @param val picojson::object&
             * @return robot pointer
             */
            Robot* CreateEntity(const picojson::object& val);

            /**
             * constructor
             */
            RobotFactory();


        private:


    };
}
#endif
