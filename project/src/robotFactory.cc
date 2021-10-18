#include "robotFactory.h"

namespace csci3081{
        Robot* RobotFactory::CreateEntity(const picojson::object& val){
        if(JsonHelper::GetString(val,"type").compare("robot") == 0){
            std::vector<float> position = JsonHelper::GetStdFloatVector(val, "position");
            std::vector<float> direction = JsonHelper::GetStdFloatVector(val, "direction");
            Robot* robot = new Robot(position, direction, val);
            if(JsonHelper::ContainsKey(val, "speed")){
                robot->SetSpeed(JsonHelper::GetDouble(val, "speed"));
            }
            if(JsonHelper::ContainsKey(val, "name")){
                robot->SetName(JsonHelper::GetString(val, "name"));
            }
            if(JsonHelper::ContainsKey(val, "battery_capacity")){
                robot->SetBattery(JsonHelper::GetDouble(val, "battery_capacity"));
            }
            if(JsonHelper::ContainsKey(val, "path")){
                robot->SetPath(JsonHelper::GetString(val, "path")); 
            }

            robot->SetDynamic(false);
            robot->SetLoaded(false);
            return robot;
        }
        return NULL;

    }
    RobotFactory::RobotFactory(){}
}