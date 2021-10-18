#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/delivery_simulation.h"
#include <EntityProject/entity.h>
#include "json_helper.h"


namespace csci3081{

using entity_project::IEntity;

    class CustomerTest : public ::testing :: Test{
        protected:
        void SetUp() {
            system = dynamic_cast<IDeliverySystem*>(GetEntitySystem("default"));
            obj = JsonHelper::CreateJsonObject();
            JsonHelper::AddStringToJsonObject(obj, "type", "customer");
            std::string expected_name = "hellocustomer";
            JsonHelper::AddStringToJsonObject(obj, "name", expected_name);
            std::vector<float> initialPos;
            initialPos.push_back(-951.412);
            initialPos.push_back(254.665);
            initialPos.push_back(298.271);
            JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", initialPos);
            std::vector<float> direction;
            direction.push_back(0);
            direction.push_back(0);
            direction.push_back(1);
            JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction);


            CustomerFactory* customerfac = new CustomerFactory();
            customer = customerfac->CreateEntity(obj);
            
            system->AddEntity(customer);
        }
        IDeliverySystem* system;    
        picojson::object obj;
        Customer* customer;    
    };

    TEST_F(CustomerTest, CustomerConstructorAndGetters_usingFactory){
        

        ASSERT_NE(customer, nullptr) << "Customer created";

        // ASSERT_FLOAT_EQ(customer->GetRotation()[0], rotation[0]);
        // ASSERT_FLOAT_EQ(customer->GetRotation()[1], rotation[1]);
        // ASSERT_FLOAT_EQ(customer->GetRotation()[2], rotation[2]);
        // ASSERT_FLOAT_EQ(customer->GetRotation()[3], rotation[3]);

    }

    TEST_F(CustomerTest, CustomerPositionGetter){
        std::vector<float> initialPos;
            initialPos.push_back(-951.412);
            initialPos.push_back(254.665);
            initialPos.push_back(298.271);
        ASSERT_FLOAT_EQ(customer->GetPosition()[0], initialPos[0]);
        ASSERT_FLOAT_EQ(customer->GetPosition()[1], initialPos[1]);
        ASSERT_FLOAT_EQ(customer->GetPosition()[2], initialPos[2]);
    }

    TEST_F(CustomerTest, CustomerDirectionGetter){
        std::vector<float> direction;
            direction.push_back(0);
            direction.push_back(0);
            direction.push_back(1);
        ASSERT_FLOAT_EQ(customer->GetDirection()[0], direction[0]);
        ASSERT_FLOAT_EQ(customer->GetDirection()[1], direction[1]);
        ASSERT_FLOAT_EQ(customer->GetDirection()[2], direction[2]);
    }

    TEST_F(CustomerTest, CustomerNameGetter){
        std::string expected_name = "hellocustomer";
        EXPECT_EQ(customer->GetName(), expected_name) << "Customer name getter are not setup properly";
    }

    TEST_F(CustomerTest, CustomerDynamicSetterAndGetter){
        //customer->SetDynamic(true);
        bool expected_dynamic_state = false;
        
        EXPECT_EQ(customer->IsDynamic(), expected_dynamic_state)<< "Customer dynamic getter and setter are not setup correctly";
    }

}