//
//  SimplePublisher.hpp
//  HW4_R
//
//  Created by Kaloyan Vachkov on 25.05.21.
//

#ifndef SimplePublisher_hpp
#define SimplePublisher_hpp

#include "Message.hpp"
#include "Averager.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include <typeinfo>



// You are not allowed to make breaking changes to the class interface,
// but you are allowed to add additional methods/fields, as
// well as MODIFY the existing interface so as to make it
// "more correct" and more compact if possible
class Subscriber;
// SimplePublisher is a Publisher, which can have one
// or more subscribers and upon receiving a message
// via `signal()`, it replays that message to all the
// subscribers
class SimplePublisher {
protected:
    std::vector<Subscriber*> _Sub;
    
    
public:
    SimplePublisher() = default;
  // subscribe registers a Subscriber to start receiving messages
  virtual void subscribe(Subscriber *);
    

  // unsubscribe removes a Subscriber from the Publisher
  // Subscribers are removed based on their `id`
  // id's will always be unique
  void unsubscribe(Subscriber *);
  

  // signal receives a message from an external source
  // and replays that message to all the current subscribers
  virtual void signal(const Message&);
};

#endif /* SimplePublisher_hpp */
