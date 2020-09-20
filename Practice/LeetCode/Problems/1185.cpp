class Solution {
public:
    
    bool isLeap(int y) {
        if(y%400 == 0) return true;
        
        if(y%100 == 0) return false;
        
        if(y%4 == 0) return true;
        
        return false;
    }
    string dayOfTheWeek(int day, int month, int year) {
        int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string d[8] = {"", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
        
        int days = 0;
        for(int i = 1971; i < year; ++i) {
            if(isLeap(i)) {
                days+=366;
            }
            else {
                days+=365;
            }
        }
        
        for(int i = 1; i < month; ++i) {
            if(isLeap(year) && i == 2)
                days += 29;
            else {
                days+=m[i];
            }
        }
        
        days+=day;
        
        int r = days%7;
        if(r)
            return d[r];
        return d[7];
        
    }
};
