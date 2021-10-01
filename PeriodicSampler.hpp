//
//  PeriodicSampler.hpp
//  HW4_R
//
//  Created by Kaloyan Vachkov on 25.05.21.
//

#ifndef PeriodicSampler_hpp
#define PeriodicSampler_hpp

#include "Subscriber.hpp"

// You are not allowed to make breaking changes to the class interface,
// but you are allowed to add additional methods/fields, as
// well as MODIFY the existing interface so as to make it
// "more correct" and more compact if possible

// PeriodicSampler is a type of Subscriber, which saves every
// period-th data point starting from the first data point provided.
// Data is provided with the `signal()` method.
//
// e.g if the period = 2, we save every 2nd data point provided
// so if we have
// signal(1), read(), signal(2), read(), signal(3), read(), signal(4), read()
// the output will be 1,1,3,3 as we skip every 2nd data point,
// which in our case is 2 and 4
class PeriodicSampler : public Subscriber {
public:
  PeriodicSampler(const std::string& id,const size_t& period);


  const size_t period;
  // id is a unique identifier for a Subscriber
  // Should never be changed once initialized
  //const std::string id;

  // signal adds a new data point and saves only every period-th
  // data point, the data points inbetween are ignored
  //void signal(const Message&);

  // read returns the latest period-th data point if such exists
  // 0 otherwise
  int read() const override;
};

#endif /* PeriodicSampler_hpp */
