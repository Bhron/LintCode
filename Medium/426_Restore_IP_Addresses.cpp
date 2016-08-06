class Solution {
public:
    /**
     * @param s the IP string
     * @return All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string& s) {
        vector<string> IPAddresses;

        if (s.empty()) {
            return IPAddresses;
        }

        getIPAddresses(s, "", 0, 0, IPAddresses);

        return IPAddresses;
    }
private:
    void getIPAddresses(const string& s, string cur, int pos, int count, vector<string>& IPAddresses) {
        if (count == 3) {
            if (s.length() - pos > 3) {
                return;
            }

            string address = s.substr(pos, s.length() - pos);
            if (!(address.length() > 1 && address[0] == '0') && (stoi(address) <= 255)) {
                cur += address;
                IPAddresses.push_back(cur);
            }

            return;
        }

        for (int i = 1; i <= 3; i++) {
            if (pos + i >= s.length()) {
                break;
            }

            string address = s.substr(pos, i);
            if (address.length() > 1 && address[0] == '0' || (stoi(address) > 255)) {
                continue;
            }

            getIPAddresses(s, cur + address + ".", pos + i, count + 1, IPAddresses);
        }
    }
};
