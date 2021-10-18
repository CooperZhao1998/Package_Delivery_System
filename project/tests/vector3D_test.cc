#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "vector3D.h"

namespace csci3081{

    class Vector3DTest : public::testing::Test{
        public:
            void SetUp(){
                initVector = Vector3D();
                vector1 = Vector3D(1,1,1);
                vector2 = Vector3D(1,2,3);
            }

        protected:
            Vector3D initVector;
            Vector3D vector1;
            Vector3D vector2;
            
    };

    TEST_F(Vector3DTest, Vector3DConstructorAndBoolGetters){
        std::vector<float> init_expected_position;
        init_expected_position.push_back(0);
        init_expected_position.push_back(0);
        init_expected_position.push_back(0);

        std::vector<float> vector1_expected_position;
        vector1_expected_position.push_back(1);
        vector1_expected_position.push_back(1);
        vector1_expected_position.push_back(1);

        std::vector<float> vector2_expected_position;
        vector2_expected_position.push_back(1);
        vector2_expected_position.push_back(2);
        vector2_expected_position.push_back(3);

        ASSERT_FLOAT_EQ(initVector.GetPosition()[0], init_expected_position[0]);
        ASSERT_FLOAT_EQ(initVector.GetPosition()[1], init_expected_position[1]);
        ASSERT_FLOAT_EQ(initVector.GetPosition()[2], init_expected_position[2]);
        ASSERT_FLOAT_EQ(vector1.GetPosition()[0], vector1_expected_position[0]);
        ASSERT_FLOAT_EQ(vector1.GetPosition()[1], vector1_expected_position[1]);
        ASSERT_FLOAT_EQ(vector1.GetPosition()[2], vector1_expected_position[2]);
        ASSERT_FLOAT_EQ(vector2.GetPosition()[0], vector2_expected_position[0]);
        ASSERT_FLOAT_EQ(vector2.GetPosition()[1], vector2_expected_position[1]);
        ASSERT_FLOAT_EQ(vector2.GetPosition()[2], vector2_expected_position[2]);

    }
    TEST_F(Vector3DTest, GetMagnitude){
        float x, y ,z;
        x = initVector.GetPosition()[0];
        y = initVector.GetPosition()[1];
        z = initVector.GetPosition()[2];
        float init_expected_magnitude = sqrt(x*x + y*y + z*z);
        ASSERT_FLOAT_EQ(initVector.GetMagnitude(), init_expected_magnitude) << "magnitude getter not setup properly";
        x = vector1.GetPosition()[0];
        y = vector1.GetPosition()[1];
        z = vector1.GetPosition()[2];
        float vector1_expected_magnitude = sqrt(x*x + y*y + z*z);
        ASSERT_FLOAT_EQ(vector1.GetMagnitude(), vector1_expected_magnitude);
        x = vector2.GetPosition()[0];
        y = vector2.GetPosition()[1];
        z = vector2.GetPosition()[2];
        float vector2_expected_magnitude = sqrt(x*x + y*y + z*z);
        ASSERT_FLOAT_EQ(vector2.GetMagnitude(), vector2_expected_magnitude);
    }

    TEST_F(Vector3DTest, GetDistanceBetween){
        float x, y ,z;
        x = vector1.GetPosition()[0] - vector2.GetPosition()[0];
        y = vector1.GetPosition()[1] - vector2.GetPosition()[1];
        z = vector1.GetPosition()[2] - vector2.GetPosition()[2];
        float expected_distance_vector1_vector2 = sqrt(x*x + y*y + z*z);
        ASSERT_FLOAT_EQ(vector1.GetDistanceBetween(vector2), expected_distance_vector1_vector2) << "distance function not setup properly";
    }

    TEST_F(Vector3DTest, Add){
        Vector3D vec =Vector3D();
        Vector3D expected_addition_vector = Vector3D(1,1,1);
        Vector3D vector1ptr = Vector3D(vector1.GetPosition()[0], vector1.GetPosition()[1], vector1.GetPosition()[2]);
        Vector3D actual_vector = vector1ptr.Add(vec);
        ASSERT_FLOAT_EQ(actual_vector.GetPosition()[0], expected_addition_vector.GetPosition()[0]);
        ASSERT_FLOAT_EQ(actual_vector.GetPosition()[1], expected_addition_vector.GetPosition()[1]);
        ASSERT_FLOAT_EQ(actual_vector.GetPosition()[2], expected_addition_vector.GetPosition()[2]);
    }

    TEST_F(Vector3DTest, Minus){
        Vector3D vec =Vector3D();
        Vector3D expected_addition_vector = Vector3D(1,1,1);
        Vector3D vector1ptr = Vector3D(vector1.GetPosition()[0], vector1.GetPosition()[1], vector1.GetPosition()[2]);
        Vector3D actual_vector = vector1ptr.Minus(vec);
        ASSERT_FLOAT_EQ(actual_vector.GetPosition()[0], expected_addition_vector.GetPosition()[0]);
        ASSERT_FLOAT_EQ(actual_vector.GetPosition()[1], expected_addition_vector.GetPosition()[1]);
        ASSERT_FLOAT_EQ(actual_vector.GetPosition()[2], expected_addition_vector.GetPosition()[2]);
    }

    TEST_F(Vector3DTest, Normalize){
        std::vector<float> expected_normalized_vector1;
        expected_normalized_vector1.push_back(1/sqrt(3));
        expected_normalized_vector1.push_back(1/sqrt(3));
        expected_normalized_vector1.push_back(1/sqrt(3));
        ASSERT_FLOAT_EQ(vector1.Normalize().GetPosition()[0], expected_normalized_vector1[0]);
        ASSERT_FLOAT_EQ(vector1.Normalize().GetPosition()[1], expected_normalized_vector1[1]);
        ASSERT_FLOAT_EQ(vector1.Normalize().GetPosition()[2], expected_normalized_vector1[2]);
    }

}