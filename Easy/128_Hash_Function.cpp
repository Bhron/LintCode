class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        long code = 0;

        for (int i = 0; i < key.length(); i++) {
            code = (code * 33 + (int)key[i]) % HASH_SIZE;
        }

        return code;
    }
};
