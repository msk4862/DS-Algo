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
        
    	room.push(intervals[0][1]);
        
        int roomNum = 1;
        for(int i=1; i < intervals.size(); ++i) {
            
         	// no room can accomodate -> another room needed
         	if(intervals[i][0] < room.top()) {
         		roomNum++;
      			room.push(intervals[i][1]);
         	}
         	// accomodate meeting in same room
         	else {
         		room.pop();
         		room.push(intervals[i][1]);
         	}
        }	
        
        return roomNum;
    }
};
