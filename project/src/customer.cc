#include "customer.h"

namespace csci3081{
    Customer::Customer(std::vector<float> pos, std::vector<float> direct, const picojson::object& details){
        position = pos;
        direction = direct;
        details_ = details;

    }

    Customer::~Customer(){}

    int Customer::GetId() const{
        return id;
    }

    void Customer::SetName(std::string newName){
        name = newName;
    }

    const std::string& Customer::GetName(){
        return name;
    }

    const std::vector<float>& Customer::GetPosition() const{
        return position;
    }

    const std::vector<float>& Customer::GetDirection() const{
        return direction;
    }

    float Customer::GetRadius() const{
        return radius;
    }

    // const std::vector<float>& Customer::GetRotation() const{
    //     return rotation;
    // }

    // void Customer::SetRotation(std::vector<float>& value){
    //     rotation = value;
    // }

    bool Customer::IsDynamic() const {
  // TODO: This is just a stub for compilation
        return isDynamic;
    }

    int Customer::GetVersion() const {
  // TODO: This is just a stub for compilation
        return version;
    }


}
