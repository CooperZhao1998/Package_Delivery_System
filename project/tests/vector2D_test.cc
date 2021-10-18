#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "vector2D.h"

namespace csci3081{

    class Vector2DTest : public :: testing :: Test{
        public:
            void SetUp(){
                initVector = Vector2D();
                vector3 = Vector2D(2,2);
        }

        protected:
            Vector2D initVector;
            Vector2D vector3;

    };

    TEST_F(Vector2DTest, Vector2DConstructor){
        std::vector<float> init_expected_position;
        init_expected_position.push_back(0);
        init_expected_position.push_back(0);
        init_expected_position.push_back(0);
        ASSERT_FLOAT_EQ(initVector.GetPosition()[0], init_expected_position[0]);
        ASSERT_FLOAT_EQ(initVector.GetPosition()[1], init_expected_position[1]);
        ASSERT_FLOAT_EQ(initVector.GetPosition()[2], init_expected_position[2]);

        std::vector<float> vector3_expected_position;
        vector3_expected_position.push_back(2);
        vector3_expected_position.push_back(0);
        vector3_expected_position.push_back(2);
        ASSERT_FLOAT_EQ(vector3.GetPosition()[0], vector3_expected_position[0]);
        ASSERT_FLOAT_EQ(vector3.GetPosition()[1], vector3_expected_position[1]);
        ASSERT_FLOAT_EQ(vector3.GetPosition()[2], vector3_expected_position[2]);


    }

    TEST_F(Vector2DTest, Vector2D_GetMagnitude){
        EXPECT_EQ(vector3.GetMagnitude(), (float)sqrt(8)) << "Vector2D_GetMagnitude is not setup correctly";
    }

    TEST_F(Vector2DTest, Vector2D_Multiply){
        std::vector<float> vector3_expected_position;
        vector3_expected_position.push_back(2);
        vector3_expected_position.push_back(0);
        vector3_expected_position.push_back(2);
        vector3.Multiply(1);
        ASSERT_FLOAT_EQ(vector3.GetPosition()[0], vector3_expected_position[0]);
        ASSERT_FLOAT_EQ(vector3.GetPosition()[1], vector3_expected_position[1]);
        ASSERT_FLOAT_EQ(vector3.GetPosition()[2], vector3_expected_position[2]);
    }
    TEST_F(Vector2DTest, Vector2D_Add){
        Vector2D addtest(1,1);
        Vector2D expected(3,3);
        vector3.Add(addtest);
        ASSERT_FLOAT_EQ(vector3.GetPosition()[0], expected.GetPosition()[0]);
        ASSERT_FLOAT_EQ(vector3.GetPosition()[1], expected.GetPosition()[1]);
        ASSERT_FLOAT_EQ(vector3.GetPosition()[2], expected.GetPosition()[2]);
    }
    TEST_F(Vector2DTest, Vector2D_Minus){
        Vector2D mintest(1,1);
        Vector2D expected(1,1);
        vector3.Minus(mintest);
        ASSERT_FLOAT_EQ(vector3.GetPosition()[0], expected.GetPosition()[0]);
        ASSERT_FLOAT_EQ(vector3.GetPosition()[1], expected.GetPosition()[1]);
        ASSERT_FLOAT_EQ(vector3.GetPosition()[2], expected.GetPosition()[2]);
    }
    TEST_F(Vector2DTest, Vector2D_Normalize){
        ASSERT_FLOAT_EQ(vector3.Normalize().GetPosition()[0], 2/(sqrt(8)));
        ASSERT_FLOAT_EQ(vector3.Normalize().GetPosition()[1], 0);
        ASSERT_FLOAT_EQ(vector3.Normalize().GetPosition()[2], 2/(sqrt(8)));
    }
    TEST_F(Vector2DTest, Vector2D_GetDistanceBetween){
        Vector2D disttest(2,2);
        ASSERT_FLOAT_EQ(vector3.GetDistanceBetween(disttest), 0);
    }

}