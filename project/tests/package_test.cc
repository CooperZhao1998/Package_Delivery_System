#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/delivery_simulation.h"
#include <EntityProject/entity.h>
#include "json_helper.h"

namespace csci3081{

using entity_project::IEntity;

    class PackageTest : public ::testing :: Test{
        protected:
        void SetUp() {
            system = dynamic_cast<IDeliverySystem*>(GetEntitySystem("default"));
            obj = JsonHelper::CreateJsonObject();
            JsonHelper::AddStringToJsonObject(obj, "type", "package");
            std::string expected_name = "hellopackage";
            JsonHelper::AddStringToJsonObject(obj, "name", expected_name);
            std::vector<float> initialPos;
            initialPos.push_back(-255.994);
            initialPos.push_back(257.798);
            initialPos.push_back(-296.859);
            JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", initialPos);
            std::vector<float> direction;
            direction.push_back(0);
            direction.push_back(0);
            direction.push_back(1);
            JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction);
            PackageFactory* packagefac = new PackageFactory();
            package = packagefac->CreateEntity(obj);
            
            system->AddEntity(package);
        }
        IDeliverySystem* system;
        picojson::object obj;
        Package* package;
    };

    TEST_F(PackageTest, PackageConstructorAndGetters_usingFactory){
        

        ASSERT_NE(package, nullptr) << "package created";

        ASSERT_EQ(picojson::value(system->GetEntities()[0]->GetDetails()).serialize(), picojson::value(obj).serialize());
    }

    TEST_F(PackageTest, PackagePositionGetter){
        std::vector<float> initialPos;
            initialPos.push_back(-255.994);
            initialPos.push_back(257.798);
            initialPos.push_back(-296.859);
        ASSERT_FLOAT_EQ(package->GetPosition()[0], initialPos[0]);
        ASSERT_FLOAT_EQ(package->GetPosition()[1], initialPos[1]);
        ASSERT_FLOAT_EQ(package->GetPosition()[2], initialPos[2]);
    }

    TEST_F(PackageTest, Package_SetPosition){
        package->SetPosition(0,0,0);
        ASSERT_FLOAT_EQ(package->GetPosition()[0], 0);
        ASSERT_FLOAT_EQ(package->GetPosition()[1], 0);
        ASSERT_FLOAT_EQ(package->GetPosition()[2], 0);
    }

    TEST_F(PackageTest, PackageDirectionGetter){
        std::vector<float> direction;
            direction.push_back(0);
            direction.push_back(0);
            direction.push_back(1);
        ASSERT_FLOAT_EQ(package->GetDirection()[0], direction[0]);
        ASSERT_FLOAT_EQ(package->GetDirection()[1], direction[1]);
        ASSERT_FLOAT_EQ(package->GetDirection()[2], direction[2]);
    }

    TEST_F(PackageTest, PackageNameGetter){
        std::string expected_name = "hellopackage";
        EXPECT_EQ(package->GetName(), expected_name) << "Package name getter are not setup properly";
    }

    TEST_F(PackageTest, PackageDynamicSetterAndGetter){
        package->SetisDynamic(true);
        bool expected_dynamic_state = true;
        
        EXPECT_EQ(package->IsDynamic(), expected_dynamic_state)<< "Package dynamic getter and setter are not setup correctly";
    }

    TEST_F(PackageTest, Time_setter_and_getter){
        package->SetTime(10);
        double time = package->GetTimeFromPickToDel(20);
        EXPECT_EQ(time, 10) << "package time getter and setter are not setup correctly";
    }

}