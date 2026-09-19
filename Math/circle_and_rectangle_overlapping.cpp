/*
{
    "problem_name": "Circle and Rectangle Overlapping",
    "category": "Math",
    "time_complexity": "O(1)",
    "space_complexity": "O(1)"
}
*/

#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Step 1: Find the closest x and y coordinates on the rectangle to the circle's center
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));
        
        // Step 2: Calculate the mathematical distance (squared to avoid floating point sqrt overhead)
        int distanceX = xCenter - closestX;
        int distanceY = yCenter - closestY;
        
        // Step 3: Check if the squared distance is strictly within the squared radius
        return (distanceX * distanceX + distanceY * distanceY) <= (radius * radius);
    }
};