#ifndef WRAPPER_H
#define WRAPPER_H
#include <memory>

template <class T>
class Wrapper {
    
public:
    Wrapper(){DataPtr = 0;}
    
    Wrapper(const T &inner){
        DataPtr = inner.clone();
    }
    ~Wrapper(){
//        if (DataPtr != 0)
//            delete DataPtr;
    }
    Wrapper(const Wrapper<T> &original){
        if (original.DataPtr != 0)
            DataPtr = original.DataPtr->clone();
        else
            DataPtr=0;
    }
    
    Wrapper &operator=(const Wrapper<T> &original){
        if (this != &original){
//            if (DataPtr != 0)
//                delete DataPtr;
            DataPtr = (original.DataPtr != 0) ? original.DataPtr->clone() : 0;
        }
        
        return *this;
    }
    
    T &operator*(){
        return *DataPtr;
    }
    
    const T &operator*() const{
        return *DataPtr;
    }
    
    const std::shared_ptr<T> operator->() const{
        return DataPtr;
    }
    
    std::shared_ptr<T> operator->(){
        return DataPtr;
    }
    
private:
    std::shared_ptr<T> DataPtr;
};


#endif
