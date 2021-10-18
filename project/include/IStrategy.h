/**
 * @file IStrategy.h
 */
#ifndef ISTRATEGY_H_
#define ISTRATEGY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <EntityProject/facade/delivery_system.h>
#include <vector>
#include <string>

namespace csci3081 {
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief istrategy class for pathing option
 * this class is a base class for implemeting different strategy of pathing using the strategy pattern
 */
class IStrategy
{
public:
  ~IStrategy(){}
  IStrategy(){}
  virtual std::vector<std::vector<float>> GetRoute(std::vector< float > src, std::vector< float > dest) = 0;
};
}

#endif  // ISTRATEGY_H_
