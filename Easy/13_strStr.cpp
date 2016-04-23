class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        if (source == NULL || target == NULL) {
            return -1;
        }

        int source_length = strlen(source);
        int target_length = strlen(target);

        for (int i = 0; i < source_length - target_length + 1; i++) {
            int j;
            for (j = 0; j < target_length && source[i + j] == target[j]; j++) {
                ;
            }

            if (j == target_length) {
                return i;
            }
        }

        return -1;
    }
};
