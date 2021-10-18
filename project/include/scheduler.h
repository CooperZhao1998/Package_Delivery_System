/**
 *@file scheduler.h
 */
#ifndef SCHEDULER_H_
#define SCHEDULER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity_base.h"
#include "json_helper.h"



namespace csci3081{
/*******************************************************************************
* Class Definitions
******************************************************************************/
/**
 * @brief scheduler class
 * this class defined the schedule funtions for both drone and robot
 */
class scheduler{
public:

  /**
   * schedule delivery of drone
   * @param graph_ Igraph for scheduleing path
   * @param drone the drone to schedule
   * @param package the package to schedule
   * @param dest the customer/destination to schedule
   */
  void scheduleDel(Drone* olddrone,const IGraph* graph__,Drone* drone,Package* package,Customer* dest)
  {
    if(!drone->IsDynamic()){
      drone->SetDynamic(true);
      drone->SetPackage(package);
      drone->SetCustomer(dest);
      drone->SetPath(graph__->GetPath(drone->GetPosition(), package->GetPosition()), graph__->GetPath(package->GetPosition(), dest->GetPosition()));
      drone->SetHasPackage(false);
      drone->SetAtCustomer(false);
      olddrone->SetReschedule(true);
  }
  return;
}

  /**
   * scheudle delivery of robot
   * @param graph_ Igraph for schedule path
   * @param robot the robot to schedule
   * @param package the package to schedule
   * @param dest the customer/destination to schedule
   */
  void scheduleRobot(Robot* oldrobot,const IGraph* graph__,Robot* robot,Package* package,Customer* dest)
  {
    if(!robot->IsDynamic()){
      robot->SetDynamic(true);
      robot->SetPackage(package);
      robot->SetCustomer(dest);
      robot->SetPath(graph__->GetPath(robot->GetPosition(), package->GetPosition()), graph__->GetPath(package->GetPosition(), dest->GetPosition()));
      robot->SetHasPackage(false);
      robot->SetAtCustomer(false);
      oldrobot->SetReschedule(true);
  }
  return;
}



};
}
#endif
