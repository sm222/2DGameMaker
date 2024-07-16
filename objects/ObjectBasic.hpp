
#ifndef OBJECTBASIC_HPP_
#define OBJECTBASIC_HPP_

# include "../inc/CPPDefine.hpp"

// Class declaration
class ObjectBasic {
  public:
    ObjectBasic();
    ~ObjectBasic();
  protected:
    id_t         id;
    std::string  name;
    //          parent
    //          groups
    //          RenderSet
    //          PhysicSet
    //          ScriptSet
};

#endif // OBJECTBASIC_HPP_
