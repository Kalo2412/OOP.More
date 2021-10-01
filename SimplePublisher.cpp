//
//  SimplePublisher.cpp
//  HW4_R
//
//  Created by Kaloyan Vachkov on 25.05.21.
//

#include "SimplePublisher.hpp"

void SimplePublisher::subscribe(Subscriber * obj){
    _Sub.push_back(obj);
}


void SimplePublisher::unsubscribe(Subscriber * obj){
    
    for (int i = 0; i < (int)_Sub.size(); i++){
        if(_Sub.at(i)->id == obj->id)
        {
            _Sub.erase(_Sub.begin() + i);
        }
    }
}



void SimplePublisher::signal(const Message& mess){
    for(Subscriber* obj : this->_Sub){
        obj->signal(mess);
    }
    
}
