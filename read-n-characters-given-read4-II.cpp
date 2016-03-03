// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    Solution() : buf_len(0) {
        
    }
    int read(char *buf, int n) {
        char buffer[5];
        int cnt = 0;
        if (buf_len > 0) {
            memcpy(buf, _buf, min(buf_len, n));
            cnt += min(buf_len, n);
            if (n < buf_len) {
                memcpy(_buf, _buf + n, buf_len - n);
                buf_len -= n;
            } else {
                buf_len = 0;
            }
        }
        int sz;
        while(cnt < n) {
            sz = read4(buffer);
            memcpy(buf + cnt, buffer, sz);
            cnt += sz;
            if (sz < 4) break;
        }
        if (cnt > n) {
            buf[n] = '\0';
            buf_len = cnt - n;
            memcpy(_buf, buffer + (sz-buf_len), buf_len);
            cnt = n;
        }
        return cnt;
    }
private:
    int buf_len;
    char _buf[5];
};
