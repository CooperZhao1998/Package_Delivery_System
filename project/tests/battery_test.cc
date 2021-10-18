#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "battery.h"

namespace csci3081{



    class BatteryTest : public::testing::Test{
        public:
            void SetUp(){
                initialBattery =Battery();
                usedBattery = Battery(10000, 300, true);
                brokenBattery = Battery(100, 200, false);                
            }

        protected:
            Battery initialBattery;
            Battery usedBattery;
            Battery brokenBattery;
            
    };

    TEST_F(BatteryTest, BatteryConstructorAndBoolGetters){
        bool usedBattery_expect_condition = true;
        EXPECT_EQ(usedBattery.GetChargeCondition(), usedBattery_expect_condition) << "battery condition getters not setup properly";

        bool broken_expect_condition = false;
        EXPECT_EQ(brokenBattery.GetChargeCondition(), broken_expect_condition) << "battery condition getters not setup properly";

        bool init_expect_condition = true;
        EXPECT_EQ(initialBattery.GetChargeCondition(), init_expect_condition) << "battery condition getters not setup properly";


    }

    TEST_F(BatteryTest, Battery_GetRemainingCharge){
        EXPECT_EQ(usedBattery.GetRemainingCharge(), 300.0) << "GetRemainingCharge is not setup correctly";
    }

    TEST_F(BatteryTest, Battery_GetMaxCharge){
        EXPECT_EQ(usedBattery.GetMaxCharge(), 10000.0) << "GetMaxCharge is not setup correctly";
    }

    TEST_F(BatteryTest, Battery_GetChargeCondition){
        EXPECT_EQ(usedBattery.GetChargeCondition(), true) << "GetChargeCondition is not setup correctly";
    }

}