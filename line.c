#include "line.h"
#include <stdlib.h> // For malloc and free
#include <stdio.h> // For sprintf

struct line_struct {
    float slope;
    float y_intercept;
	// Specify all the fields required to make a line
};

line line_create(float slope,float y_intercept) {
    line new_line = (line)malloc(sizeof(struct line_struct));
    if (new_line == NULL) {
        return NULL; // Replace this with code to create a new line "object" and return a pointer to that object
        // The returned line should have a slope and y_intercept, as specified in the arguments.
    }
    new_line->slope = slope;
    new_line->y_intercept = y_intercept;
    return new_line;
}

line line_from_coords(coord from,coord to) {
    if (coord_getx(from) == coord_getx(to)) {
        return NULL;
    }
    float slope = ((coord_gety(to)) - (coord_gety(from))) / ((coord_getx(to)) - (coord_getx(from)));
    float y_intercept = (coord_gety(from)) - slope * (coord_getx(from));

    return line_create(slope, y_intercept);
}


    // Replace this with code to create a new line "object" and return a pointer to that object
	// The returned line should go through both the from and to coordinates specified in the argument
	// Return NULL if both from and to have the same x coordinate (which would make the slope infinity)


coord line_intersect(line l1,line l2) {
    //finding the slopes and the y int of line 1 and 2
    //first line on e (writing these helps me understand my code better)
    float slope1 = l1 -> slope; //finds the slope of l1 and l2
    float slope2 = l2 -> slope;
    float y_int1 = l1 -> y_intercept; // finds the y int of l1 and l2
    float y_int2 = l2 -> y_intercept;
    //this makes it so that when the slopes of m1 and m2 are the same, it returns null as they would never intercept
    if(m1 == m2) {
        return NULL;
    }
    float x_intersection = (y_int2 - y_int1) / (slope2 - slope1); //this finds the x intersection between the two lines
    float y_intersection = ((slope1 * x_intersection) + y_int1); //this uses the previously obtained x intersection and just uses slope intercept formula to solve for the y intersecyion. we couldve used the slope and y int of either line but it just has to be connsistant

    // Replace with code to return a new coordinate where lines l1 and l2 intersect
	// Return NULL if lines l1 and l2 have the same slope. They are parallel and never intersect

}

char * line_format(line ln) {
    if (ln == NULL) {
        return "NULL";
    }
    static char buffer[100];
    sprintf(buffer, "y = %fx + %f", ln->y_intercept);
    return buffer;

    // Replace with code to return the pointer to a string that contains the formatted description of a line.
	// If ln is NULL, return "NULL"
	// The result should be in the form: "y = <m>x + <b>", 
	// where <m> and <b> are replaced by the floating point representation (%f)
	// of the slope and y-intercept of the line.
	// You may use a static char buffer (see coord_format for an example) to hold the
	// result, based on the assumption that the result will be used before line_format is called again.
}

void line_delete(line ln) {
    free(ln);

	// Add code to free any memory consumed by the ln line "object"
}