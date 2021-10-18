#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/delivery_simulation.h"
#include <EntityProject/entity.h>
#include "json_helper.h"
#include <fstream>

namespace csci3081{
    using entity_project::IEntity;
    class WriterTest : public ::testing::Test{
        protected:
            void SetUp(){
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

                system = dynamic_cast<IDeliverySystem*>(GetEntitySystem("default"));
                objp = JsonHelper::CreateJsonObject();
                JsonHelper::AddStringToJsonObject(objp, "type", "package");
                std::string expected_namep = "hellopackage";
                JsonHelper::AddStringToJsonObject(objp, "name", expected_namep);
                std::vector<float> initialPosp;
                initialPosp.push_back(-255.994);
                initialPosp.push_back(257.798);
                initialPosp.push_back(-296.859);
                JsonHelper::AddStdFloatVectorToJsonObject(objp, "position", initialPosp);
                std::vector<float> directionp;
                directionp.push_back(0);
                directionp.push_back(0);
                directionp.push_back(1);
                JsonHelper::AddStdFloatVectorToJsonObject(objp, "direction", directionp);
                PackageFactory* packagefac = new PackageFactory();
                package = packagefac->CreateEntity(objp);
                
                system->AddEntity(package);

                objc = JsonHelper::CreateJsonObject();
                JsonHelper::AddStringToJsonObject(objc, "type", "customer");
                std::string expected_namec = "hellocustomer";
                JsonHelper::AddStringToJsonObject(objc, "name", expected_namec);
                std::vector<float> initialPosc;
                initialPosc.push_back(-951.412);
                initialPosc.push_back(254.665);
                initialPosc.push_back(298.271);
                JsonHelper::AddStdFloatVectorToJsonObject(objc, "position", initialPosc);
                std::vector<float> directionc;
                directionc.push_back(0);
                directionc.push_back(0);
                directionc.push_back(1);
                JsonHelper::AddStdFloatVectorToJsonObject(objc, "direction", directionc);


                CustomerFactory* customerfac = new CustomerFactory();
                customer = customerfac->CreateEntity(objc);
                
                system->AddEntity(customer);
            }
            IDeliverySystem* system;
            Drone* drone;
            Package* package;
            Customer* customer;
            picojson::object obj;
            picojson::object objp;
            picojson::object objc;
            StatisticsWriter* writer = writer->getInstance();
    };

    TEST_F(WriterTest, Statistic_Writer_test){
        drone->SetPackage(package);
        drone->SetCustomer(customer);
        std::vector<float> path1;
        std::vector<float> path2;
        path1.push_back(0);path1.push_back(0);path1.push_back(0);
        path2.push_back(1);path2.push_back(1);path2.push_back(1);
        std::vector<std::vector<float>> patha;
        std::vector<std::vector<float>> pathb;
        patha.push_back(path1);
        pathb.push_back(path2);
        drone->SetPath(patha, pathb);
        std::vector<std::vector<std::vector<float>>> auditPath;
        auditPath.push_back(drone->GetPath(false)[0]);
        auditPath.push_back(drone->GetPath(true)[0]);
        writer->droneAudit(auditPath, drone->GetPackage(), drone->GetCustomer(), drone);
        std::ifstream fin("audit--helloDrone.csv");
        bool isFileExist = false;
        if(fin){
            isFileExist = true;
        }
        EXPECT_EQ(isFileExist, true);
    }

    TEST_F(WriterTest, pathtype_getter_and_setter){
        writer->setPathType("smart");
        EXPECT_EQ(writer->getPathType(), "smart");
    }
}