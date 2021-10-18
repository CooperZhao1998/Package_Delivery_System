/**
 *@file Parabolic.h
 */
#ifndef PARABOLIC_H_
#define PARABOLIC_H_


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
 * @brief class defined for parabolic strategy pathing
 * this class implement the path calculation of parabolic pathing
 */
class Parabolic: public IStrategy
{
public:
  /**
  * constructor
  */
  Parabolic(){}
  ~Parabolic(){}

  /**
   * get the absolute distance between two points
   * @param PointA position vector of the first point
   * @param PointB position vector of the second point
   * @return a float indicating the distance
   */
  float DistanceBetween(std::vector< float > PointA, std::vector< float > PointB)
  {
    float x = PointB[0] - PointA[0];
    float y = PointB[1] - PointA[1];
    float z = PointB[2] - PointA[2];
    return sqrt(x*x + y*y + z*z);
  }


   /**
   * GetRoute to get a path from one starting position to one destination position implementing the Parabolic path calculation.
   * @param src the starting point of path
   * @param dest  the destination point of path
   * @return a set of point representing a path from starting point src to destination dest.
   */
  std::vector< std::vector<float> > GetRoute(std::vector< float > src, std::vector< float > dest)
  {
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
    return path;
  }
};

}
#endif  // PARABOLIC_H_
