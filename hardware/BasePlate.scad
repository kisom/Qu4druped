// BasePlate.scad
// This file contains the base size of the plate, and modules
// for the various 

M2 = 1;
M25 = 1.25;
M3 = 1.75;
PlateHeight = 2.5;


module screw_hole(size, x, y, height=PlateHeight+1) {
    union() {
       translate([x, y, -1])
       cylinder(h=5, r=size, $fn=60); 
    };
}

// x and y are the center point for the battery mount.
module battery_mount(x, y, size=M3, rotation=0) {
    offset = 19.5 / 2;
    union() {
        screw_hole(size, x-offset, y);
        screw_hole(size, x+offset, y);
    }
}

module arduino_uno(x, y, size=M3, rotation=0) {
    union() {
        screw_hole(size, x, y); 
        screw_hole(size, x+50.8, y-15.2);
        screw_hole(size, x+50.8, y-43.1);
        screw_hole(size, x, y-48.3);
    }
}

module robot_power_board(x, y, size=M3, rotation=0) {
    union() {
        screw_hole(size, x, y);
        screw_hole(size, x+31.5, y);
        screw_hole(size, x, y+18.5);
        screw_hole(size, x+31.5, y+18.5);
    }
}

difference() {
    cube([70, 70, PlateHeight]);
    screw_hole(M3, 8.25, 8.25);
    screw_hole(M3, 61.75, 8.25);
    screw_hole(M3, 8.25, 61.75);
    screw_hole(M3, 61.75, 61.75);
    robot_power_board(20, 25);
}