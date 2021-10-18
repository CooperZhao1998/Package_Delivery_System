/**
 *@file Vector3D.h
 */
#ifndef VECTOR3D_H_
#define VECTOR3D_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <string>
#include <math.h>

namespace csci3081{
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
* @brief vector3D class,
* class used for calculation and storation of vector<float> used for 3D positions.
*/
    class Vector3D{
        public:
            /**
             * default constructor
             */
            Vector3D();
            /**
             * constructor of vector3D which constructs with given properties
             * @param posX x axis
             * @param posY y axis
             * @param posZ z axis
             */
            Vector3D(float posX, float posY, float posZ);

            /**
             * return the value of every axis of the vector
             * @return the actual value of the vector in terms of vector<float>
             */
            const std::vector<float>& GetPosition();
            /**
             * normalize the vector3D
             * @return a new vector3D
             */
            Vector3D Normalize();

            /**
             * calculate and return the distance between two vector
             * @param secondVector another vector
             * @return distance as a float
             */
            const float GetDistanceBetween(Vector3D& secondVector);
            /**
             * calculate and return the magnitude of the vector3D
             * @return magnitude as a float
             */
            const float GetMagnitude();
            /**
             * addition between two vector3D
             * @param V another vector3D
             * @return a new vector3D
             */
            Vector3D Add(Vector3D V);
            /**
             * multiplication between two vector3D
             * @param V another vector3D
             * @return a new vector 3D
             */
            Vector3D Multiply(Vector3D V);
            /**
             * multiplication between a vector and a scaler
             * @param V a scaler for mutiplication
             * @return a new vector3D
             */
            Vector3D Multiply(float V);
            /**
             * deduction between two vector3D
             * @param V another vector3D
             * @return a new vector3D
             */
            Vector3D Minus(Vector3D V);

            /**
             * set the position of the vector3D to given parameters
             * @param x x axis
             * @param y y axis
             * @param z z axis
             */
            void SetPosition(float x, float y, float z);
        private:
            std::vector<float> position;
    };
}
#endif
