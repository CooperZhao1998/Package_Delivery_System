#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "Parabolic.h"

namespace csci3081{
    class ParabolicTest:public::testing::Test{
        public:
            void SetUp(){

            }
            Parabolic* parabolic = new Parabolic();
    };

    TEST_F(ParabolicTest, parabolic_test){
        std::vector< float > src;
        std::vector< float > dest;
        src.push_back(1);src.push_back(1);src.push_back(1);
        dest.push_back(5);dest.push_back(5);dest.push_back(5);
        std::vector<std::vector<float>> path;
        //store the each position node in the path
        std::vector<float> node = src;

        //# intervel*
        float intervel = 100.0;
        //height*
        float Max_height = 600.0;
        //distance of intervel
        float dt = 1/intervel;

        float x_0 = src[0];
        float y_0 = src[1];
        float z_0 = src[2];

        float x_1 = dest[0];
        float y_1 = dest[1];
        float z_1 = dest[2];

        //move
        for(int i = 0; i <= (int)intervel; i++)
        {
        float t = dt*i;
        node[0] = x_0 + (x_1 - x_0)*t;
        node[2] = z_0 + (z_1 - z_0)*t;
        node[1] = (-4*Max_height + 2*y_0 + 2*y_1)*t*t + (4*Max_height - 3*y_0 - y_1)*t + y_0;

        path.push_back(node);
        }
        EXPECT_EQ(parabolic->GetRoute(src, dest), path);
    }

    TEST_F(ParabolicTest, parabolic_distancebetween_test){
        std::vector< float > src;
        std::vector< float > dest;
        src.push_back(1);src.push_back(1);src.push_back(1);
        dest.push_back(5);dest.push_back(5);dest.push_back(5);
        float x = dest[0] - src[0];
        float y = dest[1] - src[1];
        float z = dest[2] - src[2];
        float dist = sqrt(x*x + y*y + z*z);
        EXPECT_EQ(parabolic->DistanceBetween(src, dest), dist);
    }
}