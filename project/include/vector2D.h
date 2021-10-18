/**
 *@file Vector2D.h
 */
#ifndef VECTOR2D_H_
#define VECTOR2D_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <string>
#include "vector3D.h"


namespace csci3081{
/*******************************************************************************
* Class Definitions
******************************************************************************/
/**
* @brief vector2D class,
* class used for calculation and storation of vector<float> used for 2D positions.
*/
    class Vector2D : public csci3081::Vector3D{
        public:
            /**
             * default constructor
             */
            Vector2D();
            /**
             * constructor with set x and z axis value
             * @param posX x axis
             * @param posZ y axis
             */
            Vector2D(float posX, float posZ);

            /**
             * calculate and return the distance between two Vector2D
             * @param secondVector
             * @return distance as a float
             */
            const float GetDistanceBetween(Vector2D& secondVector);

            /**
             * calculate and return the magnitude of the vector
             * @return magnitude of the vector as a float
             */
            const float GetMagnitude();

            /**
             * return the value of every axis of the vector
             * @return the actual value of the vector in terms of vector<float>
             */
            const std::vector<float>& GetPosition();

            /**
             * normalize and return the vector
             * @return the actual normalized value of the vector in terms of vector<float>
             */
            Vector2D Normalize();

            /**
             * addition of two vector
             * @return a new Vector2D
             */
            Vector2D Add(Vector2D V);


            Vector2D Multiply(Vector2D V);
            /**
             * multiplication between a vector and a scaler
             * @param V a scaler for mutiplication
             * @return a new vector3D
             */
            Vector2D Multiply(float V);
            /**
             * deduction between two vector3D
             * @param V another vector3D
             * @return a new vector3D
             */
            Vector2D Minus(Vector2D V);

        private:
            std::vector<float> position;
    };
}
#endif
