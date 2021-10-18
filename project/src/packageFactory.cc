#include "packageFactory.h"

namespace csci3081{
    
        Package* PackageFactory::CreateEntity(const picojson::object& val){
            if(JsonHelper::GetString(val,"type").compare("package") == 0){
                std::vector<float> position = JsonHelper::GetStdFloatVector(val, "position");
                std::vector<float> direction = JsonHelper::GetStdFloatVector(val, "direction");
                Package* package = new Package(position, direction, val);
                package->SetName(JsonHelper::GetString(val, "name"));
                return package;
            }
            return NULL;
        }

        PackageFactory::PackageFactory(){}

}