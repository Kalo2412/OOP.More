//
//  Subscriber.hpp
//  HW4_R
//
//  Created by Kaloyan Vachkov on 29.05.21.
//

#ifndef Subscriber_hpp
#define Subscriber_hpp

#include <vector>
#include <string>
#include "Message.hpp"

class Subscriber {
protected:
    std::vector<int> _messages;
public:
    Subscriber(const std::string& id);
    
    const std::string id;
    
    void signal(const Message&);
    
    virtual int read() const = 0;
    
    virtual ~Subscriber(); 
};

#endif /* Subscriber_hpp */
