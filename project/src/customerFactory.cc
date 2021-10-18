#include "customerFactory.h"

namespace csci3081{
    Customer* CustomerFactory::CreateEntity(const picojson::object& val){
        if(JsonHelper::GetString(val,"type").compare("customer") == 0){
            std::vector<float> position = JsonHelper::GetStdFloatVector(val, "position");
            std::vector<float> direction = JsonHelper::GetStdFloatVector(val, "direction");
            Customer* customer = new Customer(position, direction, val);
            customer->SetName(JsonHelper::GetString(val, "name"));
            return customer;
        }
        return NULL;
    }

    CustomerFactory::CustomerFactory(){}
}