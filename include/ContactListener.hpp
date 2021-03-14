#ifndef			__HPP__CONTACT_LISTENER__
#define			__HPP__CONTACT_LISTENER__

#include <Box2D/Box2D.h>


class ContactListener : public b2ContactListener {
    public:
        ContactListener();
        void BeginContact(b2Contact* contact);
    
};

#endif