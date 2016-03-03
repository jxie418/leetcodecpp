int read4(char *buf);

// Forward declaration of the read4 API.

class Solution22 {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        char buffer[5];
        int cnt = 0;
        while (cnt < n) {
            int sz = read4(buffer);
            memcpy(buf + cnt, buffer, sz);
            cnt += sz;
            if (sz < 4) break;
        }
        if (cnt > n) {
            buf[n] = '\0';
            cnt = n;
        }
        return cnt;
    }
};




class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int len = 0;
        int m = INT_MAX;
        while(len+4<=n) {
            m = read4(buf+len);
            len += m;
            if(m<4) break;
        }
        if(len==n || m<4) return len;

        char *remain = new char[5];
        m = min(read4(remain),n-len);
        for(int i=0; i<m; i++) buf[len++] = remain[i];
        delete remain;
        
        return len;
    }
};
