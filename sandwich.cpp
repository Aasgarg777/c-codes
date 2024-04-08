/*You are given two integer arrays students and sandwiches where sandwiches[i] 
is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and students[j] 
is the preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue). 
Return the number of students that are unable to eat.*/

#include <vector>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> count(2, 0); // Count[0] for students preferring 0, Count[1] for students preferring 1
        
        for (int student : students)
            count[student]++; // Counting the number of students preferring each type of sandwich
        
        for (int sandwich : sandwiches) {
            if (count[sandwich] == 0) // If there are no more students preferring this type of sandwich
                break; // We can stop serving sandwiches
            count[sandwich]--; // Serve the sandwich to a student preferring it
        }
        
        // Counting the remaining unserved students
        return count[0] + count[1];
    }
};
