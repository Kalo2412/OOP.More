//
//  Repository.hpp
//  HW4_R
//
//  Created by Kaloyan Vachkov on 25.05.21.
//

#ifndef Repository_hpp
#define Repository_hpp
#include "Averager.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include <string>
#include <typeinfo>

// You are not allowed to make breaking changes to the class interface,
// but you are allowed to add additional methods/fields, as
// well as MODIFY the existing interface so as to make it
// "more correct" and more compact if possible

// Repository is the single place where Subscribers will
// be stored. A Repository has ownership of the Subscribers
// stored inside it.
// The only way to access the available Subscribers in the
// repository is via the Subscriber's unique id.
// id's are guaranteed to be unique
class Subscriber;

class Repository {
    std::vector<Subscriber*> subscribers;
    
public:
    Repository() = default;
  // add registers a new Subscriber in the Repository
  void add(Subscriber *);
  
    
    Repository& operator=(const Repository&);
    Repository(const Repository&);
    

  // get returns a Subscriber in the Repository if a
  // Subscriber with the given id exists.
  // Returns nullptr otherwise
  Subscriber *get(const std::string& id);
};

#endif /* Repository_hpp */
