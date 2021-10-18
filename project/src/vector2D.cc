#include "vector2D.h"
namespace csci3081{
    Vector2D::Vector2D(){
        position.push_back(0);
        position.push_back(0);
        position.push_back(0);
    }

    Vector2D::Vector2D(float posX, float posZ){
        position.push_back(posX);
        position.push_back(0);
        position.push_back(posZ);
    }

    const std::vector<float>& Vector2D::GetPosition(){
        return position;
    }

    Vector2D Vector2D::Normalize(){
        float length = sqrt(position[0]*position[0] + position[1]*position[1] + position[2]*position[2]);
        position[0] /= length;
        position[1] /= length;
        position[2] /= length;
        return Vector2D(position[0],position[2]);
    }
    const float Vector2D::GetDistanceBetween(Vector2D& V){
        // Vector3D distance* = new Vector3D(position[0] - V.GetPosition()[0],
        //                                 position[1] - V.GetPosition()[1],
        //                                 position[2] - V.GetPosition()[2]);
        float x = position[0] - V.GetPosition()[0];
        float y = position[1] - V.GetPosition()[1];
        float z = position[2] - V.GetPosition()[2];
        return sqrt(x*x + y*y + z*z);
    }

    const float Vector2D::GetMagnitude(){
        return sqrt(position[0]*position[0] + position[1]*position[1] + position[2]*position[2]);
    }

    Vector2D Vector2D::Add(Vector2D V){
        position[0] = position[0] + V.GetPosition()[0];
        position[2] = position[2] + V.GetPosition()[2];
        return Vector2D(position[0], position[2]);
    }

    Vector2D Vector2D::Multiply(Vector2D V){
        position[0] = position[0] * V.GetPosition()[0];
        position[2] = position[2] * V.GetPosition()[2];
        return Vector2D(position[0],position[2]);     
    }

    Vector2D Vector2D::Multiply(float V){
        position[0] *= V;
        position[2] *= V;
        return Vector2D(position[0],position[2]);
    }

    Vector2D Vector2D::Minus(Vector2D V){
        position[0] -= V.GetPosition()[0];
        position[2] -= V.GetPosition()[2];
        return Vector2D(position[0], position[2]);
    }

}