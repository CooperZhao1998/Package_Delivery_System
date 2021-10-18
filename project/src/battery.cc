#include "battery.h"

namespace csci3081{
    Battery::Battery(){
        maxCharge = 10000;
        remainingCharge = 10000;
        chargeCondition = true;
    }

    Battery::Battery(float mcharge, float rcharge, bool condition){
        maxCharge = mcharge;
        remainingCharge = rcharge;
        chargeCondition = condition;
    }
    

    float Battery::GetMaxCharge() const{
        return maxCharge;
    }

    float Battery::GetRemainingCharge() const{
        return remainingCharge;
    }

    bool Battery::GetChargeCondition() const{
        return chargeCondition;
    }

    void Battery::ChangeChargeCondition(bool newCondition){
        chargeCondition = newCondition;
    }

    void Battery::SetCapacity(float cap){
        maxCharge = cap;
        remainingCharge = cap;
    }

    void Battery::Drain(float unit){
        remainingCharge -= unit;
    }
}