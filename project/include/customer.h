/**
 *@file customer.h
 */
#ifndef CUSTOMER_H_
#define CUSTOMER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity_base.h"


namespace csci3081{
/*******************************************************************************
* Class Definitions
******************************************************************************/
/**
* @brief customer class stores information of a single customer,
* this class stores information and allows interaction between customer and other classes,
* this class is a derived class of EntityBase
*/
class Customer: public csci3081::EntityBase{
        public:
            /**
             * customer constructor with set properties
             * @param pos position of the new customer class
             * @param direction direction of the new customer class
             * @param obj picojson::object contains all the information of the simulation
             *
             */
            Customer(std::vector<float> pos, std::vector<float> direction, const picojson::object& obj);

            /**
             * destructor
             */
            ~Customer();

            /**
             * return Id of the customer
             * @return id
             */
            int GetId() const;

            /**
             * set the name of the customer
             * @param value new name will be set to the customer
             */
            void SetName(std::string value);

            /**
             * return the name of the customer
             * @return name
             */
            const std::string& GetName();

            /**
             * return the position of the customer
             * @return position
             */
            const std::vector<float>& GetPosition() const;

            /**
             * return the direction of the customer
             * @return direction
             */
            const std::vector<float>& GetDirection() const;

            /**
             * return the radius of the customer
             * @return radius
             */
            float GetRadius() const;

            /**
             * for compilation
             */
            int GetVersion() const;

            /**
             * for compilation since customer never moves
             */
            bool IsDynamic() const;




        private:
            int id;
            std::string name;
            std::vector<float> position;
            std::vector<float> direction;
            float radius;
            // std::vector<float> rotation;
            bool isDynamic;
            int version;




    };


}

#endif
