#ifndef SCENE_H
#define SCENE_H

//#include <unordered_set>
#include <set>
#include "Sphere.h"

class Scene
{
    public:
        //constructor
        Scene();

        //operations
        bool add(const Sphere &s);
        bool remove(const Sphere &s);

    private:
        std::set<Sphere> sc;  //the scene
};

#endif // SCENE_H
