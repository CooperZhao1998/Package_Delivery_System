#include "package.h"


namespace csci3081{
    Package::Package(std::vector<float> pos, std::vector<float> direct, const picojson::object& details){
        position = pos;
        direction = direct;
        details_ = details;

    }

    Package::~Package(){

    }

    int Package::GetId() const{
        return id;
    }

    void Package::SetName(std::string newName){
        name = newName;
    }

    const std::string& Package::GetName(){
        return name;
    }

    const std::vector<float>& Package::GetPosition() const{
        return position;
    }

    const std::vector<float>& Package::GetDirection() const{
        return direction;
    }

    float Package::GetRadius() const{
        return radius;
    }

    int Package::GetVersion() const{
        return version;
    }

    bool Package::IsDynamic() const{
        return isDynamic;
    }
    void Package::SetisDynamic(bool state)
    {
      isDynamic=state;
    }


    void Package::SetPosition(float x, float y, float z){
        position[0] = x;
        position[1] = y;
        position[2] = z;

    }

}
