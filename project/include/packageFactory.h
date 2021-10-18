/**
 *@file packageFactory.h
 */
#ifndef PACKAGEFACTORY_H_
#define PACKAGEFACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "package.h"
#include "json_helper.h"


namespace csci3081{

/*******************************************************************************
* Class Definitions
******************************************************************************/
/**
* @brief package factory,
* a factory class used to create package classes,
* this class is a derived class of IEntityFactory
*/
    class PackageFactory : public IEntityFactory{
        public:
            /**
             * package factory which will create a package from the information read from the picojson file
             * @param val picojson::object&
             * @return package pointer
             */
            Package* CreateEntity(const picojson::object& val);

            // void Remove(PackageFactory* object);

            // Package* GetChild(PackageFactory* object);

            /**
             * constructor
             */
            PackageFactory();


        private:


    };
}
#endif
