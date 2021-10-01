//
//  MovingAverager.cpp
//  HW4_R
//
//  Created by Kaloyan Vachkov on 25.05.21.
//

#include "MovingAverager.hpp"


MovingAverager::MovingAverager(const std::string& id,const size_t& windowSize) : Subscriber(id) , windowSize(windowSize){}



int MovingAverager::read() const{
     int average = 0;

       if (_messages.size()==0 || windowSize == 0){
           return 0;
       }
       else if (windowSize > _messages.size()) {
           for (int i = 0; i < (int)_messages.size(); i++) {
               average += _messages[i];
           }
           return average / _messages.size();
       }
       else {
           for (auto i = _messages.size() - windowSize; i < _messages.size(); i++) {
               average += _messages[i];
           }
           return average / windowSize;
       }
}
