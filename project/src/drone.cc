#include "drone.h"
#include "json_helper.h"

namespace csci3081 {

Drone::Drone(std::vector<float> pos, std::vector<float> direct, const picojson::object& obj) {
  // TODO for lab10: store the position and direction vectors.

  position = pos;
  direction = direct;



  // name = JsonHelper::GetString(obj, "name");
  // The following line saves the json object in the details_ member variable
  // from the EntityBase class, in order to return it later in GetDetails()
  details_ = obj;
}
Drone::~Drone(){}

int Drone::GetId() const {
  // TODO: This is just a stub for compilation
  return id;
}
bool Drone::HasAPackage()
{
  return HasPackageD;
}
void Drone::SetHasPackage(bool state)
{
  HasPackageD=state;
}
const std::string& Drone::GetName() {
  // TODO for lab10: What should this return?
  return name;
}

// void Drone::SetName(std::string& newName){
//   name = newName;
// }

const std::vector<float>& Drone::GetPosition() const {
  // TODO for lab10: What should this return?
  return position;
}

const std::vector<float>& Drone::GetDirection() const {
  // TODO for lab10: what should this return?
  return direction;
}

float Drone::GetRadius() const {
  // TODO: This is just a stub for compilation
  return radius;
}

int Drone::GetVersion() const {
  // TODO: This is just a stub for compilation
  return version;
}

float Drone::GetSpeed() const {
  return speed;
}

bool Drone::IsDynamic() const {
  // TODO: This is just a stub for compilation
  return isDynamic;
}

void Drone::SetName(std::string newName){
  name = newName;
}

void Drone::SetDynamic(bool b){
  isDynamic = b;
}

void Drone::SetSpeed(float s){
  speed = s;
}

void Drone::SetPackage(Package* pack){
  package.push_back(pack);
}

void Drone::SetCustomer(Customer* cust){
  customer.push_back(cust);
}

Package* Drone::GetPackage(){
  return package[0];
}

Package* Drone::GetPackageAt(int index){
  return package[index];
}

std::vector<Package*> Drone::GetPackages()
{
  return package;
}

Customer* Drone::GetCustomer(){
  return customer[0];
}

Customer* Drone::GetCustomerTail(){
  return customer[customer.size()-1];
}

void Drone::SetLoaded(bool b){
  loaded = b;
}

bool Drone::GetLoaded(){
  return loaded;
}

void Drone::SetPath(std::vector<std::vector<float>> path1, std::vector<std::vector<float>> path2){
  dppath.push_back(path1);
  pcpath.push_back(path2);
}

std::vector<std::vector<std::vector<float>>>& Drone::GetPath(bool loaded){
  if(loaded){
    return pcpath;
  }
  return dppath;
}

void Drone::SetBattery(float cap){
  battery->SetCapacity(cap);
}

float Drone::GetRemainingCharge(){
  battery->GetRemainingCharge();
}

void Drone::SetPath(std::string path){
  path = path;
}



void Drone::Update(float dt, std::vector<std::vector<std::vector<float>>>& path){

  if(isDynamic){
    battery->Drain(speed*0.00008);
    if(battery->GetRemainingCharge() <= 0){
      //isDynamic = false;
      SetBattery(0);
      atcustomer=false;
      //SetHasPackage(false);
      std::cout << "charge = " << battery->GetRemainingCharge() << std::endl;
    }
    Vector3D pos = Vector3D(position[0],position[1],position[2]);
    float distance = speed*dt;

    Vector3D nextDestNode = Vector3D(path[0][0][0],path[0][0][1],path[0][0][2]);
    Vector3D dir = nextDestNode.Minus(pos);
    if(dir.GetMagnitude()<=3){
      path[0].erase(path[0].begin());
      if(path[0].empty()){
        if(loaded){
          package[0]->SetPosition(9999,9999,9999);
          atcustomer=true;
          SetHasPackage(false);
          loaded = false;
          tempPackage=package[0];
          package.erase(package.begin());
          customer.erase(customer.begin());
          if(package.empty()){
            isDynamic = false;
          }
          path.erase(path.begin());
          return;
        }
        else{
          loaded = true;
          package[0]->SetisDynamic(true);
          path.erase(path.begin());
          return;
        }
      }
      nextDestNode = Vector3D(path[0][0][0],path[0][0][1],path[0][0][2]);
      dir = nextDestNode.Minus(pos);
    }

    dir = dir.Normalize();
    direction[0] = dir.GetPosition()[0];
    direction[1] = dir.GetPosition()[1];
    direction[2] = dir.GetPosition()[2];
    std::vector<float> vec = pos.Add(dir.Multiply(distance)).GetPosition();
    position[0] = vec[0];
    position[1] = vec[1];
    position[2] = vec[2];




    if(loaded && GetRemainingCharge() > 0){
      package[0]->SetPosition(position[0], position[1], position[2]);
    }
  }
}

}
