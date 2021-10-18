/**
 *@file battery.h
 */
#ifndef BATTERY_H_
#define BATTERY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

namespace csci3081{
  /*******************************************************************************
   * Class Definitions
   ******************************************************************************/
  /**
  *@brief battery class store information of a single battery on bounded on a drone class.
  */
  class Battery{
  public:
            /**
             * default battery constructor
             */
            Battery();
            /**
             * battery constructor with set properties
             * @param maxCharge a float indicates the max charge of the battery
             * @param remainingCharge a float indicates the remaining charge resides in the battery
             * @param chargeCondition a boolean indicates if the battery is available
             */
            Battery(float maxCharge, float remainingCharge, bool chargeCondition);
            /**
             * return the max charge of the battery
             * @return maxCharge
             */
            float GetMaxCharge() const;
            /**
             * return the remaining charge in the battery
             * @return remainingCharge
             */
            float GetRemainingCharge() const;
            /**
             * return the battery condition as a boolean
             * @return chargeCondition
             */
            bool GetChargeCondition() const;

            /**
             * set the chargeCondition
             * @param newCondition
             */
            void ChangeChargeCondition(bool newCondition);

            /**
             * set the battery capacity
             * @param float cap
             */
            void SetCapacity(float cap);

            /**
             * Drain the battery while moving
             * @param float unit
             */
            void Drain(float unit);

        private:

            float maxCharge;
            float remainingCharge;
            bool chargeCondition;
    };

}

#endif
