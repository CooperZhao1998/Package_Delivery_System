#include "delivery_simulation.h"
#include "entity_base.h"
#include "json_helper.h"
#include "scheduler.h"

namespace csci3081 {

DeliverySimulation::DeliverySimulation() {
	    // fac->AddFactory(new DroneFactory());
        // fac->AddFactory(new PackageFactory());
        // fac->AddFactory(new CustomerFactory());

}

DeliverySimulation::~DeliverySimulation() {}

IEntity* DeliverySimulation::CreateEntity(const picojson::object& val) {
	IEntity* ret = fac->CreateEntity(val);
	return ret;
}

void DeliverySimulation::AddFactory(IEntityFactory* factory) {
	fac->AddFactory(factory);
}

void DeliverySimulation::AddEntity(IEntity* entity) {
  entities_.push_back(entity);
}

void DeliverySimulation::SetGraph(const IGraph* graph) {
	graph_ = graph;
}

void DeliverySimulation::ScheduleDelivery(IEntity* package, IEntity* dest) {

	//std::cout<<"scheduledelivery run ------------------------";
	for(IEntity* entity : entities_){
		std::string type = JsonHelper::GetString(entity->GetDetails(), "type");
		if(type.compare("drone") == 0){
			Drone* drone = dynamic_cast<Drone*>(entity);
			if(!drone->IsDynamic()){
				drone->SetDynamic(true);
				drone->SetPackage(dynamic_cast<Package*>(package));
				drone->SetCustomer(dynamic_cast<Customer*>(dest));
				//Added by zjy
				std::string pathA;
				if(JsonHelper::ContainsKey(drone->GetDetails(),"path")){
					pathA = JsonHelper::GetString(drone->GetDetails(), "path");
				}
				else{
					pathA = "smart";
				}
				IStrategy *PathStrategy[3];
				PathStrategy[0] = new Smart(graph_);
				PathStrategy[1] = new Beeline();
				PathStrategy[2] = new Parabolic();
				if(pathA.compare("smart") == 0)
				{
					// PathStrategy = new Smart();
					drone->SetPath(PathStrategy[0]->GetRoute(drone->GetPosition(), package->GetPosition()), PathStrategy[0]->GetRoute(package->GetPosition(), dest->GetPosition()));
				}
				if(pathA.compare("beeline") == 0)
				{
					// PathStrategy = new Beeline();
					drone->SetPath(PathStrategy[1]->GetRoute(drone->GetPosition(), package->GetPosition()), PathStrategy[1]->GetRoute(package->GetPosition(), dest->GetPosition()));
				}
				if(pathA.compare("parabolic") == 0)
				{
					// PathStrategy = new Parabolic();
					drone->SetPath(PathStrategy[2]->GetRoute(drone->GetPosition(), package->GetPosition()), PathStrategy[2]->GetRoute(package->GetPosition(), dest->GetPosition()));
				}
				//removed
				//drone->SetPath(graph_->GetPath(drone->GetPosition(), package->GetPosition()), graph_->GetPath(package->GetPosition(), dest->GetPosition()));

				// observer for package
				picojson::object obj = JsonHelper::CreateJsonNotification();
				JsonHelper::AddStringToJsonObject(obj, "value", "scheduled");
				picojson::value val = JsonHelper::ConvertPicojsonObjectToValue(obj);
				for(IEntityObserver* observer:observers)
				{
					observer->OnEvent(val,*drone->GetPackages().back());

				}
				drone->GetPackage()->SetisDynamic(false);

				//observer for drone
				picojson::object objd = JsonHelper::CreateJsonNotification();
				JsonHelper::AddStringToJsonObject(objd, "value", "moving");
				JsonHelper:: AddStdVectorVectorFloatToJsonObject(objd, "path",(drone->GetPath(false)[0]));
				picojson::value vald = JsonHelper::ConvertPicojsonObjectToValue(objd);
				for(IEntityObserver* observer:observers)
				{
					observer->OnEvent(vald,*drone);
				}
				//std::cout<<"end observe"<<"\n";
				drone->SetHasPackage(false);
				drone->SetAtCustomer(false);


				//std::cout<<"check0"<<std::endl;
				writers.push_back(writer);
				std::vector<std::vector<std::vector<float>>> auditPath;
				//get path type
				writer->setPathType(pathA);
				auditPath.push_back(drone->GetPath(false)[0]);
				auditPath.push_back(drone->GetPath(true)[0]);
				writer->droneAudit(auditPath, drone->GetPackage(), drone->GetCustomer(), drone);
				writer->AddPackageTime(drone->GetPackage());
				return;
			}
		}

		if(type.compare("robot") == 0){
			Robot* robot = dynamic_cast<Robot*>(entity);
			if(!robot->IsDynamic()){
				robot->SetDynamic(true);
				robot->SetPackage(dynamic_cast<Package*>(package));
				robot->SetCustomer(dynamic_cast<Customer*>(dest));
				robot->SetPath(graph_->GetPath(robot->GetPosition(), package->GetPosition()), graph_->GetPath(package->GetPosition(), dest->GetPosition()));
				picojson::object obj = JsonHelper::CreateJsonNotification();
				JsonHelper::AddStringToJsonObject(obj, "value", "scheduled");
				picojson::value val = JsonHelper::ConvertPicojsonObjectToValue(obj);
				for(IEntityObserver* observer:observers)
				{
					observer->OnEvent(val,*robot->GetPackage());
				}
				//observer for robot
				picojson::object objd = JsonHelper::CreateJsonNotification();
				JsonHelper::AddStringToJsonObject(objd, "value", "moving");
				JsonHelper:: AddStdVectorVectorFloatToJsonObject(objd, "path",(robot->GetPath(false)[0]));
				picojson::value vald = JsonHelper::ConvertPicojsonObjectToValue(objd);
				for(IEntityObserver* observer:observers)
				{
					observer->OnEvent(vald,*robot);
				}
				robot->SetHasPackage(false);
				robot->SetAtCustomer(false);
				//std::cout<<"check1"<<std::endl;
				return;
			}

		}
	}
	for(IEntity* entity : entities_){
		std::string type = JsonHelper::GetString(entity->GetDetails(), "type");
		//std::cout<<for_drone<<"-----------------------"<<"\n";
			if(type.compare("drone") == 0){
				if(for_drone)
				{
					for_drone=false;
					Drone* drone = dynamic_cast<Drone*>(entity);
					drone->SetDynamic(true);
					drone->SetPackage(dynamic_cast<Package*>(package));
					drone->SetCustomer(dynamic_cast<Customer*>(dest));
					//route setup
					drone->SetPath(graph_->GetPath(drone->GetCustomerTail()->GetPosition(), package->GetPosition()), graph_->GetPath(package->GetPosition(), dest->GetPosition()));
					// create observer
					picojson::object obj = JsonHelper::CreateJsonNotification();
					JsonHelper::AddStringToJsonObject(obj, "value", "scheduled");
					picojson::value val = JsonHelper::ConvertPicojsonObjectToValue(obj);
					for(IEntityObserver* observer:observers)
					{
						observer->OnEvent(val,*drone->GetPackages().back());
					}
					drone->SetHasPackage(false);
					drone->SetAtCustomer(false);

					//std::cout<<"check0"<<std::endl;
					writers.push_back(writer);
					std::vector<std::vector<std::vector<float>>> auditPath;
					//get path type
					writer->setPathType("smart");
					auditPath.push_back(drone->GetPath(false)[0]);
					auditPath.push_back(drone->GetPath(true)[0]);
					writer->droneAudit(auditPath, drone->GetPackage(), drone->GetCustomer(), drone);
					writer->AddPackageTime(drone->GetPackage());
					return;
				}

			}

			if(type.compare("robot") == 0){
				if(!for_drone)
				{
					for_drone=true;
					Robot* robot = dynamic_cast<Robot*>(entity);
					robot->SetDynamic(true);
					robot->SetPackage(dynamic_cast<Package*>(package));
					robot->SetCustomer(dynamic_cast<Customer*>(dest));
					robot->SetPath(graph_->GetPath(robot->GetCustomerTail()->GetPosition(), package->GetPosition()), graph_->GetPath(package->GetPosition(), dest->GetPosition()));
					picojson::object obj = JsonHelper::CreateJsonNotification();
					JsonHelper::AddStringToJsonObject(obj, "value", "scheduled");
					picojson::value val = JsonHelper::ConvertPicojsonObjectToValue(obj);
					for(IEntityObserver* observer:observers)
					{
						observer->OnEvent(val,*robot->GetPackage());
					}
					//observer for robot
					robot->SetHasPackage(false);
					robot->SetAtCustomer(false);
					//std::cout<<"check1"<<std::endl;
					return;
				}

			}





	}
}

void DeliverySimulation::AddObserver(IEntityObserver* observer) {
	observers.push_back(observer);
}

void DeliverySimulation::RemoveObserver(IEntityObserver* observer) {
	observers.erase(std::remove(observers.begin(),observers.end(),observer),observers.end());
}

const std::vector<IEntity*>& DeliverySimulation::GetEntities() const { return entities_; }

void DeliverySimulation::Update(float dt) {
	//<<"start updating"<<"\n";
	for(IEntity* entity : entities_){
		std::string type_ = JsonHelper::GetString(entity->GetDetails(), "type");

		if(type_.compare("drone") == 0){
			//std::cout<<"start updating -----drone"<<"\n";
			Drone* newWorker = dynamic_cast<Drone*>(entity);
			newWorker->Update(dt, newWorker->GetPath(newWorker->GetLoaded()));


			if(!newWorker->HasAPackage() && newWorker->GetLoaded())
			{
				if(newWorker->GetPackage()->IsDynamic())
				{
					picojson::object obj = JsonHelper::CreateJsonNotification();
					JsonHelper::AddStringToJsonObject(obj, "value", "en route");
					picojson::value val = JsonHelper::ConvertPicojsonObjectToValue(obj);
					for(IEntityObserver* observer:observers)
					{
						observer->OnEvent(val,*newWorker->GetPackage());
					}
					writer->GetPackageDuration(newWorker,newWorker->GetPackage(),"en route");
				}

				newWorker->SetHasPackage(true);
			}

			//
		if(newWorker->GetRemainingCharge() == 0){
			if(newWorker->IsDynamic()){
				//std::cout <<"has a package ? " << newWorker->HasAPackage() << std::endl;
				newWorker->SetDynamic(false);
				picojson::object objd = JsonHelper::CreateJsonNotification();
				JsonHelper::AddStringToJsonObject(objd, "value", "idle");
				picojson::value vald = JsonHelper::ConvertPicojsonObjectToValue(objd);
				for(IEntityObserver* observer:observers)
				{
					observer->OnEvent(vald,*newWorker);
				}
				//std::cout<<"end observepp"<<"\n";

			}
			if(!newWorker->GetReschedule())
			{
				for(IEntity* find_next : entities_){
					std::string type__ = JsonHelper::GetString(find_next->GetDetails(), "type");
					if(type__.compare("drone") == 0){
						Drone* new_Worker = dynamic_cast<Drone*>(find_next);
						if(new_Worker->GetPackages().empty() && new_Worker->GetRemainingCharge() > 0){
							scheduler* reschedule=new scheduler;
							//std::cout<<"start reschedule"<<"\n";
							reschedule->scheduleDel(newWorker,graph_,new_Worker,newWorker->GetPackage(),newWorker->GetCustomer());
							// observe for drone
							picojson::object robjd = JsonHelper::CreateJsonNotification();
							JsonHelper::AddStringToJsonObject(robjd, "value", "moving");
							picojson::value rvald = JsonHelper::ConvertPicojsonObjectToValue(robjd);
							for(IEntityObserver* observer:observers)
							{
								observer->OnEvent(rvald,*new_Worker);
							}
							//observe for pacakge

							picojson::object obj_p = JsonHelper::CreateJsonNotification();
							JsonHelper::AddStringToJsonObject(obj_p, "value", "scheduled");
							picojson::value val_p = JsonHelper::ConvertPicojsonObjectToValue(obj_p);
							for(IEntityObserver* observer:observers)
							{
								observer->OnEvent(val_p,*new_Worker->GetPackage());
							}


							//std::cout<<"end reschedule"<<"\n";
							newWorker->SetLoaded(false);
							return;
						}

					}
					}
				//std::cout<<"end loop "<<"\n";
				return;
			}

		}else if(!newWorker->IsDynamic())
			{
				if(!newWorker->HasAPackage())
				{
					picojson::object objd = JsonHelper::CreateJsonNotification();
					JsonHelper::AddStringToJsonObject(objd, "value", "idle");
					picojson::value vald = JsonHelper::ConvertPicojsonObjectToValue(objd);
					for(IEntityObserver* observer:observers)
					{
						observer->OnEvent(vald,*newWorker);
					}
					//std::cout<<"end observe"<<"\n";
					newWorker->SetHasPackage(true);
				}

		}
		//std::cout << newWorker->IsAtCustomer()<<"is at Customer" << '\n';
		if(newWorker->IsAtCustomer())
		{
				picojson::object obj = JsonHelper::CreateJsonNotification();
				JsonHelper::AddStringToJsonObject(obj, "value", "delivered");
				picojson::value val = JsonHelper::ConvertPicojsonObjectToValue(obj);
				for(IEntityObserver* observer:observers)
				{
					observer->OnEvent(val,*newWorker->GetTempPac());
				}
				newWorker->SetAtCustomer(false);
				writer->GetPackageDuration(newWorker,newWorker->GetPackage(),"delivered");
		}


	}

		else if(type_.compare("robot") == 0){

			Robot* newWorker = dynamic_cast<Robot*>(entity);
			newWorker->Update(dt, newWorker->GetPath(newWorker->GetLoaded()));
			//std::cout<<"start updating----robot"<<"\n";
			if(!newWorker->HasAPackage() && newWorker->GetLoaded())
			{
				if(newWorker->GetPackage()->IsDynamic())
				{
					picojson::object obj = JsonHelper::CreateJsonNotification();
					JsonHelper::AddStringToJsonObject(obj, "value", "en route");
					picojson::value val = JsonHelper::ConvertPicojsonObjectToValue(obj);
					for(IEntityObserver* observer:observers)
					{
						observer->OnEvent(val,*newWorker->GetPackage());
					}
				}
				//observe for drone
				/*picojson::object objd = JsonHelper::CreateJsonNotification();
				JsonHelper::AddStringToJsonObject(objd, "value", "moving");
				JsonHelper:: AddStdVectorVectorFloatToJsonObject(objd, "path",newWorker->GetPath(newWorker->GetLoaded())[0]);
				picojson::value vald = JsonHelper::ConvertPicojsonObjectToValue(objd);

				for(IEntityObserver* observer:observers)
				{
					observer->OnEvent(vald,*newWorker);
				}
				*/
				std::cout<<"end observe"<<"\n";
				newWorker->SetHasPackage(true);
			}

			if(newWorker->GetRemainingCharge() == 0){
				//std::cout << "robot battery down" << '\n';
				if(newWorker->IsDynamic()){
					newWorker->SetDynamic(false);
					picojson::object objd = JsonHelper::CreateJsonNotification();
					JsonHelper::AddStringToJsonObject(objd, "value", "idle");
					picojson::value vald = JsonHelper::ConvertPicojsonObjectToValue(objd);
					for(IEntityObserver* observer:observers)
					{
						observer->OnEvent(vald,*newWorker);
					}
				}
			//	std::cout << newWorker->GetReschedule()<<"rescheduling the package for robot --------------------" << '\n';

				if(!newWorker->GetReschedule())
					{
						for(IEntity* find_next : entities_){
						std::string type___ = JsonHelper::GetString(find_next->GetDetails(), "type");
						if(type___.compare("robot") == 0){
							Robot* new_Worker = dynamic_cast<Robot*>(find_next);
							if(new_Worker->GetPackages().empty())
							{
								scheduler* reschedule=new scheduler;
							//	std::cout<<"start reschedule"<<"\n";
					      reschedule->scheduleRobot(newWorker,graph_,new_Worker,newWorker->GetPackage(),newWorker->GetCustomer());
								picojson::object robjd = JsonHelper::CreateJsonNotification();
								JsonHelper::AddStringToJsonObject(robjd, "value", "moving");
								picojson::value rvald = JsonHelper::ConvertPicojsonObjectToValue(robjd);
								for(IEntityObserver* observer:observers)
								{
									observer->OnEvent(rvald,*new_Worker);
								}

								picojson::object obj_p = JsonHelper::CreateJsonNotification();
								JsonHelper::AddStringToJsonObject(obj_p, "value", "scheduled");
								picojson::value val_p = JsonHelper::ConvertPicojsonObjectToValue(obj_p);
								for(IEntityObserver* observer:observers)
								{
									observer->OnEvent(val_p,*new_Worker->GetPackage());
								}
								newWorker->SetLoaded(false);
								//std::cout<<"end reschedule"<<"\n";
								return;
					}
					return;
					}
					}
				}
			}else if(!newWorker->IsDynamic())
			{
				if(!newWorker->HasAPackage())
				{
					picojson::object objd = JsonHelper::CreateJsonNotification();
					JsonHelper::AddStringToJsonObject(objd, "value", "idle");
					picojson::value vald = JsonHelper::ConvertPicojsonObjectToValue(objd);
					for(IEntityObserver* observer:observers)
					{
						observer->OnEvent(vald,*newWorker);
					}
					newWorker->SetHasPackage(true);

				}
			}

			if(newWorker->IsAtCustomer())
			{
					picojson::object obj = JsonHelper::CreateJsonNotification();
					JsonHelper::AddStringToJsonObject(obj, "value", "delivered");
					picojson::value val = JsonHelper::ConvertPicojsonObjectToValue(obj);
					for(IEntityObserver* observer:observers)
					{
						observer->OnEvent(val,*newWorker->GetTempPac());
					}
					newWorker->SetAtCustomer(false);

			}
		}

}
//std::cout<<"end updating"<<"\n";
}



// DO NOT MODIFY THE FOLLOWING UNLESS YOU REALLY KNOW WHAT YOU ARE DOING
void DeliverySimulation::RunScript(const picojson::array& script, IEntitySystem* system) const {
  JsonHelper::PrintArray(script);
  IDeliverySystem* deliverySystem = dynamic_cast<IDeliverySystem*>(system);
	if (deliverySystem) {

	    // To store the unadded entities_
	    std::vector<IEntity*> created_entities;

		for (unsigned int i=0; i < script.size(); i++) {
			const picojson::object& object = script[i].get<picojson::object>();
			const std::string cmd = object.find("command")->second.get<std::string>();
			const picojson::object& params = object.find("params")->second.get<picojson::object>();
			// May want to replace the next few if-statements with an enum
			if (cmd == "createEntity") {
				IEntity* entity = NULL;
				entity = deliverySystem->CreateEntity(params);
				if (entity) {
					created_entities.push_back(entity);
				} else {
					std::cout << "Null entity" << std::endl;
				}
			}
			else if (cmd == "addEntity") {
				int ent_index = static_cast<int>(params.find("index")->second.get<double>());
				if (ent_index >= 0 && ent_index < created_entities.size()) {
					deliverySystem->AddEntity(created_entities[ent_index]);
				}
			}
			else if (cmd == "scheduleDelivery" ) {
				int pkg_index = static_cast<int>(params.find("pkg_index")->second.get<double>());
				int dest_index = static_cast<int>(params.find("dest_index")->second.get<double>());
				if (pkg_index >= 0 && pkg_index < system->GetEntities().size()) {
					IEntity* pkg = deliverySystem->GetEntities()[pkg_index];
					if (dest_index >= 0 && pkg_index < system->GetEntities().size()) {
						IEntity* cst = system->GetEntities()[dest_index];
						if (pkg && cst) {
							deliverySystem->ScheduleDelivery(pkg, cst);
						}
					}
				}
				else {
					std::cout << "Failed to schedule delivery: invalid indexes" << std::endl;
				}
			}
		}
	}
}

}
