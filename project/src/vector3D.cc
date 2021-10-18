#include "vector3D.h"
#include <vector>
#include <string>

namespace csci3081{
    Vector3D::Vector3D(){
        position.push_back(0);
        position.push_back(0);
        position.push_back(0);
    }

    Vector3D::Vector3D(float posX, float posY, float posZ){
        position.push_back(posX);
        position.push_back(posY);
        position.push_back(posZ);
    }

    const std::vector<float>& Vector3D::GetPosition(){
        return position;
    }

    Vector3D Vector3D::Normalize(){
        float length = sqrt(position[0]*position[0] + position[1]*position[1] + position[2]*position[2]);
        position[0] /= length;
        position[1] /= length;
        position[2] /= length;
        return Vector3D(position[0],position[1],position[2]);
    }

    const float Vector3D::GetDistanceBetween(Vector3D& V){
        // Vector3D distance* = new Vector3D(position[0] - V.GetPosition()[0],
        //                                 position[1] - V.GetPosition()[1],
        //                                 position[2] - V.GetPosition()[2]);
        float x = position[0] - V.GetPosition()[0];
        float y = position[1] - V.GetPosition()[1];
        float z = position[2] - V.GetPosition()[2];
        return sqrt(x*x + y*y + z*z);
    }

    const float Vector3D::GetMagnitude(){
        return sqrt(position[0]*position[0] + position[1]*position[1] + position[2]*position[2]);
    }

    void Vector3D::SetPosition(float x, float y, float z){
        position[0] = x;
        position[1] = y;
        position[2] = z;
    }

    Vector3D Vector3D::Add(Vector3D V){
        position[0] = position[0] + V.GetPosition()[0];
        position[1] = position[1] + V.GetPosition()[1];
        position[2] = position[2] + V.GetPosition()[2];
        return Vector3D(position[0],position[1],position[2]);
    }

    Vector3D Vector3D::Multiply(Vector3D V){
        position[0] = position[0] * V.GetPosition()[0];
        position[1] = position[1] * V.GetPosition()[1];
        position[2] = position[2] * V.GetPosition()[2];
        return Vector3D(position[0],position[1],position[2]);
    }

    Vector3D Vector3D::Multiply(float V){
        position[0] *= V;
        position[1] *= V;
        position[2] *= V;
        return Vector3D(position[0],position[1],position[2]);
    }

    Vector3D Vector3D::Minus(Vector3D V){
        position[0] -= V.GetPosition()[0];
        position[1] -= V.GetPosition()[1];
        position[2] -= V.GetPosition()[2];
        return Vector3D(position[0], position[1], position[2]);
    }

}
