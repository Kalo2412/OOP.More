//
//  BacklogPublisher.cpp
//  HW4_R
//
//  Created by Kaloyan Vachkov on 25.05.21.
//

#include "BacklogPublisher.hpp"


void BacklogPublisher::subscribe(Subscriber * obj){
    
    _Sub.push_back(obj);
    if(!messagesT.empty()){
        for(auto& m : this->messagesT){
            obj->signal(m);
        }
    }
}


void BacklogPublisher::signal(const Message& mess){
    this->messagesT.push_back(mess.data);
    for(Subscriber* obj : this->_Sub){
        obj->signal(mess);
    }
}
