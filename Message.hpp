//
//  Message.hpp
//  HW4_R
//
//  Created by Kaloyan Vachkov on 25.05.21.
//

#ifndef Message_hpp
#define Message_hpp

// You are not allowed to make breaking changes to the class interface,
// but you are allowed to add additional methods/fields, as
// well as MODIFY the existing interface so as to make it
// "more correct" and more compact if possible

// Message is an abstraction over a simple data point, which
// is sent from a Publisher to a Subscriber
class Message {
public:
  // Constructor
  Message(const int& data);

  // data is the data point encapsulated in the message
  // Should never be changed once initialized
  const int data;
};

#endif /* Message_hpp */
