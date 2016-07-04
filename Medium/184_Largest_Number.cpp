bool numStrCompare(const string& s1, const string& s2) {
    return s1 + s2 > s2 + s1;
}

class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &num) {
        if (num.empty()) {
            return "";
        }

        vector<string> numStr;
        for (int i = 0; i < num.size(); i++) {
            numStr.push_back(to_string(num[i]));
        }

        sort(numStr.begin(), numStr.end(), numStrCompare);

        string result;
        for (int i = 0; i < numStr.size(); i++) {
            result += numStr[i];
        }

        // Erase the extra 0
        int i;
        for (i = 0; i < result.length() - 1 && result[i] == '0'; i++) {
            ;
        }
        result = result.substr(i, result.length() - i);

        return result;
    }
};
