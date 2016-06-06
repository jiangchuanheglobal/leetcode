// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
     Solution() {
         mLast_ptr = mLast_buf;
         mLast_len = 0;
     }
    int read(char *buf, int n) {
        if (!buf) {return 0;}
        
        if (n <= mLast_len) {
            memcpy(buf, mLast_ptr, n);
            mLast_len -= n;
            mLast_ptr += n;
            return n;
        } else {
            int need_n = n;
            if (mLast_len > 0) {
                memcpy(buf, mLast_ptr, mLast_len);
                buf += mLast_len;
                need_n -= mLast_len;
                mLast_len = 0;
                mLast_ptr = mLast_buf;
            }
            
            int num = need_n / 4 + (need_n % 4 != 0 ? 1 : 0);
            int total = 0;
            while (num > 0) {
                int cur = read4(buf);
                total += cur;
                buf += cur;
                if (cur != 4) {break;}
                num -= 1;
            }
            
            if (total > need_n) {
                mLast_len = total - need_n;
                memcpy(mLast_ptr, buf - mLast_len, mLast_len);
            }
            return total >= need_n ? n : (n - (need_n - total));
        }
    }
    
    private:
    char mLast_buf[4];
    char* mLast_ptr;
    int mLast_len;
};
