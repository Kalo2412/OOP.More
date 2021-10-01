//
//  Subscriber.cpp
//  HW4_R
//
//  Created by Kaloyan Vachkov on 29.05.21.
//

#include "Subscriber.hpp"

Subscriber::Subscriber(const std::string& id) : id(id){
}

void Subscriber::signal(const Message& obj){
    this->_messages.push_back(obj.data); 
}


Subscriber::~Subscriber(){
    _messages.clear(); 
}
