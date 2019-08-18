#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    //if tank capacity is enough 
    if (dist <= tank) {
        return 0;
    }


    int numRefills = 0, currentRefills = 0, lastRefill;

    while(currentRefills <= stops.size()-2) {
        lastRefill = currentRefills;

        while(currentRefills <= stops.size()-2 && (stops[currentRefills+1] - stops[lastRefill]) <= tank) {
            currentRefills = currentRefills + 1;
        }

        if(currentRefills == lastRefill) {
            return -1;
        }
        else {
            numRefills += 1;
        }
    }
    // checking if we can go from last stop to city b
    if (dist - stops[currentRefills] > tank)
    {
        return -1;
    }

    //if we really need a refill at last stop
    if(dist - stops[lastRefill] <= tank){
        numRefills -= 1;
    }
    return numRefills;
    
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n+1); //adding home
    stops[0] = 0;       // home
    for (size_t i = 1; i <= n; ++i)
        cin >> stops[i];

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
