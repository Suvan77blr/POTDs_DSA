// 230625
/*
    Corporate-Flight-Bookings
        - BOOKINGS[] - bookings of 'N' flights from 1->N.
        - [i] = [first, last, seats] => flights 'first' to 'last' (inclusive) 'seats' seats are reserved.
    
        - To Return: an array/list of length 'N' 
            where [i] => represents the total no of seats in i-th flight.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> corpFlightsBookings( vector <vector<int> >& bookings, int n)
    {
        vector<int> answer (n, 0);
        for(auto reservation : bookings)
        {
            int left = reservation[0];
            int right = reservation[1];
            int value = reservation[2];

            answer[left-1] += value;
            if(right < n) 
                answer[right] -= value;
        }

        for(int i=1; i<n; i++) {
            answer[i] = answer[i] + answer[i-1];
        }
        return answer;
    }
};

int main(void) {
    int nFlights;
    cin >> nFlights;               // Input 'N' : no of flights.

    int nBookings;
    cin >> nBookings;       // Input 'nBookings' : no of bookings.

    vector< vector<int> > bookings (nBookings, vector<int> (3) );
    for(int i=0; i<nBookings; i++) {
        cin >> bookings[i][0] >> bookings[i][1] >> bookings[i][2];
    }

    vector<int> answer = Solution().corpFlightsBookings(bookings, nFlights);
    cout << "Total Number of seats reserved: " << endl;
    for(int i=0; i<nFlights; i++) {
        // cout << "Flight " << i+1 << ": " << answer[i] << endl;
        cout << answer[i] << " ";
    }

    return 0;
}

/*
    TCs:
    1) 4 4
       1 2 3 
       2 3 2
       1 3 1
       3 4 2
       => 4 6 5 2
       
    2) 1 1
       1 1 7
       => 7  
*/