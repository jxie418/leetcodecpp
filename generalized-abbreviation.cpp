#include<string>
#include<vector>
#include<iostream>

class Solution1 {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        string cur = word;
        result.push_back(word);
        helper(result,cur,word.size(),0,word);
        return result;
    }
private:
    void helper(vector<string>& result,string cur,int num,int idx,string word) {
        for (int i = idx; i < word.size(); i++) {
            for (int len = 1; len <= num && i+len-1 < cur.size(); len++) {
                string tmp = cur;
                tmp.replace(i, len, to_string(len));
                result.push_back(tmp);
                helper(result, tmp, num, i+to_string(len).size()+1, word);
            }
        }
    }
};

class Solution {
public:
	vector<string> generateAbbreviations(string word) {
		vector<string> res;
		string cur;
		generateAbbreviationsHelper(word,0,&cur,&res);
		return res;
	}
	void generateAbbreviationsHelper(const string& word, int i, string *cur, vector<string>*res) {
		if (i == word.length()) {
			res->emplace_back(*cur);
			return;
		}
		cur->push_back(word[i]);
		generateAbbreviationsHelper(word, i+1, cur, res);
		cur->pop_back();
		if (cur->empty() || not isdigit(cur->back())) {
			for ( int l = 1; i+ l <= word.length(); ++l ) {
				cur->append(to_string(l));
				generateAbbreviationsHelper(word, i+l, cur, res);
				cur->resize(cur->length() - to_string(l).length());
			}
		}
	}
};

int main() {
	Solution s;
	return 0;
}
