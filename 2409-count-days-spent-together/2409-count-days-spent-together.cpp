class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

        auto convert = [&](string s) {
            int month = stoi(s.substr(0, 2));
            int day = stoi(s.substr(3));
            return days[month - 1] + day;
        };

        int a1 = convert(arriveAlice);
        int a2 = convert(leaveAlice);
        int b1 = convert(arriveBob);
        int b2 = convert(leaveBob);

        int start = max(a1, b1);
        int end = min(a2, b2);

        return max(0, end - start + 1);
    }
};