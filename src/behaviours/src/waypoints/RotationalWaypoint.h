#ifndef rotationalwaypoint_h
#define rotationalwaypoint_h

#include "Waypoint.h"
#include "../RadRotPID.h"
#include <angles/angles.h>

typedef struct rotation_params
{
    double arrived_threshold = M_PI/12;
    double rotate_to;

    int rotational_max = 120;
} RotationParams;

class RotationalWaypoint : public Waypoint
{
    public:
        RotationalWaypoint( LogicInputs *i, RotationParams rp ) : Waypoint( i ), r_params(rp)
        {
            rot_pid = WaypointUtilities::getRadianRotPIDParams();
        }
        virtual void run();
    private:
        RadRotPID rot_pid;
        RotationParams r_params;
        double goal_theta;

};

#endif
