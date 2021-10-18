/**
 *@file customerFactory.h
 */
 #ifndef CUSTOMER_FACTORY_H_
 #define CUSTOMER_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "customer.h"
#include "json_helper.h"

namespace csci3081{
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
* @brief customer factory,
* a factory class used to create customer classes,
* this class is a derived class of IEntityFactory
*/
    class CustomerFactory : public IEntityFactory{
        public:
            /**
             * customer factory which will create a customer from the information read from the picojson file
             * @param val picojson::object&
             * @return customer pointer
             */
            Customer* CreateEntity(const picojson::object& val);

            // void Remove(FactoryFactory* object);

            // FactoryFactory* GetChild(FactoryFactory* object);

            /**
             * constructor
             */
            CustomerFactory();

        private:


    };
}
#endif
