class Solution{
public:
    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int countDaysTogether(string aA, string lA, string aB, string lB)
    {
        /* calculating no of days each date represents. */
        int aliceA = accumulate(days.begin(), days.begin() + stoi(aA.substr(0, 2)) - 1, 0) + stoi(aA.substr(3, aA.size()));
        int aliceL = accumulate(days.begin(), days.begin() + stoi(lA.substr(0, 2)) - 1, 0) + stoi(lA.substr(3, aA.size()));
        int bobA = accumulate(days.begin(), days.begin() + stoi(aB.substr(0, 2)) - 1, 0) + stoi(aB.substr(3, aA.size()));
        int bobL = accumulate(days.begin(), days.begin() + stoi(lB.substr(0, 2)) - 1, 0) + stoi(lB.substr(3, aA.size()));

        /* we have to choose minimum of leave days and maximum of arrival days
           in order to get no of days together. */
        cout<<aliceA<<" "<<aliceL<<" "<<bobA<<" "<<bobL<<endl;
        int x = min(aliceL, bobL) - max(aliceA, bobA) + 1;
        if (x > 0)
            return x;
        return 0;
    }
};