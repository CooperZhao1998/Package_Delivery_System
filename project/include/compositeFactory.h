/**
 *@file compositeFactory.h
 */
#ifndef COMPOSITE_FACTORY_H_
#define COMPOSITE_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <EntityProject/facade/delivery_system.h>
#include <vector>
#include <string>
#include "json_helper.h"
#include "entity_base.h"
#include "droneFactory.h"
#include "packageFactory.h"
#include "customerFactory.h"
#include "robotFactory.h"

namespace csci3081{
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The base class for composite factories
 *
 * This class can be used as the base for all factory class in for creating the entities in the delivery system.
 *
 */
class CompositeFactory : public IEntityFactory{

    public:
        /**
        * Add a factory into the composite factory list
        *
        */
        void AddFactory(IEntityFactory* object);
        /**
        * remove a facotory from the factory list
        * @param index integer indicates which factory in the list to delete
        */
        void Remove(int index);
        /**
        * create an entity from the picojson file, work as a virtual function that will be override by derived class such as dronefactory
        * @param val picojson::object
        * @return IEntity pointer
        */
        virtual IEntity* CreateEntity(const picojson::object& val);

        // IEntityFactory* GetChild();
        /**
         * constructor
         */
        CompositeFactory();

        /**
         * destructor
         */
        ~CompositeFactory();


    protected:
        std::vector<IEntityFactory*> factories;
};

}

#endif //COMPOSITE_FACTORY_H_
