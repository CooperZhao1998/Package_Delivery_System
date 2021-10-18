#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/delivery_simulation.h"
#include <EntityProject/entity.h>
#include "json_helper.h"
#include "Beeline.h"

namespace csci3081{
    using entity_project::IEntity;
    class BeelineTest:public::testing::Test{
        public:
            void SetUp(){
                //beeline = new Beeline();
            }
            Beeline* beeline = new Beeline();
    };

    TEST_F(BeelineTest, beeline_path_test){
        std::vector<float> src;
        std::vector<float> dst;
        std::vector<std::vector<float>> path;
        src.push_back(0);src.push_back(0);src.push_back(0);
        dst.push_back(2);dst.push_back(2);dst.push_back(2);
        path.push_back(src);
        std::vector<float> node_1 = src;
        node_1[1] = node_1[1] + 600;
        path.push_back(node_1);
        std::vector<float> node_2 = dst;
        node_2[1] = node_2[1] + 600;
        path.push_back(node_2);
        path.push_back(dst);
        EXPECT_EQ(beeline->GetRoute(src, dst), path);

    }
}