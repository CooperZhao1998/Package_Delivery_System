/**
 *@file statisticsWriter.h
 */
#ifndef STATISTICS_
#define STATISTICS_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include "json_helper.h"
#include "package.h"
#include "customer.h"
#include "drone.h"
#include "robot.h"
#include "vector3D.h"

using namespace std;
namespace csci3081{
/*******************************************************************************
* Class Definitions
******************************************************************************/
/**
* @brief This class user Singleton pattern to collect the data generated
* from the simulation. The data contains the time, location, distance and route
* type for drone to deliever the package.
*/

class StatisticsWriter{
    static StatisticsWriter *instance;
    public:
        /**
        * Create an instance that can be used in all class
        *
        * @return an instance of StatisticsWriter class
        */
        static StatisticsWriter *getInstance()
        {
          if(!instance)
          {
            instance = new StatisticsWriter;
            return instance;
          }
        }

        /**
        * Constructor for StatisticsWriter class
        *
        */
        StatisticsWriter(){
        };
        /**
        * Destructor for StatisticsWriter class
        *
        */
        ~StatisticsWriter(){};

        /**
        * Collect the data of the location, route type, and distance into csv file
        * @param path path choosed by the drone
        * @param pack package entity
        * @param cust customer entity
        * @param carrier drone entity
        * @return void
        */
        void droneAudit(std::vector<std::vector<std::vector<float>>> path, IEntity* pack, IEntity* cust, Drone* carrier){

            package = dynamic_cast<Package*>(pack);
            customer = dynamic_cast<Customer*>(cust);
            drone = dynamic_cast<Drone*>(carrier);
            // time_t rawtime;
            // struct tm * timeinfo;
            // time(&rawtime);
            // //timeinfo = localtime(&rawtime);

            // timeinfo = localtime(&rawtime);
            // // auditfile.open("audit--%s.txt", timeinfo);
            std::string filename = "audit--" + drone->GetName() + ".csv";
            auditfile.open(filename,ios::app);


            auditfile << "Audit file for Drone," << std::endl;
            auditfile << "scheduled package ,<" << package->GetName()<<">" << std::endl;
            auditfile << " , X, Y, Z"<<std::endl;
            auditfile << "position ,<" << package->GetPosition()[0] << "," << package->GetPosition()[1] << "," << package->GetPosition()[2] << ">" << std::endl;

            auditfile << "scheduled customer ,<" << customer->GetName() << ">" << std::endl;
            auditfile << " , X, Y, Z"<<std::endl;
            auditfile << "position ,<" << customer->GetPosition()[0] << "," << customer->GetPosition()[1] << "," << customer->GetPosition()[2] << ">" << std::endl;

            //calculate distance of the path
            float distance1 = 0;
            std::vector<std::vector<float>> path1 = path[0];
            for(int i = 0; i < path1.size()-1; i ++){
                Vector3D p = Vector3D(path1[i+1][0],path1[i+1][1],path1[i+1][2]);
                distance1 += Vector3D(path1[i][0],path1[i][1],path1[i][2]).GetDistanceBetween(p);
            }

            float distance2 = 0;
            std::vector<std::vector<float>> path2 = path[1];
            for(int i = 0; i < path2.size()-1; i ++){
                Vector3D p = Vector3D(path2[i+1][0],path2[i+1][1],path2[i+1][2]);
                distance2 += Vector3D(path2[i][0],path2[i][1], path2[i][2]).GetDistanceBetween(p);
            }

            distance = distance1 + distance2;

            auditfile << "Distance from drone to package,"<<distance1<<std::endl;
            auditfile << "Distance from package to customer," << distance2 << std::endl;
            auditfile << "Total Distance," << distance << std::endl;


           //route type
           auditfile<<"path Type,"<<path_<<std::endl;
           auditfile.close();
          }

          /**
          * Set the path type of the data
          * @param path path choosed by the drone
          * @return void
          */
          void setPathType(string path){
            path_=path;
          }

          /**
           * Get the path type of the data
           * @return string
           */
          std::string getPathType(){
              return path_;
          }

          /**
          * Add the package start time
          * @param package
          * @return void
          */
          void AddPackageTime(Package* package)
          {
            package->packageStartTime();
          }
          /**
          * Get the package duration time for pick up the package and deliever
          * to the customer
          * @param drone
          * @param package
          * @param value route type for thr drone
          * @return void
          */
          void GetPackageDuration(Drone* drone,Package* package,string value)
          {

            std::string filename = "audit----" + package->GetName() + ".csv";
            auditfile.open(filename,ios::app);

            if(value.compare("en route")==0)
            {
              auditfile << "time cost of package delivery by," <<drone->GetName()<<std::endl;
              time_duration=package->GetDurationTime();
              package->SetTime(time_duration);
              auditfile << "Time cost from scheduled to picked up," <<time_duration<<std::endl;
            }else{
              time_duration=package->GetDurationTime();
              auditfile << "Time cost from scheduled to delivered," << time_duration<<std::endl;
              auditfile << "Time cost from picked up to delivered," << package->GetTimeFromPickToDel(time_duration)<<std::endl;
            }

            auditfile.close();
          }


      private:
          double time_duration;
          std::ofstream auditfile;
          Drone* drone;
          Robot* robot;
          Package* package;
          Customer* customer;
          std::string path_;
          float distance = 0;
  };
}
#endif // STATISTICSWRITER_H——
