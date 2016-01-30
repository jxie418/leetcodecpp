#include<vector>
#include<unordered_map>
#include<string>
#include<iostream>

using namespace std;

class WordDistance {
public:
    WordDistance(vector<string> words) {
        int n = words.size();
        for (int i = 0; i < n; i++)
            wordInd[words[i]].push_back(i);
    }

    int shortest(string word1, string word2) {
        vector<int> indexes1 = wordInd[word1];
        vector<int> indexes2 = wordInd[word2];
        int m = indexes1.size(), n = indexes2.size();
        int i = 0, j = 0, dist = INT_MAX;
        while (i < m && j < n) {
            dist = min(dist, abs(indexes1[i] - indexes2[j]));
            if (indexes1[i] < indexes2[j]) i++;
            else j++;
        }
        return dist;
    }
private:
    unordered_map<string, vector<int> > wordInd;
};
