// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        if (!buf) {return 0;}
        
        int num = n / 4 + (n % 4 != 0 ? 1 : 0);
        int total = 0;
        while (num > 0) {
            int cur = read4(buf);
            total += cur;
            if (cur != 4) {break;}
            buf += 4;
            num -= 1;
        }
        return total >= n ? n : total;
    }
};
