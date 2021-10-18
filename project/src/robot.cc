#include "robot.h"
#include "json_helper.h"

namespace csci3081 {

Robot::Robot(std::vector<float> pos, std::vector<float> direct, const picojson::object& obj) {
  // TODO for lab10: store the position and direction vectors.

  position = pos;
  direction = direct;



  // name = JsonHelper::GetString(obj, "name");
  // The following line saves the json object in the details_ member variable
  // from the EntityBase class, in order to return it later in GetDetails()
  details_ = obj;
}
Robot::~Robot(){}



const std::string& Robot::GetName() {
  // TODO for lab10: What should this return?
  return name;
}

int Robot::GetId() const{
  return id;
}

// void Robot::SetName(std::string& newName){
//   name = newName;
// }

const std::vector<float>& Robot::GetPosition() const {
  // TODO for lab10: What should this return?
  return position;
}

const std::vector<float>& Robot::GetDirection() const {
  // TODO for lab10: what should this return?
  return direction;
}

float Robot::GetRadius() const {
  // TODO: This is just a stub for compilation
  return radius;
}

int Robot::GetVersion() const {
  // TODO: This is just a stub for compilation
  return version;
}

float Robot::GetSpeed() const {
  return speed;
}

bool Robot::IsDynamic() const {
  // TODO: This is just a stub for compilation
  return isDynamic;
}

void Robot::SetName(std::string newName){
  name = newName;
}

void Robot::SetDynamic(bool b){
  isDynamic = b;
}

void Robot::SetSpeed(float s){
  speed = s;
}

void Robot::SetPackage(Package* pack){
  package.push_back(pack);
}

void Robot::SetCustomer(Customer* cust){
  customer.push_back(cust);
}

Package* Robot::GetPackage(){
  return package[0];
}

Customer* Robot::GetCustomer(){
  return customer[0];
}

Customer* Robot::GetCustomerTail(){
  return customer[customer.size()-1];
}

void Robot::SetLoaded(bool b){
  loaded = b;
}

bool Robot::GetLoaded(){
  return loaded;
}

void Robot::SetPath(std::vector<std::vector<float>> path1, std::vector<std::vector<float>> path2){
  rppath.push_back(path1);
  pcpath.push_back(path2);
}

std::vector<std::vector<std::vector<float>>>& Robot::GetPath(bool loaded){
  if(loaded){
    return pcpath;
  }
  return rppath;
}

void Robot::SetBattery(float cap){
  battery->SetCapacity(cap);
}

float Robot::GetRemainingCharge(){
  battery->GetRemainingCharge();
}

void Robot::SetPath(std::string path){
  path = path;
}

std::vector<Package*> Robot::GetPackages()
{
  return package;
}

bool Robot::HasAPackage()
{
  return HasPackageR;
}
void Robot::SetHasPackage(bool state)
{
  HasPackageR=state;
}


void Robot::Update(float dt, std::vector<std::vector<std::vector<float>>>& path){
  if(isDynamic){
    battery->Drain(0.003);
    if(battery->GetRemainingCharge() <= 0){
      //isDynamic = false;
      SetBattery(0);
      //SetHasPackage(false);
      std::cout << "charge = " << battery->GetRemainingCharge() << std::endl;
    }
    Vector2D pos = Vector2D(position[0],position[2]);
    float distance = speed*dt;

    Vector2D nextDestNode = Vector2D(path[0][0][0],path[0][0][2]);
    Vector2D dir = nextDestNode.Minus(pos);
    if(dir.GetMagnitude()<=3){
      path[0].erase(path[0].begin());
      if(path[0].empty()){
        if(loaded){
          package[0]->SetPosition(9999,9999,9999);
          SetAtCustomer(true);
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
      nextDestNode = Vector2D(path[0][0][0],path[0][0][2]);
      dir = nextDestNode.Minus(pos);
    }

    dir = dir.Normalize();
    direction[0] = dir.GetPosition()[0];
    direction[2] = dir.GetPosition()[2];
    std::vector<float> vec = pos.Add(dir.Multiply(distance)).GetPosition();
    position[0] = vec[0];
    position[2] = vec[2];




    if(loaded && GetRemainingCharge() > 0){
      package[0]->SetPosition(position[0], position[1], position[2]);
    }
  }
}

}
