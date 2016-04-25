#ifndef Location_h
#define Location_h

struct Location
{
    float x,y;
    
    Location(int a = 0, int b = 0)
    {
        x = a;
        x = b;
    }
    
    bool operator==(Location l)
    {
        return l.x == x && l.y == y;
    }
    
    bool operator!=(Location l)
    {
        return !operator==(l);
    }
};

#endif
