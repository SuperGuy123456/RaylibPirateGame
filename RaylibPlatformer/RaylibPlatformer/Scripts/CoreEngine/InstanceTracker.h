#ifndef INTRACKER_H
#define INTRACKER_H

#include <vector>
#include <algorithm>  // Needed for std::remove

using namespace std;

class ContainerInstance;  // Forward declaration
class InteractableInstance;
class NPCInstance;

template <typename T>
//TO USE ALL INSTANCES, USE THE ACTUAL CLASS TYPE INSTEAD OF INSTANCE CLASS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
class AllInstances
{
public:
    static vector<T*> objects;
    static int count;
    AllInstances(T* obj) 
    {
        objects.emplace_back(obj);
        count = objects.size();
    }
    virtual ~AllInstances() {}
};
template <typename T>
vector<T*> AllInstances<T>::objects = vector<T*>();
template <typename T>
int AllInstances<T>::count = 0;
class ContainerInstance : public AllInstances<ContainerInstance>
{
public:
    ContainerInstance() : AllInstances<ContainerInstance>(this)
    {}

    ~ContainerInstance()
    {
        auto it = std::remove(objects.begin(), objects.end(), this);
        objects.erase(it, objects.end());
    }
};




class InteractableInstance : public AllInstances<InteractableInstance>
{
public:
    InteractableInstance() : AllInstances(this){}

    ~InteractableInstance()
    {
        auto it = std::remove(objects.begin(), objects.end(), this);
        objects.erase(it, objects.end());
    }
};

class NPCInstance : public AllInstances<NPCInstance>
{
public:
    NPCInstance() : AllInstances(this){}

    ~NPCInstance()
    {
        auto it = std::remove(objects.begin(), objects.end(), this);
        objects.erase(it, objects.end());
    }
};

class WeaponInstance : public AllInstances<WeaponInstance>
{
public:
    WeaponInstance() :AllInstances<WeaponInstance>(this) {}

    ~WeaponInstance()
    {
        auto it = std::remove(objects.begin(), objects.end(), this);
        objects.erase(it, objects.end());
    }
};
#endif // INTRACKER_H
