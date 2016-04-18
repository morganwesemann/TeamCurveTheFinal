//
//  Location.h
//  3334groupproject
//
//  Created by Morgan Wesemann on 4/15/16.
//  Copyright © 2016 Morgan Wesemann. All rights reserved.
//

#ifndef Location_h
#define Location_h

struct Location {
    int x = 0;
    int y = 0;
    
    Location(int a = 0, int b = 0) {
        x = a;
        x = b;
    }
    
    bool operator==(Location l) {
        return l.x == x && l.y == y;
    }
    
    bool operator!=(Location l) {
        return !operator==(l);
    }
};

#endif /* Location_h */
