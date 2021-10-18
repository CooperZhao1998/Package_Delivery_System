#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/delivery_simulation.h"
#include <EntityProject/entity.h>
#include "json_helper.h"

namespace csci3081{
    
using entity_project::IEntity;

    class RobotTest : public ::testing::Test{
        // protected:
        // IDeliverySystem* system;
        protected:
        void SetUp() {
            system = dynamic_cast<IDeliverySystem*>(GetEntitySystem("default"));
            obj = JsonHelper::CreateJsonObject();
            JsonHelper::AddStringToJsonObject(obj, "type", "robot");

            std::string expected_name = "hellorobot";
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

            RobotFactory robotfac = RobotFactory();
            // IEntity* Robot = system->CreateEntity(obj);
            robot = robotfac.CreateEntity(obj);
            system->AddEntity(robot);
            }
            IDeliverySystem* system;
            Robot* robot;
            picojson::object obj;
            
    };

    TEST_F(RobotTest, RobotConstructorAndGetters_usingFactory){
        
        //check that the returned entity is not NULL
        ASSERT_NE(robot, nullptr) << "robot created";

        ASSERT_EQ(picojson::value(system->GetEntities()[0]->GetDetails()).serialize(), picojson::value(obj).serialize());


    }

    TEST_F(RobotTest, RobotPositionGetter){
        std::vector<float> initialPos;
            initialPos.push_back(0);
            initialPos.push_back(0);
            initialPos.push_back(0);
        ASSERT_FLOAT_EQ(robot->GetPosition()[0], initialPos[0]);
        ASSERT_FLOAT_EQ(robot->GetPosition()[1], initialPos[1]);
        ASSERT_FLOAT_EQ(robot->GetPosition()[2], initialPos[2]);
    }

    TEST_F(RobotTest, RobotDirectionGetter){
        std::vector<float> direction;
            direction.push_back(0);
            direction.push_back(0);
            direction.push_back(1);
        ASSERT_FLOAT_EQ(robot->GetDirection()[0], direction[0]);
        ASSERT_FLOAT_EQ(robot->GetDirection()[1], direction[1]);
        ASSERT_FLOAT_EQ(robot->GetDirection()[2], direction[2]);
    }

    TEST_F(RobotTest, RobotPathSetterAndGetter){
        std::vector<float> point1, point2, point3;
        point1.push_back(0);
        point1.push_back(0);
        point1.push_back(0);
        point2.push_back(1);
        point2.push_back(0);
        point2.push_back(1);
        point3.push_back(2);
        point3.push_back(0);
        point3.push_back(2);
        std::vector<std::vector<float>> expect_path1;
        expect_path1.push_back(point1);
        expect_path1.push_back(point2);

        std::vector<std::vector<float>> expect_path2;
        expect_path2.push_back(point3);

        robot->SetPath(expect_path1, expect_path2);

        EXPECT_EQ(robot->GetPath(false)[0], expect_path1) << "Robot path setter and getter are not setup properly";
        EXPECT_EQ(robot->GetPath(true)[0], expect_path2) << "Robot path setter and getter are not setup properly";
    }

    TEST_F(RobotTest, RobotDynamicSetterAndGetter){
        bool expected_dynamic = false;
        robot->SetDynamic(false);
        EXPECT_EQ(robot->IsDynamic(), expected_dynamic) << "Robot dynamic setters and getters are not setup properly";
    }

    TEST_F(RobotTest, RobotLoadedGetterAndSetter){
        bool expected_loaded = false;
        robot->SetLoaded(false);
        EXPECT_EQ(robot->GetLoaded(), expected_loaded)<< "Robot loaded getter and setter are not setup correctly";
    }

    TEST_F(RobotTest, RobotBatteryTest){
        robot->SetBattery(10);
        float expected_battery = 10;
        ASSERT_FLOAT_EQ(robot->GetRemainingCharge(), expected_battery) << "Robot loaded getter and setter are not setup correctly";
    }

    TEST_F(RobotTest, RobotHasAPackag_GetterAndSetter){
        robot->SetHasPackage(false);
        bool expected = false;
        EXPECT_EQ(robot->HasAPackage(), expected) << "Robot HasAPackage getter and setter are not setup correctly";
    }

    TEST_F(RobotTest, Robot_IsAtCustomer_GetterAndSetter){
        robot->SetAtCustomer(false);
        bool expected = false;
        EXPECT_EQ(robot->IsAtCustomer(), expected) << "Robot IsAtCustomer getter and setter are not setup correctly";
    }

    TEST_F(RobotTest, Robot_name_getter){
        std::string expected_name = "hellorobot";
        EXPECT_EQ(robot->GetName(), expected_name) << "Robot name getter is not setup correctly";
    }

    TEST_F(RobotTest, Robot_Schedule_GetterAndSetter){
        robot->SetReschedule(false);
        bool expected = false;
        EXPECT_EQ(robot->GetReschedule(), expected) << "Robot_Schedule_GetterAndSetter are not setup correctly ";
    }

}