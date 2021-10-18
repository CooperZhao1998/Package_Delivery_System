#include "droneFactory.h"

namespace csci3081{
    Drone* DroneFactory::CreateEntity(const picojson::object& val){
        if(JsonHelper::GetString(val,"type").compare("drone") == 0){
            std::vector<float> position = JsonHelper::GetStdFloatVector(val, "position");
            std::vector<float> direction = JsonHelper::GetStdFloatVector(val, "direction");
            Drone* drone = new Drone(position, direction, val);
            if(JsonHelper::ContainsKey(val, "speed")){
                drone->SetSpeed(JsonHelper::GetDouble(val, "speed"));
            }
            if(JsonHelper::ContainsKey(val, "name")){
                drone->SetName(JsonHelper::GetString(val, "name"));
            }
            if(JsonHelper::ContainsKey(val, "battery_capacity")){
                drone->SetBattery(JsonHelper::GetDouble(val, "battery_capacity"));
            }
            if(JsonHelper::ContainsKey(val, "path")){
                drone->SetPath(JsonHelper::GetString(val, "path")); 
            }

            drone->SetDynamic(false);
            drone->SetLoaded(false);
            return drone;
        }
        return NULL;

    }
    DroneFactory::DroneFactory(){}
}


