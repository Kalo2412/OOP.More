//
//  PeriodicSampler.cpp
//  HW4_R
//
//  Created by Kaloyan Vachkov on 25.05.21.
//

#include "PeriodicSampler.hpp"
PeriodicSampler::PeriodicSampler(const std::string& id,const size_t& period): Subscriber(id) , period(period) {}



int PeriodicSampler::read() const {
    int size = (int)_messages.size() - 1;
    int data = 0;
        
    while(size >= 0){
            if(size % period == 0){
                data = _messages[size];
                break; 
            }
        size--; 
    }
    
        return data;
    
}
