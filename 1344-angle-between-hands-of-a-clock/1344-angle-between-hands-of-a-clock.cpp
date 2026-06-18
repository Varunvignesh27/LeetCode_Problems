class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ha = (hour * 30) + (minutes * 0.5);
        double ma = minutes * 6;

        cout << ha << " " << ma;

        double diff = abs(ha - ma);

        return min(diff,360 - diff);
    }
};