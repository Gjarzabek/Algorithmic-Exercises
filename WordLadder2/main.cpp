#define multiset<pair<int, pair<string, int>>> MULTISET

class Solution {
public:
    void common_score(string EW, string current, int * weighted_sum, int * score) {
      *score = 0;
      *weighted_sum = 0;
      for (int i = 0; i < EW.length(); ++i) {
        if (EW[i] == current[i]) {
          ++(*score);
          (*weighted_sum) += i;
        }
      }
    }

    void dfs_search(MUTLISET words, MULTISET::iterator cur, const string & endWord, vector<vector<string>> & result, vector<string> & akt)) {
      while (*(cur+1) != words.end() && (*(cur+1)).first == (*cur).first) {
        while () {
          /* code */
        }
        ++cur;
      }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
      MULTISET words;
      for (auto x: wordList) {
        int score,weighted;
        common_score(endWord, x, &weighted, &score);
        words.insert(pair<int, pair<string, int>>(score, (x, weighted)));
      }
      vector<vector<string>> result;
      vector<strting> akt;

    }
};
