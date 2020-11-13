class Solution {
public:
	bool comp(vector<int> a, vector<int> b) {
		return a[0]< b[0];
	}	
	// [1,3],[2,5],[7,9]
	//r1 = 
    int findMinRooms(vector<vector<int>>& intervals) {

        if(intervals.size() == 0) return 0;
        
        sort(intervals.begin(), intervals.end(), comp);
        // min heap to get earliest time room available
        priority_queue<int, vector<int>, greater<int>> room; 
        
        room.insert(intervals[0][1]);
        
        int roomNum = 0;
        // hit bow at where ballon ends
        for(int i=1; i < intervals.size(); ++i) {
         	// accomodate meeting in same room
         	if(intervals[i][0] <= room.top()) {
         		room.push(intervals[i][1]);
         	}
         	else {
         		roomNum++;
         	}
        }
        
        return roomNums;
    }
};
