#include "Scene.h"
#include "Sphere.h"
#include<set>
//constructor
Scene::Scene(){}

//operations
bool Scene::add(const Sphere &s)
{
    return sc.insert(s).second;
}
bool Scene::remove(const Sphere &s)
{
    return sc.erase(s);
}

std::set<Sphere> Scene::getSpheres() const{
	return sc;
}
