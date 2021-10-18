/**
 *@file Beline.h
 */
#ifndef BEELINE_H_
#define BEELINE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "IStrategy.h"
#include <vector>
#include <string>

namespace csci3081 {
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief class defined for beeline strategy pathing
 * this class implement the path calculation of beeline pathing
 */
class Beeline: public IStrategy
{
public:
  /**
   * constructor for Beeline
   */
  Beeline(){}
  ~Beeline(){}

  /**
   * GetRoute to get a path from one starting position to one destination position implementing the Beeline path calculation.
   * @param src the starting point of path
   * @param dest  the destination point of path
   * @return a set of point representing a path from starting point src to destination dest.
   */
  std::vector< std::vector<float> > GetRoute(std::vector< float > src, std::vector< float > dest)
  {
    std::vector<std::vector<float>> path;
    //store the each position node in the path

    float height = 600.0;

    std::vector<float> node_0 = src;
    path.push_back(node_0);


    std::vector<float> node_1 = src;
    node_1[1] = node_1[1] + height;
    path.push_back(node_1);


    std::vector<float> node_2 = dest;
    node_2[1] = node_2[1] + height;
    path.push_back(node_2);


    std::vector<float> node_3 = dest;
    path.push_back(node_3);

    return path;

    // //increase height
    // for(float i = node[1]; i <= height; i = i + dt)
    // {
    //   node[1] = dt + node[1];
    //   path.push_back(node);
    // }
    //
    // //get the distancee between two point
    // float x = dest[0] - src[0];
    // float z = dest[2] - src[2];
    // float distance = sqrt(x*x + z*z);
    // //get ration on each line
    // float x_ratio = x / distance;
    // float z_ratio = z / distance;
    //
    // //move
    // for(float i = dt; i < distance; i = i + dt)
    // {
    //   node[0] = x_ratio*dt + node[0];
    //   node[2] = z_ratio*dt + node[2];
    //   path.push_back(node);
    // }
    // //decrease height
    // for (float i = node[1]; i >= dest[1]; i++)
    // {
    //   node[1] = node[1] - dt;
    //   if(node[1] < dest[1])
    //   {
    //     node[1] = dest[1];
    //   }
    //   path.push_back(node);
    // }
    // return path;
  }
};

}

#endif  // BEELINE_H_
