//
//  Repository.cpp
//  HW4_R
//
//  Created by Kaloyan Vachkov on 25.05.21.
//

#include "Repository.hpp"

void Repository::add(Subscriber * obj){
    if(typeid(*obj) == typeid(Averager)){
    this->subscribers.push_back(new Averager(*dynamic_cast<Averager *>(obj)));
    }
    else if(typeid(*obj) == typeid(MovingAverager)){
    this->subscribers.push_back(new MovingAverager(*dynamic_cast<MovingAverager *>(obj)));
    }
    else if(typeid(*obj) == typeid(PeriodicSampler)){
    this->subscribers.push_back(new PeriodicSampler(*dynamic_cast<PeriodicSampler *>(obj)));
    }
}


Subscriber* Repository::get(const std::string& id){
    auto i = 0;
    Subscriber * ptr = nullptr;
    std::vector<Subscriber*>* vPtr1;
    vPtr1 = &subscribers;
   
    for (i = (int)vPtr1->size() - 1; i >= 0; i--){
        if(vPtr1->at(i)->id == id){
            ptr = vPtr1->at(i);
        }
    }

    return ptr;
}

Repository::Repository(const Repository &from) {
    for(Subscriber* subscriber : from.subscribers) {
        this->add(subscriber);
    }
}

Repository& Repository::operator=(const Repository& from) {
    if(this != &from) {
        for(Subscriber* subscriber : this->subscribers) {
            delete subscriber;
        }

        this->subscribers.clear();

        for(Subscriber* subscriber : from.subscribers) {
            this->add(subscriber);
        }
    }

    return *this;
}
