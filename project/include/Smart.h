/**
 *@file Smart.h
 */
#ifndef SMART_H_
#define SMART_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "IStrategy.h"

namespace csci3081 {
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief class defined for smart strategy pathing
 * this class impelemnt the path calculaion of smart pathing
 */
class Smart: public IStrategy
{
public:
  /**
  * constructor for smart
  */
  Smart(const IGraph* graph){
    graph_ = graph;
  }
  ~Smart(){}

  /**
  * GetRoute to get a path from one starting position to one destination position implementing the smart path calculation.
  * @param src the starting point of path
  * @param dest  the destination point of path
  * @return a set of point representing a path from starting point src to destination dest.
  */
  std::vector< std::vector<float> > GetRoute(std::vector< float > src, std::vector< float > dest)
  {
    return graph_->GetPath(src, dest);
  }
private:
  const IGraph* graph_;
};
}

#endif  // SMART_H_
