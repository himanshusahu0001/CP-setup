#include <bits/stdc++.h>
using namespace std;
/*
    // TERMINOLOGY
    rectangle's sides are parallel to x and y axises.
    vector<int> rect(4); 
    0  1  2  3
    x1,y1 x2,y2
    bottom left = x1,y1
    top right = x2,y2
*/


// do s1 and s2 intersect
bool intersect(vector<int> s1, vector<int> s2) {
	int bl_a_x = s1[0], bl_a_y = s1[1], tr_a_x = s1[2], tr_a_y = s1[3];
	int bl_b_x = s2[0], bl_b_y = s2[1], tr_b_x = s2[2], tr_b_y = s2[3];

	// no overlap
	if (bl_a_x >= tr_b_x || tr_a_x <= bl_b_x || bl_a_y >= tr_b_y ||
	    tr_a_y <= bl_b_y) {
		return false;
	} else {
		return true;
	}
}

// area of intersecting rectangles
int inter_area(vector<int> s1, vector<int> s2) {
    if(!intersect(s1,s2)) return 0;
	int bl_a_x = s1[0], bl_a_y = s1[1], tr_a_x = s1[2], tr_a_y = s1[3];
	int bl_b_x = s2[0], bl_b_y = s2[1], tr_b_x = s2[2], tr_b_y = s2[3];

	return ((min(tr_a_x, tr_b_x) - max(bl_a_x, bl_b_x)) *
	        (min(tr_a_y, tr_b_y) - max(bl_a_y, bl_b_y)));
}

// area of rectangle
int area(vector<int> a){
    return abs( a[0]-a[2] ) * abs(a[1]-a[3]);
}