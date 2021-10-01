//
//  Averager.cpp
//  HW4_R
//
//  Created by Kaloyan Vachkov on 25.05.21.
//

#include "Averager.hpp"

Averager::Averager(const std::string& id) : Subscriber(id){}



int Averager::read() const{
    //std::vector<int>::iterator it;
    int average = 0;
    if(_messages.empty()){
        return 0;
    }
    else {
        for(auto it = _messages.begin(); it != _messages.end(); it++){
            average += *it;
        }
        return average/_messages.size();
    }
}
