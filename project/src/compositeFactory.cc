#include "compositeFactory.h"

namespace csci3081{
    

    void CompositeFactory::AddFactory(IEntityFactory* object){
        factories.push_back(object);
    }


    void CompositeFactory::Remove(int index){
        factories.erase(factories.begin() + index);
    }


    CompositeFactory::CompositeFactory(){
        factories.push_back(new DroneFactory());
        factories.push_back(new PackageFactory());
        factories.push_back(new CustomerFactory());
        factories.push_back(new RobotFactory());
    }

    CompositeFactory::~CompositeFactory(){
        // for(IEntityFactory* fac : factories){
        //     delete fac;
        // }
    }


    IEntity* CompositeFactory::CreateEntity(const picojson::object& val){
        for(IEntityFactory* component : factories){
            IEntity* entity = component->CreateEntity(val);
            if(entity){
                return entity;
            }
        }
    }

}