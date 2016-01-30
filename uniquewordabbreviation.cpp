#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (string& word : dictionary) {
            const string abbr = abbreviation(word);
            lookup_[abbr].emplace(word);
        }
    } 

    bool isUnique(string word) {
        const string abbr = abbreviation(word);
        return lookup_[abbr].empty() ||
               (lookup_[abbr].count(word) == lookup_[abbr].size());
    }

private:
    unordered_map<string, unordered_set<string> > lookup_;

    string abbreviation(const string& word) {
        return word.front() + to_string(word.length()) + word.back();
    }
};
