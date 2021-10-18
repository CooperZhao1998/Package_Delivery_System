#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/delivery_simulation.h"
#include <EntityProject/entity.h>
#include "json_helper.h"

namespace csci3081{
    
using entity_project::IEntity;

    class DroneTest : public ::testing::Test{
        // protected:
        // IDeliverySystem* system;
        protected:
        void SetUp() {
            system = dynamic_cast<IDeliverySystem*>(GetEntitySystem("default"));
            obj = JsonHelper::CreateJsonObject();
            JsonHelper::AddStringToJsonObject(obj, "type", "drone");

            std::string expected_name = "helloDrone";
            JsonHelper::AddStringToJsonObject(obj, "name", expected_name);

            std::vector<float> initialPos;
            initialPos.push_back(0);
            initialPos.push_back(0);
            initialPos.push_back(0);
            JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", initialPos);
            std::vector<float> direction;
            direction.push_back(0);
            direction.push_back(0);
            direction.push_back(1);
            JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction);



            double set_speed = 30.0;
            JsonHelper::AddFloatToJsonObject(obj, "speed", set_speed);

            DroneFactory dronefac = DroneFactory();
            // IEntity* drone = system->CreateEntity(obj);
            drone = dronefac.CreateEntity(obj);
            system->AddEntity(drone);
        }
        IDeliverySystem* system;
        Drone* drone;
        picojson::object obj;
            
    };

    TEST_F(DroneTest, DroneConstructor){

        //check that the returned entity is not NULL
        ASSERT_NE(drone, nullptr) << "Drone created";
        
        ASSERT_EQ(picojson::value(system->GetEntities()[0]->GetDetails()).serialize(), picojson::value(obj).serialize());


    }
    TEST_F(DroneTest, DronePositionGetter){
        std::vector<float> initialPos;
            initialPos.push_back(0);
            initialPos.push_back(0);
            initialPos.push_back(0);
        ASSERT_FLOAT_EQ(drone->GetPosition()[0], initialPos[0]);
        ASSERT_FLOAT_EQ(drone->GetPosition()[1], initialPos[1]);
        ASSERT_FLOAT_EQ(drone->GetPosition()[2], initialPos[2]);
    }

    TEST_F(DroneTest, DroneDirectionGetter){
        std::vector<float> direction;
            direction.push_back(0);
            direction.push_back(0);
            direction.push_back(1);
        ASSERT_FLOAT_EQ(drone->GetDirection()[0], direction[0]);
        ASSERT_FLOAT_EQ(drone->GetDirection()[1], direction[1]);
        ASSERT_FLOAT_EQ(drone->GetDirection()[2], direction[2]);
    }

    TEST_F(DroneTest, DroneNameGetter){
        std::string expected_name = "helloDrone";
        EXPECT_EQ(drone->GetName(), expected_name) << "Drone name getter are not setup properly";
    }

    TEST_F(DroneTest, DronePathSetterAndGetter){
        std::vector<float> point1, point2, point3;
        point1.push_back(0);
        point1.push_back(0);
        point1.push_back(0);
        point2.push_back(1);
        point2.push_back(1);
        point2.push_back(1);
        point3.push_back(2);
        point3.push_back(2);
        point3.push_back(2);
        std::vector<std::vector<float>> expect_path1;
        expect_path1.push_back(point1);
        expect_path1.push_back(point2);

        std::vector<std::vector<float>> expect_path2;
        expect_path2.push_back(point3);

        drone->SetPath(expect_path1, expect_path2);

        EXPECT_EQ(drone->GetPath(false)[0], expect_path1) << "Drone path setter and getter are not setup properly";
        EXPECT_EQ(drone->GetPath(true)[0], expect_path2) << "Drone path setter and getter are not setup properly";

    }

    TEST_F(DroneTest, DronePackageGetterAndSetter){
        drone->SetHasPackage(true);
        bool expected_package_state = true;
        
        EXPECT_EQ(drone->HasAPackage(), expected_package_state) << "Drone package getter and setter are not setup correctly";
    }

    TEST_F(DroneTest, DroneDynamicSetterAndGetter){
        drone->SetDynamic(true);
        bool expected_dynamic_state = true;
        
        EXPECT_EQ(drone->IsDynamic(), expected_dynamic_state)<< "Drone dynamic getter and setter are not setup correctly";
    }

    TEST_F(DroneTest, DroneLoadedSetterAndGetter){
        drone->SetLoaded(true);
        bool expected_loaded_state = true;
        EXPECT_EQ(drone->GetLoaded(), expected_loaded_state)<< "Drone loaded getter and setter are not setup correctly";
    }

    TEST_F(DroneTest, DroneBatteryTest){
        drone->SetBattery(10);
        float expected_battery = 10;
        ASSERT_FLOAT_EQ(drone->GetRemainingCharge(), expected_battery) << "Drone loaded getter and setter are not setup correctly";
    }

    TEST_F(DroneTest, Drone_IsAtCustomer){
        drone->SetAtCustomer(false);
        bool expected = false;
        EXPECT_EQ(drone->IsAtCustomer(), expected) << "Drone IsAtCustomer is not setup correctly" ;
    }

    TEST_F(DroneTest, Drone_Schedule_GetterAndSetter){
        drone->SetReschedule(false);
        bool expected = false;
        EXPECT_EQ(drone->GetReschedule(), expected) << "Drone_Schedule_GetterAndSetter are not setup correctly ";
    }


}